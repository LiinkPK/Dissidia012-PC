// The Emendatus mod (by the Emendatus community), built in as a switch like Braviest Turning.
//
// The mod changes the disc's executable (small MIPS patches and a code cave), DATA/PACKAGE_INFO.BIN (three size fields),
// the code of OVL_BATTLE_APP.ELF and OVL_MENU_APP.ELF (the menu overlay also grows), DATA/PACKAGE.BIN (about 325 KB of edits
// in existing entries) and appends 338 MB of new data (the new character) to PACKAGE.BIN. With the switch on, the port runs
// its own patched copy of the decrypted executable (its own corpus, the profile's "emendatus" edition) and serves the four
// files with the mod's bytes put over the disc's own, through the host's file provider; the appended data is read from
// mods/emendatus_assets.bin next to the program. The disc's files are never replaced as a whole: only the changed bytes are in
// d012_emendatus_data.inc (tools/mods/emendatus/make_mod_data.py). The US and EUR discs hold the same entries at other
// archive offsets, so each has its own table. The new data is placed after the end of the disc's own PACKAGE.BIN.
//
// The switch is read once at start-up, so it takes effect at the next start: settings.ini's game.emendatus (the menu's Mods
// page writes it), or D012_EMENDATUS=0/1 for a run.
#include "../../third_party/dissidia012-pc/port/host/d012_decomp_harness.hpp"

#include "app_paths.hpp"
#include "hle/hle_common.hpp"
#include "install/installer.hpp"
#include "install/user_data.hpp"
#include "kernel/iso_image.hpp"
#include "portablekit/hle_extension.hpp"
#include "profile.hpp"
#include "psprecomp/elf32.hpp"
#include "psprecomp/runtime.hpp"
#include "psprecomp/sha256.hpp"
#if defined(PORTABLEKIT_ANDROID_APP)
#include "platform/android_jni.hpp"
#endif
#if defined(PORTABLEKIT_HAS_RENDERER)
#include "ui/ui.hpp"
#include "ui/file_browser.hpp"
#include "ui/updater.hpp"
#include "ui/widgets.hpp"
#include <imgui.h>
#if __has_include(<SDL3/SDL.h>)
#include <SDL3/SDL.h>
#endif
#endif

#include <algorithm>
#include <atomic>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace d012_expansion {
bool redirect(std::filesystem::path &executable);  // d012_expansion.cpp
}
namespace d012_braviest_turning {
void patch_loaded_image(psprecomp::Runtime &runtime, const psprecomp::Elf32Image &elf);  // d012_braviest_turning.cpp
}

namespace {

#include "d012_emendatus_data.inc"

namespace ext = portablekit::hle_extension;

constexpr const char *kKey = "game.emendatus";
constexpr std::uint64_t kPackageSizeUS = 1034358784u, kPackageSizeEUR = 1035005472u;
constexpr std::uint64_t kInfoSize = 132532u, kInfoSizeEUR = 132532u, kBattleSize = 1596312u;

bool g_on = false;  // read once at start-up

bool read_setting() {
    if (const char *text = std::getenv("D012_EMENDATUS"); text != nullptr && *text != '\0') return std::strcmp(text, "0") != 0;
    try {
        const auto entries = portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        if (const auto found = entries.find(kKey); found != entries.end()) return found->second == "1";
    } catch (const std::exception &e) {
        std::cerr << "[mod] settings.ini not read for " << kKey << ": " << e.what() << "\n";
    }
    return false;
}

// The newer mod (it adds a character) also patches the executable and appends the new character's data to PACKAGE.BIN.
// The port patches its own decrypted executable (the regions in kEmEboot) into a file of its own and runs that one, which
// has a corpus of its own (the profile's "emendatus" edition); the new data is the file mods/emendatus_assets.bin next to
// the program, served after the end of PACKAGE.BIN.
constexpr const char *kStockExecutableSha256 = "0bc8e779aad2814a3d1bd77346f69ca5e16665845ed053cd0ad44a9cbfaefe6d";
constexpr const char *kPatchedExecutableSha256 = "832063088cf2dd3b4c064cb06a9c2d1a6c8eb74bfabfbdd0a7a79b5c0c894572";
constexpr const char *kPatchedExecutableFile = "EBOOT_EMENDATUS.ELF";

bool g_applied = false;  // the switch's value this run started with

// A file of the mod's: in mods/ next to the program (Windows, Linux and macOS packages) or, when it is not there, in mods/ of the data
// folder. An APK cannot carry the 338 MB of new data beside the program, so on Android the data folder is where it goes.
constexpr const char *kDataDirKey = "game.emendatus_data_dir";  // the folder the player chose for the mod's data (Android's in-app download)

std::filesystem::path mod_file(const std::string &name) {
    const std::filesystem::path beside = portablekit::executable_directory() / "mods" / name;
    std::error_code ec;
    if (std::filesystem::exists(beside, ec)) return beside;
    try {
        const std::filesystem::path in_data = portablekit::install::user_data_directory() / "mods" / name;
        if (std::filesystem::exists(in_data, ec)) return in_data;
        const auto entries = portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        if (const auto found = entries.find(kDataDirKey); found != entries.end() && !found->second.empty()) {
            const std::filesystem::path chosen = portablekit::install::path_from_utf8(found->second) / "mods" / name;
            if (std::filesystem::exists(chosen, ec)) return chosen;
        }
    } catch (const std::exception &) {
    }
    return beside;
}

std::filesystem::path assets_path() { return mod_file("emendatus_assets.bin"); }

bool assets_present() {
    std::error_code ec;
    return std::filesystem::file_size(assets_path(), ec) == kEmTailSize && !ec;
}

enum class Release { Unknown, US, EUR };

// Which disc this is, by the first bytes of PACKAGE.BIN (they hold the release's ids).
Release release() {
    static bool known = false;
    static Release which = Release::Unknown;
    if (!known) {
        known = true;
        std::uint8_t header[64]{};
        if (portablekit::read_guest_file("disc0:/PSP_GAME/USRDIR/DATA/PACKAGE.BIN", 0u, header, sizeof header) == 64) {
            if (std::memcmp(header, kEmHeaderUS, 64) == 0) which = Release::US;
            else if (std::memcmp(header, kEmHeaderEUR, 64) == 0) which = Release::EUR;
        }
        std::cout << "[mod] Emendatus: this disc is " << (which == Release::US ? "the US release" : which == Release::EUR ? "the EUR release" : "not one it knows (no change made)") << "\n";
    }
    return which;
}

// Puts the regions that fall in [offset, offset + got) of the file over what was read there.
void apply(const EmRegion *regions, std::size_t count, std::uint64_t offset, std::uint8_t *data, std::size_t got) {
    const EmRegion *end = regions + count;
    const EmRegion *it = std::partition_point(regions, end, [&](const EmRegion &r) { return r.offset + r.length <= offset; });
    for (; it != end && it->offset < offset + got; ++it) {
        const std::uint64_t from = std::max<std::uint64_t>(it->offset, offset);
        const std::uint64_t to = std::min<std::uint64_t>(it->offset + it->length, offset + got);
        std::memcpy(data + (from - offset), kEmBlob + it->blob + (from - it->offset), static_cast<std::size_t>(to - from));
    }
}

// EUR: the disc's last entries of PACKAGE.BIN sit past the end of the US file, where the mod's appended data is read (at US
// offsets). They are moved after that data (virtual offsets in PackageFile) and their rows in PACKAGE_INFO.BIN are pointed there.
// Trace to emendatus_trace.log in the working directory, flushed per line (D012_TRACE_PACKAGE), so it survives a hang.
void trace_line(const char *format, unsigned long long a = 0, unsigned long long b = 0, unsigned long long c = 0) {
    static const bool on = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    if (!on) return;
    static std::FILE *file = std::fopen("emendatus_trace.log", "w");
    if (!file) return;
    std::fprintf(file, format, a, b, c);
    std::fflush(file);
}

// D012_LOG_FILE=1: the game's console output (stdout and stderr) goes to d012_console.log in the working directory, unbuffered,
// for release builds, which have no console. Read when the program starts.
struct ConsoleToFile {
    ConsoleToFile() {
        if (std::getenv("D012_LOG_FILE") == nullptr) return;
        std::freopen("d012_console.log", "w", stdout);
        std::freopen("d012_console.log", "a", stderr);
        std::setvbuf(stdout, nullptr, _IONBF, 0);
        std::setvbuf(stderr, nullptr, _IONBF, 0);
    }
} console_to_file;

struct Move { std::uint64_t from, size, to; };
// The EUR disc's entries that end past the US file's end (found from its PACKAGE_INFO.BIN): offset, size.
constexpr std::uint64_t kEurTail[][2] = {
    {1034907648u, 15265u},
    {1034536960u, 282404u},
    {1034942464u, 17921u},
    {1034838016u, 15489u},
    {1034854400u, 17745u},
    {1034889216u, 17424u},
    {1034960896u, 43840u},
    {1034924032u, 17426u},
    {1034276864u, 259444u},
    {1034872832u, 15410u},
    {1034819584u, 17521u},
};

std::vector<Move> g_moves;
std::uint64_t g_moved_end = 0u;

// The new character's own files, taken out of the mod's data and kept in the repository (profiles/d012_vk/aerith/, copied next to the
// program into mods/): her model package and her three costume models. The disc's index has no row for them, so rows are added to
// the index the game reads (the name hash is the game's casefolded CRC32 of "obj/<file>"), pointing at places after everything
// else in PACKAGE.BIN.
// The 22 index rows the Emendatus mod adds (its data, tail offset 0xD891C04; found by their name hashes): the new character's package,
// costume models, extra data, sounds, icons and voices, as (hash, sector in PACKAGE.BIN, size | flags << 28). The sectors are those of
// the US layout, inside the appended data.
constexpr std::uint32_t kModRows[][3] = {
    {0xD02607DDu, 616410u, 0x1037A2D0u},
    {0xFB4632A5u, 618191u, 0x10266794u},
    {0xD63E252Du, 622546u, 0x10267604u},
    {0xCD162855u, 623777u, 0x102664CCu},
    {0x76E2C890u, 618191u, 0x10266794u},
    {0x31EF1BF5u, 619420u, 0x100000A0u},
    {0x1E1A0013u, 619421u, 0x10000058u},
    {0xCFE3B820u, 619421u, 0x10000058u},
    {0x80B4D031u, 619421u, 0x10000058u},
    {0x7211E240u, 619422u, 0x100BEA30u},
    {0x164281B6u, 622032u, 0x10010520u},
    {0xAE4BD83Cu, 622065u, 0x10001520u},
    {0x2E27AC41u, 622068u, 0x10001520u},
    {0x63613F1Cu, 622071u, 0x10004520u},
    {0x4E192894u, 622071u, 0x10004520u},
    {0x553125ECu, 622071u, 0x10004520u},
    {0x69745E16u, 622492u, 0x0000208Cu},
    {0xB263F681u, 622497u, 0x00002E0Cu},
    {0xFB6E910Cu, 622503u, 0x00002F8Cu},
    {0x008DBA18u, 622509u, 0x000061CCu},
    {0x4980DD95u, 622522u, 0x0000730Cu},
    {0x92977502u, 622537u, 0x000040CCu},
};

// The 11 rows the Emendatus mod puts over rows of the game's own index (its menu and message packs and a sound bank: the new
// character's pre-battle info, texts and sounds), as (hash, sector, size). The mod's plugin does this at run time (block2 + 0x7A00);
// here it is done in the index the port serves, keeping each row's own flags.
constexpr std::uint32_t kModReplace[][3] = {
    {0xBA8B325Bu, 619804u, 1151344u},
    {0x9892E431u, 620367u, 366864u},
    {0x8F593261u, 620547u, 807712u},
    {0x4AA1BF07u, 620942u, 589696u},
    {0xD756264Cu, 621230u, 541168u},
    {0x7BCC2B61u, 621495u, 543920u},
    {0x4CAE5267u, 621761u, 315568u},
    {0x50FE4705u, 621916u, 235888u},
    {0x3DB759EAu, 622080u, 306320u},
    {0x92D1AB3Bu, 622230u, 219728u},
    {0x4300D781u, 622338u, 315280u},
};

struct Extra {
    std::uint32_t hash;
    const char *file;
    std::uint64_t base, size;  // where it is served in PACKAGE.BIN, and its size (0: file not found)
};
Extra g_extras[] = {
    {0xD02607DDu, "p_sev120.objx", 0u, 0u},    // obj/p_sev120.objx
    {0xFB4632A5u, "P_SEV120_1P.gmo", 0u, 0u},  // obj/P_SEV120_1P.gmo
    {0xD63E252Du, "P_SEV120_2P.gmo", 0u, 0u},  // obj/P_SEV120_2P.gmo
    {0xCD162855u, "P_SEV120_3P.gmo", 0u, 0u},  // obj/P_SEV120_3P.gmo
    {0xC93FB94Au, "D_SEV120.objx", 0u, 0u},    // obj/D_SEV120.objx (the other FF7 fighters have a D_ pair too)
    {0x752C1C24u, "D_SEV120.gmo", 0u, 0u},     // obj/D_SEV120.gmo
};
std::uint64_t g_package_end = kPackageSizeUS + kEmTailSize;

std::filesystem::path extra_path(const Extra &extra) { return mod_file(extra.file); }

void plan_layout(bool eur) {
    static std::once_flag once;
    std::call_once(once, [eur] {
        std::uint64_t next = (kPackageSizeUS + kEmTailSize + 2047u) / 2048u * 2048u;
        if (eur && std::getenv("D012_EMENDATUS_NOMOVE") == nullptr && std::getenv("D012_EMENDATUS_RAW") == nullptr) {  // NOMOVE: A/B test, the EUR entries stay where they are
            for (const auto &row : kEurTail) {
                g_moves.push_back({row[0], row[1], next});
                next += (row[1] + 2047u) / 2048u * 2048u;
            }
            g_moved_end = next;
        }
        for (Extra &extra : g_extras) {
            std::error_code ec;
            const std::uint64_t size = std::filesystem::file_size(extra_path(extra), ec);
            if (!ec && size != 0u) {
                extra.base = next;
                extra.size = size;
                next += (size + 2047u) / 2048u * 2048u;
            } else {
                std::cerr << "[mod] Emendatus: " << extra_path(extra).string() << " not found, the new character's files are incomplete\n";
            }
        }
        g_package_end = std::max<std::uint64_t>(g_package_end, next);
        trace_line("layout: %llu moves, end %llu\n", g_moves.size(), g_package_end);
    });
}

// A file the size it has on the disc, with the mod's regions over it.
class RegionFile final : public ext::FileFilter {
public:
    RegionFile(std::uint32_t fd, std::uint64_t size, const EmRegion *regions, std::size_t count)
        : fd_(fd), size_(size), regions_(regions), count_(count) {}
    std::uint64_t size() const override { return size_; }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
        if (offset >= size_) return 0u;
        length = static_cast<std::size_t>(std::min<std::uint64_t>(length, size_ - offset));
        const std::size_t got = portablekit::read_open_file(fd_, offset, destination, length);
        apply(regions_, count_, offset, destination, got);
        return got;
    }

private:
    std::uint32_t fd_;
    std::uint64_t size_;
    const EmRegion *regions_;
    std::size_t count_;
};

// PACKAGE_INFO.BIN as the game gets it: the disc's index with the mod's size fields, the moved EUR entries pointed at their new
// place, and a row added for the new character's model package (rows are 12 bytes after a 16-byte header, sorted by hash; the
// row count is the word at +8). The game reads it into a buffer with room for 210 more rows than the disc's index has.
class InfoFile final : public ext::FileFilter {
public:
    InfoFile(std::uint32_t fd, std::uint64_t disc_size, const EmRegion *regions, std::size_t count) : bytes_(static_cast<std::size_t>(disc_size)) {
        const std::size_t got = portablekit::read_open_file(fd, 0u, bytes_.data(), bytes_.size());
        bytes_.resize(got);
        apply(regions, count, 0u, bytes_.data(), got);
        for (std::size_t pos = 16u + 4u; pos + 4u <= bytes_.size(); pos += 12u) {
            std::uint32_t sector;
            std::memcpy(&sector, bytes_.data() + pos, 4);
            for (const Move &m : g_moves)
                if (std::uint64_t(sector) * 2048u == m.from) {
                    const std::uint32_t moved = static_cast<std::uint32_t>(m.to / 2048u);
                    std::memcpy(bytes_.data() + pos, &moved, 4);
                    break;
                }
        }
        const bool raw = std::getenv("D012_EMENDATUS_RAW") != nullptr;  // A/B test: none of the rows added or replaced this session
        if (!raw) for (const auto &replaced : kModReplace) add_row(replaced[0], replaced[1], replaced[2], true);  // the mod's packs replace the game's
        if (!raw) for (const auto &mod_row : kModRows) add_row(mod_row[0], mod_row[1], mod_row[2]);  // the mod's own new rows
        if (!raw) for (const Extra &extra : g_extras)  // then any of the repository's files the mod's rows do not cover
            if (extra.size != 0u)
                add_row(extra.hash, static_cast<std::uint32_t>(extra.base / 2048u), 0x10000000u | static_cast<std::uint32_t>(extra.size));
        // D012_AERITH_CLONE=1 (debug): her model package is Warrior of Light's / Cloud's own (obj/p_sev100.objx), to tell a fault in her
        // package from a fault in the tables the game keys by her id.
        if (std::getenv("D012_AERITH_CLONE") != nullptr) copy_row(0xD02607DDu, 0x4E88D7FFu);
        trace_line("info: %llu bytes\n", bytes_.size());
    }
    std::uint64_t size() const override { return bytes_.size(); }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
        if (offset >= bytes_.size()) return 0u;
        length = static_cast<std::size_t>(std::min<std::uint64_t>(length, bytes_.size() - offset));
        std::memcpy(destination, bytes_.data() + offset, length);
        return length;
    }

private:
    // Points the row of hash `to` at the sector and size of the row of hash `from`.
    void copy_row(std::uint32_t to, std::uint32_t from) {
        if (bytes_.size() < 16u) return;
        std::uint32_t rows;
        std::memcpy(&rows, bytes_.data() + 8, 4);
        std::size_t to_at = rows, from_at = rows;
        for (std::size_t at = 0; at < rows; ++at) {
            std::uint32_t hash;
            std::memcpy(&hash, bytes_.data() + 16u + 12u * at, 4);
            if (hash == to) to_at = at;
            if (hash == from) from_at = at;
        }
        if (to_at < rows && from_at < rows)
            std::memcpy(bytes_.data() + 16u + 12u * to_at + 4u, bytes_.data() + 16u + 12u * from_at + 4u, 8);
    }
    // Adds a row in hash order, unless the index already has one for that hash.
    void add_row(std::uint32_t hash, std::uint32_t sector, std::uint32_t flags_and_size, bool replace = false) {
        if (bytes_.size() < 16u) return;
        std::uint32_t rows;
        std::memcpy(&rows, bytes_.data() + 8, 4);
        std::size_t at = 0;
        while (at < rows) {
            std::uint32_t existing;
            std::memcpy(&existing, bytes_.data() + 16u + 12u * at, 4);
            if (existing == hash) {
                if (replace) {  // another sector and size, the row's own flags kept
                    std::uint32_t old_flags;
                    std::memcpy(&old_flags, bytes_.data() + 16u + 12u * at + 8u, 4);
                    const std::uint32_t row_size = (old_flags & 0xF0000000u) | (flags_and_size & 0x0FFFFFFFu);
                    std::memcpy(bytes_.data() + 16u + 12u * at + 4u, &sector, 4);
                    std::memcpy(bytes_.data() + 16u + 12u * at + 8u, &row_size, 4);
                }
                return;
            }
            if (existing > hash) break;
            ++at;
        }
        const std::uint32_t row[3] = {hash, sector, flags_and_size};
        bytes_.insert(bytes_.begin() + 16 + 12 * static_cast<std::ptrdiff_t>(at), reinterpret_cast<const std::uint8_t *>(row),
                      reinterpret_cast<const std::uint8_t *>(row) + 12);
        ++rows;
        std::memcpy(bytes_.data() + 8, &rows, 4);
    }
    std::vector<std::uint8_t> bytes_;
};

// PACKAGE.BIN with the mod's edits over the disc's bytes, then the new character's data. The patched game reads it at the
// offsets of the US layout (kPackageSizeUS and on), so on the EUR disc, whose file is longer, the part of it that falls
// over the EUR file's own last bytes is not reachable; the disc's own bytes win there.
class PackageFile final : public ext::FileFilter {
public:
    PackageFile(std::uint32_t fd, std::uint64_t disc_size, const EmRegion *regions, std::size_t count)
        : fd_(fd), disc_size_(disc_size), regions_(regions), count_(count), assets_(assets_path(), std::ios::binary) {}
    std::uint64_t size() const override { return g_package_end; }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
        trace_line("want %llu +%llu\n", offset, length);
        const std::size_t got = read_bytes(offset, destination, length);
        {
            trace_line(got != length ? "package read %llu +%llu -> %llu SHORT\n" : "package read %llu +%llu -> %llu\n", offset, length, got);
        }
        return got;
    }
    std::size_t read_bytes(std::uint64_t offset, std::uint8_t *destination, std::size_t length) {
        if (offset >= size()) return 0u;
        for (const Move &m : g_moves)
            if (offset >= m.to && offset < m.to + ((m.size + 2047u) / 2048u) * 2048u) {
                const std::uint64_t inside = offset - m.to;
                if (inside >= m.size) return 0u;
                const std::size_t n = static_cast<std::size_t>(std::min<std::uint64_t>(length, m.size - inside));
                return portablekit::read_open_file(fd_, m.from + inside, destination, n);
            }
        for (const Extra &extra : g_extras)
            if (extra.size != 0u && offset >= extra.base && offset < extra.base + ((extra.size + 2047u) / 2048u) * 2048u) {
                const std::uint64_t inside = offset - extra.base;
                if (inside >= extra.size) return 0u;
                const std::size_t n = static_cast<std::size_t>(std::min<std::uint64_t>(length, extra.size - inside));
                std::ifstream model(extra_path(extra), std::ios::binary);
                model.seekg(static_cast<std::streamoff>(inside));
                model.read(reinterpret_cast<char *>(destination), static_cast<std::streamsize>(n));
                return static_cast<std::size_t>(std::max<std::streamsize>(model.gcount(), 0));
            }
        if (offset >= kPackageSizeUS + kEmTailSize) return 0u;
        length = static_cast<std::size_t>(std::min<std::uint64_t>(length, kPackageSizeUS + kEmTailSize - offset));
        std::size_t done = 0u;
        if (offset < std::min<std::uint64_t>(disc_size_, kPackageSizeUS)) {
            const std::size_t head = static_cast<std::size_t>(std::min<std::uint64_t>(length, std::min<std::uint64_t>(disc_size_, kPackageSizeUS) - offset));
            done = portablekit::read_open_file(fd_, offset, destination, head);
            apply(regions_, count_, offset, destination, done);
            if (done < head) return done;
        }
        if (done < length) {
            const std::lock_guard<std::mutex> lock(mutex_);
            assets_.clear();
            assets_.seekg(static_cast<std::streamoff>(offset + done - kPackageSizeUS));
            assets_.read(reinterpret_cast<char *>(destination + done), static_cast<std::streamsize>(length - done));
            done += static_cast<std::size_t>(std::max<std::streamsize>(assets_.gcount(), 0));
        }
        return done;
    }

private:
    std::uint32_t fd_;
    std::uint64_t disc_size_;
    const EmRegion *regions_;
    std::size_t count_;
    std::mutex mutex_;
    std::ifstream assets_;
};

// The decrypted executable with the mod's patches, or empty when `stock` is not the executable they are made for.
std::vector<std::uint8_t> patched_executable(const std::filesystem::path &stock) {
    std::ifstream in(stock, std::ios::binary);
    std::vector<std::uint8_t> bytes((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (bytes.size() != kEmEbootStock || psprecomp::sha256_bytes(bytes) != kStockExecutableSha256) return {};
    bytes.resize(kEmEbootSize);
    apply(kEmEboot, sizeof kEmEboot / sizeof kEmEboot[0], 0u, bytes.data(), bytes.size());
    if (psprecomp::sha256_bytes(bytes) != kPatchedExecutableSha256) return {};
    return bytes;
}

// The menu overlay: the disc's bytes up to kEmMenuKeep with the regions over them, then the mod's added code.
class MenuOverlay final : public ext::FileFilter {
public:
    explicit MenuOverlay(std::uint32_t fd) : fd_(fd) {}
    std::uint64_t size() const override { return kEmMenuSize; }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
        if (offset >= kEmMenuSize) return 0u;
        length = static_cast<std::size_t>(std::min<std::uint64_t>(length, kEmMenuSize - offset));
        std::size_t done = 0u;
        if (offset < kEmMenuKeep) {
            const std::size_t head = static_cast<std::size_t>(std::min<std::uint64_t>(length, kEmMenuKeep - offset));
            done = portablekit::read_open_file(fd_, offset, destination, head);
            apply(kEmMenu, sizeof kEmMenu / sizeof kEmMenu[0], offset, destination, done);
            apply_applier_data(offset, destination, done);
            if (done < head) return done;
        }
        if (done < length) {
            const std::uint64_t position = offset + done;  // in the added code
            std::memcpy(destination + done, kEmBlob + kEmMenuTail[0].blob + (position - kEmMenuKeep), length - done);
            done = length;
        }
        return done;
    }

private:
    // The one write of the mod's patch applier (block2 + 0x2F40, "ptr") that is not in the code: the fifth pointer of the menu's list of
    // name codes ("ten110", "gst110", "gst120", "gst130", "org210") points at a new string "sev120", the new character's code, at
    // 0x08B5803C. The applier runs at menu load in the patched game; the port never calls it, so it is done in the image it serves.
    // File offset = 0x54 + (address - 0x089DD4C0).
    static void apply_applier_data(std::uint64_t offset, std::uint8_t *data, std::size_t got) {
        static const struct { std::uint64_t at; std::uint8_t bytes[8]; std::size_t count; } kPatches[] = {
            {0x17ABCCu, {0x3C, 0x80, 0xB5, 0x08}, 4u},                              // word at 0x08B58038: 0x08B57DD8 -> 0x08B5803C
            {0x17ABD0u, {'s', 'e', 'v', '1', '2', '0', 0, 0}, 8u},                  // the string at 0x08B5803C
        };
        for (const auto &patch : kPatches)
            for (std::size_t i = 0; i < patch.count; ++i) {
                const std::uint64_t position = patch.at + i;
                if (position >= offset && position < offset + got) data[position - offset] = patch.bytes[i];
            }
    }
    std::uint32_t fd_;
};

bool ends_with_icase(std::string_view text, std::string_view tail) {
    if (text.size() < tail.size()) return false;
    text.remove_prefix(text.size() - tail.size());
    for (std::size_t i = 0; i < tail.size(); ++i)
        if ((text[i] | 0x20) != (tail[i] | 0x20)) return false;
    return true;
}

// Serves the five files that exist on the disc (fd != 0); everything else is left to the game and the other providers.
std::shared_ptr<ext::FileFilter> serve(std::string_view path, std::uint32_t fd) {
    if (fd == 0u || !g_on || !path.starts_with("disc0:/")) return nullptr;
    const bool package = ends_with_icase(path, "/data/package.bin"), info = ends_with_icase(path, "/data/package_info.bin");
    const bool battle = ends_with_icase(path, "/data/ovl_battle_app.elf"), menu = ends_with_icase(path, "/data/ovl_menu_app.elf");
    if (!package && !info && !battle && !menu) return nullptr;
    trace_line("serve fd=%llu\n", fd);
    const Release disc = release();
    trace_line("release=%llu\n", static_cast<unsigned long long>(disc));
    if (disc == Release::Unknown) return nullptr;
    std::cout << "[mod] The Emendatus Mod: " << path << " is served with the mod's changes\n";
    if (package || info) plan_layout(disc == Release::EUR);
    if (package) {
        return disc == Release::US ? std::make_shared<PackageFile>(fd, kPackageSizeUS, kEmPackageUS, sizeof kEmPackageUS / sizeof kEmPackageUS[0])
                                   : std::make_shared<PackageFile>(fd, kPackageSizeEUR, kEmPackageEUR, sizeof kEmPackageEUR / sizeof kEmPackageEUR[0]);
    }
    if (info) {
        return std::make_shared<InfoFile>(fd, kInfoSize, kEmIndex, sizeof kEmIndex / sizeof kEmIndex[0]);
    }
    if (battle) return std::make_shared<RegionFile>(fd, kBattleSize, kEmBattle, sizeof kEmBattle / sizeof kEmBattle[0]);
    return std::make_shared<MenuOverlay>(fd);
}

// The Manikin outfit (MNKN). The mod's menu offers it as costume slot 12 of a character, but the object table has no row for
// (character, 12), so the game's scan finds nothing and the battle falls back to costume 1 (the default skin). Costume 0 of
// every character is its manikin (the _ZAKO row), so a scan for slot 12 that finds nothing answers with the scan for slot 0.
// The menu's own check (is there a row for slot 12) then offers the outfit too. Only while the mod is on.
constexpr std::uint32_t kObjectScan = 0x088470DCu;  // main: (character, costume, assist) -> row of objentry.bin, or 0
constexpr std::uint32_t kManikinSlot = 12u;

// A NUL-ended text in the game's memory (at most 64 characters), for the traces.
std::string guest_text(std::uint32_t address) {
    std::string text;
    for (std::uint32_t i = 0; i < 64u; ++i) {
        const char c = static_cast<char>((d012::decomp::live_load32((address + i) & ~3u) >> (((address + i) & 3u) * 8u)) & 0xFFu);
        if (c == 0) break;
        text.push_back(c >= 32 && c < 127 ? c : '?');
    }
    return text;
}

void run_object_scan(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kObjectScan, regs);
    if (regs.v0 == 0u && g_on && in.gpr[5] == kManikinSlot) {
        GuestRegs manikin{};
        for (int i = 0; i < 8; ++i) manikin.a[i] = in.gpr[4 + i];
        manikin.a[1] = 0u;
        d012::decomp::call_original(g, kObjectScan, manikin);
        if (manikin.v0 != 0u) regs = manikin;
    }
    // Trace for the new character (0x21): what the object table answers. D012_TRACE_PACKAGE=1 turns it on.
    static const bool trace_scan = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    if (trace_scan && g_on && in.gpr[4] == 0x21u)
        std::fprintf(stderr, "[emendatus] object scan character=0x%X costume=%u assist=%u -> %u\n", in.gpr[4], in.gpr[5], in.gpr[6],
                     regs.v0);
    if (trace_scan && g_on && in.gpr[4] == 0x21u && regs.v0 != 0u)
        std::fprintf(stderr, "[emendatus]   row name \"%s\"%s", guest_text(regs.v0 + 0x24u).c_str(), "\n");
    out = regs;
}

// The file-exists check of the loader (FUN_088fe7c8): is the named file in the package index? 0 = no, and the loader flags an error.
constexpr std::uint32_t kFileExists = 0x088FE7C8u;
void run_file_exists(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kFileExists, regs);
    static const bool trace = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    static int lines = 0;
    if (trace && g_on && lines < 400) {
        ++lines;
        std::fprintf(stderr, "[emendatus] file exists \"%s\" -> %u\n", guest_text(in.gpr[4]).c_str(), regs.v0);
    }
    out = regs;
}

// The package index search (FUN_088713e4(index, name) -> row or 0). Pure memory, so it is safe to wrap: logs the names of the new
// character's files (D012_TRACE_PACKAGE=1).
constexpr std::uint32_t kIndexSearch = 0x088713E4u;
void run_index_search(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kIndexSearch, regs);
    static const bool trace = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    static int lines = 0;
    static int calls = 0;
    ++calls;
    if (trace && g_on && lines < 400) {
        const std::string name = guest_text(in.gpr[5]);
        if (name.rfind("obj/", 0) == 0 || regs.v0 == 0u) {
            ++lines;
            std::fprintf(stderr, "[emendatus] index search \"%s\" -> %08X\n", name.c_str(), regs.v0);
        }
    }
    out = regs;
}

// FUN_088470b8(index) -> row of objentry.bin or 0: a pure memory lookup, traced for the setup of the battle's objects.
constexpr std::uint32_t kObjectRow = 0x088470B8u;
void run_object_row(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kObjectRow, regs);
    static const bool trace = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    static int lines = 0;
    if (trace && g_on && lines < 120) {
        ++lines;
        std::fprintf(stderr, "[emendatus] object row %u -> %08X %s\n", in.gpr[4], regs.v0, regs.v0 != 0u ? guest_text(regs.v0 + 0x24u).c_str() : "(none)");
    }
    out = regs;
}

// The loader's per-frame state machine for one object (FUN_08846a3c(machine): state byte at +0x60, the object index at +0x10, the
// error flag at +0x61). It only starts requests, never waits, so it is safe to wrap. Logged when the state or index changes.
constexpr std::uint32_t kLoaderStep = 0x08846A3Cu;
void run_loader_step(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    static const bool trace = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    static std::uint32_t last_key = 0xFFFFFFFFu;
    static int lines = 0;
    if (trace && g_on && lines < 300) {
        const std::uint32_t machine = in.gpr[4];
        const std::uint32_t word60 = d012::decomp::live_load32(machine + 0x60u);
        const std::uint32_t state = word60 & 0xFFu, error = (word60 >> 8) & 0xFFu;
        const std::uint32_t index = d012::decomp::live_load32(machine + 0x10u);
        const std::uint32_t key = state | (error << 8) | (index << 16);
        if (key != last_key) {
            last_key = key;
            ++lines;
            std::fprintf(stderr, "[emendatus] loader %08X state %u error %u index %d\n", machine, state, error, static_cast<int>(index));
        }
    }
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kLoaderStep, regs);
    out = regs;
}

// The loader's file requests (D012_TRACE_PACKAGE=1): FUN_088fe708 starts a load of a named file (and returns its size or 0), FUN_088fe850 starts
// one with a callback. Logged with the name, to see which request of the new character's load never goes out.
template <std::uint32_t Address>
void run_request_trace(Guest *g, const d012::decomp::CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    static const bool trace = std::getenv("D012_TRACE_PACKAGE") != nullptr;
    static int lines = 0;
    if (trace && g_on && lines < 200) {
        const std::string name = guest_text(in.gpr[4]);
        if (name.rfind("obj/", 0) == 0) {
            ++lines;
            std::fprintf(stderr, "[emendatus] request %08X \"%s\"\n", Address, name.c_str());
        }
    }
    d012::decomp::call_original(g, Address, regs);
    out = regs;
}

struct ScanInstall {
    ScanInstall() {
        // The Manikin fix is always on. The rest only trace (D012_TRACE_PACKAGE=1) and are not installed otherwise: wrapping loader
        // functions that can wait crashes the game ("a guest call from decompiled code switched threads").
        static const d012::decomp::Override overrides[] = {
            {kObjectScan, "emendatus_manikin_slot", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_object_scan},
            {kFileExists, "emendatus_file_exists_trace", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_file_exists},
            {kIndexSearch, "emendatus_index_search_trace", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_index_search},
            {kObjectRow, "emendatus_object_row_trace", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_object_row},
        };
        d012::decomp::add_overrides(overrides, std::getenv("D012_TRACE_PACKAGE") != nullptr ? 4 : 1, true);
    }
} scan_install;

#if defined(PORTABLEKIT_HAS_RENDERER)
void save_setting(bool on) {
    try {
        const std::filesystem::path dir = portablekit::install::user_data_directory();
        portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        entries[kKey] = on ? "1" : "0";
        portablekit::install::write_settings_file(dir, entries);
    } catch (const std::exception &e) {
        std::cerr << "[mod] settings.ini not written for " << kKey << ": " << e.what() << "\n";
    }
}

// Closes the game and starts it again, as the menu's own restart after a save import does.
void restart_game() {
    portablekit::install::request_restart_on_exit();
#if __has_include(<SDL3/SDL.h>)
    SDL_Event quit{};
    quit.type = SDL_EVENT_QUIT;
    SDL_PushEvent(&quit);
#endif
}

// The mod's 338 MB of new data is not in the repository, so a package built from it (Linux, macOS, the Android APK) has none. It is
// downloaded once, from the latest release's emendatus_assets.bin, into mods/ of a folder the player picks on Android (the app's own
// storage or an SD card) or of the game's data folder elsewhere; mod_file() finds it there.
namespace data_download {
enum class Phase { Idle, Finding, Downloading, Done, Failed };
std::mutex g_lock;
Phase g_phase = Phase::Idle;
std::string g_error;
std::atomic<std::uint64_t> g_done{0}, g_total{0};

struct Choice {
    std::string path;  // the folder that gets mods/emendatus_assets.bin
    std::string name;
    std::uint64_t free_bytes{};
};

void set_phase(Phase phase, const std::string &error = {}) {
    const std::lock_guard<std::mutex> guard(g_lock);
    g_phase = phase;
    g_error = error;
}

// Whether this build holds the Emendatus edition's recompiled code: without it the data would be of no use.
bool corpus_in_build() {
    std::error_code ec;
#if defined(PORTABLEKIT_ANDROID_APP)
    const std::filesystem::path folder = portablekit::executable_directory();  // libcorpus_emendatus.so among the libraries
#else
    const std::filesystem::path folder = portablekit::executable_directory() / "corpora";
#endif
    for (std::filesystem::directory_iterator it(folder, ec); !ec && it != std::filesystem::directory_iterator(); it.increment(ec))
        if (it->path().filename().string().find("emendatus") != std::string::npos) return true;
    return false;
}

std::vector<Choice> choices() {
    std::vector<Choice> found;
#if defined(PORTABLEKIT_ANDROID_APP)
    for (const portablekit::android::StorageChoice &choice : portablekit::android::storage_choices())
        found.push_back({choice.path, choice.name, choice.free_bytes});
#else
    std::error_code ec;
    const std::filesystem::path data = portablekit::install::user_data_directory();
    std::filesystem::create_directories(data, ec);
    const std::filesystem::space_info space = std::filesystem::space(data, ec);
    found.push_back({portablekit::install::path_to_utf8(data), "The game's data folder", ec ? 0u : static_cast<std::uint64_t>(space.available)});
#endif
    return found;
}

// The files of the mod that the download writes: the only names it ever creates, replaces or deletes in mods/.
static const char *const kModFiles[] = {"emendatus_assets.bin", "p_sev120.objx", "D_SEV120.gmo", "D_SEV120.objx", "P_SEV120_1P.gmo", "P_SEV120_2P.gmo", "P_SEV120_3P.gmo"};

// Whether two files hold the same bytes.
bool same_content(const std::filesystem::path &a, const std::filesystem::path &b) {
    std::error_code ec;
    if (std::filesystem::file_size(a, ec) != std::filesystem::file_size(b, ec) || ec) return false;
    std::ifstream first(a, std::ios::binary), second(b, std::ios::binary);
    if (!first || !second) return false;
    char x[64 * 1024], y[64 * 1024];
    while (first.read(x, sizeof(x)) || first.gcount() > 0) {
        const std::streamsize count = first.gcount();
        second.read(y, count);
        if (second.gcount() != count || std::memcmp(x, y, static_cast<std::size_t>(count)) != 0) return false;
    }
    return true;
}

void download_into(std::string folder) {
    set_phase(Phase::Finding);
    g_done = 0;
    g_total = kEmTailSize;
    std::string error;
    // The whole mods/ folder of the data pack: the big data file and the new character's files. The small files are fetched again every
    // time (a few MB, so a changed one is always replaced); the big one only when its size is not the expected one.
    for (const char *file : kModFiles) {
        const std::string name = file;
        const bool big = name == "emendatus_assets.bin";
        const std::filesystem::path target = portablekit::install::path_from_utf8(folder) / "mods" / name;
        std::error_code ec;
        if (big && std::filesystem::file_size(target, ec) == kEmTailSize && !ec) continue;
        // Only these seven names are ever written, so a file of the player's own in mods/ is never touched. A small file that is already
        // there is fetched beside it and replaces it only when the release's differs: one that is the same is left as it is.
        const bool replacing = !big && std::filesystem::exists(target, ec);
        std::filesystem::path fetched = target;
        if (replacing) fetched += ".new";
        set_phase(Phase::Finding);
        const std::string url = portablekit::ui::updater::latest_asset_url(name, error);
        if (url.empty()) {
            set_phase(Phase::Failed, error);
            return;
        }
        set_phase(Phase::Downloading);
        g_done = 0;
        g_total = big ? kEmTailSize : 0;
#if defined(PORTABLEKIT_ANDROID_APP)
        const bool ok = portablekit::android::download_to(url, portablekit::install::path_to_utf8(fetched), big ? kEmTailSize : 0u, error);
#else
        const bool ok = portablekit::ui::updater::download_file(
            url, fetched, big ? kEmTailSize : 0u,
            [](std::uint64_t done, std::uint64_t total) {
                g_done = done;
                g_total = total;
            },
            error);
#endif
        if (!ok) {
            std::filesystem::remove(fetched, ec);
            set_phase(Phase::Failed, error);
            return;
        }
        if (replacing) {
            if (same_content(fetched, target)) std::filesystem::remove(fetched, ec);
            else {
                std::filesystem::rename(fetched, target, ec);
                if (ec) {
                    std::filesystem::remove(fetched, ec);
                    set_phase(Phase::Failed, "the new " + name + " could not replace the old one");
                    return;
                }
            }
        }
    }
    try {
        const std::filesystem::path dir = portablekit::install::user_data_directory();
        portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        entries[kDataDirKey] = folder;
        portablekit::install::write_settings_file(dir, entries);
    } catch (const std::exception &e) {
        set_phase(Phase::Failed, std::string("the file is downloaded but the choice could not be saved: ") + e.what());
        return;
    }
    set_phase(Phase::Done);
}

// Whether the player's choice of folder is saved.
bool location_saved() {
    try {
        const auto entries = portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        const auto found = entries.find(kDataDirKey);
        return found != entries.end() && !found->second.empty();
    } catch (const std::exception &) {
        return false;
    }
}

// Forgets the saved folder, so the mod's files are looked for again in the usual places and, when they are not found, the player
// chooses where to download them. Nothing is deleted: files already in a folder are kept, and a download into that folder skips the big
// file when it is whole.
void reset_location() {
    try {
        const std::filesystem::path dir = portablekit::install::user_data_directory();
        portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        entries.erase(kDataDirKey);
        portablekit::install::write_settings_file(dir, entries);
    } catch (const std::exception &) {
    }
    set_phase(Phase::Idle);
}

// The mods/ folder an earlier version could put the files in: the app's private storage (/data/...), which no file manager can open.
// Empty when the saved folder is anywhere else, or none is saved.
std::filesystem::path private_mods_folder() {
    try {
        const auto entries = portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        const auto found = entries.find(kDataDirKey);
        if (found != entries.end() && found->second.compare(0, 6u, "/data/") == 0)
            return portablekit::install::path_from_utf8(found->second) / "mods";
    } catch (const std::exception &) {
    }
    return {};
}

// Deletes the mod's files from that private folder (only the names in kModFiles, and any half-made copy of them), then the folder
// itself if nothing else is in it, and forgets the saved folder. The player cannot do this with a file manager.
void delete_private_files() {
    const std::filesystem::path folder = private_mods_folder();
    if (folder.empty()) return;
    std::error_code ec;
    for (const char *file : kModFiles) {
        const std::filesystem::path path = folder / file;
        std::filesystem::remove(path, ec);
        std::filesystem::remove(std::filesystem::path(path.string() + ".part"), ec);
        std::filesystem::remove(std::filesystem::path(path.string() + ".new"), ec);
    }
    std::filesystem::remove(folder, ec);  // fails, and keeps it, when anything else is in it
    reset_location();
}

// A folder of the player's own choice (with all files access, any folder is a plain path), as the DLC screen does. The files go into its mods/.
std::unique_ptr<portablekit::ui::FileBrowser> g_browser;
std::string g_last_folder;

void open_browser() {
    namespace ui = portablekit::ui;
    ui::FileBrowser::Options options;
    options.extensions = {};
    options.filter_name = "folders";
    options.listed_name = "folders";
    options.empty_note = "No folders here.";
    options.choose_folder = "Download the Emendatus files into this folder";
    std::filesystem::path start = portablekit::install::path_from_utf8(g_last_folder);
    std::error_code ec;
    if (start.empty() || !std::filesystem::is_directory(start, ec)) start = ui::FileBrowser::home();
    g_browser = std::make_unique<ui::FileBrowser>(start, std::move(options));
}

// The folder chooser, in a window of its own over the page. Called every frame of the Mods page.
void browser_window() {
    namespace ui = portablekit::ui;
    if (!g_browser) return;
    if (!ImGui::IsPopupOpen("##em_browser")) ImGui::OpenPopup("##em_browser");
    const ImGuiIO &io = ImGui::GetIO();
    ImGui::SetNextWindowPos({io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f}, ImGuiCond_Always, {0.5f, 0.5f});
    ImGui::SetNextWindowSize({io.DisplaySize.x * 0.9f, io.DisplaySize.y * 0.85f}, ImGuiCond_Always);
    if (!ImGui::BeginPopupModal("##em_browser", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings)) return;
    ui::heading("Choose where the Emendatus files go");
    ui::paragraph("Open the folder to put them in. They are saved in a folder called mods inside it, and the game finds them there.",
                  ui::colors::kTextDim);
    const float button_room = ImGui::GetTextLineHeightWithSpacing() * 3.2f + ImGui::GetStyle().ItemSpacing.y;
    ImGui::BeginChild("##em_browser_body", {0.0f, ImGui::GetContentRegionAvail().y - button_room}, ImGuiChildFlags_NavFlattened);
    const ui::FileBrowser::Result result = g_browser->frame(false);
    ImGui::EndChild();
    bool close = result != ui::FileBrowser::Result::Browsing;
    if (result == ui::FileBrowser::Result::Chosen) {
        const std::string chosen = portablekit::install::path_to_utf8(g_browser->chosen());
        g_last_folder = chosen;
        std::thread(download_into, chosen).detach();
    } else if (result == ui::FileBrowser::Result::Cancelled) {
        g_last_folder = portablekit::install::path_to_utf8(g_browser->folder());
    }
    if (!close && ui::big_button("Cancel", ImGui::GetContentRegionAvail().x)) close = true;
    if (close) {
        g_browser.reset();
        ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
}

void rows() {
    namespace ui = portablekit::ui;
    Phase phase;
    std::string error;
    {
        const std::lock_guard<std::mutex> guard(g_lock);
        phase = g_phase;
        error = g_error;
    }
    if (!corpus_in_build()) {
        ui::info_row("Emendatus data", "This build does not include the Emendatus Mod's code");
        return;
    }
    const bool installed = phase == Phase::Done || assets_present();
    ui::info_row("Emendatus data", installed ? "Installed" : "Not installed (a 322 MB download, once)");
    if (phase == Phase::Finding) {
        ui::info_row("Status", "Looking for the files in the data-pack release…");
        return;
    }
    if (phase == Phase::Downloading) {
        std::uint64_t done = g_done.load(), total = g_total.load();
#if defined(PORTABLEKIT_ANDROID_APP)
        portablekit::android::update_progress(done, total);
#endif
        ui::progress_bar(total != 0u ? static_cast<float>(done) / static_cast<float>(total) : 0.0f, "Downloading the Emendatus data");
        return;
    }
    if (phase == Phase::Done) {
        ui::info_row("Status", "Done. Restart the game, then turn the Emendatus Mod on here.");
        return;
    }
    if (phase == Phase::Failed) ui::info_row("Download failed", error);
    if (installed) {
        // Already there: fetch again only what differs, into the folder it is in (the big file stays when its size is right).
        ui::RowOptions options;
        options.description = "Downloads the mod's small files again and the big one only if it is not whole, replacing what differs.";
        if (ui::button_row("Update the Emendatus files###emupdate", options)) {
            const std::filesystem::path where = assets_path().parent_path().parent_path();
            std::thread(download_into, portablekit::install::path_to_utf8(where)).detach();
        }
        return;
    }
    static std::vector<Choice> places = choices();
    for (const Choice &choice : places) {
        const bool room = choice.free_bytes > kEmTailSize + (256ull << 20);
        ui::RowOptions options;
        options.disabled = !room;
        options.note = std::to_string(choice.free_bytes >> 20) + " MB free" + (room ? "" : ", not enough");
        options.description = "Downloads the Emendatus data into " + choice.path + "/mods. It stays in this game's own folder there.";
        if (ui::button_row(("Download to: " + choice.name + "###emdata " + choice.path).c_str(), options)) {
            std::thread(download_into, choice.path).detach();
            break;
        }
    }
    ui::RowOptions other;
    other.description = "Choose any folder on the phone or the SD card. The Emendatus files are saved in a folder called mods inside it.";
    if (ui::button_row("Download to another folder…###emother", other)) open_browser();
}
} // namespace data_download

void mod_rows() {
    namespace ui = portablekit::ui;
    ui::section("Emendatus");
    ui::RowOptions options;
    options.description = "The Emendatus balance and content mod, by the Emendatus community, with its new character. Works with the US and EUR discs. The game restarts to apply it.";
    static bool wanted = read_setting();  // the setting as saved
    static bool target = false;           // what the open question would set
    static bool asking = false;
    const bool have_assets = assets_present();
#if defined(PORTABLEKIT_ANDROID_APP)
    data_download::rows();  // on Android also when the files are there: "Update the Emendatus files" compares and replaces what differs
#else
    if (!have_assets) data_download::rows();  // the data is not in this build: offer to download it, whatever the platform
#endif
    data_download::browser_window();
    if (data_download::location_saved()) {
        ui::RowOptions reset;
        reset.description = "Forgets the folder chosen for the mod's files and looks for them again. If they are not found you choose where to "
                            "download them; files already in a folder are kept, and downloading into it skips what is whole.";
        if (ui::button_row("Reset the mods folder location###emreset", reset)) data_download::reset_location();
    }
    if (!data_download::private_mods_folder().empty()) {
        ui::RowOptions old;
        old.description = "The mod's files were put in the app's private storage, which no file manager can open. This deletes them from there "
                          "(only the Emendatus files, nothing else) and forgets that folder. Then download them again into the shared area.";
        if (ui::button_row("Delete the old mod files###emdelold", old)) data_download::delete_private_files();
    }
    if (!have_assets && !read_setting()) return;  // the mod's data is not here: no row
    if (const char *text = std::getenv("D012_EMENDATUS"); text != nullptr && *text != 0) {
        options.disabled = true;
        options.note = "Set by D012_EMENDATUS";
    } else if (!have_assets && !wanted) {
        options.disabled = true;
        options.note = "mods/emendatus_assets.bin is missing";
    } else if (wanted != g_applied) {
        options.note = "restart to apply";
    }
    if (ui::toggle_row("Emendatus Mod", wanted, options)) {
        target = !wanted;
        asking = true;
    }
    if (asking && !ImGui::IsPopupOpen("##em_restart")) ImGui::OpenPopup("##em_restart");
    const ImGuiIO &io = ImGui::GetIO();
    const float font = ImGui::GetFontSize();
    ImGui::SetNextWindowPos({io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f}, ImGuiCond_Always, {0.5f, 0.5f});
    ImGui::SetNextWindowSize({std::min(io.DisplaySize.x * 0.9f, font * 26.0f), 0.0f}, ImGuiCond_Always);
    if (ImGui::BeginPopupModal("##em_restart", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings)) {
        if (!asking) {
            ImGui::CloseCurrentPopup();
        } else {
            ui::heading(target ? "Turn the Emendatus Mod on?" : "Turn the Emendatus Mod off?");
            ui::paragraph("The game has to restart for this to take effect. Progress since your last save is lost.",
                          ui::colors::kTextDim);
            ImGui::Dummy({0.0f, font * 0.6f});
            const float gap = font * 0.6f;
            const float width = (ImGui::GetContentRegionAvail().x - gap) * 0.5f;
            if (ui::big_button("Restart now", width, true)) {
                wanted = target;
                save_setting(wanted);
                asking = false;
                restart_game();
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine(0.0f, gap);
            if (ui::big_button("Cancel", width)) {
                asking = false;  // nothing is changed
                ImGui::CloseCurrentPopup();
            }
            ImGui::SetItemDefaultFocus();
        }
        ImGui::EndPopup();
    }
}
struct Install {
    Install() { portablekit::ui::add_mod_rows(&mod_rows); }
} install;
#endif

} // namespace

namespace d012_emendatus {

namespace {
bool g_redirected = false;  // this run is the mod's executable (redirect_game_files)
}

// The profile's patch_loaded_image: Braviest Turning's (and the port's), then this mod's switch and file provider.
void patch_loaded_image(psprecomp::Runtime &runtime, const psprecomp::Elf32Image &elf) {
    d012_braviest_turning::patch_loaded_image(runtime, elf);
    static bool installed = false;
    if (installed) return;
    installed = true;
    g_applied = read_setting();
    if (!g_redirected) {
        if (g_applied) std::cout << "[mod] The Emendatus Mod is on, but its executable was not set up; it is not used\n";
        return;
    }
    g_on = true;
    portablekit::add_file_provider(&serve);
    std::cout << "[mod] The Emendatus Mod is on\n";
}

// While the switch is on, runs the mod's executable (the disc's own with the mod's patches, kept in the data folder) instead
// of the installed one; the disc image stays the player's own. Nothing changes when the switch is off, the mod's assets
// file is missing, or the installed executable is not the stock one the patches are made for.
static void redirect_emendatus(std::filesystem::path &executable) {
    if (!read_setting()) return;
    if (!assets_present()) {
        std::cerr << "[mod] The Emendatus Mod is not used: " << portablekit::install::path_to_utf8(assets_path()) << " is missing\n";
        return;
    }
    try {
        if (psprecomp::sha256_file(executable) != kStockExecutableSha256) return;
        const std::filesystem::path prepared = portablekit::install::user_data_directory() / kPatchedExecutableFile;
        std::error_code ec;
        if (!std::filesystem::is_regular_file(prepared, ec) || psprecomp::sha256_file(prepared) != kPatchedExecutableSha256) {
            const std::vector<std::uint8_t> bytes = patched_executable(executable);
            if (bytes.empty()) {
                std::cerr << "[mod] The Emendatus Mod is not used: the executable could not be patched\n";
                return;
            }
            std::ofstream out(prepared, std::ios::binary | std::ios::trunc);
            out.write(reinterpret_cast<const char *>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
            out.close();
            if (!out) throw std::runtime_error("cannot write " + portablekit::install::path_to_utf8(prepared));
        }
        executable = prepared;
        g_redirected = true;
    } catch (const std::exception &e) {
        std::cerr << "[mod] The Emendatus Mod is not used: " << e.what() << "\n";
    }
}

// The game files this run uses: the Emendatus Mod's executable when it is on and set up; otherwise the stock one with Gojo's memory
// expansion (d012_expansion.cpp), which the mod's executable already has.
void redirect_game_files(std::filesystem::path &executable, std::filesystem::path &) {
    redirect_emendatus(executable);
    if (!g_redirected) d012_expansion::redirect(executable);
}

} // namespace d012_emendatus

bool d012_emendatus_on() { return g_on; }

// Where the mod's files are, for the Mods page's "Open the mods folder" button: the folder that holds emendatus_assets.bin, or, when
// that file is not there yet, mods/ of the folder the player chose for the download (kept in the settings file). Empty when neither
// is known: the button then opens the data folder's mods.
std::string d012_mods_folder() {
    std::error_code ec;
    const std::filesystem::path file = mod_file("emendatus_assets.bin");
    if (std::filesystem::exists(file, ec)) return portablekit::install::path_to_utf8(file.parent_path());
    try {
        const auto entries = portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        if (const auto found = entries.find(kDataDirKey); found != entries.end() && !found->second.empty())
            return portablekit::install::path_to_utf8(portablekit::install::path_from_utf8(found->second) / "mods");
    } catch (const std::exception &) {
    }
    return {};
}

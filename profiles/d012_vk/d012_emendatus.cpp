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
#if defined(PORTABLEKIT_HAS_RENDERER)
#include "ui/ui.hpp"
#include "ui/widgets.hpp"
#include <imgui.h>
#if __has_include(<SDL3/SDL.h>)
#include <SDL3/SDL.h>
#endif
#endif

#include <algorithm>
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
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace d012_braviest_turning {
void patch_loaded_image(psprecomp::Runtime &runtime, const psprecomp::Elf32Image &elf);  // d012_braviest_turning.cpp
}

namespace {

#include "d012_emendatus_data.inc"

namespace ext = portablekit::hle_extension;

constexpr const char *kKey = "game.emendatus";
constexpr std::uint64_t kPackageSizeUS = 1034358784u, kPackageSizeEUR = 1035005472u;
constexpr std::uint64_t kInfoSize = 132532u, kBattleSize = 1596312u;

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

std::filesystem::path assets_path() { return portablekit::executable_directory() / "mods" / "emendatus_assets.bin"; }

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

// PACKAGE.BIN with the mod's edits over the disc's bytes, then the new character's data. The patched game reads it at the
// offsets of the US layout (kPackageSizeUS and on), so on the EUR disc, whose file is longer, the part of it that falls
// over the EUR file's own last bytes is not reachable; the disc's own bytes win there.
class PackageFile final : public ext::FileFilter {
public:
    PackageFile(std::uint32_t fd, std::uint64_t disc_size, const EmRegion *regions, std::size_t count)
        : fd_(fd), disc_size_(disc_size), regions_(regions), count_(count), assets_(assets_path(), std::ios::binary) {}
    std::uint64_t size() const override { return kPackageSizeUS + kEmTailSize; }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
        if (offset >= size()) return 0u;
        length = static_cast<std::size_t>(std::min<std::uint64_t>(length, size() - offset));
        std::size_t done = 0u;
        if (offset < disc_size_) {
            const std::size_t head = static_cast<std::size_t>(std::min<std::uint64_t>(length, disc_size_ - offset));
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
    const Release disc = release();
    if (disc == Release::Unknown) return nullptr;
    std::cout << "[mod] The Emendatus Mod: " << path << " is served with the mod's changes\n";
    if (package) {
        return disc == Release::US ? std::make_shared<PackageFile>(fd, kPackageSizeUS, kEmPackageUS, sizeof kEmPackageUS / sizeof kEmPackageUS[0])
                                   : std::make_shared<PackageFile>(fd, kPackageSizeEUR, kEmPackageEUR, sizeof kEmPackageEUR / sizeof kEmPackageEUR[0]);
    }
    if (info) return std::make_shared<RegionFile>(fd, kInfoSize, kEmIndex, sizeof kEmIndex / sizeof kEmIndex[0]);
    if (battle) return std::make_shared<RegionFile>(fd, kBattleSize, kEmBattle, sizeof kEmBattle / sizeof kEmBattle[0]);
    return std::make_shared<MenuOverlay>(fd);
}

// The Manikin outfit (MNKN). The mod's menu offers it as costume slot 12 of a character, but the object table has no row for
// (character, 12), so the game's scan finds nothing and the battle falls back to costume 1 (the default skin). Costume 0 of
// every character is its manikin (the _ZAKO row), so a scan for slot 12 that finds nothing answers with the scan for slot 0.
// The menu's own check (is there a row for slot 12) then offers the outfit too. Only while the mod is on.
constexpr std::uint32_t kObjectScan = 0x088470DCu;  // main: (character, costume, assist) -> row of objentry.bin, or 0
constexpr std::uint32_t kManikinSlot = 12u;

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
    out = regs;
}

struct ScanInstall {
    ScanInstall() {
        static const d012::decomp::Override overrides[] = {
            {kObjectScan, "emendatus_manikin_slot", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_object_scan},
        };
        d012::decomp::add_overrides(overrides, 1, true);
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

void mod_rows() {
    namespace ui = portablekit::ui;
    ui::section("Emendatus");
    ui::RowOptions options;
    options.description = "The Emendatus balance and content mod, by the Emendatus community, with its new character. Works with the US and EUR discs. The game restarts to apply it.";
    static bool wanted = read_setting();  // the setting as saved
    static bool target = false;           // what the open question would set
    static bool asking = false;
    const bool have_assets = assets_present();
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
void redirect_game_files(std::filesystem::path &executable, std::filesystem::path &) {
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

} // namespace d012_emendatus

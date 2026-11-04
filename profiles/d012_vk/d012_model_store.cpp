#include "d012_model_store.hpp"

#include "hle/hle_common.hpp"
#include "install/user_data.hpp"
#include "profile.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <string>

namespace d012 {
namespace {

constexpr const char *kPackage = "DISC0:/PSP_GAME/USRDIR/DATA/PACKAGE.BIN";
constexpr char kMagic[12] = {'O', 'M', 'G', '.', '0', '0', '.', '1', 'P', 'S', 'P', '\0'};
constexpr std::uint32_t kIndexTag = 0x4D323144u;  // "D12M"

// The European disc's model positions (ULES01505), so that disc needs no scan at all.
constexpr std::uint32_t kEuropePositions[] = {
#include "d012_model_positions_eur.inc"
};

std::vector<std::uint64_t> g_positions;  // complete before g_ready is set
std::atomic<bool> g_ready{false};

std::filesystem::path index_path() {
    return portablekit::install::user_data_directory() / "d012_models.idx";
}

bool magic_at(std::uint64_t position) {
    std::uint8_t head[sizeof kMagic];
    return portablekit::read_guest_file(kPackage, position, head, sizeof head) == static_cast<std::int64_t>(sizeof head) &&
           std::memcmp(head, kMagic, sizeof kMagic) == 0;
}

// A saved index is used only if its first, middle and last positions still hold a GMO header (another disc image or a
// different package would not).
bool load_index() {
    std::FILE *file = std::fopen(index_path().string().c_str(), "rb");
    if (file == nullptr) return false;
    std::uint32_t tag = 0, count = 0;
    bool good = std::fread(&tag, 4, 1, file) == 1 && std::fread(&count, 4, 1, file) == 1 && tag == kIndexTag && count > 0u &&
                count < 100000u;
    std::vector<std::uint64_t> positions;
    if (good) {
        positions.resize(count);
        good = std::fread(positions.data(), 8, count, file) == count;
    }
    std::fclose(file);
    if (!good || !magic_at(positions.front()) || !magic_at(positions[count / 2u]) || !magic_at(positions.back())) return false;
    g_positions = std::move(positions);
    return true;
}

void save_index() {
    std::error_code ec;
    std::filesystem::create_directories(index_path().parent_path(), ec);
    std::FILE *file = std::fopen(index_path().string().c_str(), "wb");
    if (file == nullptr) return;
    const std::uint32_t tag = kIndexTag, count = static_cast<std::uint32_t>(g_positions.size());
    std::fwrite(&tag, 4, 1, file);
    std::fwrite(&count, 4, 1, file);
    std::fwrite(g_positions.data(), 8, g_positions.size(), file);
    std::fclose(file);
}

// The scan state: one pass over the package in blocks, one block per call so no frame waits long; the last bytes of a block are
// searched again with the next so a header split across two blocks is found. It runs on the caller's thread (the frame
// thread) because the port's disc reads are not guarded against the game's own.
struct Scan {
    bool started = false;
    std::vector<std::uint8_t> buffer;
    std::uint64_t offset = 0;
    std::size_t carry = 0;
};

Scan &scan() {
    static Scan state;
    return state;
}

// Reads and searches one small block; true when the package is finished.
bool scan_block() {
    constexpr std::size_t kBlock = 256u << 10;
    Scan &s = scan();
    const std::int64_t count = portablekit::read_guest_file(kPackage, s.offset, s.buffer.data() + s.carry, kBlock);
    if (count <= 0) return true;
    const std::size_t total = s.carry + static_cast<std::size_t>(count);
    const std::uint8_t *begin = s.buffer.data(), *end = begin + total;
    for (const std::uint8_t *at = begin; (at = std::search(at, end, kMagic, kMagic + sizeof kMagic)) != end; ++at)
        g_positions.push_back(s.offset - s.carry + static_cast<std::uint64_t>(at - begin));
    s.carry = std::min<std::size_t>(sizeof kMagic - 1u, total);
    std::memmove(s.buffer.data(), s.buffer.data() + total - s.carry, s.carry);
    s.offset += static_cast<std::uint64_t>(count);
    return false;
}

// Each call: the saved index or the built-in table for the European disc if either is good (no disc scan), otherwise a scan of
// the package that gets about 2 ms of each frame until it is done.
void scan_step() {
    Scan &s = scan();
    if (!s.started) {
        s.started = true;
        if (load_index()) {
            g_ready = true;
            return;
        }
        if (portablekit::active_disc_id() == "ULES01505") {
            std::vector<std::uint64_t> table(std::begin(kEuropePositions), std::end(kEuropePositions));
            if (magic_at(table.front()) && magic_at(table[table.size() / 2u]) && magic_at(table.back())) {
                g_positions = std::move(table);
                g_ready = true;
                return;
            }
        }
        g_positions.clear();
        s.buffer.resize((256u << 10) + sizeof kMagic);
    }
    const auto until = std::chrono::steady_clock::now() + std::chrono::milliseconds(2);
    do {
        if (scan_block()) {
            if (!g_positions.empty()) save_index();
            s.buffer = {};
            g_ready = !g_positions.empty();
            s.offset = ~0ull;  // finished, nothing more to read
            return;
        }
    } while (std::chrono::steady_clock::now() < until);
}

}  // namespace

bool model_index_ready() {
    if (!g_ready.load() && scan().offset != ~0ull) scan_step();
    return g_ready.load();
}

unsigned model_count() {
    return g_ready.load() ? static_cast<unsigned>(g_positions.size()) : 0u;
}

std::vector<std::uint8_t> read_model(unsigned id) {
    if (!g_ready.load() || id == 0u || id > g_positions.size()) return {};
    const std::uint64_t position = g_positions[id - 1u];
    // The file chunk's header sits at +0x10: type, header size, then the chunk's length, which ends the file.
    std::uint8_t head[0x18];
    if (portablekit::read_guest_file(kPackage, position, head, sizeof head) != static_cast<std::int64_t>(sizeof head)) return {};
    std::uint32_t chunk_length;
    std::memcpy(&chunk_length, head + 0x14, 4);
    const std::uint64_t size = 0x10u + static_cast<std::uint64_t>(chunk_length);
    if (size < sizeof head || size > (64u << 20)) return {};
    std::vector<std::uint8_t> bytes(static_cast<std::size_t>(size));
    if (portablekit::read_guest_file(kPackage, position, bytes.data(), bytes.size()) != static_cast<std::int64_t>(bytes.size())) return {};
    return bytes;
}

}  // namespace d012

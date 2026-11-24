// Log only: which texture regions of PACKAGE.BIN each read brings in, from a table made offline (stamp_table.py): lines of
// "<entry id hex> <pixel offset in the entry> <length> <image name>". The game's memory is not changed. The point is to see,
// before writing anything, how many reads carry a whole texture region and how many only part of one.
#include "d012_stamp.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include "kernel/read_sources.hpp"
#include "portablekit/hle_extension.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace d012_stamp {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;

constexpr std::uint32_t kSceIoRead = 0x6A638D83u;
constexpr std::uint64_t kSector = 2048u;

struct Region {
    std::uint64_t offset;  // inside the entry
    std::uint32_t length;
    std::string name;
};

std::unordered_map<std::uint32_t, std::vector<Region>> g_table;  // entry id -> regions
std::vector<std::pair<std::uint32_t, std::uint32_t>> g_entries;  // (sector, id), sorted by sector

bool ends_with(const std::string &text, const char *tail) {
    const std::string t(tail);
    return text.size() >= t.size() && text.compare(text.size() - t.size(), t.size(), t) == 0;
}

void load_table(const char *path) {
    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream words(line);
        std::string id, name;
        std::uint64_t offset = 0, length = 0;
        if (!(words >> id >> offset >> length >> name)) continue;
        g_table[static_cast<std::uint32_t>(std::strtoul(id.c_str(), nullptr, 16))].push_back(
            {offset, static_cast<std::uint32_t>(length), name});
    }
    std::printf("[stamp] table: %zu entries with texture regions (log only)\n", g_table.size());
    std::fflush(stdout);
}

void on_read(Runtime &rt) {
    read_sources::Source read;
    if (!read_sources::latest(read)) return;
    if (ends_with(read.path, "PACKAGE_INFO.BIN") && read.offset == 0u && read.size >= 16u) {
        // 16-byte header (the count at +8), then 12-byte entries: id, sector, flags.
        const std::uint32_t count = rt.memory().load32(read.address + 8u);
        g_entries.clear();
        for (std::uint32_t i = 0; i < count && 16u + 12u * (i + 1u) <= read.size; ++i)
            g_entries.emplace_back(rt.memory().load32(read.address + 16u + 12u * i + 4u),
                                   rt.memory().load32(read.address + 16u + 12u * i));
        std::sort(g_entries.begin(), g_entries.end());
        std::printf("[stamp] PACKAGE_INFO.BIN: %zu entries\n", g_entries.size());
        std::fflush(stdout);
        return;
    }
    if (!ends_with(read.path, "PACKAGE.BIN") || g_entries.empty()) return;

    static std::uint64_t whole = 0, partial = 0, reads = 0;
    static int lines = 0;
    const std::uint64_t begin = read.offset, end = read.offset + read.size;
    // The first entry that starts at or before the read's start.
    auto it = std::upper_bound(g_entries.begin(), g_entries.end(), std::make_pair(static_cast<std::uint32_t>(begin / kSector), 0xFFFFFFFFu));
    if (it != g_entries.begin()) --it;
    bool any = false;
    for (; it != g_entries.end() && static_cast<std::uint64_t>(it->first) * kSector < end; ++it) {
        const auto regions = g_table.find(it->second);
        if (regions == g_table.end()) continue;
        const std::uint64_t entry_start = static_cast<std::uint64_t>(it->first) * kSector;
        for (const Region &region : regions->second) {
            const std::uint64_t a = entry_start + region.offset, b = a + region.length;
            if (b <= begin || a >= end) continue;
            any = true;
            const bool full = a >= begin && b <= end;
            ++(full ? whole : partial);
            if (++lines <= 400)
                std::printf("[stamp] %s entry %08X +%llu len %u %s at guest 0x%X\n", full ? "whole  " : "partial", it->second,
                            static_cast<unsigned long long>(region.offset), region.length, region.name.c_str(),
                            full ? read.address + static_cast<std::uint32_t>(a - begin) : 0u);
        }
    }
    if (any && (++reads % 200u) == 0u)
        std::printf("[stamp] so far: %llu whole regions, %llu partial, in %llu reads\n", static_cast<unsigned long long>(whole),
                    static_cast<unsigned long long>(partial), static_cast<unsigned long long>(reads));
    std::fflush(stdout);
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    const char *table = portablekit::env("STAMP_TABLE");
    if (table == nullptr || *table == '\0') return;
    load_table(table);
    const portablekit::HleFunction read = hle.bound_function("IoFileMgrForUser", kSceIoRead);
    if (!read) return;
    hle.bind("IoFileMgrForUser", kSceIoRead, [read](Runtime &rt, AllegrexContext &ctx) {
        read(rt, ctx);
        on_read(rt);
    });
}

} // namespace d012_stamp

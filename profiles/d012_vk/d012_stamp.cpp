// Stamps the textures the pack replaces. After each PACKAGE.BIN read, the pixels of every texture region the read brought in
// whole get a 16-byte marker (kernel/texture_stamp.hpp) that names the pack's image for it; the renderer finds the marker when the
// texture is uploaded and loads that image, so the pixels the game read from the disc are never used to find the replacement.
// The table of regions (which entry, where, which image) is the bundle's "@stamp" entry, loaded by the renderer; made by
// stamp_table.py. D012_NO_STAMP=1 turns it off.
#include "d012_stamp.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include "kernel/read_sources.hpp"
#include "kernel/texture_stamp.hpp"
#include "portablekit/hle_extension.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

namespace d012_stamp {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;

constexpr std::uint32_t kSceIoRead = 0x6A638D83u;
constexpr std::uint64_t kSector = 2048u;

std::vector<std::pair<std::uint32_t, std::uint32_t>> g_entries;  // (sector, id), sorted by sector

bool ends_with(const std::string &text, const char *tail) {
    const std::string t(tail);
    return text.size() >= t.size() && text.compare(text.size() - t.size(), t.size(), t) == 0;
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
        return;
    }
    if (!texture_stamp::loaded() || g_entries.empty() || !ends_with(read.path, "PACKAGE.BIN")) return;

    static std::uint64_t stamped = 0, partial = 0;
    const std::uint64_t begin = read.offset, end = read.offset + read.size;
    // The first entry that starts at or before the read's start.
    auto it = std::upper_bound(g_entries.begin(), g_entries.end(),
                               std::make_pair(static_cast<std::uint32_t>(begin / kSector), 0xFFFFFFFFu));
    if (it != g_entries.begin()) --it;
    for (; it != g_entries.end() && static_cast<std::uint64_t>(it->first) * kSector < end; ++it) {
        const std::vector<texture_stamp::Region> *regions = texture_stamp::regions(it->second);
        if (regions == nullptr) continue;
        const std::uint64_t entry_start = static_cast<std::uint64_t>(it->first) * kSector;
        for (const texture_stamp::Region &region : *regions) {
            const std::uint64_t a = entry_start + region.offset, b = a + region.length;
            if (b <= begin || a >= end) continue;
            // A region the read brought in only in part is left alone: the renderer finds it by its hash, as before.
            if (a < begin || b > end) { ++partial; continue; }
            std::vector<std::uint8_t> marker(texture_stamp::kMarkerSize);
            texture_stamp::write_marker(marker.data(), region.name);
            rt.memory().copy_in(read.address + static_cast<std::uint32_t>(a - begin), marker);
            if (++stamped % 1000u == 0u)
                std::printf("[stamp] %llu texture regions stamped so far (%llu only in part, left to the hash)\n",
                            static_cast<unsigned long long>(stamped), static_cast<unsigned long long>(partial));
        }
    }
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    if (portablekit::env("NO_STAMP") != nullptr) return;
    const portablekit::HleFunction read = hle.bound_function("IoFileMgrForUser", kSceIoRead);
    if (!read) return;
    hle.bind("IoFileMgrForUser", kSceIoRead, [read](Runtime &rt, AllegrexContext &ctx) {
        read(rt, ctx);
        on_read(rt);
    });
}

} // namespace d012_stamp

// The profile of the game's own code. The runtime can tell a host, through its chained-call hooks, which translated function it is
// entering and leaving and how deep the native chain is; this keeps the function at each depth, and a thread of its own looks at the
// innermost one a thousand times a second. The numbers are shares of those looks, not times; they say where to look, not how long.
//
// Turning the hooks on makes the runtime take its slower chained-call path (psprecomp::set_runtime_pre_chained_call_hook), so a profiled
// run is slower than a normal one. MIT licence; see port/README.md.

#include "d012_guest_profile.hpp"

#include "install/user_data.hpp"

#include "psprecomp/runtime.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

namespace d012::guest_profile {
namespace {

constexpr std::uint32_t kDepth = 128;
std::atomic<std::uint32_t> g_function[kDepth];  // the translated function entered at each depth of the chain
std::atomic<std::uint32_t> g_top{0};            // the depth of the one running now
std::atomic<psprecomp::Runtime *> g_runtime{nullptr};  // seen by the first hook: the host's side is timed through it

void entering(psprecomp::Runtime &runtime, psprecomp::AllegrexContext &, std::uint32_t target_pc, std::uint32_t depth) {
    if (g_runtime.load(std::memory_order_relaxed) == nullptr) g_runtime.store(&runtime, std::memory_order_relaxed);
    const std::uint32_t at = depth < kDepth ? depth : kDepth - 1u;
    g_function[at].store(target_pc, std::memory_order_relaxed);
    g_top.store(at, std::memory_order_relaxed);
}

void leaving(psprecomp::Runtime &, psprecomp::AllegrexContext &, std::uint32_t, std::uint32_t depth) {
    const std::uint32_t at = depth < kDepth ? depth : kDepth - 1u;
    g_top.store(at > 0u ? at - 1u : 0u, std::memory_order_relaxed);
}

std::string top_list(const std::unordered_map<std::uint32_t, std::uint32_t> &counts, std::uint32_t total, std::size_t how_many) {
    std::vector<std::pair<std::uint32_t, std::uint32_t>> sorted(counts.begin(), counts.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
    std::string text;
    for (std::size_t i = 0; i < sorted.size() && i < how_many; ++i) {
        char entry[48];
        std::snprintf(entry, sizeof entry, " %08X %.1f%%", sorted[i].first,
                      100.0 * static_cast<double>(sorted[i].second) / static_cast<double>(std::max<std::uint32_t>(total, 1u)));
        text += entry;
    }
    return text;
}

void report(const std::string &line) {
    std::fputs(line.c_str(), stdout);
    std::fputc('\n', stdout);
    std::fflush(stdout);
#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_INFO, "D012", "%s", line.c_str());  // a phone's stdout goes nowhere: read with adb logcat -s D012
#endif
}

void sample_forever() {
    using Clock = std::chrono::steady_clock;
    std::unordered_map<std::uint32_t, std::uint32_t> self, inclusive;
    std::uint32_t samples = 0;
    bool timing = false;
    Clock::time_point window = Clock::now();
    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        const std::uint32_t top = std::min(g_top.load(std::memory_order_relaxed), kDepth - 1u);
        ++self[g_function[top].load(std::memory_order_relaxed)];
        // Each function once per look, however many times it is on the chain (a recursive one would count several times).
        std::uint32_t seen[kDepth];
        std::uint32_t seen_count = 0;
        for (std::uint32_t depth = 0; depth <= top; ++depth) {
            const std::uint32_t function = g_function[depth].load(std::memory_order_relaxed);
            if (std::find(seen, seen + seen_count, function) == seen + seen_count) {
                seen[seen_count++] = function;
                ++inclusive[function];
            }
        }
        ++samples;
        if (Clock::now() - window >= std::chrono::seconds(1)) {
            report("[guest-profile] " + std::to_string(samples) + " looks. self:" + top_list(self, samples, 10));
            report("[guest-profile] inclusive:" + top_list(inclusive, samples, 14));
            // The host's side: how long each system call the game made took in this second (the time inside the flip, the waits, the
            // graphics list calls), and how many calls. The total is of the calls, which may overlap with waits for another thread.
            if (psprecomp::Runtime *runtime = g_runtime.load(std::memory_order_relaxed)) {
                if (!timing) {
                    runtime->set_hle_timing(true);
                    timing = true;
                } else {
                    std::string host;
                    std::size_t shown = 0;
                    for (const psprecomp::Runtime::HleTime &call : runtime->take_hle_times()) {
                        if (shown++ >= 8) break;
                        char entry[160];
                        std::snprintf(entry, sizeof entry, " %s %.0fms/%llu", call.name.c_str(), call.milliseconds,
                                      static_cast<unsigned long long>(call.calls));
                        host += entry;
                    }
                    report("[guest-profile] host calls (ms spent / calls):" + host);
                }
            }
            self.clear();
            inclusive.clear();
            samples = 0;
            window = Clock::now();
        }
    }
}

bool wanted() {
    if (const char *value = std::getenv("D012_PROFILE"); value != nullptr && *value != '\0') return true;
    // The data folder in use, and (on a phone) the app's shared folder, which adb can write to: /sdcard/Android/data/<app>/files.
    std::vector<std::filesystem::path> folders;
    try {
        folders.push_back(portablekit::install::user_data_directory());
    } catch (const std::exception &) {
    }
    try {
        folders.push_back(portablekit::install::shared_data_directory());
    } catch (const std::exception &) {
    }
    std::error_code ec;
    for (const std::filesystem::path &folder : folders)
        if (!folder.empty() && std::filesystem::exists(folder / "profile.txt", ec)) return true;
    return false;
}

} // namespace

void install() {
    static bool installed = false;
    if (installed || !wanted()) return;
    installed = true;
    psprecomp::set_runtime_pre_chained_call_hook(entering);
    psprecomp::set_runtime_post_chained_call_hook(leaving);
    std::thread(sample_forever).detach();
    report("[guest-profile] on: the game's translated functions are sampled every millisecond (slower than a normal run)");
}

} // namespace d012::guest_profile

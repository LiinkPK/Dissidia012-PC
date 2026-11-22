// Start skips the screens the game shows at start-up: the Square Enix logo, then the credits, then the title menu. Time on
// those screens only runs out by itself; Start makes it run fast (fast_loading::force) until the next screen has loaded.
//
// What a screen is, found from a trace of a first start (D012_TRACE_IO=1): each is loaded by one read of 800 KB or more from
// PACKAGE.BIN into the scene buffers at 0x08C00000..0x08E00000 (the logo, then the credits; the third one is the title menu).
// No file names are read: the game reads by offset, and the sizes differ from one disc to the next. Verified on the European
// disc only. The skip works before the third read and never after it, so the title menu, battles and the rest keep real time.
//
// D012_NO_BOOT_SKIP=1 turns it off.

#include "d012_boot_skip.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include "kernel/fast_loading.hpp"

#include <chrono>
#include <cstdint>
#include <cstdio>

namespace d012_boot_skip {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;

constexpr std::uint32_t kSceIoRead = 0x6A638D83u;
constexpr std::uint32_t kSceCtrlReadBufferPositive = 0x1F803938u;
constexpr std::uint32_t kStart = 0x0008u;
constexpr std::uint32_t kSceneBytes = 800'000u;
constexpr std::uint32_t kSceneBufferLow = 0x08C00000u, kSceneBufferHigh = 0x08E00000u;
constexpr int kTitleRead = 3;  // the read that brings in the title menu: the skip is over
constexpr std::chrono::seconds kLongest{15};  // a forced stretch never lasts longer than this, whatever happens

struct State {
    int scene_reads = 0;       // big scene reads seen so far
    bool forcing = false;
    bool start_was_held = false;
    std::chrono::steady_clock::time_point forced_at{};
};

State &state() {
    static State s;
    return s;
}

void stop(State &s, const char *why) {
    if (!s.forcing) return;
    s.forcing = false;
    portablekit::fast_loading::force(false);
    std::printf("[bootskip] over: %s\n", why);
    std::fflush(stdout);
}

void on_read(const AllegrexContext &ctx) {
    State &s = state();
    const std::uint32_t buffer = ctx.gpr[5], size = ctx.gpr[6];
    if (size < kSceneBytes || buffer < kSceneBufferLow || buffer >= kSceneBufferHigh) return;
    ++s.scene_reads;
    std::printf("[bootskip] scene read %d (%u bytes into 0x%08X)\n", s.scene_reads, size, buffer);
    std::fflush(stdout);
    stop(s, "the next screen is loaded");
}

void on_pad(Runtime &rt, const AllegrexContext &ctx) {
    State &s = state();
    const std::uint32_t buffer = ctx.gpr[4];
    if (buffer == 0u) return;
    const bool held = (rt.memory().load32(buffer + 4u) & kStart) != 0u;
    const bool pressed = held && !s.start_was_held;
    s.start_was_held = held;
    // Only on the logo (one scene read so far) or the credits (two); the title menu is the third read.
    const bool on_a_skippable_screen = s.scene_reads >= 1 && s.scene_reads < kTitleRead;
    if (s.forcing && std::chrono::steady_clock::now() - s.forced_at > kLongest) stop(s, "15 seconds");
    if (pressed && on_a_skippable_screen && !s.forcing) {
        s.forcing = true;
        s.forced_at = std::chrono::steady_clock::now();
        portablekit::fast_loading::force(true);
        std::printf("[bootskip] Start on screen %d: running fast until the next one\n", s.scene_reads);
        std::fflush(stdout);
    }
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    if (const char *off = portablekit::env("NO_BOOT_SKIP"); off != nullptr && off[0] != '\0' && off[0] != '0') return;
    const portablekit::HleFunction read = hle.bound_function("IoFileMgrForUser", kSceIoRead);
    if (read) {
        hle.bind("IoFileMgrForUser", kSceIoRead, [read](Runtime &rt, AllegrexContext &ctx) {
            const AllegrexContext arguments = ctx;  // the read returns in the same registers
            read(rt, ctx);
            on_read(arguments);
        });
    }
    const portablekit::HleFunction pad = hle.bound_function("sceCtrl", kSceCtrlReadBufferPositive);
    if (pad) {
        hle.bind("sceCtrl", kSceCtrlReadBufferPositive, [pad](Runtime &rt, AllegrexContext &ctx) {
            const AllegrexContext arguments = ctx;
            pad(rt, ctx);
            on_pad(rt, arguments);
        });
    }
}

} // namespace d012_boot_skip

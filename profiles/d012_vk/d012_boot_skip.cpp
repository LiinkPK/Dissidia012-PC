// Start skips the screens the game shows at start-up, one at a time: the Square Enix logo goes to the credits, the credits go to the
// title animation, and the title animation goes to the menu (NEW GAME, LOAD GAME, EXTRAS). Each screen's time only runs out by
// itself, so Start makes time run fast (fast_loading::force) until the game itself moves on, and only that far: the next screen then
// plays at normal speed until Start is pressed again.
//
// What the game says, found by comparing snapshots of its RAM across the screens (European disc, memory-expansion edition):
//   * A stage counter at 0x08CF70C8 steps 12 (the logo), 13, 14 (the credits), 15, 16 (the title animation, then the menu). Each
//     of 12, 14 and 16 has a sequence node in main's data (0x08B887F8, 0x08B88824, 0x08B88850), reached through a pointer.
//   * The word at 0x08B8C220 is 0 while the title animation plays and 224.0 from the moment the menu is built.
// Nothing here is read from the disc. The addresses are those of this edition: where the stage counter never reads 12, 14 or 16 (an
// edition with another layout) nothing happens at all.
//
// The skip is over for good once the menu has been built, so battles and everything after keep real time. It never runs in an ad hoc
// session or with the in-game menu open (fast_loading::force refuses), and a stretch of fast time ends after a few seconds at most.
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

constexpr std::uint32_t kSceCtrlReadBufferPositive = 0x1F803938u;
constexpr std::uint32_t kStart = 0x0008u;

constexpr std::uint32_t kStage = 0x08CF70C8u;
constexpr std::uint32_t kNodePointers[3] = {0x08CF70D8u, 0x08CF70E0u, 0x08CF70D4u};  // stage 12, 14, 16
constexpr std::uint32_t kNodeLow = 0x08B80000u, kNodeHigh = 0x08B90000u;
constexpr std::uint32_t kMenuReady = 0x08B8C220u;

struct State {
    bool start_was_held = false;
    bool fast = false;
    bool over = false;  // the menu has been built: nothing more to skip
    std::uint32_t from_stage = 0u, from_status = 0u;
    std::chrono::steady_clock::time_point since{};
};

State &state() {
    static State s;
    return s;
}

double seconds() {
    static const auto start = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
}

void stop_fast(State &s, const char *why) {
    if (!s.fast) return;
    s.fast = false;
    portablekit::fast_loading::force(false);
    std::printf("[bootskip] %.2f s: fast time over (%s)\n", seconds(), why);
    std::fflush(stdout);
}

void on_pad(Runtime &rt, const AllegrexContext &ctx) {
    State &s = state();
    if (s.over) return;
    const std::uint32_t buffer = ctx.gpr[4];
    if (buffer == 0u) return;
    const bool held = (rt.memory().load32(buffer + 4u) & kStart) != 0u;
    const bool pressed = held && !s.start_was_held;
    s.start_was_held = held;

    const std::uint32_t stage = rt.memory().load32(kStage);
    const int slot = stage == 12u ? 0 : stage == 14u ? 1 : stage == 16u ? 2 : -1;
    std::uint32_t node = 0u, status = 0xFFFFFFFFu;
    if (slot >= 0) {
        node = rt.memory().load32(kNodePointers[slot]);
        if (node >= kNodeLow && node < kNodeHigh) status = rt.memory().load32(node + 8u);
        else node = 0u;
    }
    const bool menu_ready = rt.memory().load32(kMenuReady) != 0u;

    if (s.fast) {
        const bool changed = slot < 0 || stage != s.from_stage || (s.from_stage == 16u && (status != s.from_status || menu_ready));
        const bool too_long =
            std::chrono::steady_clock::now() - s.since > std::chrono::seconds(s.from_stage == 16u ? 8 : 4);
        if (changed || too_long) stop_fast(s, changed ? "the screen changed" : "time limit");
    }
    // Once the title animation has reached the menu, the skip has done its job; from then on Start is the menu's own button.
    if (stage == 16u && menu_ready) {
        stop_fast(s, "the menu is up");
        s.over = true;
        return;
    }
    if (pressed && !s.fast && node != 0u) {
        s.fast = true;
        s.from_stage = stage;
        s.from_status = status;
        s.since = std::chrono::steady_clock::now();
        portablekit::fast_loading::force(true);
        std::printf("[bootskip] %.2f s: Start on stage %u: fast time until the screen changes\n", seconds(), stage);
        std::fflush(stdout);
    }
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    if (const char *off = portablekit::env("NO_BOOT_SKIP"); off != nullptr && off[0] != '\0' && off[0] != '0') return;
    const portablekit::HleFunction pad = hle.bound_function("sceCtrl", kSceCtrlReadBufferPositive);
    if (!pad) return;
    hle.bind("sceCtrl", kSceCtrlReadBufferPositive, [pad](Runtime &rt, AllegrexContext &ctx) {
        const AllegrexContext arguments = ctx;
        pad(rt, ctx);
        on_pad(rt, arguments);
    });
}

} // namespace d012_boot_skip

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
#include <filesystem>
#include <string>

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

bool g_forcing_allowed = false;
bool g_snapshots = false;
int g_snapshot_count = 0;
bool g_after_pending = false;
std::chrono::steady_clock::time_point g_after_due{};

// Seconds since the first line, so a log shows how long each screen lasted.
double seconds() {
    static const auto start = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
}

// The game's RAM (0x08800000..0x0A000000) to <temp>/d012_boot/snap_N_<what>.bin, to find what changes from one screen to the next.
void snapshot(Runtime &rt, const char *what) {
    constexpr std::uint32_t kFrom = 0x08800000u, kBytes = 0x01800000u;
    const std::uint8_t *ram = static_cast<const std::uint8_t *>(rt.memory().raw_pointer(kFrom, kBytes));
    if (ram == nullptr) return;
    const std::filesystem::path folder = std::filesystem::temp_directory_path() / "d012_boot";
    std::error_code ec;
    std::filesystem::create_directories(folder, ec);
    const std::filesystem::path file = folder / ("snap_" + std::to_string(g_snapshot_count++) + "_" + what + ".bin");
    if (std::FILE *out = std::fopen(file.string().c_str(), "wb")) {
        std::fwrite(ram, 1, kBytes, out);
        std::fclose(out);
        std::printf("[bootskip] %.2f s: RAM saved to %s\n", seconds(), file.string().c_str());
        std::fflush(stdout);
    }
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
    if (size >= 50'000u) {
        std::printf("[bootskip] %.2f s: read of %u bytes into 0x%08X\n", seconds(), size, buffer);
        std::fflush(stdout);
    }
    if (size < kSceneBytes || buffer < kSceneBufferLow || buffer >= kSceneBufferHigh) return;
    ++s.scene_reads;
    std::printf("[bootskip] %.2f s: scene read %d\n", seconds(), s.scene_reads);
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
    if (pressed) {
        std::printf("[bootskip] %.2f s: Start pressed\n", seconds());
        std::fflush(stdout);
        if (g_snapshots && g_snapshot_count < 8) {
            snapshot(rt, "before_start");
            g_after_pending = true;
            g_after_due = std::chrono::steady_clock::now() + std::chrono::milliseconds(1500);
        }
    }
    if (g_after_pending && std::chrono::steady_clock::now() >= g_after_due) {
        g_after_pending = false;
        snapshot(rt, "after_start");
    }
    // Only on the logo (one scene read so far) or the credits (two); the title menu is the third read.
    const bool on_a_skippable_screen = s.scene_reads >= 1 && s.scene_reads < kTitleRead;
    if (s.forcing && std::chrono::steady_clock::now() - s.forced_at > kLongest) stop(s, "15 seconds");
    if (pressed && on_a_skippable_screen && !s.forcing && g_forcing_allowed) {
        s.forcing = true;
        s.forced_at = std::chrono::steady_clock::now();
        portablekit::fast_loading::force(true);
        std::printf("[bootskip] Start on screen %d: running fast until the next one\n", s.scene_reads);
        std::fflush(stdout);
    }
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    // Off unless D012_BOOT_SKIP=1: it is a trace of the start-up screens for now (every big read and every Start press, with the
    // time), not a skip that works. 2 also runs the fast-forward, which does not stop on the right screen. 3 saves the game's RAM at
    // each Start press and 1.5 s after it (up to 8 files of 24 MB in <temp>/d012_boot).
    const char *on = portablekit::env("BOOT_SKIP");
    if (on == nullptr || on[0] == '\0' || on[0] == '0') return;
    g_forcing_allowed = on[0] == '2';
    g_snapshots = on[0] == '3';
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

// A trace for the speed of online battles. The game's per-frame network step (main:0x0890D664) sends the player's input and
// takes in the other players' packets; the battle's own frame (offset 0x48 of its session object) only advances when every
// player's input for that frame has arrived. This wraps the step and, once a second while a session is running, logs what it
// returned: 0 = the battle frame advanced, 1 = it waited for the other player's input, 3 = the game's resend step ran, 2 = no session.
// It also logs both frame counters and the newest frame each other player has sent, so a stall shows who is behind and by how much.
// It changes nothing: the step runs as before and its answer is passed on.
//
// Always on (one line a second, only while a session is running); D012_TRACE_NETPLAY=0 turns it off.

#include "d012_netplay_trace.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace d012_netplay_trace {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::CorpusRuntime;
using psprecomp::Runtime;

constexpr std::uint32_t kStep = 0x0890D664u;  // main: the per-frame network step, a0 = the session object

Runtime::RecompiledFunction g_original = nullptr;

struct Window {
    std::chrono::steady_clock::time_point start{};
    unsigned calls = 0, advanced = 0, waiting = 0, resend = 0, inactive = 0, other = 0;
    std::uint32_t first_frame = 0;
    bool open = false;
} g_window;

bool user_ram(std::uint32_t address) {
    const std::uint32_t a = address & 0x1FFFFFFFu;
    return a >= 0x08800000u && a < 0x0A000000u - 4u;
}

std::uint32_t word(Runtime &rt, std::uint32_t address) { return user_ram(address) ? rt.memory().load32(address) : 0u; }

void step(CorpusRuntime &corpus, AllegrexContext &ctx) {
    Runtime &rt = static_cast<Runtime &>(corpus);
    const std::uint32_t session = ctx.gpr[4];
    g_original(corpus, ctx);
    const std::uint32_t result = ctx.gpr[2];
    const auto now = std::chrono::steady_clock::now();
    if (!g_window.open) {
        g_window = Window{};
        g_window.open = true;
        g_window.start = now;
        g_window.first_frame = word(rt, session + 0x48u);
    }
    ++g_window.calls;
    switch (result) {
    case 0u: ++g_window.advanced; break;
    case 1u: ++g_window.waiting; break;
    case 2u: ++g_window.inactive; break;
    case 3u: ++g_window.resend; break;
    default: ++g_window.other; break;
    }
    const double seconds = std::chrono::duration<double>(now - g_window.start).count();
    if (seconds < 1.0) return;
    // Only a session worth a line: not the idle "no session" answer alone.
    if (g_window.inactive != g_window.calls) {
        const std::uint32_t frame = word(rt, session + 0x48u);
        const std::uint32_t sent = word(rt, session + 0x568u);
        const std::uint32_t others = word(rt, session + 0x354u);
        std::fprintf(stderr, "[netplay] %.1f s: %u steps, battle frame advanced %u, waited for input %u, resend %u (frame %u -> %u, %u/s; sent %u)",
                     seconds, g_window.calls, g_window.advanced, g_window.waiting, g_window.resend, g_window.first_frame, frame,
                     static_cast<unsigned>((frame - g_window.first_frame) / (seconds > 0.0 ? seconds : 1.0)), sent);
        for (std::uint32_t i = 0; i < others && i < 3u; ++i)
            std::fprintf(stderr, "; peer %u newest frame %u", i, word(rt, session + 0x4Cu + i * 0x54u + 0x50u));
        std::fprintf(stderr, "\n");
        std::fflush(stderr);
    }
    g_window.open = false;
}

void arm(Runtime &rt) {
    static bool armed = false;
    if (armed) return;
    armed = true;
    g_original = rt.registered_function(kStep);
    if (g_original == nullptr) return;
    rt.register_function(kStep, &step, "d012_netplay_trace");
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    const char *off = portablekit::env("TRACE_NETPLAY");
    if (off != nullptr && std::strcmp(off, "0") == 0) return;
    for (const std::uint32_t nid : {0x46F186C3u, 0x984C27E7u}) {
        const portablekit::HleFunction previous = hle.bound_function("sceDisplay", nid);
        if (!previous) continue;
        hle.bind("sceDisplay", nid, [previous](Runtime &rt, AllegrexContext &ctx) {
            arm(rt);
            previous(rt, ctx);
        });
    }
}

} // namespace d012_netplay_trace

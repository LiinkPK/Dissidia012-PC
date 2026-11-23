// The battle moves that take two PSP buttons, on one control of a pad or a touch screen, in a battle only (the menus keep the D-pad):
//
//   L2 (left trigger, or the touch screen's L2)   dodge                R1 + Cross
//   R2 (right trigger, or the touch screen's R2)  dash to the target   R1 + Triangle
//   L3 (left stick click)                         EX Mode / Revenge    R1 + Square
//   D-pad up                                      call an Assist       L1 + Circle
//   D-pad down                                    call a BRV Assist    L1 + Square
//   D-pad left                                    manual Summon        R1 + Circle
//
// The game takes these moves only when both buttons go down within two frames, so the buttons are added to the same pad read.
//
// It is the pad read's own wrapper: whether a battle runs is read from the game (the battle object the Discord presence reads too), so
// it does not depend on the right-stick camera code (d012_camera.cpp, which does the same while its camera runs, and finds nothing left
// to change here), on the camera mode, on a controller or on the touch screen. A battle against a person online is a battle like any.
//
// D012_NO_BATTLE_SHORTCUTS=1 turns it off.
#include "d012_battle_shortcuts.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include "portablekit/hle_extension.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>

namespace d012::camera {
bool battle_running();
}

namespace d012_battle_shortcuts {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;
namespace ext = portablekit::hle_extension;

constexpr std::uint32_t kSceCtrlReadBufferPositive = 0x1F803938u;
constexpr std::uint32_t kBattleManager = 0x089D6A10u;  // *(u32*) is the battle object, 0 outside a battle
constexpr std::uint32_t kBattleStage = 0x08B98854u;    // the stage's number during a battle, else 0xFFFFFFFF

constexpr std::uint32_t kDpadUp = 0x0010u, kDpadDown = 0x0040u, kDpadLeft = 0x0080u;
constexpr std::uint32_t kL1 = 0x0100u, kR1 = 0x0200u;
constexpr std::uint32_t kTriangle = 0x1000u, kCircle = 0x2000u, kCross = 0x4000u, kSquare = 0x8000u;

bool in_battle(Runtime &rt) {
    return rt.memory().load32(kBattleManager) != 0u && rt.memory().load32(kBattleStage) != 0xFFFFFFFFu &&
           d012::camera::battle_running();
}

void on_pad(Runtime &rt, const AllegrexContext &ctx) {
    const std::uint32_t buffer = ctx.gpr[4];
    if (buffer == 0u || !in_battle(rt)) return;
    const std::uint32_t count = std::clamp<std::uint32_t>(ctx.gpr[5], 1u, 64u);
    const std::uint32_t extra = ext::extra_buttons();
    std::uint32_t add = 0u;
    if ((extra & ext::kExtraL3) != 0u) add |= kR1 | kSquare;
    if ((extra & ext::kExtraL2) != 0u) add |= kR1 | kCross;
    if ((extra & ext::kExtraR2) != 0u) add |= kR1 | kTriangle;
    for (std::uint32_t i = 0; i < count; ++i) {
        const std::uint32_t at = buffer + i * 16u + 4u;
        std::uint32_t buttons = rt.memory().load32(at);
        const std::uint32_t before = buttons;
        if ((buttons & kDpadUp) != 0u) buttons = (buttons & ~kDpadUp) | kL1 | kCircle;
        if ((buttons & kDpadDown) != 0u) buttons = (buttons & ~kDpadDown) | kL1 | kSquare;
        if ((buttons & kDpadLeft) != 0u) buttons = (buttons & ~kDpadLeft) | kR1 | kCircle;
        buttons |= add;
        if (buttons != before) {
            static bool announced = false;
            if (!announced) {
                announced = true;
                std::printf("[shortcuts] a battle shortcut was pressed (buttons 0x%X -> 0x%X, extra 0x%X)\n", before, buttons, extra);
                std::fflush(stdout);
            }
        }
        rt.memory().store32(at, buttons);
    }
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    if (const char *off = portablekit::env("NO_BATTLE_SHORTCUTS"); off != nullptr && off[0] != '\0' && off[0] != '0') return;
    const portablekit::HleFunction pad = hle.bound_function("sceCtrl", kSceCtrlReadBufferPositive);
    if (!pad) return;
    hle.bind("sceCtrl", kSceCtrlReadBufferPositive, [pad](Runtime &rt, AllegrexContext &ctx) {
        const AllegrexContext arguments = ctx;
        pad(rt, ctx);
        on_pad(rt, arguments);
    });
}

} // namespace d012_battle_shortcuts

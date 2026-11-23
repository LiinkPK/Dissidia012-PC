// Diagnostics only: the pad is not changed. One line each time the battle state changes, to find a value that tells the fight itself
// from its menus (the pause menu, the screen before the fight, the fanfare and the results).
#include "d012_battle_shortcuts.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include "portablekit/hle_extension.hpp"

#include <cstdint>
#include <cstdio>

namespace d012::camera {
bool battle_running();
}

namespace d012_battle_shortcuts {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;

constexpr std::uint32_t kSceCtrlReadBufferPositive = 0x1F803938u;
constexpr std::uint32_t kBattleManager = 0x089D6A10u;  // *(u32*) is the battle object, 0 outside a battle
constexpr std::uint32_t kBattleStage = 0x08B98854u;    // the stage's number during a battle, else 0xFFFFFFFF
constexpr std::uint32_t kPadManager = 0x089D6008u;     // *(u32*) is the pad manager
constexpr std::uint32_t kPadFlags = 0x264u;            // in the pad manager

void on_pad(Runtime &rt) {
    const std::uint32_t manager = rt.memory().load32(kBattleManager);
    const std::uint32_t stage = rt.memory().load32(kBattleStage);
    const std::uint32_t pads = rt.memory().load32(kPadManager);
    const std::uint32_t flags = pads != 0u ? rt.memory().load32(pads + kPadFlags) : 0xFFFFFFFFu;
    const int camera = static_cast<int>(d012::camera::battle_running());
    static std::uint32_t last_manager = 1u, last_stage = 1u, last_flags = 1u;
    static int last_camera = -1, lines = 0;
    if (manager == last_manager && stage == last_stage && flags == last_flags && camera == last_camera) return;
    last_manager = manager;
    last_stage = stage;
    last_flags = flags;
    last_camera = camera;
    if (++lines > 400) return;
    std::printf("[shortcuts] state: battle object 0x%X, stage 0x%X, pad flags 0x%X, battle camera %d\n", manager, stage, flags, camera);
    std::fflush(stdout);
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    const portablekit::HleFunction pad = hle.bound_function("sceCtrl", kSceCtrlReadBufferPositive);
    if (!pad) return;
    hle.bind("sceCtrl", kSceCtrlReadBufferPositive, [pad](Runtime &rt, AllegrexContext &ctx) {
        pad(rt, ctx);
        on_pad(rt);
    });
}

} // namespace d012_battle_shortcuts

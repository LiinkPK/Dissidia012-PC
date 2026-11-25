// The right-stick camera in battle (docs/port/right-stick-camera.md).
//
// The battle camera's two input modes, free and lock-on, each have a
// per-frame update the camera manager calls through the mode's vtable. Both
// run as decompiled overrides (port/decomp/battle_camera.c) with a hook
// between the stock input, which still reads the D-pad, recentre and
// auto-follow, and the code that builds the view. The hook adds the right
// stick as the owner's PPSSPP plugin did: full deflection is one stock D-pad
// step, a partial push is proportional, with the game's speed table (the
// camera-speed option), its distance limits and its two direction options.
// Only the local player's camera listens, and only while the game itself
// would take camera input.
//
// The stick is read from the pad the game reads (sceCtrlReadBufferPositive's
// buffer, bytes 10 and 11, which the game never uses); R3, a button a PSP
// lacks, presses SELECT, the game's own recentre, while a battle camera takes
// input.
//
// The free camera's auto-follow, which turns the Story Mode world map camera
// toward where the walker faces, gets an angular dead zone while the port's
// analog stick steers the walker (docs/port/analog-movement.md, "Camera
// follow"): the free input (battle 0x08B3F7F4) runs as decompiled C, reached
// from the decompiled free update.
//
// MIT licence; see port/README.md.

#include "d012_camera.hpp"
#include "d012_decomp_harness.hpp"
#include "d012_decomp_pad.hpp"

#include "../decomp/battle_camera.h"

#include "hle/hle_common.hpp"
#include "portablekit/hle_extension.hpp"

#include "psprecomp/runtime.hpp"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#if defined(__ANDROID__)
#include <SDL3/SDL_log.h>
#endif

namespace d012::camera {
namespace {

namespace ext = portablekit::hle_extension;

constexpr std::uint32_t kSceCtrlReadBufferPositive = 0x1F803938u;
constexpr std::uint32_t kSelect = 0x0001u;
constexpr std::uint32_t kHold = 0x00020000u;
// The PSP buttons the battle shortcuts below press (SceCtrlButtons).
constexpr std::uint32_t kDpadRight = 0x0020u;
constexpr double kHeldSpeed = 6.3;  // PortableKit's factor for the 4x step of Game speed (adhoc_game_speed)
constexpr std::uint32_t kDpadUp = 0x0010u, kDpadDown = 0x0040u, kDpadLeft = 0x0080u, kL1 = 0x0100u, kR1 = 0x0200u;
constexpr std::uint32_t kTriangle = 0x1000u, kCircle = 0x2000u, kCross = 0x4000u, kSquare = 0x8000u;
// A battle camera must have taken input within this many pad reads for R3
// to press SELECT (one read a frame).
constexpr std::uint32_t kLiveReads = 4u;

bool flag(const char *name) {
    const char *value = std::getenv(name);
    return value != nullptr && *value != '\0' && std::strcmp(value, "0") != 0;
}

float number(const char *name, float fallback, float low, float high) {
    const char *value = std::getenv(name);
    if (value == nullptr || *value == '\0') return fallback;
    char *end = nullptr;
    const float parsed = std::strtof(value, &end);
    if (end == value || !std::isfinite(parsed)) return fallback;
    return std::clamp(parsed, low, high);
}

struct Options {
    bool enabled = true;
    // The battle shortcuts for the buttons a PSP lacks (L2, R2, L3) and the D-pad's up and down; D012_NO_BATTLE_SHORTCUTS=1
    // leaves the pad as the game reads it.
    bool shortcuts = true;
    // L3 (EX Mode) does nothing until the player's EX gauge is full; D012_NO_L3_GAUGE=1 presses it whatever the gauge reads.
    bool l3_needs_gauge = true;
    // The D-pad's assist and summon shortcuts do nothing until the move is ready (the assist gauge has the bar it costs, the summon
    // is ready); D012_NO_DPAD_GATES=1 presses them whatever the gauges read.
    bool dpad_gates = true;
    // The plugin's: each axis's dead zone, the response rescaled to start
    // from 0 at its edge. On top of PortableKit's radial dead zone for the
    // stick (the menu's Dead zone), as the plugin's was on top of PPSSPP's.
    float dead_zone = 0.18f;
    // Full deflection as a share of the stock D-pad speed. Lock-on caps the
    // visible turn at the D-pad speed whatever this is.
    float sensitivity = 1.0f;
    bool invert_x = false;
    bool invert_y = false;
    bool trace = false;
    // The differential test checks the hooked updates themselves rather than
    // the plain decompiled ones: SAME while the stick is centred.
    bool verify_hook = false;
    // The follow's angular dead zone, degrees each side of straight ahead;
    // 0: the game's follow.
    float follow_dead_zone = 22.5f;
    bool trace_follow = false;
};

const Options &options() {
    static const Options o = [] {
        Options v;
        v.enabled = !flag("D012_NO_RIGHT_STICK_CAMERA");
        v.shortcuts = !flag("D012_NO_BATTLE_SHORTCUTS");
        v.l3_needs_gauge = !flag("D012_NO_L3_GAUGE");
        v.dpad_gates = !flag("D012_NO_DPAD_GATES");
        v.dead_zone = number("D012_CAMERA_DEAD_ZONE", v.dead_zone, 0.0f, 0.9f);
        v.sensitivity = number("D012_CAMERA_SENSITIVITY", v.sensitivity, 0.05f, 4.0f);
        v.invert_x = flag("D012_CAMERA_INVERT_X");
        v.invert_y = flag("D012_CAMERA_INVERT_Y");
        v.trace = flag("D012_TRACE_STICK_CAMERA");
        v.verify_hook = flag("D012_CAMERA_VERIFY_HOOK");
        v.follow_dead_zone = number("D012_CAMERA_FOLLOW_DEADZONE", v.follow_dead_zone, 0.0f, 60.0f);
        v.trace_follow = flag("D012_TRACE_CAMERA_FOLLOW");
        return v;
    }();
    return o;
}

// What the last pad read held.
struct Pad {
    std::uint8_t x = 0x80u;
    std::uint8_t y = 0x80u;
    std::uint32_t reads = 0;
    // The read at which the local camera last took input; far in the past
    // at first.
    std::uint32_t live_read = 0xFFFF0000u;
    // The read at which a battle camera was running while raw pad 0 was fed by ad hoc (or a replay): the stick must not move
    // that camera, but the button shortcuts still apply (they are ordinary buttons, sent to the other player like any).
    std::uint32_t fed_read = 0xFFFF0000u;
    // The read at which any battle camera ran, whatever the game's camera option says (manual or automatic): the button
    // shortcuts follow the battle, not the camera mode.
    std::uint32_t battle_read = 0xFFFF0000u;
    bool r3 = false;
};

Pad &pad() {
    static Pad p;
    return p;
}

// -1..1 with the plugin's per-axis dead zone. PortableKit centres the stick
// on 0x80 and pushes it 127 each way.
float stick_axis(std::uint8_t raw) {
    const float value = std::clamp((static_cast<float>(raw) - 128.0f) / 127.0f, -1.0f, 1.0f);
    float magnitude = std::fabs(value);
    const float zone = options().dead_zone;
    if (magnitude <= zone) return 0.0f;
    magnitude = std::min((magnitude - zone) / (1.0f - zone), 1.0f);
    return value < 0.0f ? -magnitude : magnitude;
}

// The local player's camera with manual input on, while the game takes
// input: the gates of the game's own pad accessors (input muted, a replay
// playing) and hardware feeding pad 0 (not ad-hoc): 0 for the player's camera,
// -1 for any other.
int local_camera(Guest *g, gaddr camera, bool *fed_externally = nullptr) {
    if (g_ld8(g, camera + CAM_MANUAL) == 0) return -1;
    const gaddr pads = g_ld32(g, G_PAD_MANAGER);
    if (pads == 0) return -1;
    if ((g_ld32(g, pads + PAD_FLAGS) & (PAD_FLAG_REPLAY | PAD_FLAG_MUTED)) != 0) return -1;
    const gaddr listens = g_ld32(g, camera + CAM_PAD);
    if (listens == pads + PAD_LOGICAL0) {
        const bool fed = g_ld32s(g, pads + PAD_RAW0_MODE) == 1;
        if (fed_externally != nullptr) *fed_externally = fed;
        return fed ? -1 : 0;
    }
    return -1;
}

// What the stick asks of this camera: turn > 0 is what D-pad right does,
// closer > 0 what D-pad up does, after the player's two direction options.
bool camera_stick(Guest *g, gaddr camera, float &turn, float &closer) {
    // A battle camera is running, in automatic camera mode too (CAM_MANUAL 0 is the game's own camera option): the shortcuts apply.
    if (g_ld32s(g, camera + CAM_STEP_SOURCE) == 0) {
        static bool announced = false;
        if (!announced) {
            announced = true;
            std::cout << "[camera] a battle camera is running: the battle shortcuts (D-pad, L2, R2, L3) apply" << std::endl;
        }
        // Only while the game takes input (muted on the post-battle fanfare and results, and in a replay).
        const gaddr pads = g_ld32(g, G_PAD_MANAGER);
        const std::uint32_t pad_flags = pads != 0 ? g_ld32(g, pads + PAD_FLAGS) : 0xFFFFFFFFu;
        const bool listens = pads != 0 && g_ld32(g, camera + CAM_PAD) == pads + PAD_LOGICAL0;
        const bool taking_input = pads != 0 && (pad_flags & (PAD_FLAG_REPLAY | PAD_FLAG_MUTED)) == 0 && listens;
        static int last_state = -1;
        if (last_state != static_cast<int>(taking_input)) {
            last_state = static_cast<int>(taking_input);
            std::cout << "[camera] battle camera, input " << (taking_input ? "taken" : "not taken") << " (pad flags 0x" << std::hex
                      << pad_flags << std::dec << ", listens " << listens << ", manual " << int(g_ld8(g, camera + CAM_MANUAL)) << ")"
                      << std::endl;
        }
        if (taking_input) pad().battle_read = pad().reads;
    }
    bool fed = false;
    const int player = local_camera(g, camera, &fed);
    if (player < 0) {
        // Ad hoc play: the camera stays as the game has it (turning it would differ between the two machines), but a
        // battle is running, so the button shortcuts may apply.
        if (fed && g_ld32s(g, camera + CAM_STEP_SOURCE) == 0) pad().fed_read = pad().reads;
        return false;
    }
    Pad &p = pad();
    // R3 presses SELECT only for a battle combatant's camera (time step
    // source 0, battle 0x08B0E200): the Story Mode world map runs this
    // camera too (source 1, main 0x08918E90), and SELECT is not its recentre.
    const bool battle = g_ld32s(g, camera + CAM_STEP_SOURCE) == 0;
    std::uint8_t x = p.x, y = p.y;
    if (battle) p.live_read = p.reads;
    turn = stick_axis(x);
    closer = -stick_axis(y);  // the Y axis grows downward
    if (turn == 0.0f && closer == 0.0f) return false;
    const Options &o = options();
    if (o.invert_x) turn = -turn;
    if (o.invert_y) closer = -closer;
    turn *= o.sensitivity;
    closer *= o.sensitivity;
    // Each player's own direction options (slot 1's are copied from player 1's).
    const std::uint16_t flags =
        static_cast<std::uint16_t>(g_ld32(g, G_PLAYER_FLAGS + 4u * static_cast<std::uint32_t>(player)) & 0xFFFFu);
    if ((flags & PLAYER_INVERT_HORIZONTAL) != 0) turn = -turn;
    if ((flags & PLAYER_INVERT_VERTICAL) != 0) closer = -closer;
    return true;
}

// battle 0x08B3B4FC: the camera's time step, in 1/60 s (2.0 at 30 Hz).
float time_step(Guest *g, gaddr camera) {
    float step = 0.0f;
    switch (g_ld32s(g, camera + CAM_STEP_SOURCE)) {
    case 0: std::memcpy(&step, g_ptr(g, g_ld32(g, G_FRAME_STEP_PTR) + 0x18u, 4), 4); break;
    case 1: std::memcpy(&step, g_ptr(g, G_FRAME_STEP, 4), 4); break;
    case 2: std::memcpy(&step, g_ptr(g, camera + CAM_STEP_OWN, 4), 4); break;
    default: break;
    }
    return step;
}

float ldf(Guest *g, gaddr address) {
    float value;
    std::memcpy(&value, g_ptr(g, address, 4), 4);
    return value;
}

gaddr row_of(Guest *g, gaddr camera) {
    return g_ld32(g, G_CAMERA_ROWS) + static_cast<std::uint32_t>(g_ld32s(g, camera + CAM_ROW)) * ROW_SIZE;
}

std::uint32_t speed_index(Guest *g, gaddr camera) {
    return static_cast<std::uint32_t>(std::clamp(g_ld32s(g, camera + CAM_SPEED_INDEX), 0, 2));
}

constexpr float kPi = 3.14159265f;
constexpr float kDegrees = kPi / 180.0f;

void trace(const char *mode, float turn, float closer, float yaw, float distance) {
    static std::uint32_t lines = 0;
    if (!options().trace || lines >= 4000u) return;
    ++lines;
    std::printf("[camera] read %u %s turn %+.3f closer %+.3f -> yaw %+.4f distance %.3f\n", pad().reads, mode, turn,
                closer, yaw, distance);
    std::fflush(stdout);
}

void announce(const char *mode) {
    static bool free_seen = false, lock_seen = false;
    bool &seen = std::strcmp(mode, "free") == 0 ? free_seen : lock_seen;
    if (seen) return;
    seen = true;
    std::cout << "[camera] the right stick turned the " << mode << " camera" << std::endl;
}

// After the free camera's stock input (battle 0x08B3F7F4).
void free_hook(Guest *g, gaddr mode, gaddr camera) {
    float turn = 0.0f, closer = 0.0f;
    if (!camera_stick(g, camera, turn, closer)) return;
    const gaddr row = row_of(g, camera);
    const float step = time_step(g, camera);
    float yaw = ldf(g, mode + FREE_YAW) +
                turn * kDegrees * ldf(g, row + ROW_FREE_YAW_SPEED + 4u * speed_index(g, camera)) * step;
    // One frame turns well under half a circle, so one wrap is enough.
    if (yaw > kPi) yaw -= 2.0f * kPi;
    else if (yaw < -kPi) yaw += 2.0f * kPi;
    g_stf(g, mode + FREE_YAW, yaw);
    const float distance = std::clamp(ldf(g, mode + FREE_DISTANCE) - closer * ldf(g, row + ROW_FREE_DISTANCE_SPEED) * step,
                                      ldf(g, row + ROW_FREE_MIN), ldf(g, row + ROW_FREE_MAX));
    g_stf(g, mode + FREE_DISTANCE, distance);
    announce("free");
    trace("free", turn, closer, yaw, distance);
}

// After the lock-on camera's stock input (battle 0x08B40290), which has just
// written this frame's turn from the D-pad; the game applies it, at most at
// the stock speed, later in the same update.
void lock_hook(Guest *g, gaddr mode, gaddr camera) {
    float turn = 0.0f, closer = 0.0f;
    if (!camera_stick(g, camera, turn, closer)) return;
    const gaddr row = row_of(g, camera);
    const float step = time_step(g, camera);
    const float delta = ldf(g, mode + LOCK_YAW_DELTA) +
                        turn * kDegrees * ldf(g, row + ROW_LOCK_YAW_SPEED + 4u * speed_index(g, camera)) * step;
    g_stf(g, mode + LOCK_YAW_DELTA, delta);
    const float distance = std::clamp(ldf(g, mode + LOCK_DISTANCE) - closer * ldf(g, row + ROW_LOCK_DISTANCE_SPEED) * step,
                                      ldf(g, row + ROW_LOCK_MIN), ldf(g, row + ROW_LOCK_MAX));
    g_stf(g, mode + LOCK_DISTANCE, distance);
    announce("lock-on");
    trace("lock-on", turn, closer, delta, distance);
}

namespace decomp = d012::decomp;

// ---- The auto-follow's dead zone -----------------------------------------------

// On with the smooth stick (D012_NO_SMOOTH_STICK=1 is the game's) and a zone.
bool follow_zone_on() {
    static const bool on = decomp::smooth_stick_on() && options().follow_dead_zone > 0.0f;
    return on;
}

void trace_follow(Guest *g, gaddr mode, gaddr camera, const CameraFollowTrace &t, bool zoned, bool analog,
                  const PadAnalog &stick) {
    static std::uint32_t calls = 0, lines = 0;
    ++calls;
    if (lines >= 40000u) return;
    ++lines;
    const gaddr owner = g_ld32(g, camera + CAM_OWNER);
    const float yaw = ldf(g, mode + FREE_YAW);
    // The stick's angle from straight ahead (up), right positive.
    const float stick_angle = std::atan2(stick.x, -stick.y) / kDegrees;
    if (t.followed)
        std::printf("[follow] %u cam %08X step %u yaw %+9.4f deg in %+9.4f target %+9.4f diff %+9.4f fed %+9.4f "
                    "turn %+8.4f %s stick %s %+7.2f %.2f pos (%.3f, %.3f)\n",
                    calls, camera, static_cast<unsigned>(g_ld32s(g, camera + CAM_STEP_SOURCE)), yaw / kDegrees,
                    t.yaw_in / kDegrees, t.target / kDegrees, t.diff / kDegrees, t.fed / kDegrees,
                    std::remainder(t.yaw_out - t.yaw_in, 2.0f * kPi) / kDegrees, zoned ? "zone" : "game", analog ? "port" : "none",
                    stick_angle, stick.magnitude, ldf(g, owner + 0x30u), ldf(g, owner + 0x38u));
    else
        std::printf("[follow] %u cam %08X step %u yaw %+9.4f deg (no follow) stick %s %+7.2f %.2f pos (%.3f, %.3f)\n",
                    calls, camera, static_cast<unsigned>(g_ld32s(g, camera + CAM_STEP_SOURCE)), yaw / kDegrees,
                    analog ? "port" : "none", stick_angle, stick.magnitude, ldf(g, owner + 0x30u),
                    ldf(g, owner + 0x38u));
}

// battle 0x08B3F7F4, the free input: the zone applies while the camera's
// owner is walked by the port's stick (so not in battle, and not with the
// D-pad control option). Reached from the decompiled free update below.
void check_free_input(Guest *g, const decomp::CallState &in, GuestRegs &);

// Whether the follow's gates are open for this call (as battle 0x08B3FAA4
// tests them): the differential test checks those calls as a probe of
// their own, the first calls being at rest.
bool following(Guest *g, gaddr camera) {
    if (g_ld8(g, camera + CAM_MANUAL) == 0 || g_ld8(g, camera + CAM_FOLLOW) != 1u) return false;
    const gaddr owner = g_ld32(g, camera + CAM_OWNER);
    return g_ld8(g, owner + 0x542u) <= 1u && (g_ld8(g, owner + 0x5B0u) & 0x08u) != 0;
}

void run_free_input(Guest *g, const decomp::CallState &in, GuestRegs &) {
    const gaddr mode = in.gpr[4], camera = in.gpr[5];
    if (decomp::verifying() && following(g, camera)) {
        GuestRegs args{};
        args.a[0] = mode;
        args.a[1] = camera;
        decomp::verify_probe("camera_free_input (following)", F_FREE_INPUT, decomp::Returns::Nothing,
                             &check_free_input, in, args);
    }
    PadAnalog stick{};
    const bool analog = decomp::analog_walker(g_ld32(g, camera + CAM_OWNER), &stick);
    const Options &o = options();
    const bool zoned = follow_zone_on() && analog;
    // The ramp, half the zone, ends (33.75 degrees by default) short of
    // where the game's follow settles for a diagonal push (about 35 degrees,
    // the walker's facing lagging its walk while the camera turns), so a
    // diagonal still turns at the game's full rate.
    const CameraFollowZone zone{o.follow_dead_zone * kDegrees, o.follow_dead_zone * 0.5f * kDegrees};
    CameraFollowTrace t{};
    camera_free_input(g, mode, camera, zoned ? &zone : nullptr, &t);
    if (o.trace_follow) trace_follow(g, mode, camera, t, zoned, analog, stick);
}
void check_free_input(Guest *g, const decomp::CallState &in, GuestRegs &) {
    camera_free_input(g, in.gpr[4], in.gpr[5], nullptr, nullptr);
}

void run_free(Guest *g, const decomp::CallState &in, GuestRegs &) {
    camera_free_update(g, in.gpr[4], in.gpr[5], &free_hook);
}
void check_free(Guest *g, const decomp::CallState &in, GuestRegs &) {
    camera_free_update(g, in.gpr[4], in.gpr[5], nullptr);
}
void run_lock(Guest *g, const decomp::CallState &in, GuestRegs &) {
    camera_lock_update(g, in.gpr[4], in.gpr[5], &lock_hook);
}
void check_lock(Guest *g, const decomp::CallState &in, GuestRegs &) {
    camera_lock_update(g, in.gpr[4], in.gpr[5], nullptr);
}

// The two updates are reached only through their modes' vtables (battle
// 0x08B3FCF4 and 0x08B4157C), so every call goes through dispatch and meets
// the override; the input functions themselves are called inline from the
// same generated unit and could not be overridden.
struct Install {
    Install() {
        const Options &o = options();
        // The free input only through the decompiled free update, which
        // calls it by lookup; the original update calls it inline.
        const bool follow = follow_zone_on() || o.trace_follow;
        std::vector<decomp::Override> overrides;
        if (o.enabled) {
            overrides.push_back({F_FREE_UPDATE, "camera_free_update", decomp::Module::BattleOverlay,
                                 decomp::Returns::Nothing, &run_free, true, nullptr,
                                 o.verify_hook ? nullptr : &check_free});
            overrides.push_back({F_LOCK_UPDATE, "camera_lock_update", decomp::Module::BattleOverlay,
                                 decomp::Returns::Nothing, &run_lock, true, nullptr,
                                 o.verify_hook ? nullptr : &check_lock});
        } else if (follow) {
            overrides.push_back({F_FREE_UPDATE, "camera_free_update", decomp::Module::BattleOverlay,
                                 decomp::Returns::Nothing, &check_free});
        }
        if (follow) {
            overrides.push_back({F_FREE_INPUT, "camera_free_input", decomp::Module::BattleOverlay,
                                 decomp::Returns::Nothing, &run_free_input, true, nullptr, &check_free_input});
            if (follow_zone_on())
                std::printf("[camera] follow dead zone %.1f degrees each side of straight ahead "
                            "(D012_CAMERA_FOLLOW_DEADZONE)\n",
                            o.follow_dead_zone);
        }
        decomp::add_overrides(overrides.data(), overrides.size(), !overrides.empty());
    }
} install_overrides;

// Whether the player's EX gauge is full: a float from 0 to 10000 in the fighter's status block,
// *(*(*(0x089D6A10) + 0x38) + 0x52C) + 0x18 (docs/research: the battle manager, its player fighter, its status block). It is
// full at 10000, and it falls as soon as EX Mode starts, so the shortcut is off again by itself. A chain that does not read as a
// fighter's (a battle that is not set up yet, an address that is not memory) answers true: a wrong address must never take L3 away.
// -1: the chain does not read as a fighter's (no battle yet); 0: the gauge is not full; 1: it is full.
int ex_gauge_state(psprecomp::Runtime &rt) {
    const auto ram = [](std::uint32_t address) {
        const std::uint32_t a = address & 0x1FFFFFFFu;
        return a >= 0x08800000u && a < 0x0A000000u - 4u;
    };
    const std::uint32_t manager = rt.memory().load32(0x089D6A10u);
    if (!ram(manager)) return -1;
    const std::uint32_t fighter = rt.memory().load32(manager + 0x38u);
    if (!ram(fighter)) return -1;
    const std::uint32_t status = rt.memory().load32(fighter + 0x52Cu);
    if (!ram(status)) return -1;
    const std::uint32_t bits = rt.memory().load32(status + 0x18u);
    float gauge = 0.0f;
    std::memcpy(&gauge, &bits, sizeof(gauge));
    if (!std::isfinite(gauge) || gauge < 0.0f || gauge > 10000.0f) return -1;
    return gauge >= 9999.0f ? 1 : 0;
}

// Written by the pad read, read by the interface thread (the on-screen EX button).
std::atomic<bool> g_ex_full{false};
std::atomic<bool> g_assist_bar{false}, g_assist_full{false}, g_summon_ready{false};

// What the D-pad shortcuts wait for, read from the player's fighter in a battle (measured with D012_TRACE_GAUGES):
//   the assist gauge: the float at +0x1C of the status block, 0 to 10000; a bar is 5000 and two bars (full) 10000;
//   the summon: the status block's word at +0x28 is 1 once the summon is ready, and the battle manager's word at +0x2C is 2 while a
//   summon is out (1 otherwise).
// `valid` is false when the chain does not read as a fighter's (no battle yet): then nothing is held back.
struct BattleGauges {
    bool valid = false;
    float assist = 0.0f;
    std::uint32_t summon_flag = 0u;
    std::uint32_t summon_out = 0u;
};

BattleGauges read_battle_gauges(psprecomp::Runtime &rt) {
    const auto ram = [](std::uint32_t address) {
        const std::uint32_t a = address & 0x1FFFFFFFu;
        return a >= 0x08800000u && a < 0x0A000000u - 4u;
    };
    BattleGauges out;
    const std::uint32_t manager = rt.memory().load32(0x089D6A10u);
    if (!ram(manager)) return out;
    const std::uint32_t fighter = rt.memory().load32(manager + 0x38u);
    if (!ram(fighter)) return out;
    const std::uint32_t status = rt.memory().load32(fighter + 0x52Cu);
    if (!ram(status)) return out;
    const std::uint32_t bits = rt.memory().load32(status + 0x1Cu);
    std::memcpy(&out.assist, &bits, sizeof(out.assist));
    if (!std::isfinite(out.assist) || out.assist < 0.0f || out.assist > 10000.0f) return out;
    out.summon_flag = rt.memory().load32(status + 0x28u);
    out.summon_out = rt.memory().load32(manager + 0x2Cu);
    out.valid = true;
    return out;
}

// D012_TRACE_GAUGES=1: log only. The first 64 bytes of the player's status block (the EX gauge is the float at +0x18) printed each
// time a word of them changes, to find the assist gauge and the other values the D-pad shortcuts would wait for: play a battle,
// use an assist, fill the gauges, and read which offsets move. Nothing is changed.
void trace_gauges(psprecomp::Runtime &rt) {
    static const bool on = flag("D012_TRACE_GAUGES");
    if (!on) return;
    static std::uint32_t last[64] = {};
    static int lines = 0;
    const auto ram = [](std::uint32_t address) {
        const std::uint32_t a = address & 0x1FFFFFFFu;
        return a >= 0x08800000u && a < 0x0A000000u - 4u;
    };
    const std::uint32_t manager = rt.memory().load32(0x089D6A10u);
    if (!ram(manager)) return;
    const std::uint32_t fighter = rt.memory().load32(manager + 0x38u);
    if (!ram(fighter)) return;
    const std::uint32_t status = rt.memory().load32(fighter + 0x52Cu);
    if (!ram(status)) return;
    // D012_TRACE_GAUGES=2: the first 256 bytes, without the three gauges that change all the time (+0x14, the EX gauge +0x18, the
    // assist gauge +0x1C), to see the other flags (the summon's) on their own.
    static const bool quiet = [] {
        const char *text = std::getenv("D012_TRACE_GAUGES");
        return text != nullptr && text[0] == '2';
    }();
    // D012_TRACE_GAUGES=3: the status block (256 bytes), the fighter object (1536 bytes) and the battle manager (512 bytes), each word
    // printed when it changes, but a word that has changed 12 times is muted (positions and timers), so a flag that flips once stands out.
    static const bool wide = [] {
        const char *text = std::getenv("D012_TRACE_GAUGES");
        return text != nullptr && text[0] == '3';
    }();
    // D012_TRACE_GAUGES=4: no changes, a snapshot. Once, 5 seconds after the battle's data appears, the same three regions printed as they
    // are, to compare two battles that differ in one thing (a manual summon against an automatic one): the words that differ are the setting.
    static const bool snapshot = [] {
        const char *text = std::getenv("D012_TRACE_GAUGES");
        return text != nullptr && text[0] == '4';
    }();
    if (snapshot) {
        static std::uint32_t first_read = 0u;
        static bool taken = false;
        if (taken) return;
        if (first_read == 0u) first_read = pad().reads;
        if (pad().reads - first_read < 300u) return;
        taken = true;
        const struct {
            const char *name;
            std::uint32_t base, words;
        } regions[3] = {{"status", status, 64u}, {"fighter", fighter, 384u}, {"manager", manager, 128u}};
        for (const auto &r : regions)
            for (std::uint32_t i = 0; i < r.words; i += 8u) {
                std::printf("[snapshot] %s +0x%03X:", r.name, i * 4u);
                for (std::uint32_t k = 0; k < 8u && i + k < r.words; ++k) std::printf(" %08X", rt.memory().load32(r.base + (i + k) * 4u));
                std::printf("\n");
            }
        std::fflush(stdout);
        return;
    }
    if (wide) {
        struct Region {
            const char *name;
            std::uint32_t base, words;
            std::vector<std::uint32_t> last;
            std::vector<std::uint8_t> changes;
            bool primed = false;
            std::uint32_t where = 0u;
        };
        static Region regions[3] = {{"status", 0u, 64u}, {"fighter", 0u, 384u}, {"manager", 0u, 128u}};
        regions[0].base = status;
        regions[1].base = fighter;
        regions[2].base = manager;
        for (Region &r : regions) {
            if (r.where != r.base) {  // another object: start again without printing what it already holds
                r.where = r.base;
                r.primed = false;
            }
            r.last.resize(r.words);
            r.changes.resize(r.words);
            for (std::uint32_t i = 0; i < r.words; ++i) {
                const std::uint32_t word = rt.memory().load32(r.base + i * 4u);
                if (!r.primed) {
                    r.last[i] = word;
                    continue;
                }
                if (word == r.last[i] || r.changes[i] >= 12u) continue;
                float before = 0.0f, after = 0.0f;
                std::memcpy(&before, &r.last[i], 4u);
                std::memcpy(&after, &word, 4u);
                if (++lines <= 900)
                    std::printf("[gauges] pad read %u: %s +0x%03X: %08X -> %08X (as float %g -> %g)%s\n", pad().reads, r.name, i * 4u,
                                r.last[i], word, before, after, ++r.changes[i] >= 12u ? "  [muted from here on]" : "");
                r.last[i] = word;
            }
            r.primed = true;
        }
        std::fflush(stdout);
        return;
    }
    for (std::uint32_t i = 0; i < 64u; ++i) {
        if (quiet && i >= 5u && i <= 7u) continue;
        if (!quiet && i >= 16u) break;
        const std::uint32_t word = rt.memory().load32(status + i * 4u);
        if (word == last[i]) continue;
        float before = 0.0f, after = 0.0f;
        std::memcpy(&before, &last[i], 4u);
        std::memcpy(&after, &word, 4u);
        if (++lines <= 600)
            std::printf("[gauges] pad read %u: status +0x%02X: %08X -> %08X (as float %g -> %g)\n", pad().reads, i * 4u, last[i], word,
                        before, after);
        last[i] = word;
    }
    std::fflush(stdout);
}

} // namespace

bool enabled() { return options().enabled; }
bool ex_ready() { return g_ex_full.load(std::memory_order_relaxed); }
bool brv_assist_ready() { return g_assist_bar.load(std::memory_order_relaxed); }
bool hp_assist_ready() { return g_assist_full.load(std::memory_order_relaxed); }
bool summon_ready() { return g_summon_ready.load(std::memory_order_relaxed); }

// True while a battle camera is stepping (not in the pause menu, the pre-battle screens or the results).
bool battle_running() {
    const Pad &p = pad();
    return p.reads - p.live_read <= kLiveReads || p.reads - p.fed_read <= kLiveReads || p.reads - p.battle_read <= kLiveReads;
}

void install(portablekit::HleRegistrar &hle) {
    static bool installed = false;
    // Installed whether or not the right-stick camera is on: the pad read also keeps up the gauge state the on-screen move buttons wait
    // for (a phone's EX Mode, assists and Summon), which must not depend on the camera option.
    if (installed) return;
    installed = true;
    const portablekit::HleFunction previous = hle.bound_function("sceCtrl", kSceCtrlReadBufferPositive);
    if (!previous) {
        std::cerr << "[camera] sceCtrlReadBufferPositive is not bound; the right stick cannot reach the camera\n";
        return;
    }
    const Options &o = options();
    if (o.enabled)
        std::cout << "[camera] right-stick battle camera on (dead zone " << o.dead_zone << ", sensitivity "
                  << o.sensitivity << (o.invert_x ? ", X inverted" : "") << (o.invert_y ? ", Y inverted" : "")
                  << "); R3 recentres" << std::endl;
#if defined(__ANDROID__)
    SDL_Log("[camera] pad hook installed");
#endif
    hle.bind("sceCtrl", kSceCtrlReadBufferPositive, [previous](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t buffer = ctx.gpr[4];
        const std::uint32_t count = std::clamp<std::uint32_t>(ctx.gpr[5], 1u, 64u);
        previous(rt, ctx);
        Pad &p = pad();
        ++p.reads;
        if (buffer == 0u) return;
        const std::uint32_t last = buffer + (count - 1u) * 16u;
        // The game centres the left stick while HOLD is on; so does this.
        const bool hold = (rt.memory().load32(last + 4u) & kHold) != 0u;
        p.x = hold ? 0x80u : rt.memory().load8(last + 10u);
        p.y = hold ? 0x80u : rt.memory().load8(last + 11u);
        const bool r3 = (ext::extra_buttons() & ext::kExtraR3) != 0u;
        const bool live = p.reads - p.live_read <= kLiveReads;
        if (r3 && live) {
            for (std::uint32_t i = 0; i < count; ++i) {
                const std::uint32_t at = buffer + i * 16u + 4u;
                rt.memory().store32(at, rt.memory().load32(at) | kSelect);
            }
            if (!p.r3) std::cout << "[camera] R3: recentre (SELECT)" << std::endl;
        }
        // Battle shortcuts, only while a local battle camera is running (menus keep the D-pad and the R1/L1 buttons):
        //   L3 (stick click)  EX Mode / EX Revenge   R1 + Square
        //   L2 (left trigger) dodge                  R1 + Cross
        //   R2 (right trigger) dash to the target    R1 + Triangle
        //   D-pad up          call an Assist         L1 + Circle
        //   D-pad down        call a BRV Assist      L1 + Square
        //   D-pad left        manual Summon          R1 + Circle
        // D-pad up and down no longer move the camera closer or away (the right stick does that), and D-pad left no longer
        // turns it (the right stick does that too); D-pad right still turns it.
        const bool shortcut_live = live || p.reads - p.fed_read <= kLiveReads || p.reads - p.battle_read <= kLiveReads;
        // The EX gauge's state on every read, in or out of a battle: L3 and the on-screen EX button wait for it. An unreadable chain (-1)
        // leaves L3 alone, so a wrong address never takes it away, but it hides the on-screen button, which only belongs in a battle.
        const int ex_state = ex_gauge_state(rt);
        // With the camera off nothing marks a battle as running, so the gauge chain reading as a fighter's is the sign of one.
        const bool shown = shortcut_live || !enabled();
        g_ex_full.store(shown && ex_state == 1, std::memory_order_relaxed);
        // The other gauges, on every read too: the D-pad shortcuts and the on-screen buttons of the moves wait for them.
        const BattleGauges gauges = read_battle_gauges(rt);
        // The status word that says "summon ready" is not cleared when the summon is used (measured: it stays 1 after Ifrit), so the use is
        // remembered here: a summon that comes out right after this shortcut was pressed is this player's, and the stone stays used
        // until the word drops to 0 or the battle ends. The manager's "a summon is out" word is shared with the CPU, which is why it
        // alone does not mark the player's use.
        static bool summon_used = false;
        static std::uint32_t left_pressed_read = 0u;
        static bool left_pressed_once = false;
        if (!gauges.valid || gauges.summon_flag == 0u) {
            summon_used = false;
            left_pressed_once = false;
        } else if (gauges.summon_out == 2u && left_pressed_once && p.reads - left_pressed_read <= 180u) {
            summon_used = true;
        }
        // The on-screen Summon button presses R1 + Circle itself, not the D-pad shortcut: that press counts as the use too.
        if (gauges.valid && gauges.summon_flag == 1u && (rt.memory().load32(last + 4u) & (kR1 | kCircle)) == (kR1 | kCircle)) {
            left_pressed_once = true;
            left_pressed_read = p.reads;
        }
        const bool summon_ready_now = gauges.valid && gauges.summon_flag == 1u && gauges.summon_out != 2u && !summon_used;
        g_assist_bar.store(shown && gauges.valid && gauges.assist >= 4999.0f, std::memory_order_relaxed);
        g_assist_full.store(shown && gauges.valid && gauges.assist >= 9999.0f, std::memory_order_relaxed);
        g_summon_ready.store(shown && summon_ready_now, std::memory_order_relaxed);
        // What the on-screen move buttons wait for, logged when it changes (at most 60 lines), to see on a device why a button stays
        // hidden: whether a battle is "live", whether the gauge chain reads as a fighter's, and what it reads.
        {
            static int last_key = -1, logged = 0;
            const int key = (shortcut_live ? 1 : 0) | (ex_state + 1) << 1 | (gauges.valid ? 1 : 0) << 4 |
                            (gauges.assist >= 9999.0f ? 2 : gauges.assist >= 4999.0f ? 1 : 0) << 5 |
                            (summon_ready_now ? 1 : 0) << 7;
            if (key != last_key && logged < 60) {
                last_key = key;
                ++logged;
                std::printf("[buttons] live %d (camera %d, fed %d, battle %d), EX state %d, gauges valid %d, assist %g, summon flag %u out %u, "
                            "ready: EX %d BRV %d HP %d summon %d\n",
                            shortcut_live, live, p.reads - p.fed_read <= kLiveReads, p.reads - p.battle_read <= kLiveReads, ex_state,
                            gauges.valid, gauges.assist, gauges.summon_flag, gauges.summon_out, ex_state == 1 && shortcut_live,
                            gauges.valid && gauges.assist >= 4999.0f && shortcut_live,
                            gauges.valid && gauges.assist >= 9999.0f && shortcut_live, shortcut_live && summon_ready_now);
#if defined(__ANDROID__)
                // A phone's stdout goes nowhere: the same line to logcat (tag SDL), read with adb logcat -s SDL.
                SDL_Log("[buttons] live %d (camera %d, fed %d, battle %d), EX state %d, gauges valid %d, assist %g, summon flag %u out %u",
                        shortcut_live, live, p.reads - p.fed_read <= kLiveReads, p.reads - p.battle_read <= kLiveReads, ex_state,
                        gauges.valid, gauges.assist, gauges.summon_flag, gauges.summon_out);
#endif
                std::fflush(stdout);
            }
        }
        if (shortcut_live && options().shortcuts) {
            const std::uint32_t extra = ext::extra_buttons();
            static bool announced = false;
            if (!announced && (extra != 0u || (rt.memory().load32(buffer + 4u) & (kDpadUp | kDpadDown | kDpadLeft)) != 0u)) {
                announced = true;
                std::cout << "[camera] battle shortcut pressed (extra buttons 0x" << std::hex << extra << std::dec << ")" << std::endl;
            }
            std::uint32_t add = 0u;
            if ((extra & ext::kExtraL3) != 0u && (!options().l3_needs_gauge || ex_state != 0)) add |= kR1 | kSquare;
            if ((extra & ext::kExtraL2) != 0u) add |= kR1 | kCross;
            if ((extra & ext::kExtraR2) != 0u) add |= kR1 | kTriangle;
            trace_gauges(rt);
            const bool gates = options().dpad_gates && gauges.valid;
            const bool assist_up = !gates || gauges.assist >= 4999.0f;       // one bar or more
            const bool assist_down = !gates || gauges.assist >= 9999.0f;     // completely full
            const bool summon_left = !gates || summon_ready_now;
            bool speed_held = false;
            for (std::uint32_t i = 0; i < count; ++i) {
                const std::uint32_t at = buffer + i * 16u + 4u;
                std::uint32_t buttons = rt.memory().load32(at);
                // D-pad right held: the game runs at 4x (the menu's Game speed 4x step) until it is let go. It no longer turns the camera.
                if ((buttons & kDpadRight) != 0u) {
                    speed_held = true;
                    buttons &= ~kDpadRight;
                }
                // Each of the three does its move only when the move is ready; otherwise the press is dropped, so the fighter does not
                // attack with the circle or the square the shortcut would have pressed.
                if ((buttons & kDpadUp) != 0u) buttons = (buttons & ~kDpadUp) | (assist_up ? (kL1 | kCircle) : 0u);
                if ((buttons & kDpadDown) != 0u) buttons = (buttons & ~kDpadDown) | (assist_down ? (kL1 | kSquare) : 0u);
                if ((buttons & kDpadLeft) != 0u) {
                    buttons = (buttons & ~kDpadLeft) | (summon_left ? (kR1 | kCircle) : 0u);
                    if (summon_left) {
                        left_pressed_once = true;
                        left_pressed_read = p.reads;
                    }
                }
                rt.memory().store32(at, buttons | add);
            }
            ext::hold_game_speed(speed_held ? kHeldSpeed : 1.0);
        } else {
            ext::hold_game_speed(1.0);
        }
        // Ad hoc battle: the right stick cannot turn the camera itself (the camera is part of the simulation both machines
        // run), but the D-pad bits of the pad state can, because they are sent like any button and each side turns the
        // camera by the stock amount. Pushing the stick presses the D-pad bit the game turns, or moves closer or away, with.
        if (!live && p.reads - p.fed_read <= kLiveReads) {
            float turn = stick_axis(p.x), closer = -stick_axis(p.y);
            if (options().invert_x) turn = -turn;
            if (options().invert_y) closer = -closer;
            std::uint32_t camera_bits = 0u;
            if (turn > 0.5f) camera_bits |= kDpadRight;
            else if (turn < -0.5f) camera_bits |= kDpadLeft;
            if (closer > 0.5f) camera_bits |= kDpadUp;
            else if (closer < -0.5f) camera_bits |= kDpadDown;
            if (camera_bits != 0u) {
                for (std::uint32_t i = 0; i < count; ++i) {
                    const std::uint32_t at = buffer + i * 16u + 4u;
                    rt.memory().store32(at, rt.memory().load32(at) | camera_bits);
                }
            }
        }
        p.r3 = r3;
    });
}

} // namespace d012::camera

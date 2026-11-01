// The battle HUD's layouts (scaffold for moving and resizing the game's UI in its own data).
//
// The game's menu manager draws every on-screen layout (the character HUD, the pause menu, the speech
// text, ...) from one draw function, main 0x088CED50(manager): the layouts are linked from manager+0x24
// through their own +0x24, and a layout draws while its byte +0x14 has bit 1 and neither 0x0C nor 0x20
// (docs/port/local-versus.md, "The HUD"). A layout's sprite list starts at layout+0x3C: a chain of 0x14-byte
// nodes {object, id, key, next, prev}, the object being the sprite itself.
//
// This wraps that draw. With D012_TRACE_HUD_LAYOUTS=1 it logs, with a draw-call counter, each layout that
// starts or stops drawing, and the words of the sprite objects of a layout that starts, to find which layouts
// are the character HUD and where a sprite keeps its position and size. Nothing is changed yet.

#include "../../third_party/dissidia012-pc/port/host/d012_decomp_harness.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <vector>

namespace {

using d012::decomp::CallState;  // Guest and GuestRegs come from the decompiled-code header, at global scope

constexpr std::uint32_t kMenuDraw = 0x088CED50u;

bool tracing() {
    static const bool on = [] {
        const char *text = std::getenv("D012_TRACE_HUD_LAYOUTS");
        return text != nullptr && *text != '\0' && std::strcmp(text, "0") != 0;
    }();
    return on;
}

void dump_words(Guest *g, std::uint32_t address, std::uint32_t bytes) {
    for (std::uint32_t off = 0; off < bytes; off += 4u) std::printf(" %08X", g_ld32(g, address + off));
}

void trace_layouts(Guest *g, std::uint32_t manager) {
    static std::map<std::uint32_t, bool> was_drawing;
    static std::uint64_t calls = 0;
    ++calls;
    if (g_ld8(g, manager + 0x20u) == 0u) return;
    unsigned layouts = 0;
    for (std::uint32_t layout = g_ld32(g, manager + 0x24u); layout != 0u && layouts < 512u;
         layout = g_ld32(g, layout + 0x24u), ++layouts) {
        const std::uint8_t flags = g_ld8(g, layout + 0x14u);
        const bool draws = (flags & 1u) != 0u && (flags & 0x2Cu) == 0u;
        auto found = was_drawing.find(layout);
        if (found != was_drawing.end() && found->second == draws) continue;
        const bool known = found != was_drawing.end();
        was_drawing[layout] = draws;
        if (!known && !draws) continue;  // never seen drawing: not worth a line
        // The sprites hang from the layout's first word, each linked to the next through its +0x3C (the
        // game's draw, FUN_088d16f4); a layout whose +0x10 is zero is drawn by another routine (text).
        unsigned sprites = 0;
        for (std::uint32_t sprite = g_ld32(g, layout); sprite != 0u && sprites < 512u;
             sprite = g_ld32(g, sprite + 0x3Cu))
            ++sprites;
        std::printf("[hudlayout] call %llu layout %08X %s flags=%02X data=%08X +0x10=%08X sprites=%u\n",
                    static_cast<unsigned long long>(calls), layout, draws ? "STARTS" : "stops", flags,
                    g_ld32(g, layout + 0x0Cu), g_ld32(g, layout + 0x10u), sprites);
        if (!draws) continue;
        // The first sprites of a layout that starts drawing: their words, to find position and size.
        unsigned shown = 0;
        for (std::uint32_t sprite = g_ld32(g, layout); sprite != 0u && shown < 3u;
             sprite = g_ld32(g, sprite + 0x3Cu), ++shown) {
            float x = 0.0f, y = 0.0f;
            const std::uint32_t xw = g_ld32(g, sprite + 0x10u), yw = g_ld32(g, sprite + 0x14u);
            std::memcpy(&x, &xw, 4);
            std::memcpy(&y, &yw, 4);
            std::printf("[hudlayout]   sprite %08X (+0x10 %.1f, +0x14 %.1f):", sprite, x, y);
            dump_words(g, sprite, 0x48u);
            std::printf("\n");
        }
    }
    std::fflush(stdout);
}

const std::set<std::uint32_t> &hud_layouts();
float env_number(const char *name, float fallback);

// Where each named layout hangs from (0, 240 or 480 on x), decided from its first element, in run_sprite_draw.
std::map<std::uint32_t, float> &layout_anchors() {
    static std::map<std::uint32_t, float> anchors;
    return anchors;
}

struct HudParams {
    float scale, lift, side;
};

const HudParams &hud_params() {
    static const HudParams params = {std::fmin(1.0f, std::fmax(0.1f, env_number("D012_HUD_SCALE", 80.0f) / 100.0f)),
                                     env_number("D012_HUD_MARGIN", 0.0f), env_number("D012_HUD_SIDE", 0.0f)};
    return params;
}

float load_float(Guest *g, std::uint32_t address) {
    const std::uint32_t word = g_ld32(g, address);
    float value;
    std::memcpy(&value, &word, 4);
    return value;
}

void store_float(Guest *g, std::uint32_t address, float value) {
    std::uint32_t word;
    std::memcpy(&word, &value, 4);
    g_st32(g, address, word);
}

// The sprites of the named layouts get their own position (+0x10, +0x14) and scale (+0x18, +0x1C) changed for
// the one draw, the way the game's draw reads them (FUN_088D16F4: the screen position is the sprite's plus the
// element's translation, the size the sprite's scale times the element's), then put back.
void run_menu_draw(Guest *g, const CallState &in, GuestRegs &) {
    if (tracing()) trace_layouts(g, in.gpr[4]);
    struct Saved {
        std::uint32_t sprite;
        float x, y, sx, sy;
    };
    std::vector<Saved> saved;
    const HudParams &hud = hud_params();
    if (!hud_layouts().empty() && g_ld8(g, in.gpr[4] + 0x20u) != 0u) {
        unsigned layouts = 0;
        for (std::uint32_t layout = g_ld32(g, in.gpr[4] + 0x24u); layout != 0u && layouts < 512u;
             layout = g_ld32(g, layout + 0x24u), ++layouts) {
            const auto anchor = layout_anchors().find(layout);
            if (hud_layouts().count(layout) == 0u || anchor == layout_anchors().end()) continue;
            const float ax = anchor->second;
            const float target = ax < 1.0f ? hud.side : ax > 479.0f ? 480.0f - hud.side : 240.0f;
            const float ox = target - ax * hud.scale;
            const float oy = (272.0f - hud.lift) - 272.0f * hud.scale;
            unsigned sprites = 0;
            for (std::uint32_t sprite = g_ld32(g, layout); sprite != 0u && sprites < 512u;
                 sprite = g_ld32(g, sprite + 0x3Cu), ++sprites) {
                const std::uint16_t flags = static_cast<std::uint16_t>(g_ld16s(g, sprite + 0x20u));
                if ((flags & 0x800u) != 0u) continue;  // projected from the world, not placed on the screen
                saved.push_back({sprite, load_float(g, sprite + 0x10u), load_float(g, sprite + 0x14u),
                                 load_float(g, sprite + 0x18u), load_float(g, sprite + 0x1Cu)});
                const Saved &s = saved.back();
                store_float(g, sprite + 0x10u, s.x * hud.scale + ox);
                store_float(g, sprite + 0x14u, s.y * hud.scale + oy);
                if ((flags & 0x400u) == 0u) {
                    store_float(g, sprite + 0x18u, s.sx * hud.scale);
                    store_float(g, sprite + 0x1Cu, s.sy * hud.scale);
                }
            }
        }
    }
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kMenuDraw, regs);
    for (const Saved &s : saved) {
        store_float(g, s.sprite + 0x10u, s.x);
        store_float(g, s.sprite + 0x14u, s.y);
        store_float(g, s.sprite + 0x18u, s.sx);
        store_float(g, s.sprite + 0x1Cu, s.sy);
    }
}

// ---------------------------------------------------------------------------------------------------------
// FUN_088DBE64(float time, layout, animation, parent matrix, sprite): for one sprite of a layout, builds the
// element the draw will use: an 0x50-byte record appended to the array at *(manager+0x10) (count at
// manager+0x14), whose first 0x40 bytes from +0x10 are the sprite's 4x4 matrix (scale in [0] and [5],
// translation in [12] and [13], the parent matrix already multiplied in). This wraps it and changes the
// elements it just appended, which is the game's own placement data, before the original draw reads them.
//
// D012_HUD_LAYOUTS="08B89F58,08B89F84" names the layouts to change; D012_HUD_SCALE (percent, default 80),
// D012_HUD_MARGIN (bottom lift) and D012_HUD_SIDE (side space), in game pixels, set how.
constexpr std::uint32_t kSpriteDraw = 0x088DBE64u;
constexpr std::uint32_t kMenuManager = 0x089D7830u;

float env_number(const char *name, float fallback) {
    const char *text = std::getenv(name);
    return text != nullptr && *text != '\0' ? static_cast<float>(std::atof(text)) : fallback;
}

const std::set<std::uint32_t> &hud_layouts() {
    static const std::set<std::uint32_t> layouts = [] {
        std::set<std::uint32_t> list;
        if (const char *text = std::getenv("D012_HUD_LAYOUTS"))
            for (const char *p = text; *p != '\0';) {
                char *end = nullptr;
                const unsigned long value = std::strtoul(p, &end, 16);
                if (end == p) { ++p; continue; }
                list.insert(static_cast<std::uint32_t>(value));
                p = end;
            }
        return list;
    }();
    return layouts;
}

struct Box {
    float x0 = 1e9f, y0 = 1e9f, x1 = -1e9f, y1 = -1e9f;
    unsigned elements = 0;
};

void run_sprite_draw(Guest *g, const CallState &in, GuestRegs &out) {
    const std::uint32_t layout = in.gpr[4];
    const std::uint32_t manager = g_ld32(g, kMenuManager);
    const std::uint32_t before = manager != 0u ? g_ld32(g, manager + 0x14u) : 0u;
    // The parent matrix (4th argument, $a2... the sprite's +0x2C) the game multiplies in: where the layout
    // really sits on screen. Logged once per layout and matrix.
    if (tracing() && in.gpr[6] != 0u) {
        static std::set<std::pair<std::uint32_t, std::uint32_t>> seen;
        if (seen.insert({layout, in.gpr[6]}).second && seen.size() < 600u) {
            float p[16];
            std::memcpy(p, g_ptr(g, in.gpr[6], 64u), 64u);
            std::printf("[hudlayout] parent layout %08X matrix %08X scale %.2f %.2f translation %.1f %.1f (%.2f %.2f)\n",
                        layout, in.gpr[6], p[0], p[5], p[12], p[13], p[1], p[4]);
        }
    }
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    regs.f[0] = in.fpr[12];
    d012::decomp::call_original(g, kSpriteDraw, regs);
    out = regs;
    if (manager == 0u) return;
    const std::uint32_t after = g_ld32(g, manager + 0x14u);
    const std::uint32_t base = g_ld32(g, manager + 0x10u);
    if (after <= before || after > 0xAAu || base == 0u) return;

    static std::map<std::uint32_t, Box> boxes;
    static std::uint64_t calls = 0;
    const bool change = hud_layouts().count(layout) != 0u;
    const HudParams &hud = hud_params();
    const std::uint32_t sprite = in.gpr[7];
    const std::uint16_t flags = static_cast<std::uint16_t>(g_ld16s(g, sprite + 0x20u));
    const bool projected = (flags & 0x800u) != 0u;
    for (std::uint32_t i = before; i < after; ++i) {
        const std::uint32_t matrix = base + i * 0x50u + 0x10u;
        float m[16];
        std::memcpy(m, g_ptr(g, matrix, 64u), 64u);
        // Absolute screen position: the element's translation plus the sprite's own.
        const float abs_x = m[12] + (projected ? 0.0f : load_float(g, sprite + 0x10u));
        const float abs_y = m[13] + (projected ? 0.0f : load_float(g, sprite + 0x14u));
        if (tracing()) {
            Box &box = boxes[layout];
            box.x0 = std::fmin(box.x0, abs_x);
            box.y0 = std::fmin(box.y0, abs_y);
            box.x1 = std::fmax(box.x1, abs_x);
            box.y1 = std::fmax(box.y1, abs_y);
            ++box.elements;
        }
        if (!change || projected) continue;
        // Which side the layout hangs from, from its first element, kept for the sprite fields above.
        if (layout_anchors().count(layout) == 0u)
            layout_anchors()[layout] = abs_x < 200.0f ? 0.0f : abs_x > 280.0f ? 480.0f : 240.0f;
        m[12] *= hud.scale;
        m[13] *= hud.scale;
        if ((flags & 0x400u) != 0u)  // the sprite's own scale is ignored: scale the element's
            for (int row : {0, 4, 8}) { m[row] *= hud.scale; m[row + 1] *= hud.scale; }
        std::memcpy(g_ptr(g, matrix, 64u), m, 64u);
    }
    if (tracing() && (++calls % 20000u) == 0u) {
        std::printf("[hudlayout] boxes after %llu sprite draws (screen positions, game pixels):\n",
                    static_cast<unsigned long long>(calls));
        for (const auto &[addr, box] : boxes)
            std::printf("[hudlayout]   layout %08X  x %.0f..%.0f  y %.0f..%.0f  elements %u\n", addr, box.x0, box.x1,
                        box.y0, box.y1, box.elements);
        boxes.clear();
        std::fflush(stdout);
    }
}

struct Install {
    Install() {
        // Only with the trace on or layouts named, so a normal run is untouched.
        if (!tracing() && hud_layouts().empty()) return;
        static const d012::decomp::Override overrides[] = {
            {kMenuDraw, "hud_menu_draw", d012::decomp::Module::Main, d012::decomp::Returns::Nothing, &run_menu_draw},
            {kSpriteDraw, "hud_sprite_draw", d012::decomp::Module::Main, d012::decomp::Returns::Integer,
             &run_sprite_draw},
        };
        d012::decomp::add_overrides(overrides, sizeof overrides / sizeof overrides[0], true);
        std::printf("[hudlayout] tracing the menu manager's layouts (D012_TRACE_HUD_LAYOUTS)\n");
    }
} install;

} // namespace

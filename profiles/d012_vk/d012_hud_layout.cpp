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

void run_menu_draw(Guest *g, const CallState &in, GuestRegs &) {
    if (tracing()) trace_layouts(g, in.gpr[4]);
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kMenuDraw, regs);
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
    static const float scale = std::fmin(1.0f, std::fmax(0.1f, env_number("D012_HUD_SCALE", 80.0f) / 100.0f));
    static const float lift = env_number("D012_HUD_MARGIN", 0.0f);
    static const float side = env_number("D012_HUD_SIDE", 0.0f);
    for (std::uint32_t i = before; i < after; ++i) {
        const std::uint32_t matrix = base + i * 0x50u + 0x10u;
        float m[16];
        std::memcpy(m, g_ptr(g, matrix, 64u), 64u);
        if (tracing()) {
            Box &box = boxes[layout];
            box.x0 = std::fmin(box.x0, m[12]);
            box.y0 = std::fmin(box.y0, m[13]);
            box.x1 = std::fmax(box.x1, m[12]);
            box.y1 = std::fmax(box.y1, m[13]);
            ++box.elements;
        }
        if (!change) continue;
        // Scale about the corner this piece hangs from, then lift and space it: left pieces move right,
        // right pieces left, the centre stays. x and y outputs are columns 0 and 1 of the matrix.
        const float ax = m[12] < 200.0f ? 0.0f : m[12] > 280.0f ? 480.0f : 240.0f;
        const float tx = (ax < 1.0f ? side : ax > 479.0f ? 480.0f - side : 240.0f) - ax * scale;
        const float ty = (272.0f - lift) - 272.0f * scale;
        for (int row : {0, 4, 8}) { m[row] *= scale; m[row + 1] *= scale; }
        m[12] = m[12] * scale + tx;
        m[13] = m[13] * scale + ty;
        std::memcpy(g_ptr(g, matrix, 64u), m, 64u);
    }
    if (tracing() && (++calls % 20000u) == 0u) {
        std::printf("[hudlayout] boxes after %llu sprite draws (element translations, game pixels):\n",
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

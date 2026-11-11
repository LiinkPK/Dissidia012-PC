// The battle HUD's layouts (scaffold for moving and resizing the game's UI in its own data).
//
// The game's menu manager draws every on-screen layout (the character HUD, the pause menu, the speech
// text, ...) from one draw function, main 0x088CED50(manager): the layouts are linked from manager+0x24
// through their own +0x24, and a layout draws while its byte +0x14 has bit 1 and neither 0x0C nor 0x20
// (docs/port/local-versus.md, "The HUD"). A layout's sprite list starts at layout+0x3C: a chain of 0x14-byte
// nodes {object, id, key, next, prev}, the object being the sprite itself.
//
// This wraps that draw and moves the character HUD's layouts (table kPieces) to the Battle HUD settings: their
// size, the side space and the lift. Nothing else on the screen is touched, so BREAK, THE FINAL BLOW, the EX
// Core and EX Revenge leave the HUD as it is.
//
#include "../../third_party/dissidia012-pc/port/host/d012_decomp_harness.hpp"

#include "settings/settings.hpp"
#include "kernel/kernel.hpp"

#if __has_include(<SDL3/SDL.h>)
#include <SDL3/SDL.h>
#endif

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

extern float g_d012_roster_cells[40][2];  // vulkan_renderer.cpp
extern int g_d012_roster_count;

namespace {

using d012::decomp::CallState;  // Guest and GuestRegs come from the decompiled-code header, at global scope

constexpr std::uint32_t kMenuDraw = 0x088CED50u;

// ---------------------------------------------------------------------------------------------------------
// THE LAYOUTS OF THE BATTLE SCREEN, by what names them (the layout's resource: kind at +0x68, id at +0x66; the
// layout's own address changes every run). Found by tracing the game's layouts in battle: the pieces marked `scale` are the ones the HUD size, side space and lift settings move; the rest are
// left exactly as the game draws them, whatever the screen does (BREAK, THE FINAL BLOW, EX Core, EX Revenge).
// To change what is scaled, change `scale` here. `how sure` says what the label rests on.
struct HudPiece {
    std::uint8_t kind;
    std::uint16_t id;
    bool scale;
    const char *label;  // for people; how sure is in it
    bool left = false;  // scaled about the bottom-left corner as one block (roster grid), by the markers only
    std::uint8_t mode = 0;  // 0x13: about the left edge keeping each quad's height; 0x14: right side, upper part at the top
};

constexpr HudPiece kPieces[] = {
    // Drawn with sprites at the screen's edges, and hidden together with everything else of the HUD while a
    // cut-in (THE FINAL BLOW, EX Revenge) takes the screen. Seen in battle: all of them.
    {1, 0x0218, true, "HUD, main part: 2 layouts, 13 sprites (0,0 to 480,272) and 2 sprites (480,272 and 0,272). Sure it is HUD; what it draws exactly: not named"},
    {1, 0x021A, true, "HUD, 5 sprites at the left and right bottom corners. Sure it is HUD; what it draws exactly: not named"},
    {1, 0x0216, true, "HUD, 2 layouts of 1 sprite each, one per side, y = 288 (just below the screen, so it slides in). Sure it is HUD; not named"},
    {1, 0x0256, true, "HUD, 16 sprites around (413,257), the bottom right. Sure it is HUD; not named"},
    {1, 0x0220, true, "3 sprites at (0,0), hidden with the HUD. Probably HUD; not named"},
    // Found in battle captures: these draw the BRV numbers and a bottom strip.
    // Found in the second round of captures: the summon stone and the AP Chance and Save Replay messages.
    {1, 0x0204, true, "Summon stone frame (x 311..334, y 223..245 in a capture)"},
    {0, 0xFFFF, true, "Status icons over the HP bar and, while an EX Finisher input is up (layout 0x0248 has a sprite), that finisher's gauge or command input (left unscaled, see mark_layout)"},
    {1, 0x0224, true, "AP Chance (bottom right) and RULES (upper right, scaled about the top right)", false, 0x14},
    {1, 0x0254, true, "Save Replay bar and its text: scaled about the left edge, keeping its height", false, 0x13},
    {0xFE, 0x1002, true, "The HP numbers (6999 / 1000 at the bottom): a layout without a resource, 2 to 24 slots behind 0x0256. After a few battles the skill-name message sits at that distance too (frame, caps and text, x 177..303), so it takes the same mode as 0x1010..0x1FFE: digits low on the screen, and the message as one piece", false, 0x18},
    // These also draw message boxes ("Cross-Slash", "Skip cutscene?"), so only their small digits low on the screen scale.
    {0xFE, 0x1010, true, "Resource-less layout 25..64 slots behind 0x0256: only digits low on the screen", false, 0x18},
    {0xFE, 0x1020, true, "Resource-less layout ahead of 0x0256: only digits low on the screen", false, 0x18},
    {0xFE, 0x1FFE, true, "Other resource-less layouts: the skill-name message at the top (x 176..304, y 8..40); only that scales, in place", false, 0x18},
    {1, 0x0200, true, "Floating numbers, and the BREAK word (62 x 26, near the BRV): only big quads low on the screen", false, 0x15},
    {1, 0x0238, true, "Big BRV number at the left (x 57..148, y 205..250 in a capture)"},
    {1, 0x0206, true, "BRV number at the right (x 366..427, y 195..262 in a capture)"},
    {1, 0x0214, true, "Bottom strip (x 121..416, y 209..270 in a capture); HP bar corners or stage BRV frame: not named"},
    // Quick Battle player select (kind 29): the roster grid and its cursor frame, anchored bottom-left. The hand
    // (0x7222) is not listed, so it keeps its size.
    {29, 0x7220, true, "Roster squares (x 28..348, y 113..269 in a capture)", true},
    {29, 0x7228, true, "Roster cursor frame: moved by the renderer to the new place of its cell", false, 0x16},
    {29, 0x722A, true, "Party roster right panel, slot rows: 85% about the middle of the right edge", false, 0x19},
    {29, 0x7218, true, "Party roster portrait strips (x 354..480, y 67..226 in a capture): same panel scale", false, 0x19},
    {29, 0x722E, true, "Party roster right panel, frame: same", false, 0x19},
    {30, 0x163E, true, "Story Mode party panel frame (low 13 bits of the id): same panel scale", false, 0x19},
    {30, 0x163C, true, "Story Mode party panel slot rows: same", false, 0x19},
    {30, 0x161E, true, "Story Mode party panel portrait strips: same", false, 0x19},
    {29, 0x7222, true, "Roster hand: follows the frame, keeps its size", false, 0x17},
    // Hidden with the HUD but with no sprites of their own (their parts are drawn by the text routine): nothing
    // for the scaling to move here.
    {1, 0x0208, true, "No sprites, hidden with the HUD (drawn by a callback of its own): part of the HUD"},
    {1, 0x0212, true, "Hidden with the HUD, and 2 sprites that come and go on their own at times: part of the HUD"},
    {1, 0x0258, true, "The ASSIST bar when an assist is called (a sprite at the middle of the screen then; none otherwise)", false, 0x1D},
    // Story Mode Chess and Open World screens: the corner HUD (found with the layout log). Only while that HUD is
    // on screen (g_corner_hud); the map splash uses the same ids at a large sprite scale.
    {4, 0x1208, true, "Chess / Open World corner HUD", false, 0x1A}, {4, 0x120A, true, "Chess / Open World corner HUD", false, 0x1A},
    {4, 0x120C, true, "Chess / Open World corner HUD", false, 0x1A}, {4, 0x120E, true, "Map description box", false, 0x1B},
    {4, 0x1212, true, "Chess / Open World corner HUD", false, 0x1A}, {4, 0x1214, true, "Chess / Open World corner HUD", false, 0x1A},
    {4, 0x121A, true, "Chess / Open World corner HUD", false, 0x1A}, {4, 0x121C, true, "Chess / Open World corner HUD", false, 0x1A},
    {4, 0x122C, true, "Chess / Open World corner HUD", false, 0x1A},
    {36, 0x8A08, true, "Open World corner HUD", false, 0x1A}, {36, 0x8A0A, true, "Open World corner HUD", false, 0x1A},
    {36, 0x8A0C, true, "Open World corner HUD", false, 0x1A}, {36, 0x8A12, true, "Open World corner HUD", false, 0x1A},
    {36, 0x8A14, true, "Open World corner HUD", false, 0x1A}, {36, 0x8A16, true, "Open World corner HUD", false, 0x1A},
    {36, 0x8A1E, true, "Open World corner HUD", false, 0x1A},
    // Kind 4 0x1216 (Chess only: the KP gained banner with its "2 KP" and the chain icon) is left as the game draws it: the
    // banner is a band across the whole screen made of several quads, and scaling them about a corner broke it apart.
    // The map's description boxes (gate / skill): drawn by one layout whose place changes (left or right).
    {4, 0x1210, true, "Map description box (text part)", false, 0x1B}, {36, 0x8A10, true, "Map description box", false, 0x1B},
    {36, 0x8A0E, true, "Map description box", false, 0x1B},
    // The top message bar ("Cannot hold more skills. Select a skill to discard."): moved down a little.
    {36, 0x8A00, true, "Top message bar", false, 0x1C}, {36, 0x8A18, true, "Top message bar", false, 0x1C},
    {4, 0x1200, true, "Top message bar", false, 0x1C}, {4, 0x1218, true, "Top message bar", false, 0x1C},
    // Never scaled.
    {1, 0x0222, false, "The lock-on cursor: pinned to the world, not to the screen"},
    {1, 0x0226, false, "3 sprites at the screen centre (240,136): a centre banner, shown while the HUD is"},
    {1, 0x0236, false, "Appears while the HUD is hidden (a cut-in)"},
    {1, 0x024A, false, "Priority C8, drawn over everything"},
    {1, 0x024C, false, "Priority C7, drawn over everything"},
    {1, 0x024E, false, "Priority C7, drawn over everything"},
};

// What names a layout from run to run: its resource's kind and id .
// Whether `length` bytes at a guest address are inside the game's RAM. The layout lists are walked on every menu draw, and
// a screen whose manager is not the kind expected (Customization) has other values where a pointer would be.
bool in_guest(Guest *g, std::uint32_t address, std::uint32_t length) {
    const std::uint32_t offset = (address & 0x1FFFFFFFu) - GUEST_RAM_BASE;
    return offset < g->ram_size && g->ram_size - offset >= length;
}

void layout_name(Guest *g, std::uint32_t layout, std::uint8_t &kind, std::uint16_t &id) {
    kind = 0xFFu;  // not a layout: no name
    id = 0xFFFFu;
    if (!in_guest(g, layout, 0x30u)) return;
    const std::uint32_t resource = g_ld32(g, layout + 0x0Cu);
    if (resource != 0u && !in_guest(g, resource, 0x70u)) return;
    if (resource == 0u) {
        // A layout without a resource (text and number layouts) has no callback either. Its address changes
        // with the battle (the layouts sit in a pool whose order follows the layout ids), so it is named by its
        // distance, in 0x2C-byte slots, behind the layout of kind 1 id 0x256: kind 0xFE, id 0x1000 + slots.
        // In captures the two number layouts of the HUD are 2 and 4 slots behind it.
        kind = 0xFEu;
        id = 0x1FFEu;
        auto is_0256 = [&](std::uint32_t other) {
            if (!in_guest(g, other, 0x30u)) return false;
            const std::uint32_t other_resource = g_ld32(g, other + 0x0Cu);
            if (other_resource < 0x08000000u || other_resource >= 0x0A000000u) return false;
            return g_ld8(g, other_resource + 0x68u) == 1u && g_ld16s(g, other_resource + 0x66u) == 0x0256;
        };
        // 1..24 slots behind it: the HP numbers of the captures (id 0x1002). Further behind (25..64) and ahead of it
        // (1..64) the same pool holds the other layouts without a resource: 0x1010 and 0x1020.
        for (std::uint32_t slots = 1; slots <= 64u && id == 0x1FFEu; ++slots)
            if (is_0256(layout - slots * 0x2Cu)) id = slots <= 24u ? (slots >= 2u ? 0x1002u : 0x1001u) : 0x1010u;
        for (std::uint32_t slots = 1; slots <= 64u && id == 0x1FFEu; ++slots)
            if (is_0256(layout + slots * 0x2Cu)) id = 0x1020u;
        return;
    }
    kind = g_ld8(g, resource + 0x68u);
    id = static_cast<std::uint16_t>(g_ld16s(g, resource + 0x66u));
}

// The select screens (Quick Battle player and CPU select, Labyrinth character select) draw their grid with the same
// three layouts: a cell per position, the cursor frame, and the hand. Kind 29 ids 0x7220 / 0x7228 / 0x7222;
// the Labyrinth screen is kind 34 with ids whose low 13 bits are 0x636 / 0x63E / 0x638 (the box trace prints 13).
// 1: cell, 2: frame, 3: hand, 0: not one of them. The party screen uses the cell layout for five small icons and
// the CPU screen's confirmation prompt is drawn by the hand layout, so everything below only applies while a
// full grid is on screen (g_roster_active, set by place_roster).
bool g_roster_active = false;
std::map<std::uint32_t, unsigned> g_roster_position;  // cell layout -> its position index, set by place_roster

int roster_role(std::uint8_t kind, std::uint16_t id) {
    if (kind == 29u) return id == 0x7220u ? 1 : id == 0x7228u ? 2 : id == 0x7222u ? 3 : 0;
    if (kind == 34u) {
        const unsigned low = id & 0x1FFFu;
        return low == 0x636u ? 1 : low == 0x63Eu ? 2 : low == 0x638u ? 3 : 0;
    }
    // Original Quest character select (kind 26) and the Story Mode party screens (kind 30): the same three layouts,
    // named by the low 13 bits the box trace prints (cell, frame, hand).
    if (kind == 26u) {
        const unsigned low = id & 0x1FFFu;
        return low == 0x640u ? 1 : low == 0x644u ? 2 : low == 0x636u ? 3 : 0;
    }
    if (kind == 30u) {
        const unsigned low = id & 0x1FFFu;
        return low == 0x162Au ? 1 : low == 0x1638u ? 2 : low == 0x1634u ? 3 : 0;
    }
    return 0;
}

// What the menu manager is drawing, set at the start of each draw: the battle HUD (a kind 1 layout 0x0218 or 0x0256
// is drawn) or the Chess / Open World corner HUD. Resource-less layouts (kind 0 and 0xFE) also draw Story Mode
// dialogue, the Skip Cutscene menu and the Limit bar outside battle, so they only scale in battle; the corner
// layouts (kind 4 and 36) only while their sprites are at normal size (the map splash draws them at 7x).
bool g_battle_hud = false;
bool g_corner_hud = false;
bool g_limit_prompt = false;  // an EX Finisher input is up (kind 1 layout 0x0248 has a sprite on screen)

bool piece_active(std::uint8_t kind) {
    if (kind == 0u || kind == 0xFEu) return g_battle_hud;
    if (kind == 4u || kind == 36u) return g_corner_hud;
    return true;
}

// Is `layout` one of the scaled pieces? Looked up by its resource, so it holds across runs.
bool is_hud_layout(Guest *g, std::uint32_t layout) {
    std::uint8_t kind;
    std::uint16_t id;
    layout_name(g, layout, kind, id);
    for (const HudPiece &piece : kPieces)
        if (piece.kind == kind && piece.id == id) return piece.scale && !piece.left && piece_active(kind);
    return false;
}

// The special scaling mode of `layout` (HudPiece::mode), 0 for none.
std::uint8_t layout_mode(Guest *g, std::uint32_t layout) {
    std::uint8_t kind;
    std::uint16_t id;
    layout_name(g, layout, kind, id);
    for (const HudPiece &piece : kPieces)
        if (piece.kind == kind && piece.id == id) return piece.scale && piece_active(kind) ? piece.mode : 0u;
    // The Story Mode party panel (kind 30) is known by the low 13 bits of its ids only.
    for (const HudPiece &piece : kPieces)
        if (piece.mode == 0x19u && piece.kind == kind && (piece.id & 0x1FFFu) == (static_cast<unsigned>(id) & 0x1FFFu)) return piece.mode;
    return 0u;
}

// Is `layout` a piece scaled about the bottom-left corner? Only the markers act on these.
bool is_left_layout(Guest *g, std::uint32_t layout) {
    std::uint8_t kind;
    std::uint16_t id;
    layout_name(g, layout, kind, id);
    for (const HudPiece &piece : kPieces)
        if (piece.kind == kind && piece.id == id) return piece.scale && piece.left;
    return false;
}

struct HudParams {
    float scale, lift, side;
};

// The in-game menu's Battle HUD settings, read every draw so a change shows at once.
HudParams hud_params() {
    const portablekit::settings::Settings &s = portablekit::settings::current();
    return {std::fmin(1.0f, std::fmax(0.5f, static_cast<float>(s.hud_scale) / 100.0f)),
            static_cast<float>(s.hud_margin), static_cast<float>(s.hud_side_margin)};
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
// ---------------------------------------------------------------------------------------------------------
// MARKERS IN THE DISPLAY LIST. The menu manager draws its layouts one after the other, each into the frame's
// display list (libGu's context at 0x09AF6830, write cursor at +8; FUN_089A00F4 reserves from it). A layout
// with sprites builds its elements (FUN_088DBE64, called once per sprite with the layout in $a0) and then writes
// its commands; a layout with a callback (+0x10 zero) is drawn by FUN_088DB318(layout, index). So the first call
// of either for a layout is where its commands begin, and the first call for the next layout, or the end of the
// whole draw (FUN_088CED50), is where they end. A NOP with the port's marker tag is written at each of those
// places for each layout that kPieces lists as scaled; the renderer scales the draws between a begin and an end
// marker (VulkanRenderer::kMarkerHudBegin and kMarkerHudEnd) and no others.
constexpr std::uint32_t kGuContext = 0x09AF6830u;
constexpr std::uint32_t kMarkerHudBegin = 0x00A50010u;
constexpr std::uint32_t kMarkerHudEnd = 0x00A50011u;
constexpr std::uint32_t kMarkerHudBeginLeft = 0x00A50012u;
constexpr std::uint32_t kMarkerHudBeginLeftMid = 0x00A50013u;
constexpr std::uint32_t kMarkerHudBeginRightSplit = 0x00A50014u;
constexpr std::uint32_t kMarkerHudBeginBigLow = 0x00A50015u;
constexpr std::uint32_t kMarkerHudBeginRosterFrame = 0x00A50016u;
constexpr std::uint32_t kMarkerHudBeginSmallLow = 0x00A50018u;
constexpr std::uint32_t kMarkerHudBeginPanelRight = 0x00A50019u;
constexpr std::uint32_t kMarkerHudBeginCorner = 0x00A5001Au;
constexpr std::uint32_t kMarkerHudBeginBox = 0x00A5001Bu;
constexpr std::uint32_t kMarkerHudBeginBanner = 0x00A5001Cu;
constexpr std::uint32_t kMarkerHudBeginNotice = 0x00A5001Du;
constexpr std::uint32_t kMarkerHudBeginKeepBig = 0x00A5001Eu;
constexpr std::uint32_t kMarkerHudBeginRosterHand = 0x00A50017u;
constexpr std::uint32_t kCallbackLayoutDraw = 0x088DB318u;  // FUN_088DB318(layout, index)
struct MarkState {
    std::uint32_t layout = 0;  // the layout whose first call came last
    bool open = false;         // its begin marker is in the list
};

MarkState &mark_state() {
    static MarkState state;
    return state;
}

// Markers are only needed while the Battle HUD settings change something.
bool markers_wanted() {
    const HudParams hud = hud_params();
    return (hud.scale < 1.0f || hud.lift > 0.0f || hud.side > 0.0f);
}

void emit_word(Guest *g, std::uint32_t word) {
    const std::uint32_t context = g_ld32(g, kGuContext);
    const std::uint32_t cursor = g_ld32(g, context + 8u);
    g_st32(g, cursor, word);
    g_st32(g, context + 8u, cursor + 4u);
}

void mark_end(Guest *g) {
    MarkState &state = mark_state();
    if (state.open) emit_word(g, kMarkerHudEnd);
    state.open = false;
}

std::uint32_t layout_kind_for_marker(Guest *g, std::uint32_t layout) {
    std::uint8_t kind;
    std::uint16_t id;
    layout_name(g, layout, kind, id);
    return kind;
}
std::uint32_t layout_id_for_marker(Guest *g, std::uint32_t layout) {
    std::uint8_t kind;
    std::uint16_t id;
    layout_name(g, layout, kind, id);
    return id;
}

// Sprites of a layout that are on screen (scale above 0): the sprite chain starts at the layout's first word and is linked
// through +0x3C.
unsigned active_sprites(Guest *g, std::uint32_t layout) {
    unsigned count = 0;
    const std::uint32_t first = in_guest(g, layout, 0x30u) ? g_ld32(g, layout) : 0u;
    for (std::uint32_t s = first, n = 0; s != 0u && n < 64u && in_guest(g, s, 0x40u); s = g_ld32(g, s + 0x3Cu), ++n)
        if (load_float(g, s + 0x18u) > 0.0f) ++count;
    return count;
}

// A call of the layout draw functions for `layout`: the first one for a layout ends the last one's span and,
// for a scaled layout, begins its own.
void mark_layout(Guest *g, std::uint32_t layout) {
    MarkState &state = mark_state();
    if (layout == state.layout) return;
    mark_end(g);
    state.layout = layout;
    const std::uint8_t mode_any = layout_mode(g, layout);
    const std::uint8_t mode = (markers_wanted() || (mode_any >= 0x16u && mode_any <= 0x17u) || mode_any == 0x19u) ? mode_any : 0u;  // the roster and the Party panel do not depend on the HUD settings
    bool left = is_left_layout(g, layout);  // fixed size: not tied to the Battle HUD settings
    std::uint8_t mode_final = mode;
    {
        std::uint8_t kind;
        std::uint16_t id;
        layout_name(g, layout, kind, id);
        const int role = roster_role(kind, id);
        if (role != 0) {
            left = false;
            mode_final = 0;
            if (g_roster_active) {
                // The hand layout has several sprites even when only the hand shows, so the renderer picks the hand
                // quad by its size and only follows a frame drawn this frame or the one before.
                if (role == 1) left = true;
                else if (role == 2) mode_final = 0x16u;
                else if (role == 3) mode_final = 0x17u;
            }
        }
    }
    // The panel layouts (mode 0x19) are only the Party panel next to a roster grid: the pre-battle party screen
    // draws its portrait strips with the same layout (kind 29 id 0x7218) and must not be touched.
    if (mode_final == 0x19u && !g_roster_active) mode_final = 0u;
    std::uint8_t role_kind;
    std::uint16_t role_id;
    layout_name(g, layout, role_kind, role_id);
    const bool is_roster_layout = roster_role(role_kind, role_id) != 0;
    // Layout kind 0 id 0xFFFF draws the status icons over the HP bars (also animated ones, with many quads) and, while an EX
    // Finisher input is up, that finisher's gauge or command input (every character's own). During a finisher it is left as the
    // game draws it; the rest of the time it scales.
    if (role_kind == 0u && role_id == 0xFFFFu && mode_final == 0u && !left && g_limit_prompt) mode_final = 0x1Eu;
    const bool scaled = left || mode_final != 0u || (!is_roster_layout && markers_wanted() && is_hud_layout(g, layout));
    if (!scaled) return;
    emit_word(g, mode_final == 0x13u ? kMarkerHudBeginLeftMid : mode_final == 0x14u ? kMarkerHudBeginRightSplit : mode_final == 0x15u ? kMarkerHudBeginBigLow : mode_final == 0x16u ? kMarkerHudBeginRosterFrame : mode_final == 0x17u ? kMarkerHudBeginRosterHand : mode_final == 0x18u ? kMarkerHudBeginSmallLow : mode_final == 0x19u ? kMarkerHudBeginPanelRight : mode_final == 0x1Au ? kMarkerHudBeginCorner : mode_final == 0x1Bu ? kMarkerHudBeginBox : mode_final == 0x1Cu ? kMarkerHudBeginBanner : mode_final == 0x1Du ? kMarkerHudBeginNotice : mode_final == 0x1Eu ? kMarkerHudBeginKeepBig : left ? kMarkerHudBeginLeft : kMarkerHudBegin);
    state.open = true;
    // For the quad dump (hud_quads.txt): which layout this span is. Two extra markers, only while tracing.
    static const bool tracing = std::getenv("D012_TRACE_HUD_LAYOUTS") != nullptr;
    if (tracing) {
        emit_word(g, 0x00A50000u | (0x3000u + layout_kind_for_marker(g, layout)));
        emit_word(g, 0x00A50000u | (0x4000u + (layout_id_for_marker(g, layout) & 0x3FFFu)));
    }
}

void run_callback_layout_draw(Guest *g, const CallState &in, GuestRegs &out) {
    mark_layout(g, in.gpr[4]);
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kCallbackLayoutDraw, regs);
    out = regs;
}

// The Quick Battle roster as two rows of 16. The select screen has one layout (kind 29, id 0x7220) per grid
// position, in position order, each with one sprite. The game keeps its own 6 / 10 / 10 / 6 geometry; for the
// draw only, the sprites are put on two rows (x = 28 + 32 * column, y = 113 or 152), and put back afterwards,
// so the game's logic still sees what it made. The cursor frame (kind 29 id 0x7228) and the hand (0x7222)
// are moved with the cell the frame is on: the frame to that cell's new place, the hand by the same step as
// the frame appears on screen after the renderer's shrink (0.65 about (7, 203), see hud_anchor_left).
struct RosterSaved {
    std::uint32_t sprite;
    float x, y;
};

void roster_new_position(unsigned position, float &x, float &y) {
    // Two rows of 16; the CPU Select screen has one more cell (boss Chaos), which makes the second row 17 long
    // (Random goes after Chaos), so the column of the second row is not wrapped.
    const unsigned row = position < 16u ? 0u : 1u;
    x = 28.0f + 32.0f * static_cast<float>(position - 16u * row);
    y = 113.0f + 39.0f * static_cast<float>(row);
}

void place_roster(Guest *g, std::uint32_t manager, std::vector<RosterSaved> &saved) {
    std::vector<std::pair<float, float>> cells;  // the game's own position of each cell (top-left of its sprite)
    std::vector<std::uint32_t> frame_sprites, hand_sprites;
    unsigned cell_layouts = 0;
    unsigned layouts = 0;
    if (!in_guest(g, manager, 0x28u)) return;
    for (std::uint32_t layout = g_ld32(g, manager + 0x24u); layout != 0u && layouts < 512u && in_guest(g, layout, 0x30u);
         layout = g_ld32(g, layout + 0x24u), ++layouts) {
        std::uint8_t kind;
        std::uint16_t id;
        layout_name(g, layout, kind, id);
        const int role = roster_role(kind, id);
        if (role == 0) continue;
        // Every cell layout counts, drawn or not: the Party roster hides the cells that scroll out of its window, and
        // counting only the drawn ones switched the handling off after the first frame. The party icons screen is
        // told apart by the renderer, from the number of cells it really draws.
        if (role == 1) ++cell_layouts;
        const std::uint32_t sprite = g_ld32(g, layout);
        if (sprite == 0u || !in_guest(g, sprite, 0x40u)) continue;
        if (role == 1) cells.emplace_back(load_float(g, sprite + 0x10u), load_float(g, sprite + 0x14u));
        else if (role == 2) {
            for (std::uint32_t s = sprite, n = 0; s != 0u && n < 64u && in_guest(g, s, 0x40u); s = g_ld32(g, s + 0x3Cu), ++n)
                frame_sprites.push_back(s);
        } else if (role == 3) {
            for (std::uint32_t s = sprite, n = 0; s != 0u && n < 64u && in_guest(g, s, 0x40u); s = g_ld32(g, s + 0x3Cu), ++n)
                hand_sprites.push_back(s);
        }
    }
    // The character description on hover (see L_08A84464 in the menu overlay's generated_unit_0041.cpp): the text is built
    // and shown, but its sprite keeps the flags of the hover state (0xFFFF0412) and is drawn small-left (lines centred at x = 3,
    // 1.7 times too big). In the confirmation state the same sprite has 0xFFFF841B and sits right. Same flags here.
    if (!hand_sprites.empty() && load_float(g, hand_sprites[0] + 0x10u) == 3.0f && load_float(g, hand_sprites[0] + 0x14u) == 119.0f)
        g_st32(g, hand_sprites[0] + 0x20u, 0xFFFF841Bu);
    // Only the Quick Battle / Labyrinth geometry (rows of 6, 10, 10, 6 starting at x = 92, 28, 28, 92). The Party roster
    // (rows of 11 and 22, the first cell at x = 188) has its own geometry and is left as the game draws it for now.
    // Any full grid (Quick Battle, CPU, Labyrinth, Party) has its cell layouts at the resource's positions: the first
    // six on one row from x = 92, the next at x = 28 one row lower. The party icons screen (five icons, same layouts)
    // does not, and is left alone.
    g_roster_active = cell_layouts >= 20u && cells.size() >= 7u && cells[0].first == 92.0f && cells[0].second == 113.0f &&
                      cells[6].first == 28.0f && cells[6].second == 152.0f;
    if (!g_roster_active) return;
    // The renderer places the cells, the frame and the hand from what the game draws (kMarkerHudBeginLeft cells
    // tagged with their position, kMarkerHudBeginRosterFrame / Hand). Here only the position of each cell layout is
    // recorded, for mark_layout: the cells are in position order in the manager's list.
    g_roster_position.clear();
    unsigned position = 0, layouts2 = 0;
    for (std::uint32_t layout = g_ld32(g, manager + 0x24u); layout != 0u && layouts2 < 512u && in_guest(g, layout, 0x30u);
         layout = g_ld32(g, layout + 0x24u), ++layouts2) {
        std::uint8_t kind;
        std::uint16_t id;
        layout_name(g, layout, kind, id);
        if (roster_role(kind, id) != 1) continue;
        // The position is the rank among the cells that draw: the Party roster keeps five unused cell layouts at the
        // start of the list, and counting them put its first cell in the sixth column (the 11 + 22 shape).
        const std::uint8_t flags = g_ld8(g, layout + 0x14u);
        if ((flags & 1u) == 0u || (flags & 0x2Cu) != 0u) continue;
        g_roster_position[layout] = position++;
    }
    (void)saved;
}

// The select screen's layout table (menu overlay 0x08A864D0: 33 rows of 6 s16, the character id in the fifth) is
// what orders the roster: the grid takes the rows in table order. This puts the rows in the order of the
// mockup (two rows of 16), keeping each row whole. Done from here, every frame, because the overlay's code is
// not touched: the table is only rewritten while its content is recognised as the select table (the last row
// is Random, {-1, -1, 12, 0, 0, 0}, and rows 0..31 hold the 32 character ids), so another overlay at the same
// addresses is left alone.
void order_roster_table(Guest *g) {
    constexpr std::uint32_t kTable = 0x08A864D0u;
    static const std::int16_t order[32] = {0x01, 0x03, 0x05, 0x07, 0x18, 0x09, 0x0B, 0x0D, 0x1A, 0x0F, 0x1B,
                                           0x11, 0x13, 0x1C, 0x1E, 0x1F, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C,
                                           0x0E, 0x10, 0x12, 0x14, 0x16, 0x19, 0x20, 0x15, 0x1D, 0x17};
    if (g_ld16s(g, kTable + 32u * 12u) != -1 || g_ld16s(g, kTable + 32u * 12u + 2u) != -1 ||
        g_ld16s(g, kTable + 32u * 12u + 4u) != 12)
        return;
    std::int16_t rows[32][6];
    unsigned seen_mask_hi = 0;
    for (unsigned r = 0; r < 32u; ++r) {
        for (unsigned c = 0; c < 6u; ++c) rows[r][c] = g_ld16s(g, kTable + r * 12u + c * 2u);
        const int id = rows[r][4];
        if (id < 1 || id > 0x20) return;
        if (id >= 32) seen_mask_hi |= 1u << (id - 32);
    }
    if (rows[0][4] == order[0] && rows[31][4] == order[31]) return;  // already in the new order
    if (seen_mask_hi != 1u) return;                                    // 0x20 once
    std::int16_t sorted[32][6];
    for (unsigned r = 0; r < 32u; ++r) {
        bool found = false;
        for (unsigned src = 0; src < 32u && !found; ++src) {
            if (rows[src][4] != order[r]) continue;
            for (unsigned c = 0; c < 6u; ++c) sorted[r][c] = rows[src][c];
            found = true;
        }
        if (!found) return;
    }
    for (unsigned r = 0; r < 32u; ++r)
        for (unsigned c = 0; c < 6u; ++c) g_st16(g, kTable + r * 12u + c * 2u, static_cast<std::uint16_t>(sorted[r][c]));
}

// D012_TRACE_HUD_LAYOUTS=1: each press of F10 appends one block to d012_hud_layouts.log (the file is never rewritten)
// with the layouts the menu manager draws at that moment: kind, id, whether kPieces scales it, and the first sprite's
// position and scale. To name what a screen (a Story Mode dialogue, a splash image, the Skip Cutscene menu) is made of,
// press F10 while it is on screen.
void trace_layouts(Guest *g, std::uint32_t manager) {
    static const bool enabled = std::getenv("D012_TRACE_HUD_LAYOUTS") != nullptr;
    static unsigned frame = 0, blocks = 0;
    static bool was_down = false;
    ++frame;
    if (!enabled) return;
    bool down = false;
#if __has_include(<SDL3/SDL.h>)
    if (const bool *keys = SDL_GetKeyboardState(nullptr)) down = keys[SDL_SCANCODE_F10];
#endif
    const bool pressed = down && !was_down;
    was_down = down;
    if (!pressed || !in_guest(g, manager, 0x28u)) return;
    std::string text;
    char line[200];
    unsigned layouts = 0;
    for (std::uint32_t layout = g_ld32(g, manager + 0x24u); layout != 0u && layouts < 512u && in_guest(g, layout, 0x30u);
         layout = g_ld32(g, layout + 0x24u), ++layouts) {
        const std::uint8_t flags = g_ld8(g, layout + 0x14u);
        if ((flags & 1u) == 0u || (flags & 0x2Cu) != 0u) continue;  // the draw's own test: not drawn
        std::uint8_t kind;
        std::uint16_t id;
        layout_name(g, layout, kind, id);
        bool scaled = false;
        for (const HudPiece &piece : kPieces)
            if (piece.kind == kind && piece.id == id && piece.scale) scaled = true;
        float x = 0, y = 0, sx = 0, sy = 0;
        const std::uint32_t sprite = g_ld32(g, layout);
        if (sprite != 0u && in_guest(g, sprite, 0x40u)) {
            x = load_float(g, sprite + 0x10u);
            y = load_float(g, sprite + 0x14u);
            sx = load_float(g, sprite + 0x18u);
            sy = load_float(g, sprite + 0x1Cu);
        }
        std::snprintf(line, sizeof line, "  kind %u id 0x%04X %s mode 0x%02X sprites %u sprite0 (%.0f,%.0f) scale (%.2f,%.2f)\n",
                      static_cast<unsigned>(kind), static_cast<unsigned>(id), scaled ? "SCALED" : "-     ",
                      static_cast<unsigned>(layout_mode(g, layout)), active_sprites(g, layout), x, y, sx, sy);
        text += line;
    }
    ++blocks;
    std::error_code logs_error;
    std::filesystem::create_directories("logs", logs_error);
    if (std::FILE *out = std::fopen("logs/d012_hud_layouts.log", "ab")) {
        std::fprintf(out, "snapshot %u, frame %u (%u layouts in the list)\n%s", blocks, frame, layouts, text.c_str());
        std::fclose(out);
    }
}

void detect_scene(Guest *g, std::uint32_t manager) {
    g_battle_hud = false;
    g_corner_hud = false;
    g_limit_prompt = false;
    if (!in_guest(g, manager, 0x28u)) return;
    unsigned layouts = 0;
    for (std::uint32_t layout = g_ld32(g, manager + 0x24u); layout != 0u && layouts < 512u && in_guest(g, layout, 0x30u);
         layout = g_ld32(g, layout + 0x24u), ++layouts) {
        const std::uint8_t flags = g_ld8(g, layout + 0x14u);
        if ((flags & 1u) == 0u || (flags & 0x2Cu) != 0u) continue;
        if (g_ld32(g, layout + 0x0Cu) == 0u) continue;
        std::uint8_t kind;
        std::uint16_t id;
        layout_name(g, layout, kind, id);
        if (kind == 1u && (id == 0x0218u || id == 0x0256u)) g_battle_hud = true;
        // Layout kind 1 id 0x0248 has a sprite on screen (at 459,176 in captures) only while an EX Finisher input is up (every
        // character's own: mash, commands): in all the captures of the finishers and in none of the ordinary battles.
        if (kind == 1u && id == 0x0248u) {
            const std::uint32_t sprite = g_ld32(g, layout);
            if (sprite != 0u && in_guest(g, sprite, 0x40u) && load_float(g, sprite + 0x10u) > 0.0f) g_limit_prompt = true;
        }
        if ((kind == 4u && id == 0x120Cu) || (kind == 36u && id == 0x8A0Cu)) {
            const std::uint32_t sprite = g_ld32(g, layout);
            if (sprite != 0u && in_guest(g, sprite, 0x40u)) {
                const float sx = load_float(g, sprite + 0x18u);
                if (sx > 0.0f && sx < 2.0f) g_corner_hud = true;
            }
        }
    }
}

void run_menu_draw(Guest *g, const CallState &in, GuestRegs &) {
    mark_state() = MarkState{};
    detect_scene(g, in.gpr[4]);
    trace_layouts(g, in.gpr[4]);
    order_roster_table(g);
    g_roster_active = false;
    std::vector<RosterSaved> roster_saved;
    place_roster(g, in.gpr[4], roster_saved);
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, kMenuDraw, regs);
    mark_end(g);
    for (auto it = roster_saved.rbegin(); it != roster_saved.rend(); ++it) {
        store_float(g, it->sprite + 0x10u, it->x);
        store_float(g, it->sprite + 0x14u, it->y);
    }
}

// ---------------------------------------------------------------------------------------------------------
// FUN_088DBE64(float time, layout, animation, parent matrix, sprite): for one sprite of a layout, builds the
// element the draw will use: an 0x50-byte record appended to the array at *(manager+0x10) (count at
// manager+0x14), whose first 0x40 bytes from +0x10 are the sprite's 4x4 matrix (scale in [0] and [5],
// translation in [12] and [13], the parent matrix already multiplied in). This wraps it and changes the
// elements it just appended, which is the game's own placement data, before the original draw reads them.
//
// Which layouts change is the table kPieces above; the in-game menu's Battle HUD settings (size, side space,
// lift) set how.
constexpr std::uint32_t kSpriteDraw = 0x088DBE64u;

void run_sprite_draw(Guest *g, const CallState &in, GuestRegs &out) {
    mark_layout(g, in.gpr[4]);
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    regs.f[0] = in.fpr[12];
    d012::decomp::call_original(g, kSpriteDraw, regs);
    out = regs;
}

// D012_TRACE_COSTUME=1: appends to d012_costume.log every call of the functions that pick a fighter's object by (character,
// costume, assist), with the arguments and the answer, to see what costume number the menu hands the battle (the Emendatus
// Manikin outfit is costume 0). 0x088FB934 is the battle setup's, 0x088470DC the scan, 0x088D5E0C the menu's costume mask.
template <std::uint32_t Address>
void run_trace(Guest *g, const CallState &in, GuestRegs &out) {
    GuestRegs regs{};
    for (int i = 0; i < 8; ++i) regs.a[i] = in.gpr[4 + i];
    d012::decomp::call_original(g, Address, regs);
    out = regs;
    if (std::FILE *log = std::fopen("d012_costume.log", "ab")) {
        std::fprintf(log, "function 0x%08X a0 %u a1 %u a2 %u -> %d\n", Address, in.gpr[4], in.gpr[5], in.gpr[6],
                     static_cast<int>(regs.v0));
        std::fclose(log);
    }
}

struct Install {
    Install() {
        static const d012::decomp::Override overrides[] = {
            {kMenuDraw, "hud_menu_draw", d012::decomp::Module::Main, d012::decomp::Returns::Nothing, &run_menu_draw},
            {kSpriteDraw, "hud_sprite_draw", d012::decomp::Module::Main, d012::decomp::Returns::Integer,
             &run_sprite_draw},
            {kCallbackLayoutDraw, "hud_callback_layout_draw", d012::decomp::Module::Main,
             d012::decomp::Returns::Nothing, &run_callback_layout_draw},
        };
        d012::decomp::add_overrides(overrides, sizeof overrides / sizeof overrides[0], true);
        if (std::getenv("D012_TRACE_COSTUME") != nullptr) {
            static const d012::decomp::Override costume[] = {
                {0x088FB934u, "trace_lookup_fb934", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_trace<0x088FB934u>},
                {0x088D5E0Cu, "trace_mask_d5e0c", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_trace<0x088D5E0Cu>},
                {0x088F98E0u, "trace_setup_f98e0", d012::decomp::Module::Main, d012::decomp::Returns::Integer, &run_trace<0x088F98E0u>},
            };
            d012::decomp::add_overrides(costume, 3, true);
            std::fprintf(stderr, "[costume] tracing costume lookups into d012_costume.log\n");
        }
    }
} install;

} // namespace

// Whether a full select-screen grid is on screen (read by the roster model, d012_roster_model.cpp).
bool d012_roster_screen_active() { return g_roster_active; }

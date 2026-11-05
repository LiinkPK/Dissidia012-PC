// Remove Bloom (v1.0.2): the ghosting / bloom effect, gone for good.
//
// The known cheat patches the game's code at 0x089A17DC (a jump to a cave at 0x0880109C). A recompiled build
// does not run the bytes in memory, so the patch is made here instead: FUN_089A1770 (the 2D sprite packet
// builder, pseudocode/089A1770.c) as a native override that does what the original does, except that when
// its second argument ($a1, signed) is negative the three screen-coordinate halfwords at packet+0x14/0x16/0x18
// and the halfword at packet+0x12 are written as -4 (0xFFFC), exactly what the cave loads into $t7, $t0, $v1
// and $t6 before it jumps back to 0x089A17E4. The packet is then collapsed off screen.
//
// Calls from the function's own unit reach this override because 0x089A1770 is in port/config/dispatch-calls.txt;
// regenerate the main corpus after that change.
//
// D012_KEEP_BLOOM=1   the game's own function (bloom stays).

#include "d012_decomp_harness.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace d012::decomp {
namespace {

void run_sprite(Guest *g, const CallState &in, GuestRegs &) {
    const gaddr ctx = in.gpr[4];
    const std::int32_t p2_raw = static_cast<std::int32_t>(in.gpr[5]);
    const std::int16_t p2 = static_cast<std::int16_t>(in.gpr[5]);
    const std::int16_t p3 = static_cast<std::int16_t>(in.gpr[6]);
    const std::uint16_t p4 = static_cast<std::uint16_t>(in.gpr[7]);
    const std::int16_t p5 = static_cast<std::int16_t>(in.gpr[8]);
    const std::int16_t p6 = static_cast<std::int16_t>(in.gpr[9]);
    const std::uint32_t p7 = in.gpr[10];
    const std::int32_t p8 = static_cast<std::int32_t>(in.gpr[11]);
    const bool bloom_off = p2_raw < 0;

    const gaddr pk = g_ld32(g, ctx + 8);
    const std::int16_t off_bc = static_cast<std::int16_t>(g_ld32(g, ctx + 0xbc));
    const std::int16_t off_c0 = static_cast<std::int16_t>(g_ld32(g, ctx + 0xc0));
    const std::int16_t off_c4 = static_cast<std::int16_t>(g_ld32(g, ctx + 0xc4));
    const std::int16_t off_c8 = static_cast<std::int16_t>(g_ld32(g, ctx + 200));
    const gaddr next = pk + 28;
    const gaddr body = pk + 8;
    const std::int16_t s4 = static_cast<std::int16_t>(p5 + off_bc);

    g_st16(g, body, static_cast<std::uint16_t>(p5));
    g_st32(g, pk, (((next & 0xfffffff) >> 24) << 16) | 0x10000000u);
    g_st32(g, pk + 4, (next & 0xffffff) | 0x8000000u);
    g_st32(g, ctx + 8, next);
    std::uint16_t x14 = static_cast<std::uint16_t>(p6 + off_c0);
    std::uint16_t x16 = static_cast<std::uint16_t>(p2 + off_c4);
    std::uint16_t x18 = static_cast<std::uint16_t>(p3 + off_c8);
    std::uint16_t x12 = static_cast<std::uint16_t>(s4);
    if (bloom_off) x14 = x16 = x18 = x12 = 0xFFFCu;
    g_st16(g, pk + 0x14, x14);
    g_st16(g, pk + 0x16, x16);
    g_st16(g, pk + 0x18, x18);
    g_st16(g, pk + 0x1a, p4);
    g_st16(g, pk + 0x0a, static_cast<std::uint16_t>(p6));
    g_st16(g, pk + 0x0c, static_cast<std::uint16_t>(p2));
    g_st16(g, pk + 0x0e, static_cast<std::uint16_t>(p3));
    g_st16(g, pk + 0x10, p4);
    g_st16(g, pk + 0x12, x12);
    if ((p7 & 1) != 0) {
        const std::uint16_t old8 = static_cast<std::uint16_t>(g_ld32(g, body));
        g_st16(g, body, x12);
        g_st16(g, pk + 0x12, old8);
    }
    if (static_cast<std::int32_t>(p7 << 30) < 0) {
        const std::uint16_t old14 = static_cast<std::uint16_t>(g_ld32(g, pk + 0x14));
        g_st16(g, pk + 0x14, static_cast<std::uint16_t>(g_ld32(g, pk + 0x0a)));
        g_st16(g, pk + 0x0a, old14);
    }
    if (p8 == 1) {
        const std::uint16_t old18 = static_cast<std::uint16_t>(g_ld32(g, pk + 0x18));
        g_st16(g, pk + 0x18, static_cast<std::uint16_t>(g_ld32(g, pk + 0x0e)));
        g_st16(g, pk + 0x0e, old18);
    } else if (p8 >= 2) {
        if (p8 == 2) {
            const std::uint16_t u0e = static_cast<std::uint16_t>(g_ld32(g, pk + 0x0e));
            const std::uint16_t u16 = static_cast<std::uint16_t>(g_ld32(g, pk + 0x16));
            g_st16(g, pk + 0x16, static_cast<std::uint16_t>(g_ld32(g, pk + 0x0c)));
            g_st16(g, pk + 0x0c, u16);
            g_st16(g, pk + 0x0e, static_cast<std::uint16_t>(g_ld32(g, pk + 0x18)));
            g_st16(g, pk + 0x18, u0e);
        } else if (p8 == 3) {
            const std::uint16_t u16 = static_cast<std::uint16_t>(g_ld32(g, pk + 0x16));
            g_st16(g, pk + 0x16, static_cast<std::uint16_t>(g_ld32(g, pk + 0x0c)));
            g_st16(g, pk + 0x0c, u16);
        }
    }
    gaddr w = g_ld32(g, ctx + 8);
    g_st32(g, w, 0x12800102u);
    g_st32(g, ctx + 8, w + 4);
    w = w + 4;
    g_st32(g, w, (((body & 0xfffffff) >> 24) << 16) | 0x10000000u);
    g_st32(g, w + 4, (body & 0xffffff) | 0x1000000u);
    g_st32(g, ctx + 8, w + 8);
    w = g_ld32(g, ctx + 8);
    g_st32(g, w, 0x4060002u);
    g_st32(g, ctx + 8, w + 4);
}

const Override kSprite[] = {
    {0x089A1770u, "sprite_packet_no_bloom", Module::Main, Returns::Nothing, run_sprite},
};

struct Install {
    Install() {
        const char *keep = std::getenv("D012_KEEP_BLOOM");
        const bool wanted = keep == nullptr || *keep == '\0' || std::strcmp(keep, "0") == 0;
        add_overrides(kSprite, wanted ? 1 : 0, wanted);
    }
} install;

} // namespace
} // namespace d012::decomp

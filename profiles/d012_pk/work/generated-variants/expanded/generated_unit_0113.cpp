#include "psprecomp/corpus_abi.hpp"
#include "recomp_units.hpp"
#include <atomic>
#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>

namespace psprecomp {
static const std::uint16_t kEntryIds_recomp_unit_0113[18] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
};
void recomp_unit_0113_entry(CorpusRuntime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x089CB080u;
        entry_id = (entry_delta < 72u && (entry_delta & 3u) == 0u) ? kEntryIds_recomp_unit_0113[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_089CB080;
    case 2u: goto L_089CB084;
    case 3u: goto L_089CB088;
    case 4u: goto L_089CB08C;
    case 5u: goto L_089CB090;
    case 6u: goto L_089CB094;
    case 7u: goto L_089CB098;
    case 8u: goto L_089CB09C;
    case 9u: goto L_089CB0A0;
    case 10u: goto L_089CB0A4;
    case 11u: goto L_089CB0A8;
    case 12u: goto L_089CB0AC;
    case 13u: goto L_089CB0B0;
    case 14u: goto L_089CB0B4;
    case 15u: goto L_089CB0B8;
    case 16u: goto L_089CB0BC;
    case 17u: goto L_089CB0C0;
    case 18u: goto L_089CB0C4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_089CB080:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089CB084;
L_089CB084:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_089CB088;
L_089CB088:
    ctx.gpr[6] = (ctx.gpr[4] | 0u);
    goto L_089CB08C;
L_089CB08C:
    ctx.gpr[4] = (2205u << 16u);
    goto L_089CB090;
L_089CB090:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(-27680));
    goto L_089CB094;
L_089CB094:
    ctx.gpr[5] = (0u | 0u);
    goto L_089CB098;
L_089CB098:
    ctx.gpr[31] = (0x089CB0A0u);
    ctx.gpr[7] = (0u | 0u);
    ctx.pc = 0x089C5F38u;
    return;
L_089CB09C:
    ctx.gpr[7] = (0u | 0u);
    goto L_089CB0A0;
L_089CB0A0:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[2]) < 0;
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
      if (branch_taken) {
          goto L_089CB0C0;
      }
      goto L_089CB0A8;
    }
L_089CB0A4:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_089CB0A8;
L_089CB0A8:
    ctx.gpr[31] = (0x089CB0B0u);
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(4));
    ctx.pc = 0x089C5F20u;
    return;
L_089CB0AC:
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(4));
    goto L_089CB0B0;
L_089CB0B0:
    ctx.gpr[2] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_089CB0B4;
L_089CB0B4:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_089CB0B8;
L_089CB0B8:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089CB0BC:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_089CB0C0;
L_089CB0C0:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[2] = (0u | 0u);
      if (branch_taken) {
          goto L_089CB0B4;
      }
      (void)rt.invoke_chained_direct<&recomp_unit_0113, 113u>(ctx, &aot_mem); return;
    }
L_089CB0C4:
    ctx.gpr[2] = (0u | 0u);
    ctx.pc = 0x089CB0C8u; return;
}

void recomp_unit_0113(CorpusRuntime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    recomp_unit_0113_entry(rt, ctx, 0u, aot_mem);
}

void register_recomp_unit_113(CorpusRuntime &runtime) {
    runtime.register_generated_unit(113u, 0x089C8040u, 16384u, &recomp_unit_0113, &recomp_unit_0113_entry);
    runtime.register_function(0x089CB080u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB084u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB088u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB08Cu, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB090u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB094u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB098u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB09Cu, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0A0u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0A4u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0A8u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0ACu, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0B0u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0B4u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0B8u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0BCu, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0C0u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
    runtime.register_function(0x089CB0C4u, &recomp_unit_0113, "recomp_unit_recomp_unit_0113");
}
} // namespace psprecomp

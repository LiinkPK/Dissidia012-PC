// A trace for a crash at the start of an online battle: the game looks up the row of an equipped ability in the ability table
// (main:0x088B1D9C, system.bin/ablt) and uses the answer without checking it. When the table has no such ID the answer is 0
// and battle:0x08AB7FE0 reads address 0x0C. This wraps the lookup and logs, the first few times it answers 0 for an ID that is not -1:
// the ID, which player's setup block the caller walks (blocks of 0x1060 bytes from 0x09AFB8A0), the table's size and first ID, and
// the words of the block. It changes nothing: the lookup runs as before and its answer is passed on.
//
// Always on (it only prints when the lookup fails); D012_TRACE_ABILITY=0 turns it off.

#include "d012_ability_trace.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/corpus_abi.hpp"
#include "psprecomp/runtime.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace d012_ability_trace {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::CorpusRuntime;
using psprecomp::Runtime;

constexpr std::uint32_t kLookup = 0x088B1D9Cu;        // main: ability ID -> row of system.bin/ablt, or 0
constexpr std::uint32_t kTableHeader = 0x089D7290u;   // a word that holds a pointer; +8 of it is the number of rows
constexpr std::uint32_t kTablePointer = 0x089D7294u;  // a word that holds the pointer to the first row (rows of 0x28 bytes)
constexpr std::uint32_t kPlayerBlocks = 0x09AFB8A0u;  // the per-player battle setup blocks
constexpr std::uint32_t kPlayerBlockSize = 0x1060u;

Runtime::RecompiledFunction g_original = nullptr;
int g_logged = 0;

bool user_ram(std::uint32_t address) {
    const std::uint32_t a = address & 0x1FFFFFFFu;
    return a >= 0x08800000u && a < 0x0A000000u - 4u;
}

std::uint32_t word(Runtime &rt, std::uint32_t address) { return user_ram(address) ? rt.memory().load32(address) : 0u; }

void report(Runtime &rt, const AllegrexContext &ctx, std::uint32_t id, std::uint32_t ra) {
    const std::uint32_t header = word(rt, kTableHeader);
    const std::uint32_t rows = word(rt, kTablePointer);
    const std::uint32_t count = word(rt, header + 8u);
    const std::uint32_t first = user_ram(rows) ? (rt.memory().load16(rows) & 0xFFFFu) : 0u;
    // The caller, battle:0x08AB7F40, keeps the block it walks in s1 (r17), the form in s2 (r18), the manager in s0 (r16).
    const std::uint32_t block = ctx.gpr[17];
    std::fprintf(stderr, "[ability] lookup of id %d (0x%04X) found no row; caller ra=0x%08X\n", static_cast<std::int32_t>(id), id & 0xFFFFu, ra);
    std::fprintf(stderr, "[ability]   table: header word 0x%08X, %u rows, rows at 0x%08X, first id %u\n", header, count, rows, first);
    if (block >= kPlayerBlocks && block < kPlayerBlocks + 8u * kPlayerBlockSize) {
        std::fprintf(stderr, "[ability]   block 0x%08X = player slot %u, offset 0x%X\n", block, (block - kPlayerBlocks) / kPlayerBlockSize,
                     (block - kPlayerBlocks) % kPlayerBlockSize);
    } else {
        std::fprintf(stderr, "[ability]   block 0x%08X is not one of the player setup blocks\n", block);
    }
    std::fprintf(stderr, "[ability]   s0=0x%08X s1=0x%08X s2=0x%08X s3=0x%08X s4=0x%08X s5=0x%08X\n", ctx.gpr[16], ctx.gpr[17], ctx.gpr[18],
                 ctx.gpr[19], ctx.gpr[20], ctx.gpr[21]);
    // The set the equipped abilities are read from: block + 0x10 + block[0x773] * 0xC6 (see battle-moveset.md).
    if (user_ram(block) && user_ram(block + 0x780u)) {
        const std::uint8_t set = static_cast<std::uint8_t>(rt.memory().load32(block + 0x770u) >> 24);
        std::fprintf(stderr, "[ability]   block[0x773] (set) = %u\n", set);
        for (std::uint32_t row = 0; row < 4u; ++row) {
            std::fprintf(stderr, "[ability]   block+0x%03X:", row * 0x20u);
            for (std::uint32_t w = 0; w < 8u; ++w) std::fprintf(stderr, " %08X", word(rt, block + row * 0x20u + w * 4u));
            std::fprintf(stderr, "\n");
        }
    }
    // Every player block's set byte and first words, to tell a block that was never filled from one that holds data.
    for (std::uint32_t slot = 0; slot < 4u; ++slot) {
        const std::uint32_t b = kPlayerBlocks + slot * kPlayerBlockSize;
        std::fprintf(stderr, "[ability]   slot %u: +0x00 %08X %08X  +0x10 %08X %08X  +0x770 %08X\n", slot, word(rt, b), word(rt, b + 4u),
                     word(rt, b + 0x10u), word(rt, b + 0x14u), word(rt, b + 0x770u));
    }
    std::fflush(stderr);
}

void lookup(CorpusRuntime &corpus, AllegrexContext &ctx) {
    Runtime &rt = static_cast<Runtime &>(corpus);
    const std::uint32_t id = ctx.gpr[4];
    const std::uint32_t ra = ctx.gpr[31];
    g_original(corpus, ctx);
    if (ctx.gpr[2] == 0u && id != 0xFFFFFFFFu && g_logged < 24) {
        ++g_logged;
        report(rt, ctx, id, ra);
    }
}

// Run once, from the game's first frame: only then is there a Runtime to register the wrapper with.
void arm(Runtime &rt) {
    static bool armed = false;
    if (armed) return;
    armed = true;
    g_original = rt.registered_function(kLookup);
    if (g_original == nullptr) return;
    rt.register_function(kLookup, &lookup, "d012_ability_trace");
}

} // namespace

void install(portablekit::HleRegistrar &hle) {
    const char *off = portablekit::env("TRACE_ABILITY");
    if (off != nullptr && std::strcmp(off, "0") == 0) return;
    // sceDisplayWaitVblankStartCB and sceDisplayWaitVblankStart, as the Discord presence does.
    for (const std::uint32_t nid : {0x46F186C3u, 0x984C27E7u}) {
        const portablekit::HleFunction previous = hle.bound_function("sceDisplay", nid);
        if (!previous) continue;
        hle.bind("sceDisplay", nid, [previous](Runtime &rt, AllegrexContext &ctx) {
            arm(rt);
            previous(rt, ctx);
        });
    }
}

} // namespace d012_ability_trace

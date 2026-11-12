"""The port's roster grid for the Emendatus mod's 34-row select table (the new character).

The mod moves the select screen's layout table (stock 0x08A864D0, 33 rows of 6 s16: 32 fighters and Random) to 0x0BFEB200
inside its plugin block and appends a row for its new character (id 0x21, row 33) after Random; make_variant_corpora.py bakes
that into the corpus (apply_runtime_patches.py), including the raised row counts.

The port's grid is 2 rows x 17 columns. Its rows 0..31 are the fighters in the port's order (the table is rewritten into
that order each time a grid is built), row 32 is Random, and the position p of a cell sits in slot p, or p + 1 from 16 on:
slot 16, the 17th cell of the first row (next to Lightning), is empty. The new character keeps the row the mod gave her
(position 33) and is put in that empty slot, so nothing else in the grid moves.

apply(menu corpus folder) edits the two generated units that hold the port's grid code and fails if a piece is not where
it expects it, so a regenerated corpus never silently loses the roster.
"""
from pathlib import Path


NL = chr(10)


def replace_once(text, old, new, what):
    if text.count(old) != 1:
        raise SystemExit(f"patch_roster: {what}: expected one occurrence, found {text.count(old)}")
    return text.replace(old, new)


def with_cstdio(text):
    return text if "#include <cstdio>" in text else text.replace("#include <atomic>", "#include <atomic>\n#include <cstdio>", 1)


def apply(corpus):
    corpus = Path(corpus)
    unit40 = next(corpus.glob("generated_unit_0040.cpp"))
    unit41 = next(corpus.glob("generated_unit_0041.cpp"))

    text = unit40.read_text(encoding="utf-8")
    # the slot of position p is final here (a5, also stored at 0(sp)); position 33 is the new character's row
    text = replace_once(
        text, "L_08A7FBB8:\n    ctx.gpr[7] = (ctx.gpr[17] + ctx.gpr[17]);",
        "L_08A7FBB8:\n"
        "    if (!g_d012_grid_party && ctx.gpr[17] == 33u) {  // the mod's new character: the empty 17th cell of the first row\n"
        "        ctx.gpr[5] = 16u;\n"
        "        aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[5]);\n"
        "        { static bool traced = false; if (!traced) { traced = true; std::fprintf(stderr, \"[roster-mod] position 33 -> slot 16\\n\"); } }\n"
        "    }\n"
        "    ctx.gpr[7] = (ctx.gpr[17] + ctx.gpr[17]);", "slot of position 33 in unit 0040")
    unit40.write_text(with_cstdio(text), encoding="utf-8", newline="\n")

    text = unit41.read_text(encoding="utf-8")
    text = replace_once(text, "constexpr std::uint32_t kTable = 0x08A864D0u;", "constexpr std::uint32_t kTable = 0x0BFEB200u;  // the mod's table (stock 0x08A864D0)", "table address")
    text = replace_once(text, "static std::int16_t original[33][6];", "static std::int16_t original[34][6];", "original copy size")
    text = replace_once(text, "for (int r = 0; r < 33; ++r)\n            for (int c = 0; c < 6; ++c)\n                original[r][c]",
                        "for (int r = 0; r < 34; ++r)\n            for (int c = 0; c < 6; ++c)\n                original[r][c]", "copy loop")
    # a trace of what the grid builder sees (run the program with its output redirected to a file)
    text = replace_once(
        text, "            break;\n        }\n    }\n}\nvoid ovl089DD4C0_menu_56F41D05F1B93EE9_unit_0041_entry(",
        "            break;\n        }\n    }\n"
        "    std::fprintf(stderr, \"[roster-mod] table 0x%08X ids:\", kTable);\n"
        "    for (int r = 0; r < 34; ++r) std::fprintf(stderr, \" %02X\", static_cast<unsigned>(m.aot_load16(kTable + static_cast<std::uint32_t>(r * 12 + 8)) & 0xFFFFu));\n"
        "    std::fprintf(stderr, \" (screen %08X mode %u)\\n\", screen, mode);\n"
        "}\n"
        "void ovl089DD4C0_menu_56F41D05F1B93EE9_unit_0041_entry(", "roster trace")
    # the port's character description on hover reads the table by slot: the mod's table, 34 rows, ids up to 0x21
    text = replace_once(text, "d_slot < 33u ? static_cast<std::int16_t>(aot_mem.aot_load16(0x08A864D0u + d_slot * 12u + 8u))",
                        "d_slot < 34u ? static_cast<std::int16_t>(aot_mem.aot_load16(0x0BFEB200u + d_slot * 12u + 8u))", "description lookup")
    text = replace_once(text, "aot_mem.aot_load16(0x08A864D0u + d_r * 12u + 8u)", "aot_mem.aot_load16(0x0BFEB200u + d_r * 12u + 8u)", "party description lookup")
    text = replace_once(text, "d_id >= 1 && d_id <= 0x20;", "d_id >= 1 && d_id <= 0x21;", "description id range")
    text = replace_once(text, "d_r < 32u && d_member >= 1", "d_r < 34u && d_member >= 1", "party description rows")
    # the select screen builds its cells from a list of character ids (W+32, 8 bytes each, count in s2); the stock list stops at
    # id 32, so the new character's row (33, id 0x21) is never counted. Append her before the count.
    text = replace_once(
        text, "L_08A85084:" + NL + "    ctx.gpr[22] = (0u | 0u);",
        NL.join([
            "L_08A85084:",
            "    if (!g_d012_grid_party && ctx.gpr[18] > 0u && ctx.gpr[18] < 40u) {  // the mod's new character, id 0x21",
            "        const std::uint32_t list = aot_mem.aot_load32(ctx.gpr[19] + 32u);",
            "        if (list != 0u && aot_mem.aot_load32(list + (ctx.gpr[18] - 1u) * 8u) != 0x21u) {",
            "            aot_mem.aot_store32(list + ctx.gpr[18] * 8u, 0x21u);",
            "            aot_mem.aot_store32(list + ctx.gpr[18] * 8u + 4u, aot_mem.aot_load32(list + (ctx.gpr[18] - 1u) * 8u + 4u));",
            "            ctx.gpr[18] = ctx.gpr[18] + 1u;",
            "        }",
            "    }",
            "    ctx.gpr[22] = (0u | 0u);"]), "character list")
    # trace: how many cells the builder counted, and the list of characters it picked them from
    text = replace_once(
        text, "    if (!g_d012_grid_party) {\n        if (ctx.gpr[22] >= 17u) {",
        "    {\n"
        "        const std::uint32_t w = aot_mem.aot_load32(ctx.gpr[19] + 40u), list = aot_mem.aot_load32(ctx.gpr[19] + 32u);\n"
        "        std::fprintf(stderr, \"[roster-mod] cells counted %u, list %08X count %u ids:\", ctx.gpr[22], list, ctx.gpr[18]);\n"
        "        for (std::uint32_t i = 0; i < ctx.gpr[18] && i < 40u; ++i) std::fprintf(stderr, \" %d\", static_cast<int>(aot_mem.aot_load32(list + i * 8u)));\n"
        "        std::fprintf(stderr, \"; 08B24328:\");\n"
        "        for (std::uint32_t i = 0; i < 8u; ++i) std::fprintf(stderr, \" %08X\", aot_mem.aot_load32(0x08B24328u + i * 4u));\n"
        "        std::fprintf(stderr, \" (W %08X)\\n\", w);\n"
        "    }\n"
        "    if (!g_d012_grid_party) {\n        if (ctx.gpr[22] >= 17u) {", "builder trace")
    unit41.write_text(with_cstdio(text), encoding="utf-8", newline="\n")
    print("patch_roster: the mod's roster row is placed in", corpus.name)

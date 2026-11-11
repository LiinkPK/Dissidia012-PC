"""The port's roster grid for the Emendatus mod's 34-row select table (the new character).

The mod moves the select screen's layout table (stock 0x08A864D0, 33 rows of 6 s16: 32 fighters and Random) to 0x0BFEB200
inside its plugin block and appends a row for its new character (id 0x21) after Random; make_variant_corpora.py bakes that
into the corpus (apply_runtime_patches.py). The port's grid is 2 rows x 17 columns = 34 cells, which now all hold a
character: Quick Battle's first row gets the new character as its 17th cell (next to Lightning, id 0x1F), the second row
keeps its 16, and Random is the last cell. The stock grid leaves the 17th cell of the first row empty (a position p from
16 on sits in slot p + 1); with the new character there is no gap.

apply(menu corpus folder) edits the two generated units that hold the port's grid code and fails if a piece is not where
it expects it, so a regenerated corpus never silently loses the roster.
"""
from pathlib import Path

FIRST_ROW = [0x01, 0x03, 0x05, 0x07, 0x18, 0x09, 0x0B, 0x0D, 0x1A, 0x0F, 0x1B, 0x11, 0x13, 0x1C, 0x1E, 0x1F, 0x21]
SECOND_ROW = [0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x12, 0x14, 0x16, 0x19, 0x20, 0x15, 0x1D, 0x17]
ORDER = FIRST_ROW + SECOND_ROW + [0x00]  # 0 is Random's id


def replace_once(text, old, new, what):
    if text.count(old) != 1:
        raise SystemExit(f"patch_roster: {what}: expected one occurrence, found {text.count(old)}")
    return text.replace(old, new)


def apply(corpus):
    corpus = Path(corpus)
    unit40 = next(corpus.glob("generated_unit_0040.cpp"))
    unit41 = next(corpus.glob("generated_unit_0041.cpp"))

    text = unit40.read_text(encoding="utf-8")
    # the slot of position p: p, or p + 1 from 16 on (the empty 17th cell); now p
    text = replace_once(text, "(g_d012_grid_party ? 2u : 1u)", "(g_d012_grid_party ? 2u : 0u)", "slot gap in unit 0040")
    unit40.write_text(text, encoding="utf-8", newline="\n")

    text = unit41.read_text(encoding="utf-8")
    text = replace_once(text, "constexpr std::uint32_t kTable = 0x08A864D0u;", "constexpr std::uint32_t kTable = 0x0BFEB200u;  // the mod's table (stock 0x08A864D0)", "table address")
    text = replace_once(text, "static std::int16_t original[33][6];", "static std::int16_t original[34][6];", "original copy size")
    text = replace_once(text, "for (int r = 0; r < 33; ++r)\n            for (int c = 0; c < 6; ++c)\n                original[r][c]",
                        "for (int r = 0; r < 34; ++r)\n            for (int c = 0; c < 6; ++c)\n                original[r][c]", "copy loop")
    start = text.index("    static const std::int16_t order[32] = {")
    end = text.index("    for (int r = 0; r < 32; ++r) {\n        for (int src = 0; src < 32; ++src) {")
    order = ", ".join("0x%02X" % x for x in ORDER)
    text = text[:start] + "    static const std::int16_t order[34] = {" + order + "};\n" + text[end:]
    text = replace_once(text, "    for (int r = 0; r < 32; ++r) {\n        for (int src = 0; src < 32; ++src) {",
                        "    for (int r = 0; r < 34; ++r) {\n        for (int src = 0; src < 34; ++src) {", "rewrite loop")
    unit41.write_text(text, encoding="utf-8", newline="\n")
    print("patch_roster: the 34-cell roster is in", corpus.name)

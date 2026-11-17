#!/usr/bin/env python3
"""Fills the Emendatus hook stubs of the block2 corpus with the base address they jump from.

    patch_block2_stubs.py <overlays/ovl0BFE8000_block2_<hash> directory> <assets file>

Every hook the plugin puts into the game jumps into a stub in block2 (block + 0x2000 and on): two placeholder nops, then
`addiu t8,t9,N` and `jr t8`, which only works with t9 = the block's base address. At run time block2's entry (a0 = its
base) stores `lui t9,hi` and `ori t9,t9,lo` over the two nops of every stub. Recompiled code does not see a store into
code, so here the two nops are made into the two assignments themselves. The stubs are found the way the entry finds
them: its `sw` of t0 (the lui) and t2 (the ori) to offsets of s0 from 0x2000 on.
"""
import re
import struct
import sys
from pathlib import Path

BLOCK_BASE = 0x0BFE8000
BLOCK_TAIL_OFFSET = 227080192


def stub_offsets(assets):
    with open(assets, "rb") as f:
        f.seek(BLOCK_TAIL_OFFSET)
        block = f.read(0x8000)
    his = []
    for offset in range(0, 0x400, 4):
        word = struct.unpack_from("<I", block, offset)[0]
        # sw t0, imm(s0): the lui word; the offsets below 0x2000 are other data
        if word >> 26 == 0x2B and (word >> 21) & 31 == 16 and (word >> 16) & 31 == 8 and 0x2000 <= (word & 0xFFFF) < 0x3000:
            his.append(word & 0xFFFF)
    return his


def main():
    corpus, assets = Path(sys.argv[1]), Path(sys.argv[2])
    units = {}
    for path in sorted(corpus.glob("generated_unit_*.cpp")):
        with open(path, newline="") as f:
            units[path] = f.read()
    hi_word = "ctx.gpr[25] = (%du << 16u);" % (BLOCK_BASE >> 16)
    lo_word = "ctx.gpr[25] = (ctx.gpr[25] | %du);" % (BLOCK_BASE & 0xFFFF)
    done = 0
    for offset in stub_offsets(assets):
        for slot, text in ((offset, hi_word), (offset + 4, lo_word)):
            label = "L_%08X:" % (BLOCK_BASE + slot)
            pattern = re.compile(re.escape(label) + r"(\r?\n)    // nop(\r?\n)")
            for path, source in units.items():
                match = pattern.search(source)
                if match:
                    units[path] = source[:match.start()] + label + match.group(1) + "    " + text + match.group(2) + source[match.end():]
                    done += 1
                    break
            else:
                print("slot %08X: no nop found (already done?)" % (BLOCK_BASE + slot))
    for path, source in units.items():
        with open(path, "w", newline="") as f:
            f.write(source)
    print("%d stub slots filled" % done)


main()

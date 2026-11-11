#!/usr/bin/env python3
"""Bakes the Emendatus mod's runtime code patches into its executable and overlay images.

    apply_runtime_patches.py <assets file> <dir with EBOOT.ELF, OVL_MENU_APP.ELF, OVL_BATTLE_APP.ELF> <out dir>

The newer mod patches the game's code while it runs: its plugin (the 32 KB block at 0x0BFE8000, tail offset 227080192 of
mods/emendatus_assets.bin) walks two tables when a menu overlay loads. The "swap" table (block + 0x5400, 12-byte entries
{address, original word, new word}) replaces instruction words; the "reloc" table (block + 0x3400, 16-byte entries
{address, original word, type, delta}) points lui/addiu pairs (type 1 = HI16, 2 = LO16) and jal targets (type 3) at data and
code inside the block (block base + delta). A patch is only applied where the word is still the original one.

Recompiled code never sees a change made to guest memory at run time, so the corpora have to be made from images that
already hold these patches. This tool writes those images; make_variant_corpora.py then reads them.
"""
import struct
import sys
from pathlib import Path

BLOCK_BASE = 0x0BFE8000
BLOCK_TAIL_OFFSET = 227080192
BLOCK_SIZE = 32768
SWAP_TABLE, RELOC_TABLE = 0x5400, 0x3400


class Image:
    def __init__(self, path):
        self.path = path
        self.data = bytearray(Path(path).read_bytes())
        phoff = struct.unpack_from("<I", self.data, 28)[0]
        phentsize, phnum = struct.unpack_from("<HH", self.data, 42)
        self.loads = []
        for i in range(phnum):
            p_type, offset, vaddr, _pa, filesz, memsz, _fl, _al = struct.unpack_from("<8I", self.data, phoff + i * phentsize)
            if p_type == 1:
                self.loads.append((vaddr, offset, filesz))

    def position(self, address):
        for vaddr, offset, filesz in self.loads:
            if vaddr <= address < vaddr + filesz:
                return offset + address - vaddr
        return None

    def word(self, address):
        pos = self.position(address)
        return None if pos is None else struct.unpack_from("<I", self.data, pos)[0]

    def set(self, address, value):
        struct.pack_into("<I", self.data, self.position(address), value)


def read_tables(assets):
    with open(assets, "rb") as f:
        f.seek(BLOCK_TAIL_OFFSET)
        block = f.read(BLOCK_SIZE)

    def table(offset, size):
        count = struct.unpack_from("<I", block, offset)[0]
        return [struct.unpack_from("<%dI" % (size // 4), block, offset + 4 + i * size) for i in range(count)]

    return table(SWAP_TABLE, 12), table(RELOC_TABLE, 16)


def relocated(orig, kind, delta):
    target = (BLOCK_BASE + delta) & 0xFFFFFFFF
    if kind == 3:
        return 0x0C000000 | (target >> 2)
    high = orig & 0xFFFF0000
    if kind == 1:
        target = ((target + 0x8000) >> 16) & 0xFFFF
    return high | (target & 0xFFFF)


def main():
    assets, source, out = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
    swaps, relocs = read_tables(assets)
    out.mkdir(parents=True, exist_ok=True)
    images = {n: Image(source / n) for n in ("EBOOT.ELF", "OVL_MENU_APP.ELF", "OVL_BATTLE_APP.ELF")}
    entries = [(a, o, n, "swap") for a, o, n in swaps] + [(a, o, relocated(o, k, d), "reloc%d" % k) for a, o, k, d in relocs]
    for name, image in images.items():
        applied = 0
        for address, orig, new, kind in entries:
            if image.word(address) == orig:
                image.set(address, new)
                applied += 1
                print("%-18s %08x %-7s %08x -> %08x" % (name, address, kind, orig, new))
        (out / name).write_bytes(image.data)
        print("%s: %d patches applied" % (name, applied))
    for address, orig, new, kind in entries:
        hits = [n for n, i in images.items() if i.word(address) == orig]
        if not hits and kind != "swap":
            print("not applied anywhere: %08x %s (data written at run time, or another overlay)" % (address, kind))


main()

#!/usr/bin/env python3
"""Generates the recompiled code (corpus) of the "expanded" edition: the stock executable with Gojo's memory expansion.

    make_expanded_corpus.py --stock-elf EBOOT.ELF [--recompiler EXE] [--work DIR]

EBOOT.ELF is the decrypted stock executable (the one the installer made, 4640948 bytes). The edits are read from
profiles/d012_vk/d012_expansion_data.inc, the same table the port applies when it makes EBOOT_EXPANDED.ELF at run time, so the
corpus and the executable cannot disagree; the result must hash to the value in that file or the tool stops.

It writes work/generated-variants/expanded/, which the build turns into corpora/expanded.<ext> (the profile's "expanded"
edition). Only the main executable changes: the overlays are the stock ones. The expansion adds a small code cave, which the
analysis is told is code, as it is for the Emendatus mod's. psp_recomp takes about a minute; the compile after it is the long part.
"""
import argparse
import hashlib
import re
import struct
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools" / "mods" / "emendatus"))
import make_variant_corpora as mvc  # noqa: E402  (its run(), sync_tree() and constants)

overlay_meta = mvc.overlay_meta
INC = ROOT / "profiles" / "d012_vk" / "d012_expansion_data.inc"
STOCK_SHA256 = "0bc8e779aad2814a3d1bd77346f69ca5e16665845ed053cd0ad44a9cbfaefe6d"


def read_table(path):
    text = path.read_text(encoding="utf-8")
    edits = [(int(o), int(n)) for o, n in re.findall(r"\{(\d+)u,\s*(\d+)u,\s*\"", text)]
    blob = bytes(int(x, 16) for x in re.findall(r"0x([0-9A-Fa-f]{2})", re.search(r"kExpansionBlob\[\d+\]\s*=\s*\{(.*?)\};", text, re.S).group(1)))
    sha = re.search(r'kExpandedExecutableSha256\s*=\s*"([0-9a-f]{64})"', text).group(1)
    return edits, blob, sha


def virtual_address(elf, offset):
    """The guest address of a file offset, from the program headers."""
    phoff, phentsize, phnum = struct.unpack_from("<I", elf, 0x1C)[0], struct.unpack_from("<H", elf, 0x2A)[0], struct.unpack_from("<H", elf, 0x2C)[0]
    for i in range(phnum):
        at = phoff + i * phentsize
        kind, p_offset, vaddr, _, filesz = struct.unpack_from("<IIIII", elf, at)
        if kind == 1 and p_offset <= offset < p_offset + filesz:
            return vaddr + offset - p_offset
    raise SystemExit(f"file offset {offset:#x} is in no PT_LOAD segment")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--stock-elf", required=True, type=Path)
    parser.add_argument("--recompiler", type=Path, default=ROOT / "out" / "d012_vk" / "portablekit" / "Release" / "psp_recomp.exe")
    parser.add_argument("--work", type=Path, default=ROOT / "profiles" / "d012_pk" / "work")
    options = parser.parse_args()
    if not options.recompiler.is_file():
        raise SystemExit(f"psp_recomp not found: {options.recompiler}")
    stock = options.stock_elf.read_bytes()
    if hashlib.sha256(stock).hexdigest() != STOCK_SHA256:
        raise SystemExit("--stock-elf is not the stock decrypted executable (sha256 differs)")
    edits, blob, want = read_table(INC)
    image = bytearray(stock)
    at = 0
    caves = []
    for offset, length in edits:
        was_empty = not any(stock[offset:offset + length])
        image[offset:offset + length] = blob[at:at + length]
        at += length
        if was_empty:  # new code over empty space (a cave): it is in no function the analysis knows
            start = virtual_address(stock, offset)
            caves.append(f"0x{start:08X}-0x{start + length:08X}")
    got = hashlib.sha256(image).hexdigest()
    if got != want:
        raise SystemExit(f"the edited executable hashes to {got}, the port expects {want}")
    with tempfile.TemporaryDirectory(prefix="expanded_corpus_") as tmp:
        staging = Path(tmp)
        elf = staging / "EBOOT.ELF"
        elf.write_bytes(bytes(image))
        main_out = staging / "main"
        command = [options.recompiler, elf, "--auto", main_out, mvc.MAIN_BASE] + overlay_meta.dispatch_calls("main")
        for cave in caves:
            command += ["--code", cave]
        mvc.run(command)
        variant = options.work / "generated-variants" / "expanded"
        print(f"main corpus: {mvc.sync_tree(main_out, variant)} file(s) changed in {variant}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

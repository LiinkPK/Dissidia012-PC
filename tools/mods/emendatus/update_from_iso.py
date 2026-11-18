#!/usr/bin/env python3
"""Compares a newer Emendatus-patched US disc with the mod data this repository holds, and with --apply replaces that data.

    update_from_iso.py --us <original US iso> --patched <patched US iso> --eur <your EUR iso> --stock-elf <decrypted EBOOT.ELF> [--apply]

Without --apply nothing in the repository is written: it prints what changed. With --apply it writes
  profiles/d012_vk/d012_emendatus_data.inc   (the mod's changes to the game's code and index, from make_mod_data.py)
  release/mods/emendatus_assets.bin          (the mod's appended data, 338 MB)
  profiles/d012_vk/aerith/*                  (the new character's model files that sit in that data and whose entry the plugin lists)
and then says whether the corpora (the recompiled code, hours of compile) must be made again: that is so when the plugin's block
(its code, its swap and reloc tables) changed, or when the code regions did.
"""
import argparse
import mmap
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
INC = ROOT / "profiles/d012_vk/d012_emendatus_data.inc"
ASSETS = ROOT / "release/mods/emendatus_assets.bin"
AERITH = ROOT / "profiles/d012_vk/aerith"
BLOCK_OFFSET, BLOCK_SIZE = 227080192, 32768  # the plugin's block in the tail (see apply_runtime_patches.py)
ENTRY_TABLE = 0x23F8                          # the plugin's added index rows: {hash, sector, 0x10000000 | size}, 12 bytes each
PACKAGE_STOCK_SIZE = 1034358784              # the US PACKAGE.BIN before the mod; the tail starts here
FILES = {0xD02607DD: "p_sev120.objx", 0xFB4632A5: "P_SEV120_1P.gmo", 0xD63E252D: "P_SEV120_2P.gmo", 0xCD162855: "P_SEV120_3P.gmo"}
TABLES = ("kEmEboot", "kEmBattle", "kEmMenu", "kEmMenuTail", "kEmIndex", "kEmPackageUS", "kEmPackageEUR")


def inc_tables(path):
    text = Path(path).read_text(encoding="utf-8")
    blob = re.search(r"kEmBlob\[\d+\] = \{(.*?)\};", text, re.S).group(1)
    blob = bytes(int(x, 16) for x in re.findall(r"0x([0-9A-Fa-f]{1,2})", blob))
    result = {}
    for name in TABLES:
        m = re.search(r"EmRegion " + name + r"\[\] = \{(.*?)\n\};", text, re.S)
        rows = re.findall(r"\{\s*(\d+)\w*,\s*(\d+)\w*,\s*(\d+)\w*\s*\}", m.group(1)) if m else []
        result[name] = [(r[0], blob[int(r[1]):int(r[1]) + int(r[2])]) for r in rows]
    return result


def changed_ranges(new_path, old_path, step=1 << 16):
    if not Path(old_path).exists():
        return None
    with open(new_path, "rb") as a, open(old_path, "rb") as b:
        ma = mmap.mmap(a.fileno(), 0, access=mmap.ACCESS_READ)
        mb = mmap.mmap(b.fileno(), 0, access=mmap.ACCESS_READ)
        if len(ma) != len(mb):
            return [("size", len(ma), len(mb))]
        runs = []
        for off in range(0, len(ma), step):
            if ma[off:off + step] != mb[off:off + step]:
                if runs and off - runs[-1][1] <= step * 2:
                    runs[-1][1] = off + step
                else:
                    runs.append([off, off + step])
        out = []
        for s, e in runs:
            e = min(e, len(ma))
            while ma[s] == mb[s]:
                s += 1
            e2 = e - 1
            while ma[e2] == mb[e2]:
                e2 -= 1
            out.append(("range", s, e2 + 1))
        return out


def block_report(new_path, old_path):
    """Which part of the plugin's block changed: code and data, the reloc table, the swap table."""
    if not Path(old_path).exists():
        return None
    with open(new_path, "rb") as a, open(old_path, "rb") as b:
        a.seek(BLOCK_OFFSET)
        b.seek(BLOCK_OFFSET)
        bn, bo = a.read(BLOCK_SIZE), b.read(BLOCK_SIZE)
    parts = (("code and data (0x0000-0x3400)", 0, 0x3400), ("reloc table (0x3400-0x5400)", 0x3400, 0x5400), ("swap table (0x5400-0x8000)", 0x5400, 0x8000))
    return [(name, sum(1 for i in range(lo, hi) if bn[i] != bo[i])) for name, lo, hi in parts]


def plugin_files(tail_path):
    """{file name: (offset in the tail, size)} for the character files the plugin lists in its added index rows."""
    with open(tail_path, "rb") as f:
        f.seek(BLOCK_OFFSET)
        block = f.read(BLOCK_SIZE)
    found = {}
    for k in range(0, 64):
        h, sector, word = struct.unpack_from("<3I", block, ENTRY_TABLE + 12 * k)
        if h in FILES and sector * 2048 > PACKAGE_STOCK_SIZE:
            found[FILES[h]] = (sector * 2048 - PACKAGE_STOCK_SIZE, word & 0xFFFFFF)
    return found


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--us", required=True)
    ap.add_argument("--patched", required=True)
    ap.add_argument("--eur", required=True)
    ap.add_argument("--stock-elf", required=True)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--corpora", action="store_true", help="after --apply, also bake the plugin's patches and make the corpora again (about a minute; the build then compiles them)")
    args = ap.parse_args()

    work = Path(tempfile.mkdtemp(prefix="emendatus_update_"))
    new_inc, new_tail = work / "em.inc", work / "tail.bin"
    (work / "elf").mkdir()
    cmd = [sys.executable, str(HERE / "make_mod_data.py"), args.us, args.patched, args.eur, str(new_inc),
           "--tail-out", str(new_tail), "--stock-elf", args.stock_elf, "--elf-dir", str(work / "elf")]
    print("running make_mod_data.py ...")
    subprocess.run(cmd, check=True)

    print("\n== what changed against the data in this repository ==")
    corpora = False
    if INC.exists():
        new, old = inc_tables(new_inc), inc_tables(INC)
        for name in TABLES:
            changed = sum(1 for row in new[name] if row not in old[name]) + abs(len(new[name]) - len(old[name]))
            print(f"  {name:14} {'same' if not changed else str(changed) + ' rows changed'}")
            if changed and name in ("kEmEboot", "kEmBattle", "kEmMenu", "kEmMenuTail"):
                corpora = True
    else:
        print("  no data include in the repository yet")
        corpora = True
    ranges = changed_ranges(new_tail, ASSETS)
    if ranges is None:
        print("  no current assets file")
        corpora = True
    else:
        print(f"  assets file: {'same' if not ranges else str(len(ranges)) + ' changed ranges'}")
        for r in ranges:
            print("    ", r)
    block = block_report(new_tail, ASSETS)
    if block:
        for name, n in block:
            print(f"  plugin block, {name}: {n} bytes differ")
            if n:
                corpora = True
    files = plugin_files(new_tail)
    with open(new_tail, "rb") as f:
        for name, (off, size) in sorted(files.items()):
            f.seek(off)
            data = f.read(size)
            cur = AERITH / name
            same = cur.exists() and cur.read_bytes() == data
            print(f"  character file {name}: {'same' if same else 'changed (' + str(size) + ' bytes)'}")

    if not args.apply:
        print("\nNothing written (add --apply to replace the data).")
        print("The corpora must be made again after applying." if corpora else "The corpora do not need to be made again.")
        return
    print("\n== applying ==")
    shutil.copyfile(new_inc, INC)
    print("  wrote", INC.relative_to(ROOT))
    ASSETS.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(new_tail, ASSETS)
    print("  wrote", ASSETS.relative_to(ROOT))
    AERITH.mkdir(parents=True, exist_ok=True)
    with open(new_tail, "rb") as f:
        for name, (off, size) in files.items():
            f.seek(off)
            (AERITH / name).write_bytes(f.read(size))
            print("  wrote", (AERITH / name).relative_to(ROOT))
    print("  not touched: D_SEV120.objx and D_SEV120.gmo (the plugin does not list them)")
    print("\nNext:")
    print("  - copy the aerith files and the assets file into the release's mods folder (make_release.ps1 does it);")
    print("  - put the new assets file in data.zip (mods/) of the data-pack release, and rebuild.")
    if corpora:
        print("  - the plugin or the code changed: bake the patches and make the corpora again (apply_runtime_patches.py, then"
              " make_variant_corpora.py, see this folder); the build needs them before the mod works.")
    else:
        print("  - the corpora do not need to be made again.")
    if args.corpora:
        make_corpora(args, work)
    shutil.rmtree(work, ignore_errors=True)


def make_corpora(args, work):
    """The patched images (the plain executable of the patched disc and its two overlays), the plugin's patches baked in, and the corpora."""
    import types
    src = (HERE / "make_mod_data.py").read_text(encoding="utf-8").rsplit("\nmain()", 1)[0]
    mod = types.ModuleType("make_mod_data")
    exec(src, mod.__dict__)
    iso = mod.Iso(args.patched)
    images, baked = ROOT / "out/emendatus_patched", ROOT / "out/emendatus_runtime"
    for d in (images, baked):
        shutil.rmtree(d, ignore_errors=True)
        d.mkdir(parents=True)
    lba, size = iso.files["/PSP_GAME/SYSDIR/EBOOT.BIN"]
    iso.f.seek(lba * mod.SECTOR)
    (images / "EBOOT.ELF").write_bytes(iso.f.read(size))
    for name in ("OVL_BATTLE_APP.ELF", "OVL_MENU_APP.ELF"):
        shutil.copyfile(work / "elf" / name, images / name)
    print("\n== baking the plugin's patches ==")
    subprocess.run([sys.executable, str(HERE / "apply_runtime_patches.py"), str(ASSETS), str(images), str(baked)], check=True)
    print("\n== making the corpora ==")
    subprocess.run([sys.executable, str(HERE / "make_variant_corpora.py"), "--patched-dir", str(baked), "--executable-elf", str(images / "EBOOT.ELF"),
                    "--battle-code-size", "20416", "--prefer-patched", "--stock-iso", args.us], check=True)
    print("\nThe corpora are made. Build the game: the compile of the changed units is the long step.")


if __name__ == "__main__":
    main()

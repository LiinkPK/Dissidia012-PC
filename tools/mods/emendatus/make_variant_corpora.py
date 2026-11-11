#!/usr/bin/env python3
"""Generates the recompiled code (corpora) for a disc patched by the newer Emendatus mod (the one with a new character).

    make_variant_corpora.py --patched-dir DIR --stock-iso ISO [--recompiler EXE] [--work DIR]

DIR holds the patched disc's EBOOT.ELF (the plain EBOOT.BIN), OVL_MENU_APP.ELF and OVL_BATTLE_APP.ELF. ISO is an unmodified
disc of the game, read for its OVL_MENU_APP.ELF: the port's hand edits of the menu code (the roster grid, in a few units of
the stock menu corpus) are put on the patched menu by a three-way merge of the stock menu freshly generated (base), the
stock menu corpus in work/overlays as it is in git (the edits), and the patched menu freshly generated (the new code).

What it writes, all under --work (default profiles/d012_pk/work, the folder the build reads):
  generated-variants/emendatus/   the patched EBOOT's units (the profile's "emendatus" edition runs them)
  overlays/<name>_<hash>/         the patched battle overlay, and the patched menu overlay with the edits merged in

It stops before touching overlays/ when a merge has a conflict. psp_recomp takes about a minute for all of it.
"""
import argparse
import hashlib
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
TOOLS = ROOT / "third_party" / "dissidia012-pc" / "tools" / "port"
sys.path.insert(0, str(TOOLS))
import overlay_meta  # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parent))
import patch_roster  # noqa: E402

SECTOR = 2048
MAIN_BASE = "0x08804000"
MAIN_CODE = "0x089CB080-0x089CB0C8"  # the mod's code cave in the executable (the patched runs end at 0x089CB0C6)
HASH = re.compile(r"(ovl[0-9A-F]{8}_[a-z]+_)[0-9A-F]{16}")


def iso_file(path, wanted):
    """The bytes of one file of an ISO 9660 image (a plain walk of the directory records)."""
    with open(path, "rb") as f:
        f.seek(16 * SECTOR)
        root = f.read(SECTOR)[156:190]
        stack = [("", struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0])]
        while stack:
            prefix, lba, size = stack.pop()
            f.seek(lba * SECTOR)
            data = f.read(size)
            pos = 0
            while pos < len(data):
                n = data[pos]
                if n == 0:
                    pos = (pos // SECTOR + 1) * SECTOR
                    continue
                rec, pos = data[pos:pos + n], pos + n
                elba, esize = struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0]
                name = rec[33:33 + rec[32]]
                if name in (b"\x00", b"\x01"):
                    continue
                full = prefix + "/" + name.decode("latin-1").split(";")[0]
                if rec[25] & 2:
                    stack.append((full, elba, esize))
                elif full.upper() == wanted.upper():
                    f.seek(elba * SECTOR)
                    return f.read(esize)
    raise SystemExit(f"{wanted} is not in {path}")


def run(args):
    print(" ".join(str(a) for a in args), flush=True)
    subprocess.run([str(a) for a in args], check=True)


def corpus_dir(root, name):
    """The overlay corpus folder of `name` ("menu") under root, and its hash prefix."""
    found = [d for d in Path(root).iterdir() if d.is_dir() and d.name.startswith(f"ovl089DD4C0_{name}_")]
    if len(found) != 1:
        raise SystemExit(f"expected one {name} corpus in {root}, found {len(found)}")
    return found[0]


def read(path):
    with open(path, encoding="utf-8", newline="") as stream:
        return stream.read()


def write(path, text):
    with open(path, "w", encoding="utf-8", newline="") as stream:
        stream.write(text)


def normalized(text):
    return HASH.sub(r"\g<1>" + "0" * 16, text)


def merge_menu(base_dir, edited_dir, new_dir):
    """Puts the edits that edited_dir has over base_dir onto new_dir's units. Returns the conflicts, by unit."""
    new_hash = new_dir.name.rsplit("_", 1)[1]
    conflicts = []
    for unit in sorted(base_dir.glob("generated_unit_*.cpp")):
        edited = read(edited_dir / unit.name)
        base = read(unit)
        if normalized(edited) == normalized(base):
            continue  # no hand edit in this unit
        with tempfile.TemporaryDirectory() as tmp:
            paths = {}
            for tag, text in (("ours", edited), ("base", base), ("theirs", read(new_dir / unit.name))):
                paths[tag] = Path(tmp) / tag
                write(paths[tag], normalized(text))
            result = subprocess.run(["git", "merge-file", "-p", "-L", "hand edits", "-L", "stock menu", "-L", "patched menu", str(paths["ours"]), str(paths["base"]), str(paths["theirs"])],
                                    capture_output=True, text=True, encoding="utf-8")
        if result.returncode < 0 or result.returncode > 127:
            raise SystemExit(f"git merge-file failed on {unit.name}: {result.stderr}")
        merged = re.sub(r"(ovl[0-9A-F]{8}_[a-z]+_)0{16}", r"\g<1>" + new_hash, result.stdout)
        write(new_dir / unit.name, merged)
        print(f"{unit.name}: hand edits merged, {result.returncode} conflict(s)")
        if result.returncode:
            conflicts.append(unit.name)
    return conflicts


def taken_hashes(overlays):
    """The identity hashes of the overlay corpora already in work/overlays (from their meta.txt)."""
    found = set()
    for meta in Path(overlays).glob("*/meta.txt"):
        for line in meta.read_text(encoding="utf-8").splitlines():
            if line.startswith("hash="):
                found.add(int(line[5:], 16))
    return found


def old_mod_battle(stock, inc):
    """The battle overlay of the older Emendatus mod: the stock one with the regions of d012_emendatus_data.inc put over it."""
    text = Path(inc).read_text(encoding="utf-8", errors="ignore")
    blob = bytes(int(x, 16) for x in re.findall(r"0x([0-9A-Fa-f]{1,2})", re.search(r"kEmBlob\[\d+\]\s*=\s*\{(.*?)\};", text, re.S).group(1)))
    regions = re.findall(r"\{(\d+)u,\s*(\d+)u,\s*(\d+)u\}", re.search(r"kEmBattle\[\]\s*=\s*\{(.*?)\};", text, re.S).group(1))
    data = bytearray(stock)
    for offset, at, length in regions:
        data[int(offset):int(offset) + int(length)] = blob[int(at):int(at) + int(length)]
    return bytes(data)


def distinguishing_code_size(elf, siblings):
    """The code size to hash for an overlay that other, similar overlays have corpora for. The framework picks an
    overlay's corpus by the hash of its first bytes (a header and `code size` bytes of code), and a mod changes few of
    them: the window has to reach the first byte where this overlay differs from each sibling, or it runs the code of
    the wrong one. Returns the size in bytes, in steps of 4 KB."""
    _, image = overlay_meta.load_image(str(elf))
    reach = 0
    for sibling in siblings:
        _, other = overlay_meta.load_image(str(sibling))
        n = min(len(image), len(other))
        first = next((i for i in range(n) if image[i] != other[i]), None)
        if first is None:
            raise SystemExit(f"{elf.name} is the same as {sibling}: nothing tells their corpora apart")
        reach = max(reach, first + 1)
    window = (reach + 4095) // 4096 * 4096
    return max(overlay_meta.DEFAULT_CODE_SIZE, window - overlay_meta.HEADER_BYTES)


def check_unique(elf, taken):
    """The default code size must give a hash no existing corpus has (the same length of code is compared)."""
    _, image = overlay_meta.load_image(str(elf))
    if overlay_meta.fnv1a64(image[:overlay_meta.HEADER_BYTES + overlay_meta.DEFAULT_CODE_SIZE]) in taken:
        raise SystemExit(f"{elf.name}: its first 4 KB are the same as an overlay corpus already in work/overlays")


def with_memsz_of_filesz(source, target):
    """A copy of an overlay ELF whose PT_LOAD memory size is at least its file size (the mod's menu overlay grows in the
    file but not in memory size, and psp_recomp rejects that)."""
    data = bytearray(source.read_bytes())
    phoff, phentsize, phnum = struct.unpack_from("<I", data, 0x1C)[0], struct.unpack_from("<H", data, 0x2A)[0], struct.unpack_from("<H", data, 0x2C)[0]
    for i in range(phnum):
        at = phoff + i * phentsize
        if struct.unpack_from("<I", data, at)[0] == 1:
            filesz, memsz = struct.unpack_from("<II", data, at + 16)
            if memsz < filesz:
                struct.pack_into("<I", data, at + 20, filesz)
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(bytes(data))
    return target


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--patched-dir", required=True, type=Path)
    parser.add_argument("--stock-iso", required=True, type=Path)
    parser.add_argument("--recompiler", type=Path, default=ROOT / "out" / "d012_vk" / "portablekit" / "Release" / "psp_recomp.exe")
    parser.add_argument("--work", type=Path, default=ROOT / "profiles" / "d012_pk" / "work")
    parser.add_argument("--executable-elf", type=Path, help="the executable as the game runs it (EBOOT.ELF of the patched disc): its hash is the one the "
                        "corpus is checked against, when --patched-dir holds images with the plugin's runtime patches baked in (apply_runtime_patches.py)")
    parser.add_argument("--battle-code-size", type=int, help="hash this many bytes of the battle overlay after its header (the older Emendatus mod\'s battle overlay shares its first 4 KB; 20416 tells them apart)")
    parser.add_argument("--main-only", action="store_true", help="only make the executable's corpus again (the overlay corpora stay as they are)")
    options = parser.parse_args()
    if not options.recompiler.is_file():
        raise SystemExit(f"psp_recomp not found: {options.recompiler}")
    elves = {n: options.patched_dir / n for n in ("EBOOT.ELF", "OVL_MENU_APP.ELF", "OVL_BATTLE_APP.ELF")}
    for path in elves.values():
        if not path.is_file():
            raise SystemExit(f"missing {path}")
    staging = Path(tempfile.mkdtemp(prefix="emendatus_corpora_"))
    keep = False
    try:
        # 1. the patched EBOOT's own corpus
        main_out = staging / "main"
        # The mod puts new code over data of the original (a cave at 0x089CB080, called from the patched code): the analysis is
        # told that range is code, as it is for the menu overlay's added code.
        run([options.recompiler, elves["EBOOT.ELF"], "--auto", main_out, MAIN_BASE] + overlay_meta.dispatch_calls("main")
            + ["--code", MAIN_CODE])
        if options.executable_elf:
            registry = main_out / "generated_registry.cpp"
            text = registry.read_text(encoding="utf-8")
            own = hashlib.sha256(elves["EBOOT.ELF"].read_bytes()).hexdigest()
            real = hashlib.sha256(options.executable_elf.read_bytes()).hexdigest()
            if own not in text:
                raise SystemExit("the generated registry does not name the executable it was made from")
            registry.write_text(text.replace(own, real), encoding="utf-8", newline="\n")
            print(f"the corpus is checked against {real[:16]}... (the executable as it runs)")
        if options.main_only:
            variant = options.work / "generated-variants" / "emendatus"
            if variant.exists():
                shutil.rmtree(variant)
            shutil.copytree(main_out, variant)
            print(f"main corpus written to {variant}")
            return 0
        # 2. the overlays: battle as it is, menu with its added code named as code
        new = staging / "new"
        taken = taken_hashes(options.work / "overlays")
        battle_elf = with_memsz_of_filesz(elves["OVL_BATTLE_APP.ELF"], staging / "patched" / "OVL_BATTLE_APP.ELF")
        stock_battle = staging / "stock" / "OVL_BATTLE_APP.ELF"
        stock_battle.parent.mkdir(exist_ok=True)
        stock_battle.write_bytes(iso_file(options.stock_iso, "/PSP_GAME/USRDIR/DATA/OVL_BATTLE_APP.ELF"))
        battle_size = (options.battle_code_size or distinguishing_code_size(battle_elf, [stock_battle]))
        print(f"battle overlay: code size {battle_size}")
        run([sys.executable, TOOLS / "overlay_meta.py", "--recompile", "--recompiler", options.recompiler, "--out", new,
             "--code-size", battle_size, battle_elf])
        # the stock menu overlay, read from the disc: its image is what the mod's added code is measured against
        stock_elf = staging / "stock" / "OVL_MENU_APP.ELF"
        stock_elf.parent.mkdir(exist_ok=True)
        stock_elf.write_bytes(iso_file(options.stock_iso, "/PSP_GAME/USRDIR/DATA/OVL_MENU_APP.ELF"))
        base_addr, image = overlay_meta.load_image(str(elves["OVL_MENU_APP.ELF"]))
        _, stock_image = overlay_meta.load_image(str(stock_elf))
        if len(image) <= len(stock_image):
            raise SystemExit("the patched menu overlay is not larger than the stock one: nothing to name as added code")
        code = f"0x{base_addr + len(stock_image):08X}-0x{base_addr + len(image):08X}"
        print(f"the mod adds {len(image) - len(stock_image)} bytes of code to the menu overlay: --code {code}")
        menu_elf = with_memsz_of_filesz(elves["OVL_MENU_APP.ELF"], staging / "patched" / "OVL_MENU_APP.ELF")
        check_unique(menu_elf, taken)
        menu_size = overlay_meta.DEFAULT_CODE_SIZE
        print(f"menu overlay: code size {menu_size}")
        run([sys.executable, TOOLS / "overlay_meta.py", "--recompile", "--recompiler", options.recompiler, "--out", new,
             "--code", code, "--code-size", menu_size, menu_elf])
        # 3. the stock menu, freshly generated, is the base of the merge
        base = staging / "base"
        run([sys.executable, TOOLS / "overlay_meta.py", "--recompile", "--recompiler", options.recompiler, "--out", base, stock_elf])
        base_menu = corpus_dir(base, "menu")
        stock_hash = base_menu.name.rsplit("_", 1)[1]
        edited_menu = next((d for d in (options.work / "overlays").iterdir() if d.name.endswith("_" + stock_hash)), None)
        if edited_menu is None:
            raise SystemExit(f"the stock menu corpus ({stock_hash}) is not in {options.work / 'overlays'}")
        conflicts = merge_menu(base_menu, edited_menu, corpus_dir(new, "menu"))
        if conflicts:
            print(f"\nStopped: {len(conflicts)} unit(s) have conflicts ({', '.join(conflicts)}). Nothing was written to {options.work}.\n"
                  f"The merged files are in {staging}; fix the <<<<<<< markers there and copy them over by hand.")
            keep = True
            return 1
        patch_roster.apply(corpus_dir(new, "menu"))  # the port's roster grid for the mod's 34-row table
        # 4. install (nothing is written until it is clear that no existing overlay corpus would be overwritten)
        for source in new.iterdir():
            if (options.work / "overlays" / source.name).exists():
                raise SystemExit(f"{options.work / 'overlays' / source.name} already exists: it would be overwritten. Nothing was written.")
        variant = options.work / "generated-variants" / "emendatus"
        if variant.exists():
            shutil.rmtree(variant)
        shutil.copytree(main_out, variant)
        for source in new.iterdir():
            target = options.work / "overlays" / source.name
            shutil.copytree(source, target)
            print(f"overlay corpus {source.name} written")
        print(f"main corpus written to {variant}")
    finally:
        if not keep:
            shutil.rmtree(staging, ignore_errors=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())

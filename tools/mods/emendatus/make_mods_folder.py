#!/usr/bin/env python3
"""Puts the Emendatus Mod's seven files together in one `mods` folder, the one that goes in data.zip of the data-pack release.

    make_mods_folder.py [--out DIR]        (default: dist/data-pack/mods)

The six small files of the new character come from profiles/d012_vk/aerith/ and the 338 MB data file from release/mods/. The
folder is checked: seven files, the data file with the size the program expects. Put it in data.zip next to ms0/ and textures/
(7-Zip or any zip tool: drag the folder over the old mods/ in the zip and replace the files).
"""
import argparse
import os
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
AERITH = ROOT / "profiles/d012_vk/aerith"
ASSETS = ROOT / "release/mods/emendatus_assets.bin"
INC = ROOT / "profiles/d012_vk/d012_emendatus_data.inc"
SMALL = ("D_SEV120.gmo", "D_SEV120.objx", "P_SEV120_1P.gmo", "P_SEV120_2P.gmo", "P_SEV120_3P.gmo", "p_sev120.objx")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path, default=ROOT / "dist/data-pack/mods")
    out = ap.parse_args().out
    expected = int(re.search(r"kEmTailSize = (\d+)u", INC.read_text(encoding="utf-8")).group(1))
    problems = [f"missing {p}" for p in [ASSETS] + [AERITH / n for n in SMALL] if not p.is_file()]
    if ASSETS.is_file() and ASSETS.stat().st_size != expected:
        problems.append(f"{ASSETS.name} is {ASSETS.stat().st_size} bytes, the program expects {expected}")
    if problems:
        sys.exit("Not made:\n  " + "\n  ".join(problems))
    shutil.rmtree(out, ignore_errors=True)
    out.mkdir(parents=True)
    for n in SMALL:
        shutil.copyfile(AERITH / n, out / n)
    try:
        os.link(ASSETS, out / ASSETS.name)  # a hard link: the 338 MB file is not stored twice (same drive only)
    except OSError:
        shutil.copyfile(ASSETS, out / ASSETS.name)
    print(f"{out}: {len(list(out.iterdir()))} files, {sum(f.stat().st_size for f in out.iterdir()) >> 20} MB")
    for f in sorted(out.iterdir()):
        print(f"  {f.name:20} {f.stat().st_size:>12}")


if __name__ == "__main__":
    main()

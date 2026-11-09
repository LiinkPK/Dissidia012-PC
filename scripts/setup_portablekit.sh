#!/usr/bin/env bash
# Gets PortableKit for the build: clones the upstream project (TeamGDB/PortableKit, MIT) at the commit this port is based on
# and applies two patch series on top: the upstream port's (third_party/dissidia012-pc/port/portablekit-patches) and this
# project's (patches/portablekit). Nothing of PortableKit itself is stored in this repository.
#   bash scripts/setup_portablekit.sh            (creates third_party/PortableKit-d012; does nothing if it is there)
#   PORTABLEKIT_SOURCE=<local clone or URL>      clone from there instead of GitHub (it must contain commit 33800c4)
#   FORCE=1                                      remove an existing third_party/PortableKit-d012 and start over
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST="${PK_DEST:-$ROOT/third_party/PortableKit-d012}"
BASE=33800c4060c53f3233e08f8ab2cc4590a0872063
SOURCE="${PORTABLEKIT_SOURCE:-https://github.com/TeamGDB/PortableKit.git}"
[ "${FORCE:-0}" = 1 ] && rm -rf "$DEST"
# Up to date only when it was patched with as many patches as there are now: a copy of an older checkout of this project is made again
WANT="$(ls "$ROOT"/third_party/dissidia012-pc/port/portablekit-patches/*.patch "$ROOT"/patches/portablekit/*.patch | wc -l | tr -d ' ')"
HAVE="$(sed 's/ .*//' "$DEST/.d012_patched" 2>/dev/null || echo 0)"
if [ -f "$DEST/cmake/PortableKit.cmake" ] && [ -f "$DEST/.d012_patched" ] && [ "$WANT" = "$HAVE" ]; then echo "PortableKit is already set up: $DEST ($HAVE patches)"; exit 0; fi
[ -d "$DEST" ] && echo "PortableKit in $DEST has $HAVE patches, $WANT are needed: making it again"
rm -rf "$DEST"
command -v git >/dev/null || { echo "git is needed"; exit 1; }
echo "Cloning PortableKit from $SOURCE ..."
git clone -q "$SOURCE" "$DEST"
cd "$DEST"
git checkout -q "$BASE"
git config user.name "d012 setup"; git config user.email "setup@localhost"; git config core.autocrlf false
n=0
for patch in "$ROOT"/third_party/dissidia012-pc/port/portablekit-patches/*.patch "$ROOT"/patches/portablekit/*.patch; do
  # the patches may have been checked out with Windows line endings, which git am does not take
  tr -d '\r' < "$patch" | git am -q || { echo "Patch failed: $patch"; git am --abort 2>/dev/null || true; exit 1; }
  n=$((n+1))
done
echo "$n patches applied" > .d012_patched
echo "PortableKit ready: $DEST ($n patches)"

#!/usr/bin/env bash
# One-command Linux build + packaging. Usage: bash scripts/build_linux.sh
# Output: dist/d012_native-linux/ (d012_native, run.sh, lib/, overlays/, fonts/, requirements.sh, README.txt), made from the
# build and from release/linux/ (the Linux-only files kept in the repo). Windows-only files (release/requirements.bat, .dll,
# .exe) are never copied, and the player's own folders (game, saves, mods) go in empty. Set REL_DIR to put it elsewhere.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PK="${PORTABLEKIT_ROOT:-$ROOT/third_party/PortableKit-d012}"  # the copy in this repo; set PORTABLEKIT_ROOT to use another
SDL_SRC="${SDL_SRC:-$HOME/Documents/SDL}"
# Where build files go. FFmpeg's build needs symlinks, which NTFS/exFAT/FAT mounts (a shared Windows drive) refuse,
# so fall back to a native Linux folder when the project is on one. Override with OUT_DIR=/some/path.
OUT="${OUT_DIR:-$ROOT/out}"
mkdir -p "$OUT"
if ! ln -s probe "$OUT/.symlink_probe" 2>/dev/null; then
  OUT="$HOME/.cache/d012_native_build"
  echo "Project folder does not support symlinks; building in $OUT instead (kept between runs, so builds stay incremental)."
  mkdir -p "$OUT"
else
  rm -f "$OUT/.symlink_probe"
fi
SDL_PREFIX="$OUT/sdl3-install"
BUILD="$OUT/d012_vk"
REL="${REL_DIR:-$ROOT/dist/d012_native-linux}"
JOBS="${JOBS:-2}"

# PortableKit is not stored in this repository: fetch and patch it the first time.
[ -f "$PK/cmake/PortableKit.cmake" ] || { [ -z "${PORTABLEKIT_ROOT:-}" ] && bash "$ROOT/scripts/setup_portablekit.sh"; }
[ -f "$PK/cmake/PortableKit.cmake" ] || { echo "PortableKit not found: $PK (set PORTABLEKIT_ROOT)"; exit 1; }

echo "== 1/5 dependencies (sudo; apt/dnf/pacman/zypper/apk). Skip with SKIP_DEPS=1 =="
# shellcheck disable=SC1091
. "$ROOT/scripts/linux_deps.sh"
[ "${SKIP_DEPS:-0}" = 1 ] || d012_install_build
# ccache is optional: only use it if present.
LAUNCHER=()
command -v ccache >/dev/null 2>&1 && LAUNCHER=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)

echo "== 2/5 SDL3 =="
if [ ! -f "$SDL_PREFIX/lib/cmake/SDL3/SDL3Config.cmake" ] && [ ! -f "$SDL_PREFIX/lib64/cmake/SDL3/SDL3Config.cmake" ]; then
  [ -f "$SDL_SRC/CMakeLists.txt" ] || { echo "SDL3 source not found: $SDL_SRC (set SDL_SRC)"; exit 1; }
  cmake -S "$SDL_SRC" -B "$OUT/sdl3-build" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$SDL_PREFIX" -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF
  cmake --build "$OUT/sdl3-build" -j"$JOBS"
  cmake --install "$OUT/sdl3-build"
fi
SDL_CMAKE="$(dirname "$(find "$SDL_PREFIX" -name SDL3Config.cmake | head -1)")"

echo "== 3/5 configure =="
[ -d "$ROOT/profiles/d012_pk/work/overlays" ] || { echo "Missing profiles/d012_pk/work/overlays"; exit 1; }
# Incremental: the existing cache is kept so only what changed is rebuilt. Set CLEAN=1 to start from scratch.
[ "${CLEAN:-0}" = 1 ] && rm -rf "$BUILD"
cmake -S "$ROOT/profiles/d012_vk" -B "$BUILD" -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" ${LAUNCHER[@]+"${LAUNCHER[@]}"}

echo "== 4/5 build (-j$JOBS) =="
cmake --build "$BUILD" -j"$JOBS"

echo "== 5/5 package -> $REL =="
mkdir -p "$REL/game" "$REL/lib" "$REL/data/mods" "$REL/data/ms0/PSP/GAME" "$REL/data/ms0/PSP/SAVEDATA"
rm -rf "$REL/overlays"; mkdir -p "$REL/overlays"
install -m755 "$BUILD/bin/d012_native" "$REL/d012_native"
cp -a "$BUILD"/bin/*.so* "$REL/lib/" 2>/dev/null || true
cp -a "$BUILD"/bin/overlays/. "$REL/overlays/"
find "$SDL_PREFIX" \( -name 'libSDL3.so*' \) -exec cp -a {} "$REL/lib/" \;
find "$BUILD" -path '*ffmpeg*' -name 'lib*.so*' -exec cp -an {} "$REL/lib/" \; 2>/dev/null || true
rm -f "$REL/psp_recomp"

# run.sh, requirements.sh, README.txt and the fonts are kept in release/linux/ and copied as they are.
cp -a "$ROOT/release/linux/." "$REL/"
cp -f "$ROOT/scripts/linux_deps.sh" "$REL/linux_deps.sh"
# Nothing for Windows or macOS travels in the Linux package.
find "$REL" -type f \( -name '*.dll' -o -name '*.exe' -o -name '*.bat' -o -name '*.ps1' -o -name '*.dylib' \) -delete
chmod +x "$REL/run.sh" "$REL/requirements.sh" "$REL/d012_native"
echo "Done: $REL"; ls -la "$REL"

#!/usr/bin/env bash
# One-command Linux build + packaging. Usage: bash scripts/build_linux.sh
# Output: dist/ itself (d012_native, run.sh, lib/, overlays/, fonts/, requirements.sh, README.txt), made from the
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
REL="${REL_DIR:-$ROOT/dist}"
JOBS="${JOBS:-$(nproc)}"
# Generated code: -O1 compiles much faster than -O2 (GEN_OPT=2 or 3 to change). GEN_JOBS = units compiled at once
# (default RAM / 3 GiB, at least 1; each needs 1-2+ GiB).
GEN_OPT="${GEN_OPT:-1}"
RAM_GIB=$(( $(awk '/MemTotal/{print $2}' /proc/meminfo) / 1048576 ))
GEN_JOBS="${GEN_JOBS:-$(( RAM_GIB / 3 < 1 ? 1 : RAM_GIB / 3 ))}"

# PortableKit is not stored in this repository: fetch and patch it the first time.
# Always asked: the script does nothing when PortableKit is current, and makes it again when the folder is an older copy (a stale
# PortableKit mixed with newer project files fails to compile).
[ -n "${PORTABLEKIT_ROOT:-}" ] || bash "$ROOT/scripts/setup_portablekit.sh"
[ -f "$PK/cmake/PortableKit.cmake" ] || { echo "PortableKit not found: $PK (set PORTABLEKIT_ROOT)"; exit 1; }

# Everything the package is made from must be here before hours of building start.
for need in release/linux/run.sh release/linux/requirements.sh release/linux/README.txt release/linux/fonts \
            profiles/d012_pk/work/generated profiles/d012_pk/work/overlays scripts/linux_deps.sh; do
  [ -e "$ROOT/$need" ] || { echo "ERROR: $need is missing in $ROOT (copy it from the repository; release/linux holds run.sh, requirements.sh, README.txt and fonts/)"; exit 1; }
done

echo "== 1/5 dependencies (sudo; apt/dnf/pacman/zypper/apk). Skip with SKIP_DEPS=1 =="
# shellcheck disable=SC1091
. "$ROOT/scripts/linux_deps.sh"
[ "${SKIP_DEPS:-0}" = 1 ] || d012_install_build
# ccache is optional: only use it if present.
LAUNCHER=()
command -v ccache >/dev/null 2>&1 && LAUNCHER=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)

echo "== 2/5 SDL3 =="
if [ ! -f "$SDL_PREFIX/lib/cmake/SDL3/SDL3Config.cmake" ] && [ ! -f "$SDL_PREFIX/lib64/cmake/SDL3/SDL3Config.cmake" ]; then
  if [ ! -f "$SDL_SRC/CMakeLists.txt" ]; then
    # A clean machine has no SDL3 source: fetch the release (SDL_VERSION, default 3.4.18) into the build folder.
    SDL_VERSION="${SDL_VERSION:-3.4.18}"
    SDL_SRC="$OUT/SDL3-$SDL_VERSION"
    if [ ! -f "$SDL_SRC/CMakeLists.txt" ]; then
      echo "SDL3 source not found in ~/Documents/SDL: downloading SDL $SDL_VERSION"
      command -v curl >/dev/null 2>&1 || { echo "curl is needed to download SDL3 (or set SDL_SRC to an SDL3 source folder)"; exit 1; }
      curl -fL --retry 3 -o "$OUT/SDL3-$SDL_VERSION.tar.gz" \
        "https://github.com/libsdl-org/SDL/releases/download/release-$SDL_VERSION/SDL3-$SDL_VERSION.tar.gz" \
        || { echo "Could not download SDL3 $SDL_VERSION: put an SDL3 source folder in ~/Documents/SDL or set SDL_SRC (and SDL_VERSION for another release)"; exit 1; }
      tar -C "$OUT" -xzf "$OUT/SDL3-$SDL_VERSION.tar.gz"
    fi
  fi
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
  -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" \
  -DPSPRECOMP_GENERATED_OPT_LEVEL="$GEN_OPT" -DPSPRECOMP_GENERATED_JOBS="$GEN_JOBS" ${LAUNCHER[@]+"${LAUNCHER[@]}"}

echo "== 4/5 build (-j$JOBS) =="
# -k 0: keep compiling what does not depend on a failure, so one error does not stop hours of work
# The whole output is kept in build_linux.log: the terminal only shows the last line when ninja stops.
BUILD_LOG="$ROOT/build_linux.log"
set +e
cmake --build "$BUILD" -j"$JOBS" -- -k 0 2>&1 | tee "$BUILD_LOG"
BUILD_RC=${PIPESTATUS[0]}
set -e
if [ "$BUILD_RC" != 0 ]; then
  echo
  echo "===== BUILD FAILED. The first errors: ====="
  grep -n -m 6 -B1 -A6 -E 'error:|error |FAILED:|undefined reference|No such file' "$BUILD_LOG" | cut -c1-240
  echo "===== Full log: $BUILD_LOG (send this file) ====="
  exit "$BUILD_RC"
fi

echo "== 5/5 package -> $REL =="
# dist/ also holds the Windows and macOS packages, so only what this script makes is cleared: a stray textures/ in the root
# and the old tarball or zip.
rm -rf "$REL/textures" "$REL/lib" "$REL/d012_native-linux-x86_64.tar.gz" "$REL/d012_native-linux.zip"
mkdir -p "$REL/game" "$REL/lib" "$REL/data/mods" "$REL/data/ms0/PSP/GAME" "$REL/data/ms0/PSP/SAVEDATA"
rm -rf "$REL/overlays"; mkdir -p "$REL/overlays"
install -m755 "$BUILD/bin/d012_native" "$REL/d012_native"
cp -a "$BUILD"/bin/*.so* "$REL/lib/" 2>/dev/null || true
cp -a "$BUILD"/bin/overlays/. "$REL/overlays/" 2>/dev/null || true
# Battle, menu and extra code live in the overlays and the release has no interpreter: a package without them
# crashes at the first battle ("no function at 0x089E...").
[ "$(find "$REL/overlays" -type f -name '*.so' | wc -l)" -ge 4 ] || { echo "ERROR: fewer than 4 overlay libraries in $BUILD/bin/overlays (a build failure hidden by -k 0?)"; exit 1; }
find "$SDL_PREFIX" \( -name 'libSDL3.so*' \) -exec cp -a {} "$REL/lib/" \;
find "$BUILD" -path '*ffmpeg*' -name 'lib*.so*' -exec cp -an {} "$REL/lib/" \; 2>/dev/null || true
rm -f "$REL/psp_recomp"

# run.sh, requirements.sh, README.txt and the fonts are kept in release/linux/ and copied as they are.
cp -a "$ROOT/release/linux/." "$REL/"
cp -f "$ROOT/scripts/linux_deps.sh" "$REL/linux_deps.sh"
# Icon, and the Memory Stick extras kept in release/data/ms0/PSP/ (CHEATS with the ULES and ULUS files, textures/ in release/data/textures/<disc id>, if present).
# The fonts stay next to the executable (fonts/): that is where PortableKit looks for them, not in data/.
[ -f "$ROOT/favicon.png" ] && cp -f "$ROOT/favicon.png" "$REL/d012_native.png"
# Only CHEATS (the ULES and ULUS files) is taken from release/data/ms0/PSP: never a DLC or a save that happens to be there.
mkdir -p "$REL/data/ms0/PSP/CHEATS"
[ -d "$ROOT/release/data/ms0/PSP/CHEATS" ] && cp -a "$ROOT/release/data/ms0/PSP/CHEATS/." "$REL/data/ms0/PSP/CHEATS/"
if [ -d "$ROOT/release/data/textures" ]; then mkdir -p "$REL/data/textures"; cp -a "$ROOT/release/data/textures/." "$REL/data/textures/"; else echo "Note: no release/data/textures: the package has no texture pack."; fi
# Textures live in data/textures only, never in the root of the package.
rm -rf "$REL/textures"
# Logs are the player's own (running the game from this folder makes data/logs): they never travel in a package.
rm -rf "$REL/data/logs"
# Nothing for Windows or macOS travels in the Linux package.
# dist/ also holds the win and macos packages: they are left alone.
find "$REL" -type f \( -name '*.dll' -o -name '*.exe' -o -name '*.bat' -o -name '*.ps1' -o -name '*.dylib' \) -not -path "$REL/win/*" -not -path "$REL/macos/*" -not -path "$REL/linux/*" -delete
chmod +x "$REL/run.sh" "$REL/requirements.sh" "$REL/d012_native"
# The package: d012_native-linux.tar.gz (the files at the top, no folder around them; the in-game updater takes it as it is).
# The player's own files never go in: nothing inside game/, mods, PSP/GAME (ISO, DLC) or PSP/SAVEDATA, no logs, settings or caches.
ITEMS=()
for item in d012_native lib overlays fonts data game run.sh requirements.sh linux_deps.sh README.txt d012_native.png d012_native.desktop; do
  [ -e "$REL/$item" ] && ITEMS+=("$item")
done
TARBALL="$REL/d012_native-linux.tar.gz"
TMP_TAR="$(mktemp "${TMPDIR:-/tmp}/d012_linux_XXXXXX.tar.gz")"
tar -C "$REL" -czf "$TMP_TAR"   --exclude='game/*' --exclude='data/mods/*' --exclude='data/ms0/PSP/GAME/*' --exclude='data/ms0/PSP/SAVEDATA/*'   --exclude='data/logs' --exclude='data/settings.ini' --exclude='data/pipeline_cache.bin' --exclude='data/pipeline_keys.bin'   "${ITEMS[@]}"
# Leave only the tar in dist/. What the player put in the empty folders (an ISO, DLC, mods, saves) is never deleted: those
# folders are kept, with a warning.
rm -f "$TARBALL"
KEPT=()
for own in "$REL/game" "$REL/data/mods" "$REL/data/ms0/PSP/GAME" "$REL/data/ms0/PSP/SAVEDATA"; do
  [ -n "$(ls -A "$own" 2>/dev/null)" ] && KEPT+=("$own")
done
if [ "${#KEPT[@]}" -eq 0 ]; then
  for item in "${ITEMS[@]}"; do rm -rf "${REL:?}/$item"; done
else
  for item in "${ITEMS[@]}"; do
    case "$item" in game|data) continue ;; esac
    rm -rf "${REL:?}/$item"
  done
  # data/ and game/ stay as they are: they hold files of yours. Only what the package made there goes.
  rm -rf "$REL/data/textures" "$REL/data/ms0/PSP/CHEATS" "$REL/data/logs"
  for own in "${KEPT[@]}"; do echo "NOT deleted (your files): $own"; done
fi
mv -f "$TMP_TAR" "$TARBALL"
echo "Release package: $TARBALL"
echo "Done: $REL"; ls -la "$REL"

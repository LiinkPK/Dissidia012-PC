#!/usr/bin/env bash
# macOS universal build (Intel x86_64 + Apple Silicon arm64) and packaging. Run on a Mac:  bash scripts/build_macos.sh
# Output: dist/d012_native-macos/ (d012_native, run.sh, lib/, overlays/, fonts/, README.txt), made from the builds and from
# release/macos/. Windows and Linux files are never copied; the player's own folders (game, saves, mods) go in empty.
#
# Needs: Xcode or the Command Line Tools, CMake, Ninja, Python 3 (brew install cmake ninja python), the LunarG Vulkan SDK for
# macOS (it is universal and holds the Vulkan loader, MoltenVK and glslang: https://vulkan.lunarg.com/sdk/home#mac) and the
# SDL3 source (SDL_SRC, default ~/Documents/SDL).
#
# How the universal binary is made: SDL3 is built once for both CPUs; the game is built once per CPU (ARCHS, default
# "x86_64 arm64", the generated code compiles twice) and the two are joined with lipo. FFmpeg is cross-compiled for the CPU
# that is not the Mac's own. To test quickly on this Mac only: ARCHS=$(uname -m) bash scripts/build_macos.sh
# Other settings: PORTABLEKIT_ROOT, SDL_SRC, VULKAN_SDK, OUT_DIR, REL_DIR, JOBS, MACOSX_DEPLOYMENT_TARGET (default 12.0).
set -euo pipefail
[ "$(uname -s)" = Darwin ] || { echo "This script builds the macOS version and must run on a Mac."; exit 1; }
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PK="${PORTABLEKIT_ROOT:-$ROOT/third_party/PortableKit-d012}"
SDL_SRC="${SDL_SRC:-$HOME/Documents/SDL}"
ARCHS="${ARCHS:-x86_64 arm64}"
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-12.0}"
OUT="${OUT_DIR:-$ROOT/out/macos}"
REL="${REL_DIR:-$ROOT/dist/d012_native-macos}"
JOBS="${JOBS:-$(sysctl -n hw.ncpu)}"
SDL_PREFIX="$OUT/sdl3-install"

echo "== 1/6 checks =="
xcode-select -p >/dev/null 2>&1 || { echo "Install the Command Line Tools first: xcode-select --install"; exit 1; }
for tool in cmake ninja python3 lipo codesign; do
  command -v "$tool" >/dev/null 2>&1 || { echo "Missing $tool (brew install cmake ninja python)"; exit 1; }
done
# PortableKit is not stored in this repository: fetch and patch it the first time.
[ -f "$PK/cmake/PortableKit.cmake" ] || { [ -z "${PORTABLEKIT_ROOT:-}" ] && bash "$ROOT/scripts/setup_portablekit.sh"; }
[ -f "$PK/cmake/PortableKit.cmake" ] || { echo "PortableKit not found: $PK (set PORTABLEKIT_ROOT)"; exit 1; }
[ -d "$ROOT/profiles/d012_pk/work/overlays" ] || { echo "Missing profiles/d012_pk/work/overlays"; exit 1; }
if [ -z "${VULKAN_SDK:-}" ]; then
  VULKAN_SDK="$(ls -d "$HOME"/VulkanSDK/*/macOS 2>/dev/null | sort -V | tail -1 || true)"
fi
[ -f "${VULKAN_SDK:-/nonexistent}/lib/libMoltenVK.dylib" ] || { echo "Vulkan SDK for macOS not found. Install it from https://vulkan.lunarg.com/sdk/home#mac or set VULKAN_SDK=<.../macOS>."; exit 1; }
export VULKAN_SDK
export PATH="$VULKAN_SDK/bin:$PATH"
for arch in $ARCHS; do case "$arch" in x86_64|arm64) ;; *) echo "ARCHS holds x86_64 and arm64 only (got $arch)"; exit 1;; esac; done
mkdir -p "$OUT"

echo "== 2/6 SDL3 (universal) =="
if ! find "$SDL_PREFIX" -name SDL3Config.cmake 2>/dev/null | grep -q .; then
  [ -f "$SDL_SRC/CMakeLists.txt" ] || { echo "SDL3 source not found: $SDL_SRC (set SDL_SRC)"; exit 1; }
  cmake -S "$SDL_SRC" -B "$OUT/sdl3-build" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DCMAKE_OSX_DEPLOYMENT_TARGET="$MACOSX_DEPLOYMENT_TARGET" \
    -DCMAKE_INSTALL_PREFIX="$SDL_PREFIX" -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF
  cmake --build "$OUT/sdl3-build" -j"$JOBS"
  cmake --install "$OUT/sdl3-build"
fi
SDL_CMAKE="$(dirname "$(find "$SDL_PREFIX" -name SDL3Config.cmake | head -1)")"

echo "== 3/6 build per CPU: $ARCHS (-j$JOBS) =="
for arch in $ARCHS; do
  echo "-- $arch --"
  cmake -S "$ROOT/profiles/d012_vk" -B "$OUT/d012_vk-$arch" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_OSX_ARCHITECTURES="$arch" -DCMAKE_OSX_DEPLOYMENT_TARGET="$MACOSX_DEPLOYMENT_TARGET" \
    -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" -DCMAKE_PREFIX_PATH="$VULKAN_SDK"
  cmake --build "$OUT/d012_vk-$arch" -j"$JOBS"
done

echo "== 4/6 joining the CPUs -> $REL =="
FIRST="${ARCHS%% *}"
B1="$OUT/d012_vk-$FIRST/bin"
rm -rf "$REL"
mkdir -p "$REL/lib" "$REL/overlays" "$REL/game" "$REL/data/mods" "$REL/data/ms0/PSP/GAME" "$REL/data/ms0/PSP/SAVEDATA"
# join <relative path inside bin/>  -> $REL/<same path>; one file per CPU, merged with lipo (a single CPU is just copied)
join() {
  local rel="$1" dest="$2" inputs=()
  for arch in $ARCHS; do inputs+=("$OUT/d012_vk-$arch/bin/$rel"); done
  if [ "${#inputs[@]}" -gt 1 ]; then lipo -create "${inputs[@]}" -output "$dest"; else cp "${inputs[0]}" "$dest"; fi
}
join d012_native "$REL/d012_native"
chmod +x "$REL/d012_native"
for f in "$B1"/overlays/*; do [ -f "$f" ] && join "overlays/$(basename "$f")" "$REL/overlays/$(basename "$f")"; done
# FFmpeg's libraries (real files, not links)
if [ -d "$B1/lib" ]; then
  for f in "$B1"/lib/*.dylib; do [ -f "$f" ] && [ ! -L "$f" ] && join "lib/$(basename "$f")" "$REL/lib/$(basename "$f")"; done
fi
# SDL3 (already universal) and the Vulkan loader and MoltenVK from the SDK (universal)
cp -a "$SDL_PREFIX"/lib/libSDL3*.dylib "$REL/lib/"
cp -L "$VULKAN_SDK/lib/libvulkan.1.dylib" "$REL/lib/libvulkan.1.dylib"
cp -L "$VULKAN_SDK/lib/libMoltenVK.dylib" "$REL/lib/libMoltenVK.dylib"
cat > "$REL/lib/MoltenVK_icd.json" <<'JSON'
{ "file_format_version": "1.0.0", "ICD": { "library_path": "libMoltenVK.dylib", "api_version": "1.2.0", "is_portability_driver": true } }
JSON
# the executable finds lib/ beside it
install_name_tool -add_rpath "@executable_path/lib" "$REL/d012_native" 2>/dev/null || true

echo "== 5/6 release files =="
cp -a "$ROOT/release/macos/." "$REL/"
chmod +x "$REL/run.sh"
# Nothing for Windows or Linux travels in the macOS package.
find "$REL" -type f \( -name '*.dll' -o -name '*.exe' -o -name '*.bat' -o -name '*.ps1' -o -name '*.so' -o -name '*.so.*' \) -delete
rm -f "$REL/requirements.sh" "$REL/linux_deps.sh"
# arm64 code must be signed to run: ad hoc, after every edit above.
find "$REL" -type f \( -name '*.dylib' -o -name 'd012_native' \) -exec codesign --force --sign - {} \;

echo "== 6/6 check =="
for f in "$REL/d012_native" "$REL"/overlays/* "$REL"/lib/*.dylib; do
  [ -f "$f" ] && printf '%s: %s\n' "$(basename "$f")" "$(lipo -archs "$f" 2>/dev/null || echo 'not a Mach-O')"
done
echo "Done: $REL"

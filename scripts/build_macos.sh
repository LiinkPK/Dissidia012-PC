#!/usr/bin/env bash
# macOS universal build (Intel x86_64 + Apple Silicon arm64) and packaging. Run on a Mac:  bash scripts/build_macos.sh
# Output: dist/Dissidia 012 Final Fantasy HD Remastered.app and d012_native-macos.tar.gz (the app inside), made from the builds and from
# release/macos/. Windows and Linux files are never copied; the player's own folders (game, saves, mods) go in empty.
#
# Needs: Xcode or the Command Line Tools, CMake, Ninja, Python 3 (brew install cmake ninja python), the LunarG Vulkan SDK for
# macOS (it is universal and holds the Vulkan loader, MoltenVK and glslang: https://vulkan.lunarg.com/sdk/home#mac) and the
# SDL3 source (SDL_SRC, default ~/Documents/SDL).
#
# Speed: by default only this Mac's own CPU is built (the generated code is the slow part and a universal build compiles it
# twice). UNIVERSAL=1 (or ARCHS="x86_64 arm64") builds both CPUs and joins them with lipo; FFmpeg is then cross-compiled for
# the other CPU. The generated code is compiled at -O1 (GEN_OPT=2 or 3 for the old, much slower, faster-running code), through
# ccache when installed (brew install ccache; reruns are then nearly free) and under caffeinate so the Mac cannot sleep.
# GEN_JOBS = how many generated units compile at once (default: RAM / 3 GiB, at least 1); each one needs 1-2+ GiB.
# Other settings: PORTABLEKIT_ROOT, SDL_SRC, VULKAN_SDK, OUT_DIR, REL_DIR, JOBS, MACOSX_DEPLOYMENT_TARGET (default 12.0).
set -euo pipefail
[ "$(uname -s)" = Darwin ] || { echo "This script builds the macOS version and must run on a Mac."; exit 1; }
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PK="${PORTABLEKIT_ROOT:-$ROOT/third_party/PortableKit-d012}"
SDL_SRC="${SDL_SRC:-$HOME/Documents/SDL}"
if [ "${UNIVERSAL:-0}" = 1 ]; then ARCHS="${ARCHS:-x86_64 arm64}"; else ARCHS="${ARCHS:-$(uname -m)}"; fi
GEN_OPT="${GEN_OPT:-1}"
RAM_GIB=$(( $(sysctl -n hw.memsize) / 1073741824 ))
GEN_JOBS="${GEN_JOBS:-$(( RAM_GIB / 3 < 1 ? 1 : RAM_GIB / 3 ))}"
# Keep the Mac awake for the whole build (re-run this script under caffeinate once).
if [ -z "${D012_CAFFEINATED:-}" ] && command -v caffeinate >/dev/null 2>&1; then
  D012_CAFFEINATED=1 exec caffeinate -dimsu bash "$0" "$@"
fi
LAUNCHER=()
command -v ccache >/dev/null 2>&1 && LAUNCHER=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-12.0}"
OUT="${OUT_DIR:-$ROOT/out/macos}"
REL="${REL_DIR:-$ROOT/dist}"
JOBS="${JOBS:-$(sysctl -n hw.ncpu)}"
SDL_PREFIX="$OUT/sdl3-install"

echo "== 1/6 checks =="
xcode-select -p >/dev/null 2>&1 || { echo "Install the Command Line Tools first: xcode-select --install"; exit 1; }
for tool in cmake ninja python3 lipo codesign; do
  command -v "$tool" >/dev/null 2>&1 || { echo "Missing $tool (brew install cmake ninja python)"; exit 1; }
done
# PortableKit is not stored in this repository: fetch and patch it the first time.
# Always asked: the script does nothing when PortableKit is current, and makes it again when the folder is an older copy (a stale
# PortableKit mixed with newer project files fails to compile).
[ -n "${PORTABLEKIT_ROOT:-}" ] || bash "$ROOT/scripts/setup_portablekit.sh"
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

echo "== 3/6 build per CPU: $ARCHS (-j$JOBS, generated units $GEN_JOBS at once, -O$GEN_OPT) =="
for arch in $ARCHS; do
  echo "-- $arch --"
  cmake -S "$ROOT/profiles/d012_vk" -B "$OUT/d012_vk-$arch" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_OSX_ARCHITECTURES="$arch" -DCMAKE_OSX_DEPLOYMENT_TARGET="$MACOSX_DEPLOYMENT_TARGET" \
    -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" -DCMAKE_PREFIX_PATH="$VULKAN_SDK"     -DPSPRECOMP_GENERATED_OPT_LEVEL="$GEN_OPT" -DPSPRECOMP_GENERATED_JOBS="$GEN_JOBS" ${LAUNCHER[@]+"${LAUNCHER[@]}"}
  # -k 0: keep compiling what does not depend on a failure, so one error does not stop hours of work
  cmake --build "$OUT/d012_vk-$arch" -j"$JOBS" -- -k 0
done

echo "== 4/6 joining the CPUs -> $REL =="
FIRST="${ARCHS%% *}"
B1="$OUT/d012_vk-$FIRST/bin"
# dist/ may also hold other packages: only what this script makes is cleared.
rm -rf "$REL/Dissidia 012 Final Fantasy HD Remastered.app" "$REL/lib" "$REL/overlays" "$REL/textures" "$REL/d012_native-macos-universal.tar.gz" "$REL/d012_native-macos.tar.gz"
mkdir -p "$REL/lib" "$REL/overlays"
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

echo "== 5/6 the .app =="
# What was built in $REL (d012_native, lib/, overlays/) goes inside Dissidia 012 Final Fantasy HD Remastered.app. The app holds
# the program only. Everything the player sees or changes (ISO, saves, textures, cheats, DLC, mods, logs, settings) lives in
# ~/Library/Application Support/<APP_NAME>/, so replacing the app (an update, a drag and drop) never touches it.
APP_NAME="Dissidia 012 Final Fantasy HD Remastered"
APP="$REL/$APP_NAME.app"
VERSION="$(sed -n 's/.*kReleaseVersion = "v\{0,1\}\([^"]*\)".*/\1/p' "$ROOT/profiles/d012/host/d012_profile.cpp" | head -1)"
VERSION="${VERSION:-1.0}"
rm -rf "$APP"
MACOS="$APP/Contents/MacOS"; RES="$APP/Contents/Resources"
mkdir -p "$MACOS" "$RES/defaults/ms0/PSP/CHEATS"
# The program, its libraries, the overlays and the fonts stay together: PortableKit looks for them beside the executable.
mv "$REL/d012_native" "$MACOS/d012_native"
mv "$REL/lib" "$MACOS/lib"
mv "$REL/overlays" "$MACOS/overlays"
cp -a "$ROOT/release/macos/fonts" "$MACOS/fonts"
# First-run defaults, copied to the data folder only where a file is missing (the player's edits are never overwritten).
[ -d "$ROOT/release/data/ms0/PSP/CHEATS" ] && cp -a "$ROOT/release/data/ms0/PSP/CHEATS/." "$RES/defaults/ms0/PSP/CHEATS/"
if [ -d "$ROOT/release/data/textures" ]; then mkdir -p "$RES/defaults/textures"; cp -a "$ROOT/release/data/textures/." "$RES/defaults/textures/"; else echo "Note: no release/data/textures: the app has no texture pack."; fi
# The launcher is the bundle's executable: it points the game at the data folder and at MoltenVK, then starts it.
cat > "$MACOS/Dissidia012" <<'LAUNCHER'
#!/bin/bash
# The portable run.sh's flow with the player's folders in Application Support: game/ (the ISO) and data/ (the setup's
# EBOOT.ELF, settings, saves in ms0/, textures, cheats, mods, logs).
DIR="$(cd "$(dirname "$0")" && pwd)"
RES="$(cd "$DIR/../Resources" && pwd)"
SUPPORT="${D012_SUPPORT_DIR:-$HOME/Library/Application Support/Dissidia 012 Final Fantasy HD Remastered}"
LOG="$SUPPORT/data/logs/D012Native.log"
mkdir -p "$SUPPORT/game" "$SUPPORT/data/mods" "$SUPPORT/data/logs"
# The setup and the game both use this data folder (without it the setup uses a folder of its own).
export D012_DATA_DIR="$SUPPORT/data" D012_MEMORY_STICK_DIR="$SUPPORT/data/ms0"
# The cheats are copied where missing (the player's edits stay). The texture pack is big: it is linked, not copied twice.
cp -Rn "$RES/defaults/ms0" "$SUPPORT/data/" 2>/dev/null
[ -e "$SUPPORT/data/textures" ] || ln -s "$RES/defaults/textures" "$SUPPORT/data/textures" 2>/dev/null
export DYLD_FALLBACK_LIBRARY_PATH="$DIR/lib${DYLD_FALLBACK_LIBRARY_PATH:+:$DYLD_FALLBACK_LIBRARY_PATH}"
export VK_DRIVER_FILES="$DIR/lib/MoltenVK_icd.json"
export VK_ICD_FILENAMES="$VK_DRIVER_FILES"
say() { osascript -e "display dialog \"$1\" buttons {\"OK\"} default button \"OK\" with title \"Dissidia 012\"" >/dev/null 2>&1; }
cd "$SUPPORT"
if [ ! -f "$SUPPORT/data/EBOOT.ELF" ]; then
  # First start: an ISO already in game/ is used; otherwise the player picks the disc image in a file dialog. The image is
  # used where it is (not copied), so nothing needs moving.
  ISO="$(ls "$SUPPORT"/game/*.iso 2>/dev/null | head -1 || true)"
  if [ -z "$ISO" ]; then
    ISO="$(osascript -e 'POSIX path of (choose file with prompt "Choose your Dissidia 012 Duodecim disc image (.iso)" of type {"iso", "public.iso-image"})' 2>/dev/null || true)"
  fi
  [ -n "$ISO" ] || exit 0
  if ! "$DIR/d012_native" --install "$ISO" --in-place >"$LOG" 2>&1; then
    say "Setting the game up from the disc image failed. The log is in data/logs/D012Native.log in the folder that opens next."
    open "$SUPPORT/data/logs"
    exit 1
  fi
fi
export PSPRECOMP_NO_INTERPRETER=1
cd "$DIR"
exec "$DIR/d012_native" "$@" >>"$LOG" 2>&1
LAUNCHER
chmod +x "$MACOS/Dissidia012" "$MACOS/d012_native"
cat > "$APP/Contents/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
  <key>CFBundleName</key><string>$APP_NAME</string>
  <key>CFBundleDisplayName</key><string>$APP_NAME</string>
  <key>CFBundleIdentifier</key><string>com.dissidia012.hd</string>
  <key>CFBundleExecutable</key><string>Dissidia012</string>
  <key>CFBundleIconFile</key><string>AppIcon</string>
  <key>CFBundlePackageType</key><string>APPL</string>
  <key>CFBundleShortVersionString</key><string>$VERSION</string>
  <key>CFBundleVersion</key><string>$VERSION</string>
  <key>LSMinimumSystemVersion</key><string>$MACOSX_DEPLOYMENT_TARGET</string>
  <key>NSHighResolutionCapable</key><true/>
  <key>LSApplicationCategoryType</key><string>public.app-category.games</string>
</dict></plist>
PLIST
# The icon: favicon.png into an .icns (sips and iconutil come with macOS).
if [ -f "$ROOT/favicon.png" ] && command -v iconutil >/dev/null 2>&1; then
  ICONSET="$(mktemp -d "${TMPDIR:-/tmp}/d012_icon.XXXXXX")/AppIcon.iconset"; mkdir -p "$ICONSET"
  for s in 16 32 128 256 512; do
    sips -z $s $s "$ROOT/favicon.png" --out "$ICONSET/icon_${s}x${s}.png" >/dev/null
    sips -z $((s*2)) $((s*2)) "$ROOT/favicon.png" --out "$ICONSET/icon_${s}x${s}@2x.png" >/dev/null
  done
  iconutil -c icns "$ICONSET" -o "$RES/AppIcon.icns" || echo "Note: the icon could not be made."
  rm -rf "$(dirname "$ICONSET")"
fi
# arm64 code must be signed to run: every library and the program, then the whole app, ad hoc.
find "$MACOS" -type f \( -name '*.dylib' -o -name 'd012_native' -o -name 'ovl*' \) -exec codesign --force --sign - {} \;
codesign --force --deep --sign - "$APP"

echo "== 6/6 check and package =="
for f in "$MACOS/d012_native" "$MACOS"/overlays/* "$MACOS"/lib/*.dylib; do
  [ -f "$f" ] && printf '%s: %s\n' "$(basename "$f")" "$(lipo -archs "$f" 2>/dev/null || echo 'not a Mach-O')"
done
# d012_native-macos.tar.gz holds the .app at its top. A .app is a folder, so it is shipped compressed.
TARBALL="$REL/d012_native-macos.tar.gz"
rm -f "$TARBALL"
# COPYFILE_DISABLE: no ._ files from macOS metadata in the archive.
COPYFILE_DISABLE=1 tar -C "$REL" -czf "$TARBALL" "$APP_NAME.app"
echo "Release package: $TARBALL"
echo "To test without packing: open \"$APP\""
echo "Done: $REL"; ls -la "$REL"

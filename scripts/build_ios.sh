#!/usr/bin/env bash
# EXPERIMENTAL iOS build (arm64, iOS 15+), for personal testing only: makes dist/d012_native-ios.ipa, ad-hoc signed.
# Sideloadly or AltStore re-sign it with your Apple ID when they install it (free ID: valid 7 days). Run on a Mac, or with the
# "Build iOS" workflow. Not tested: PortableKit has no iOS target yet, so expect to fix the first failures one by one.
#
# Needs: Xcode, CMake, Ninja, Python 3, the LunarG Vulkan SDK for macOS (its MoltenVK.xcframework has the iOS slice) and the SDL3 source
# (SDL_SRC). Other settings: VERSION_NAME, PORTABLEKIT_ROOT, VULKAN_SDK, OUT_DIR, REL_DIR, JOBS, GEN_OPT, GEN_JOBS, IOS_DEPLOYMENT_TARGET (default 15.0).
set -euo pipefail
[ "$(uname -s)" = Darwin ] || { echo "The iOS build must run on a Mac."; exit 1; }
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PK="${PORTABLEKIT_ROOT:-$ROOT/third_party/PortableKit-d012}"
SDL_SRC="${SDL_SRC:-$HOME/Documents/SDL}"
IOS_TARGET="${IOS_DEPLOYMENT_TARGET:-15.0}"
# The game's version: kReleaseVersion in the profile (VERSION_NAME overrides it), without the leading "v" for the app's Info.plist.
VERSION_NAME="${VERSION_NAME:-$(sed -n 's/.*kReleaseVersion = "\(.*\)".*/\1/p' "$ROOT/profiles/d012/host/d012_profile.cpp" | head -1)}"
APP_VERSION="${VERSION_NAME#v}"
[ -n "$APP_VERSION" ] || { echo "The game's version is not known (kReleaseVersion): set VERSION_NAME"; exit 1; }
OUT="${OUT_DIR:-$ROOT/out/ios}"
REL="${REL_DIR:-$ROOT/dist}"
JOBS="${JOBS:-$(sysctl -n hw.ncpu)}"
GEN_OPT="${GEN_OPT:-1}"
RAM_GIB=$(( $(sysctl -n hw.memsize) / 1073741824 ))
GEN_JOBS="${GEN_JOBS:-$(( RAM_GIB / 3 < 1 ? 1 : RAM_GIB / 3 ))}"
LAUNCHER=()
command -v ccache >/dev/null 2>&1 && LAUNCHER=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
SDL_PREFIX="$OUT/sdl3-install"
mkdir -p "$OUT"

echo "== 1/5 checks =="
for tool in cmake ninja python3 codesign xcrun; do command -v "$tool" >/dev/null 2>&1 || { echo "Missing $tool"; exit 1; }; done
[ -n "${PORTABLEKIT_ROOT:-}" ] || bash "$ROOT/scripts/setup_portablekit.sh"
[ -f "$PK/cmake/PortableKit.cmake" ] || { echo "PortableKit not found: $PK"; exit 1; }
[ -d "$ROOT/profiles/d012_pk/work/overlays" ] || { echo "Missing profiles/d012_pk/work/overlays"; exit 1; }
if [ -z "${VULKAN_SDK:-}" ]; then VULKAN_SDK="$(ls -d "$HOME"/VulkanSDK/*/macOS 2>/dev/null | sort -V | tail -1 || true)"; fi
XCF="$(find "${VULKAN_SDK:-/nonexistent}/.." -maxdepth 4 -name MoltenVK.xcframework 2>/dev/null | head -1 || true)"
[ -n "$XCF" ] || { echo "MoltenVK.xcframework not found under the Vulkan SDK (set VULKAN_SDK=<.../macOS>)."; exit 1; }
IOS_MVK="$(ls -d "$XCF"/ios-arm64 | head -1)"
export PATH="$VULKAN_SDK/bin:$PATH"

echo "== 2/5 SDL3 for iOS =="
if ! find "$SDL_PREFIX" -name SDL3Config.cmake 2>/dev/null | grep -q .; then
  [ -f "$SDL_SRC/CMakeLists.txt" ] || { echo "SDL3 source not found: $SDL_SRC (set SDL_SRC)"; exit 1; }
  cmake -S "$SDL_SRC" -B "$OUT/sdl3-build" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET="$IOS_TARGET" -DCMAKE_INSTALL_PREFIX="$SDL_PREFIX" \
    -DSDL_SHARED=OFF -DSDL_STATIC=ON -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF
  cmake --build "$OUT/sdl3-build" -j"$JOBS"
  cmake --install "$OUT/sdl3-build"
fi
SDL_CMAKE="$(dirname "$(find "$SDL_PREFIX" -name SDL3Config.cmake | head -1)")"

echo "== 3/5 game build (arm64, -O$GEN_OPT, $GEN_JOBS generated units at once) =="
# What the renderer needs, found here (CMake's own search stays inside the iOS SDK when it cross-compiles) and handed over
# explicitly. A line is printed for each, so a missing one is named.
echo "MoltenVK iOS slice: $IOS_MVK"; ls -la "$IOS_MVK" | head -20
MVK_LIB=""
for c in "$IOS_MVK/libMoltenVK.a" "$IOS_MVK/MoltenVK.framework/MoltenVK" "$IOS_MVK/libMoltenVK.dylib"; do [ -e "$c" ] && { MVK_LIB="$c"; break; }; done
VK_INC="$(ls -d "$VULKAN_SDK/include" "$IOS_MVK/Headers" "$IOS_MVK/MoltenVK.framework/Headers" 2>/dev/null | head -1)"
GLSLANG="$(command -v glslangValidator || command -v glslang || true)"
PY3="$(command -v python3 || true)"
echo "Vulkan library: ${MVK_LIB:-MISSING}"; echo "Vulkan headers: ${VK_INC:-MISSING}"; echo "glslang: ${GLSLANG:-MISSING}"; echo "python3: ${PY3:-MISSING}"
echo "SDL3 config: $SDL_CMAKE"; ls "$SDL_CMAKE" | head -5
{ [ -n "$MVK_LIB" ] && [ -n "$VK_INC" ] && [ -n "$GLSLANG" ] && [ -n "$PY3" ]; } || { echo "Something the renderer needs is missing (see above)."; exit 1; }
cmake -S "$ROOT/profiles/d012_vk" -B "$OUT/d012_vk" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=BOTH \
  -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH \
  -DVulkan_INCLUDE_DIR="$VK_INC" -DVulkan_LIBRARY="$MVK_LIB" -DPORTABLEKIT_GLSLANG="$GLSLANG" -DPython3_EXECUTABLE="$PY3" \
  -DCMAKE_EXE_LINKER_FLAGS="-framework Metal -framework QuartzCore -framework IOSurface -framework UIKit -framework Foundation -framework CoreGraphics" \
  -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET="$IOS_TARGET" \
  -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" -DCMAKE_PREFIX_PATH="$IOS_MVK" \
  -DPSPRECOMP_GENERATED_OPT_LEVEL="$GEN_OPT" -DPSPRECOMP_GENERATED_JOBS="$GEN_JOBS" ${LAUNCHER[@]+"${LAUNCHER[@]}"} 2>&1 | tee "$OUT/configure.log"
# Stop here, not hours later: without the renderer the app would build and then show nothing.
grep -q "Vulkan renderer enabled" "$OUT/configure.log" || {
  echo "The renderer is off. What CMake found:"
  grep -E "^(SDL3_DIR|SDL3_FOUND|Vulkan_[A-Za-z_]*|PORTABLEKIT_GLSLANG|Python3_[A-Za-z_]*):" "$OUT/d012_vk/CMakeCache.txt" || true
  exit 1
}
cmake --build "$OUT/d012_vk" -j"$JOBS" -- -k 0
B="$OUT/d012_vk/bin"
[ -f "$B/d012_native" ] || { echo "The build produced no d012_native"; exit 1; }

echo "== 4/5 app bundle =="
APP="$OUT/Payload/Dissidia012.app"
rm -rf "$OUT/Payload"
mkdir -p "$APP/Frameworks" "$APP/overlays"
cp "$B/d012_native" "$APP/d012_native"
# The overlays are loaded with dlopen at run time: iOS allows that for signed libraries inside the app.
for f in "$B"/overlays/*; do [ -f "$f" ] && cp "$f" "$APP/overlays/"; done
[ -d "$B/lib" ] && for f in "$B"/lib/*.dylib; do [ -f "$f" ] && cp -L "$f" "$APP/Frameworks/"; done
cp -R "$IOS_MVK/MoltenVK.framework" "$APP/Frameworks/" 2>/dev/null || cp "$IOS_MVK"/*.dylib "$APP/Frameworks/" 2>/dev/null || true
cat > "$APP/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
<key>CFBundleExecutable</key><string>d012_native</string>
<key>CFBundleIdentifier</key><string>com.liinkpk.d012hd</string>
<key>CFBundleName</key><string>Dissidia 012</string>
<key>CFBundleDisplayName</key><string>Dissidia 012</string>
<key>CFBundlePackageType</key><string>APPL</string>
<key>CFBundleShortVersionString</key><string>$APP_VERSION</string>
<key>CFBundleVersion</key><string>$APP_VERSION</string>
<key>MinimumOSVersion</key><string>$IOS_TARGET</string>
<key>UIDeviceFamily</key><array><integer>1</integer><integer>2</integer></array>
<key>UIRequiredDeviceCapabilities</key><array><string>arm64</string></array>
<key>UISupportsDocumentBrowser</key><true/>
<key>UIFileSharingEnabled</key><true/>
<key>LSSupportsOpeningDocumentsInPlace</key><true/>
<key>UIRequiresFullScreen</key><true/>
<key>UIStatusBarHidden</key><true/>
<key>UISupportedInterfaceOrientations</key><array><string>UIInterfaceOrientationLandscapeLeft</string><string>UIInterfaceOrientationLandscapeRight</string></array>
</dict></plist>
PLIST

echo "== 5/5 sign (ad hoc) and zip -> $REL/d012_native-ios.ipa =="
for f in "$APP"/Frameworks/* "$APP"/overlays/*; do codesign --force -s - "$f" >/dev/null 2>&1 || true; done
codesign --force -s - "$APP"
mkdir -p "$REL"
rm -f "$REL/d012_native-ios.ipa"
(cd "$OUT" && zip -qry "$REL/d012_native-ios.ipa" Payload)
ls -lh "$REL/d012_native-ios.ipa"

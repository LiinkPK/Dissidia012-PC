#!/usr/bin/env bash
# Android build (arm64-v8a, Android 10 / API 29 and up) and packaging: dist/d012_native-android.apk.
# Run on Linux or macOS (FFmpeg's build needs sh and make):  bash scripts/build_android.sh
#
# Needs: the Android SDK (ANDROID_HOME: build-tools and a platform), the Android NDK (ANDROID_NDK, r27 or newer), CMake,
# Ninja, Java (javac, keytool), zip, curl and Python 3. GitHub's Ubuntu machines have the SDK and the NDK already.
# SDL3's source is downloaded (SDL_SRC names a folder to use instead).
#
# Signing: KEYSTORE, KEYSTORE_PASS and KEY_ALIAS name a key of your own. Every update must be signed with the same key,
# or it will not install over the old one and the player would lose the data: keep that key safe. Without them a throwaway
# key is made (fine for testing, not for a release).
# Other settings: APP_ID, PORTABLEKIT_ROOT, SDL_SRC, SDL_VERSION, OUT_DIR, REL_DIR, JOBS, GEN_OPT, GEN_JOBS, VERSION_NAME.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PK="${PORTABLEKIT_ROOT:-$ROOT/third_party/PortableKit-d012}"
OUT="${OUT_DIR:-$ROOT/out/android}"
REL="${REL_DIR:-$ROOT/dist}"
API=29
APP_ID="${APP_ID:-io.github.liinkpk.dissidia012}"
JOBS="${JOBS:-$(nproc 2>/dev/null || sysctl -n hw.ncpu)}"
GEN_OPT="${GEN_OPT:-1}"
if [ -r /proc/meminfo ]; then RAM_GIB=$(( $(awk '/MemTotal/{print $2}' /proc/meminfo) / 1048576 )); else RAM_GIB=$(( $(sysctl -n hw.memsize) / 1073741824 )); fi
GEN_JOBS="${GEN_JOBS:-$(( RAM_GIB / 3 < 1 ? 1 : RAM_GIB / 3 ))}"

echo "== 1/6 checks =="
ANDROID_HOME="${ANDROID_HOME:-${ANDROID_SDK_ROOT:-}}"
ANDROID_NDK="${ANDROID_NDK:-${ANDROID_NDK_HOME:-${ANDROID_NDK_LATEST_HOME:-}}}"
[ -d "${ANDROID_HOME:-/nonexistent}/build-tools" ] || { echo "Set ANDROID_HOME to the Android SDK (it needs build-tools and platforms)."; exit 1; }
[ -f "${ANDROID_NDK:-/nonexistent}/build/cmake/android.toolchain.cmake" ] || { echo "Set ANDROID_NDK to the Android NDK folder (r27 or newer)."; exit 1; }
export ANDROID_HOME ANDROID_NDK
for tool in cmake ninja python3 javac keytool zip curl; do
  command -v "$tool" >/dev/null 2>&1 || { echo "Missing $tool"; exit 1; }
done
for need in profiles/d012_pk/work/generated profiles/d012_pk/work/overlays packaging/android/res/values/strings.xml favicon.png; do
  [ -e "$ROOT/$need" ] || { echo "ERROR: $need is missing in $ROOT"; exit 1; }
done
if [ -z "${KEYSTORE:-}" ]; then
  echo "Note: no KEYSTORE given: the APK is signed with a throwaway key (testing only; updates would not install over it)."
fi
TOOLCHAIN="$ANDROID_NDK/build/cmake/android.toolchain.cmake"
mkdir -p "$OUT" "$REL"

# PortableKit is not stored in this repository: fetched and patched when missing or out of date (a no-op otherwise).
[ -n "${PORTABLEKIT_ROOT:-}" ] || bash "$ROOT/scripts/setup_portablekit.sh"
[ -f "$PK/cmake/PortableKit.cmake" ] || { echo "PortableKit not found: $PK (set PORTABLEKIT_ROOT)"; exit 1; }

echo "== 2/6 SDL3 for Android =="
SDL_VERSION="${SDL_VERSION:-3.4.18}"
SDL_SRC="${SDL_SRC:-$OUT/SDL3-$SDL_VERSION}"
if [ ! -f "$SDL_SRC/CMakeLists.txt" ]; then
  curl -fL --retry 3 -o "$OUT/SDL3-$SDL_VERSION.tar.gz" \
    "https://github.com/libsdl-org/SDL/releases/download/release-$SDL_VERSION/SDL3-$SDL_VERSION.tar.gz"
  tar -C "$OUT" -xzf "$OUT/SDL3-$SDL_VERSION.tar.gz"
fi
SDL_PREFIX="$OUT/sdl3-install"
if ! find "$SDL_PREFIX" -name libSDL3.so 2>/dev/null | grep -q .; then
  cmake -S "$SDL_SRC" -B "$OUT/sdl3-build" -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM="android-$API" \
    -DCMAKE_INSTALL_PREFIX="$SDL_PREFIX" -DSDL_SHARED=ON -DSDL_STATIC=OFF -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF
  cmake --build "$OUT/sdl3-build" -j"$JOBS"
  cmake --install "$OUT/sdl3-build"
fi
SDL_LIB="$(find "$SDL_PREFIX" -name libSDL3.so | head -1)"
SDL_CMAKE="$(dirname "$(find "$SDL_PREFIX" -name SDL3Config.cmake | head -1)")"
[ -f "$SDL_LIB" ] || { echo "libSDL3.so was not built"; exit 1; }

echo "== 3/6 configure the game (NDK, android-$API) =="
BUILD="$OUT/d012"
[ "${CLEAN:-0}" = 1 ] && rm -rf "$BUILD"
LAUNCHER=()
command -v ccache >/dev/null 2>&1 && LAUNCHER=(-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
cmake -S "$ROOT/profiles/d012_vk" -B "$BUILD" -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM="android-$API" \
  -DPORTABLEKIT_ROOT="$PK" -DSDL3_DIR="$SDL_CMAKE" -DPORTABLEKIT_ANDROID_APP=ON \
  -DPSPRECOMP_GENERATED_OPT_LEVEL="$GEN_OPT" -DPSPRECOMP_GENERATED_JOBS="$GEN_JOBS" ${LAUNCHER[@]+"${LAUNCHER[@]}"}

echo "== 4/6 build (-j$JOBS, generated units $GEN_JOBS at once) =="
# -k 0: keep compiling what does not depend on a failure; the log is kept for the report
BUILD_LOG="$ROOT/build_android.log"
set +e
cmake --build "$BUILD" -j"$JOBS" -- -k 0 2>&1 | tee "$BUILD_LOG"
BUILD_RC=${PIPESTATUS[0]}
set -e
if [ "$BUILD_RC" != 0 ]; then
  echo
  echo "===== BUILD FAILED. The first errors: ====="
  grep -n -m 6 -B1 -A6 -E 'error:|error |FAILED:|undefined reference|No such file' "$BUILD_LOG" | cut -c1-240
  echo "===== Full log: $BUILD_LOG ====="
  exit "$BUILD_RC"
fi

echo "== 5/6 the CJK fallback font (the game's text is blank on a phone without one) =="
FONT_CACHE="$OUT/fonts"
mkdir -p "$FONT_CACHE"
NOTO_TAG=Sans2.004
if [ ! -f "$FONT_CACHE/NotoSansCJKjp-Regular.otf" ]; then
  curl -fL --retry 3 -o "$FONT_CACHE/NotoSansCJKjp-Regular.otf" \
    "https://github.com/notofonts/noto-cjk/raw/$NOTO_TAG/Sans/OTF/Japanese/NotoSansCJKjp-Regular.otf"
  curl -fL --retry 3 -o "$FONT_CACHE/NotoSansCJK-LICENSE.txt" "https://github.com/notofonts/noto-cjk/raw/$NOTO_TAG/LICENSE"
fi
echo "68a3fc98800b2a27b371f2fb79991daf3633bd89309d4ffaa6946fd587f375b5  $FONT_CACHE/NotoSansCJKjp-Regular.otf" > "$FONT_CACHE/font.sha256"
if command -v sha256sum >/dev/null 2>&1; then sha256sum -c "$FONT_CACHE/font.sha256"; else shasum -a 256 -c "$FONT_CACHE/font.sha256"; fi

echo "== 6/6 the APK =="
APK="$REL/d012_native-android.apk"
rm -f "$APK"
APP_ID="$APP_ID" GAME_RES="$ROOT/packaging/android/res" GAME_REPO="$ROOT" FONT_DIR="$FONT_CACHE" \
\
  bash "$PK/packaging/android/build_apk.sh" "$BUILD" "$SDL_SRC" "$SDL_LIB" "$APK"
[ -f "$APK" ] || { echo "The APK was not made"; exit 1; }
echo "APK: $APK ($(( $(wc -c < "$APK") / 1048576 )) MB)"

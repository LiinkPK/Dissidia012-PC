#!/usr/bin/env bash
# Starts the game. First run: put your .iso in game/ and this sets the game up from it.
cd "$(dirname "$(readlink -f "$0" 2>/dev/null || echo "$0")")"
export DYLD_FALLBACK_LIBRARY_PATH="$PWD/lib${DYLD_FALLBACK_LIBRARY_PATH:+:$DYLD_FALLBACK_LIBRARY_PATH}"
# Vulkan runs on MoltenVK (Metal): the loader and driver are in lib/.
export VK_DRIVER_FILES="$PWD/lib/MoltenVK_icd.json"
export VK_ICD_FILENAMES="$VK_DRIVER_FILES"
# Files from a download carry a quarantine flag that blocks unsigned libraries; clear it once.
xattr -dr com.apple.quarantine . 2>/dev/null || true
mkdir -p game
if [ ! -f game/EBOOT.ELF ]; then
  ISO="$(ls game/*.iso 2>/dev/null | head -1 || true)"
  if [ -z "$ISO" ]; then echo "Put your .iso in the game folder and run this again."; exit 0; fi
  [ "$ISO" = "game/disc.iso" ] || mv "$ISO" game/disc.iso
  ./d012_native --install game/disc.iso --in-place
fi
exec ./d012_native "$@"

#!/usr/bin/env bash
# First-time setup: runtime dependencies (any major distro), then installs the game from game/*.iso.
# Usage: ./requirements.sh            (installs deps + game)
#        ./requirements.sh --no-deps  (skip package installation, only set up the game)
set -e
cd "$(dirname "$(readlink -f "$0")")"

if [ "${1:-}" != "--no-deps" ]; then
  # shellcheck disable=SC1091
  . ./linux_deps.sh
  d012_install_runtime || echo "Dependency install had problems; continuing. Re-run with the missing packages installed if the game fails to start."
fi

mkdir -p game
ISO="$(ls game/*.iso 2>/dev/null | head -1 || true)"
if [ -z "$ISO" ]; then echo "Put your .iso in ./game and run this again."; exit 0; fi
[ "$ISO" = "game/disc.iso" ] || mv "$ISO" game/disc.iso
[ -f game/EBOOT.ELF ] || LD_LIBRARY_PATH="$PWD/lib" ./d012_native --install game/disc.iso --in-place
echo "Done. Start with ./run.sh"

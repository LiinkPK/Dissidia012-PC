#!/usr/bin/env bash
cd "$(dirname "$(readlink -f "$0")")"
export LD_LIBRARY_PATH="$PWD/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

# Friendly diagnosis instead of a bare loader error on distros missing a system library.
missing="$(ldd ./d012_native 2>/dev/null | awk '/not found/ {print $1}' | sort -u | tr '\n' ' ')"
if [ -n "$missing" ]; then
  echo "Missing system libraries: $missing"
  echo "Run ./requirements.sh to install them (apt, dnf, pacman, zypper and apk are supported)."
  exit 1
fi
if ! ldconfig -p 2>/dev/null | grep -q 'libvulkan.so'; then
  echo "Warning: no Vulkan loader found. Run ./requirements.sh, and make sure your GPU's Vulkan driver is installed."
fi
exec ./d012_native "$@"

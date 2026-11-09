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
# Icon: an ELF file cannot carry one, so a launcher entry (menu and a clickable file in this folder) points at d012_native.png.
# Written every run, so it follows the folder if it is moved.
if [ -f d012_native.png ]; then
  entry="$(printf '[Desktop Entry]
Type=Application
Name=Dissidia 012 Native
Exec="%s/run.sh"
Path=%s
Icon=%s/d012_native.png
Terminal=false
Categories=Game;
' "$PWD" "$PWD" "$PWD")"
  printf '%s
' "$entry" > d012_native.desktop 2>/dev/null && chmod +x d012_native.desktop 2>/dev/null
  mkdir -p "$HOME/.local/share/applications" 2>/dev/null && printf '%s
' "$entry" > "$HOME/.local/share/applications/d012_native.desktop" 2>/dev/null
  # The executable itself: GNOME, Cinnamon (Mint) and MATE file managers show a custom icon set through gio.
  command -v gio >/dev/null 2>&1 && gio set d012_native metadata::custom-icon "file://$PWD/d012_native.png" >/dev/null 2>&1
fi
exec ./d012_native "$@"

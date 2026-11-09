#!/usr/bin/env bash
# Distro-agnostic dependency installer. Source it, then call:
#   d012_install_runtime   (what players need)
#   d012_install_build     (what building needs, includes runtime)
# Supports apt (Debian/Ubuntu/Kali/Mint/Pop), dnf (Fedora/RHEL/Nobara), pacman (Arch/Manjaro/EndeavourOS),
# zypper (openSUSE) and apk (Alpine). Unknown systems get a printed list instead of a failure.

d012_pm() {
  for pm in apt-get dnf pacman zypper apk; do
    command -v "$pm" >/dev/null 2>&1 && { echo "$pm"; return; }
  done
  echo none
}

d012_sudo() {
  if [ "$(id -u)" = 0 ]; then "$@"
  elif command -v sudo >/dev/null 2>&1; then sudo "$@"
  elif command -v doas >/dev/null 2>&1; then doas "$@"
  else echo "Need root: run this script as root or install sudo." >&2; return 1; fi
}

# Installs packages one by one so a single missing/renamed package never aborts the rest.
d012_install_list() {
  local pm="$1"; shift
  local pkg
  case "$pm" in
    apt-get) d012_sudo apt-get update || true ;;
    zypper)  d012_sudo zypper --non-interactive refresh || true ;;
    pacman)  d012_sudo pacman -Sy --noconfirm || true ;;
  esac
  # "a|b" is one package under two names (libasound2t64|libasound2): the first that installs is enough.
  local alt done_one
  for pkg in "$@"; do
    done_one=1
    for alt in ${pkg//|/ }; do
      case "$pm" in
        apt-get) d012_sudo apt-get install -y "$alt" ;;
        dnf)     d012_sudo dnf install -y "$alt" ;;
        pacman)  d012_sudo pacman -S --needed --noconfirm "$alt" ;;
        zypper)  d012_sudo zypper --non-interactive install "$alt" ;;
        apk)     d012_sudo apk add "$alt" ;;
      esac >/dev/null 2>&1 && { done_one=0; break; }
    done
    [ "$done_one" = 0 ] || echo "  (skipped: ${pkg//|/ or } not available on this system)"
  done
}

d012_install_runtime() {
  local pm; pm="$(d012_pm)"
  case "$pm" in
    apt-get) d012_install_list "$pm" libvulkan1 mesa-vulkan-drivers vulkan-tools "libasound2t64|libasound2" libpulse0 libx11-6 libxext6 libwayland-client0 libxkbcommon0 ;;
    dnf)     d012_install_list "$pm" vulkan-loader mesa-vulkan-drivers vulkan-tools alsa-lib pulseaudio-libs libX11 libXext libwayland-client libxkbcommon ;;
    pacman)  d012_install_list "$pm" vulkan-icd-loader vulkan-tools mesa vulkan-radeon vulkan-intel alsa-lib libpulse libx11 libxext wayland libxkbcommon ;;
    zypper)  d012_install_list "$pm" libvulkan1 Mesa-vulkan-drivers vulkan-tools alsa-lib libpulse0 libX11-6 libXext6 libwayland-client0 libxkbcommon0 ;;
    apk)     d012_install_list "$pm" vulkan-loader mesa-vulkan-layers vulkan-tools alsa-lib pulseaudio-libs libx11 libxext wayland-libs-client libxkbcommon ;;
    *) echo "Unknown package manager. Install manually: Vulkan loader + a Vulkan driver (Mesa or NVIDIA), ALSA/PulseAudio libs, libX11, libXext, Wayland client, libxkbcommon." ;;
  esac
}

d012_install_build() {
  local pm; pm="$(d012_pm)"
  case "$pm" in
    apt-get) d012_install_list "$pm" git build-essential cmake ninja-build make nasm pkg-config python3 curl xz-utils ccache \
      libvulkan-dev glslang-tools glslang-dev libx11-dev libxext-dev libxcursor-dev libxi-dev libxrandr-dev libxss-dev libxtst-dev libxfixes-dev \
      libwayland-dev libxkbcommon-dev libdrm-dev libgbm-dev libasound2-dev libpulse-dev libpipewire-0.3-dev libudev-dev libdbus-1-dev libegl-dev ;;
    dnf)     d012_install_list "$pm" git gcc gcc-c++ cmake ninja-build make nasm pkgconf-pkg-config python3 curl xz ccache \
      vulkan-loader-devel glslang libX11-devel libXext-devel libXcursor-devel libXi-devel libXrandr-devel libXScrnSaver-devel libXtst-devel libXfixes-devel \
      wayland-devel libxkbcommon-devel libdrm-devel mesa-libgbm-devel alsa-lib-devel pulseaudio-libs-devel pipewire-devel systemd-devel dbus-devel mesa-libEGL-devel ;;
    pacman)  d012_install_list "$pm" git base-devel cmake ninja nasm pkgconf python curl xz ccache vulkan-headers vulkan-icd-loader glslang \
      libx11 libxext libxcursor libxi libxrandr libxss libxtst libxfixes wayland libxkbcommon libdrm mesa alsa-lib libpulse pipewire systemd-libs dbus ;;
    zypper)  d012_install_list "$pm" git gcc gcc-c++ cmake ninja make nasm pkg-config python3 curl xz ccache vulkan-devel glslang-devel \
      libX11-devel libXext-devel libXcursor-devel libXi-devel libXrandr-devel libXss-devel libXtst-devel libXfixes-devel wayland-devel libxkbcommon-devel libdrm-devel \
      Mesa-libgbm-devel alsa-devel libpulse-devel pipewire-devel libudev-devel dbus-1-devel Mesa-libEGL-devel ;;
    apk)     d012_install_list "$pm" git build-base cmake samurai make nasm pkgconf python3 curl xz ccache vulkan-headers vulkan-loader-dev glslang \
      libx11-dev libxext-dev libxcursor-dev libxi-dev libxrandr-dev libxscrnsaver-dev libxtst-dev libxfixes-dev wayland-dev libxkbcommon-dev libdrm-dev mesa-dev alsa-lib-dev pulseaudio-dev pipewire-dev eudev-dev dbus-dev ;;
    *) echo "Unknown package manager. Install a C/C++ toolchain, cmake, ninja, nasm, pkg-config, python3, Vulkan + glslang dev files, X11/Wayland/ALSA/Pulse/udev dev files." ;;
  esac
  d012_install_runtime
}

# PSPRecomp — Dissidia 012 PC Port

A fork of the PSPRecomp static recompilation framework, used to port **Dissidia 012 [duodecim] Final Fantasy** (`ULES01505`) to PC as a native executable. The PSP's MIPS code is translated to C++ ahead of time and runs on the PortableKit runtime (cooperative kernel, HLE, Vulkan renderer, audio). No emulator is needed to play.

> **Game files not included.** You need your own copy of the game (the ISO). Nothing copyrighted is in this repository.

---

## Repository layout

```
include/psprecomp/        Public runtime and Allegrex interfaces
src/                      ELF/PRX loading, decoder, memory, runtime, support code
tools/                    Analyzer (psp_analyze), recompiler (psp_recomp), helpers
tests/                    Framework regression tests
configs/                  Generic examples and PSP NID data
docs/                     Architecture and profile guides
pseudocode/               Reverse-engineered pseudocode of the whole executable (one file per function)
profiles/
  d012/
    generated/            AOT-compiled units of the main executable and of the menu overlay
    host/                 Game profile for PortableKit (title, icon, the few game-specific HLE hooks)
  d012_pk/work/           Generated code and overlay libraries for PortableKit's d012 branch (made from your disc)
  d012_vk/                CMake entry point that builds d012_native on PortableKit's d012 branch
third_party/dissidia012-pc/  The open-source port by VCKing101 (MIT), kept as a reference and for its host code
```

---

## Requirements

- CMake 3.20+ and a C++20 compiler (MSVC on Windows), the Vulkan SDK and SDL3 3.2
- The `d012` branch of PortableKit with this project's changes (branch `tenkawa-merge`); pass its folder as `-DPORTABLEKIT_ROOT=<path>`
- Your own `ULES01505` ISO

---

## Build and run

```powershell
cmake -S profiles/d012_vk -B out/d012_vk -DPORTABLEKIT_ROOT=<PortableKit folder> -DSDL3_DIR=<SDL3 folder>/cmake
cmake --build out/d012_vk --config Release
```

Copy the DLLs from `out/d012_vk/bin` and `SDL3.dll` next to `out/d012_vk/bin/Release/d012_native.exe`, the overlay DLLs from `out/d012_vk/bin/overlays/Release` into `bin/Release/overlays`, put `game/` (EBOOT.ELF and disc.iso) next to the executable and your PPSSPP-style texture pack in `data/textures/ULES01505`. A PPSSPP save goes in `data/ms0/PSP/SAVEDATA`. 60 fps is the frame interpolation option in the in-game Video menu.

---

## How it works

The executable is recompiled **unmodified**: the code in `profiles/d012_pk/work/generated/` comes straight from the decrypted `EBOOT.BIN` and carries no hand patches or forged game state. The three code overlays (menu, battle, extra) and the font and anti-cheat modules are recompiled into libraries in `profiles/d012_pk/work/overlays/`, loaded when the game loads them. Every PSP import is bound to PortableKit's HLE. `profiles/d012/host/d012_profile.cpp` holds the game's identity, saves, overlay window, window title and icon, and the autosave-notice skip; the port's host code in `third_party/dissidia012-pc/port/host` supplies the rest, without its local versus.

---

## Texture replacement

The renderer replaces textures from a PPSSPP-style pack (`textures.ini` plus PNGs, `hash = quick`) found in `data/textures/ULES01505` next to the executable. The replacement image keeps its own resolution, so HD art works without touching the game's data.

---

## Status

**The game is fully ported and playable**: menus, battles with shadows and effects, story mode, cutscenes, music, saves and the HD texture pack all work in the native build. What is left is not porting but tweaking it into a proper HD remaster: HUD downscaling and placement (in progress, in the game's own layout data), faster HD texture loading, HD fonts, better-looking menus and performance. See `updates.md` for the session-by-session log (Session 20 is the latest).

---

## Source provenance & license

No commercial game executable or asset is included. PPSSPP source is used for **reference only**; no GPL code is copied into this repository.

The PSPRecomp framework is MIT licensed. See [`LICENSE`](LICENSE).

## Special thanks

- **VCKing101**, author of [Dissidia 012 Duodecim Final Fantasy: native PC port and decompilation](https://github.com/VCKing101/Dissidia012-pc) (MIT licence, kept in `third_party/dissidia012-pc/LICENSE`). Its documentation named the cause of the battle shadows, and its renderer, audio and frame-pacing work for PortableKit is what the current build runs on. This project does not use its base, but it got past its Session 19 problems thanks to it. Its local versus and split screen are the port's own work and are not part of this build.
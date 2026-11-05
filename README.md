<div align="center" >
<img width="1366" height="200" alt="GitHub Banner" src="https://github.com/user-attachments/assets/6512d139-da17-4b6a-b6fd-c5078f5600c9" />
</p>

[![Windows](https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white)](#)
[![Linux](https://img.shields.io/badge/Linux-%23FCC624.svg?style=for-the-badge&logo=linux&logoColor=black)](#)

</div>

<hr>

# PSPRecomp — Dissidia 012 PC Port

A fork of the PSPRecomp static recompilation framework, used to port **Dissidia 012 [duodecim] Final Fantasy** to PC as a native executable. The PSP's MIPS code is translated to C++ ahead of time and runs on the PortableKit runtime (cooperative kernel, HLE, Vulkan renderer, audio). No emulator is needed to play. The European release (`ULES01505`) is the main target; the North American release v1.00 (`ULUS10566`) is accepted as a variant, because both discs carry the same game executable (not tested yet). The Japanese release is not supported.

> **Game files not included.** You need your own copy of the game (the ISO). Nothing copyrighted is in this repository.

>[!IMPORTANT]
>**Just want to play?** Download the zip from the [Releases](./releases/latest) page (see [`RELEASE_NOTES.md`](RELEASE_NOTES.md)): run the `requirements` script, put your ISO in `game\` and start `d012_native.exe` (or simply `d012_native` on Linux). The rest of this page is for building from source.

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
  d012_vk/                CMake entry point that builds d012_native on PortableKit's d012 branch;
                          d012_hud_layout.cpp wraps the game's menu manager draw (HUD work in progress)
release/                  What goes in the release zip beside the exe: requirements.bat, README.txt, an empty game\ folder
scripts/                  make_release.ps1 builds the release zip from a finished build
third_party/dissidia012-pc/  The open-source port by VCKing101 (MIT), kept as a reference and for its host code
```

---

## Requirements

- CMake 3.20+ and a C++20 compiler (MSVC on Windows), the Vulkan SDK and SDL3 3.2
- The `d012` branch of PortableKit with this project's changes (branch `tenkawa-merge`); pass its folder as `-DPORTABLEKIT_ROOT=<path>`
- Your own ISO: `ULES01505` (European) or `ULUS10566` (North American)

---

## Build and run

```powershell
cmake -S profiles/d012_vk -B out/d012_vk -DPORTABLEKIT_ROOT=<PortableKit folder> -DSDL3_DIR=<SDL3 folder>/cmake
cmake --build out/d012_vk --config Release
```

Copy the DLLs from `out/d012_vk/bin` and `SDL3.dll` next to `out/d012_vk/bin/Release/d012_native.exe`, the overlay DLLs from `out/d012_vk/bin/overlays/Release` into `bin/Release/overlays`, put `game/` (EBOOT.ELF and disc.iso) next to the executable and your PPSSPP-style texture pack in `data/textures/ULES01505`. A PPSSPP save goes in `data/ms0/PSP/SAVEDATA`. 60 fps is the frame interpolation option in the in-game Video menu. A PPSSPP save can also be imported from the in-game menu (System tab).

To make the release zip from a finished build: `.\scripts\make_release.ps1 -Version <number>` (writes `dist\`, which git ignores).

---

## How it works

The executable is recompiled **unmodified**: the code in `profiles/d012_pk/work/generated/` comes straight from the decrypted `EBOOT.BIN` and carries no hand patches or forged game state. The three code overlays (menu, battle, extra) and the font and anti-cheat modules are recompiled into libraries in `profiles/d012_pk/work/overlays/`, loaded when the game loads them. Every PSP import is bound to PortableKit's HLE. `profiles/d012/host/d012_profile.cpp` holds the game's identity, saves, overlay window, window title and icon, and the autosave-notice skip; the port's host code in `third_party/dissidia012-pc/port/host` supplies the rest, without its local versus.

---

## Texture replacement

The renderer replaces textures from a PPSSPP-style pack (`textures.ini` plus PNGs, `hash = quick`) found in `data/textures/ULES01505` next to the executable. The replacement image keeps its own resolution, so HD art works without touching the game's data.

> [!NOTE]
> Even if you're running the US version, there is no need to change the texture folder's name from `ULES01505` to `ULUS10566`.
> Simply find the folder in the **Menu** -> **Import texture pack...** -> And then confirm changes/replacement.

---

## Status

**Version v1.0.1.** **The game is fully ported and playable**: menus, battles with shadows and effects, story mode, cutscenes, music, saves and the HD texture pack all work in the native build. What is left is not porting but tweaking it into a proper HD remaster:
- **HUD downscaling and placement:** done in the game's own layout data (`profiles/d012_vk/d012_hud_layout.cpp`; Video menu: HUD size, lift, side space). The shrink still reaches some story mode screens (dialogue boxes, the "Skip cutscene?" prompt, cutscene images); that is being fixed.
- **HD text:** done. Each line of text is drawn again from the TrueType font at 3 times its size, so menus, descriptions and dialogue are sharp; Text > Size sets the letter size. Subtitles are crisp, raised and smaller (Subtitle size and Subtitle height).
- **Select screens:** the roster is two rows of 16 with the Party roster and descriptions working. Next: a 3D model of the hovered character (a placeholder exists; reading the models from the disc is in progress).
- **HD textures that load instantly:** a fix is written (decode at upload, short wait on the first draw), not yet confirmed.
- **Region support:** the North American disc is accepted but untested, and its PPSSPP saves are not recognised by the save import yet. The Japanese disc is not supported.
- Better-looking menus and performance.

<img width="1280" height="720" alt="roster2 0" src="https://github.com/user-attachments/assets/c6c092ce-2f13-4e00-aabb-958f9d6cda53" />
<img width="1280" height="720" alt="hud1" src="https://github.com/user-attachments/assets/1ce7ac8e-db31-4b18-a5ed-2f6b7a051020" />

See `updates.md` for the session-by-session log (Session 21 is the latest).

---

## Source provenance & license

No commercial game executable or asset is included. PPSSPP source is used for **reference only**; no GPL code is copied into this repository.

The PSPRecomp framework is MIT licensed. See [`LICENSE`](LICENSE).

## Special thanks

- **VCKing101**, author of [Dissidia 012 Duodecim Final Fantasy: native PC port and decompilation](https://github.com/VCKing101/Dissidia012-pc) (MIT licence, kept in `third_party/dissidia012-pc/LICENSE`). Its documentation named the cause of the battle shadows, and its renderer, audio and frame-pacing work for PortableKit is what the current build runs on. This project does not use its base, but it got past its Session 19 problems thanks to it. Its local versus and split screen are the port's own work and are not part of this build.
- ZodiarkAmano
- Rocher
- Neo
- Henrik Rydgård ([PPSSPP](https://github.com/hrydgard/PPSSPP))
- [TeamGDB](https://github.com/TeamGDB)
- [BasedYuki](https://github.com/BasedYuki/the-3rd-birthday-recomp)
- **Everyone in my amazing [Discord community](https://discord.gg/W9rcyMJ7br)** ❤️

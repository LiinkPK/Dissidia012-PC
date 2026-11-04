<div align="center" >

<img width="200" height="200" alt="favicon" text-align="center" src="https://github.com/user-attachments/assets/56672c57-c906-423a-b55f-8b4742a7fcd0" /></p>

[![Windows](https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white)](#)
[![Linux](https://img.shields.io/badge/Linux-%23FCC624.svg?style=for-the-badge&logo=linux&logoColor=black)](#)

**_v1.0.1 — Early BETA_**

</div>

<hr>

# Dissidia 012 Final Fantasy HD Remastered (PC)

**Dissidia 012 [duodecim] Final Fantasy runs natively on your computer.** This is not an emulator: the PSP game's code is translated to C++ ahead of time and runs as a normal PC program with a Vulkan renderer, HD textures and 60 fps frame interpolation.

## State of the game

The game is **fully ported and playable**: menus, battles, story mode, cutscenes, music and sound effects, saves. What is left is polish to make it a proper HD remaster, not getting the game to run.

- Battles run with working shadows, effects and battle music
- HD textures: banners, portraits, menus and more from my HD texture pack (included)
- 60 fps (and higher) option (Video menu, frame interpolation)
- **HD text:** every line of text is drawn sharp from a TrueType font, at your window's resolution; pick the font and the letter size under Text in the menu
- **Subtitles** in cutscenes and battles are crisp, smaller and raised; Subtitle size and Subtitle height are under Text in the menu
- **Battle HUD** size, lift and side space (Video menu), done in the game's own layout data
- Quick Battle roster in two rows, with the Party screen and the character descriptions on hover
- Keyboard and gamepad support
- Import your existing PPSSPP saves from the in-game menu (System tab); your old saves are backed up first

**Known limits of this release**
- The Battle HUD size also shrinks some story mode screens (dialogue boxes, the "Skip cutscene?" prompt, images in cutscenes); keep it at 100% for story mode until this is fixed
- The subtitle position rule can also move other centred text near the bottom of the screen

## What is included

- The game's executable (`d012_native`) and the libraries it needs
- [My HD texture pack](https://github.com/LiinkPK/Dissidia-012-HD-Textures)
- `requirements` script, which installs what the game needs

## What is NOT included

- **The game itself.** No ISO, no game files, no `EBOOT`. You need your own copy of **Dissidia 012 [duodecim] Final Fantasy** as an `.iso`: the European release (ULES01505), or the North American release (ULUS10566), which carries the same game executable. Nothing copyrighted is in this release.

## Requirements

- Windows 10 or 11, 64-bit **or** Debian-based Linux
- A graphics card and driver with **Vulkan** support (GeForce 600 series / Radeon HD 7000 series / Intel HD 4000 or newer, with an up-to-date driver)
- Microsoft Visual C++ runtime (installed by `requirements.bat`/`requirements.sh`)
- About 1 GB of free space for the game and HD textures, plus room for your ISO (about 3.3 GB)
- Your own ISO of the European (ULES01505) or North American (ULUS10566) release. The Japanese release is not supported yet.

## How to install

1. Unzip anywhere.
2. Double-click **`requirements`** once. It asks for administrator/root rights and installs Vulkan and the Visual C++ runtime if they are missing.
3. Put your ISO in **`game`** and run `requirements` again, or start the game and drop the ISO onto its window.
4. Start **`d012_native.exe`**/**`d012_native`**.

If no window appears, update your graphics driver.

## Special thanks to:

- [VCKing101](https://github.com/VCKing101/Dissidia012-pc) 
- ZodiarkAmano
- Rocher
- Henrik Rydgård ([PPSSPP](https://github.com/hrydgard/PPSSPP))
- [TeamGDB](https://github.com/TeamGDB)
- [BasedYuki](https://github.com/BasedYuki/the-3rd-birthday-recomp)
- **Everyone in my amazing [Discord community](https://discord.gg/W9rcyMJ7br)** ❤️

## Third-party software

This release bundles FFmpeg (LGPL; `FFmpeg-LICENSE.txt` and `FFmpeg-SOURCE.txt` are included), SDL3, Dear ImGui, stb, xxHash and other libraries through PortableKit. Each keeps its own licence. This project is not affiliated with Square Enix or Sony; *Dissidia* and *Final Fantasy* are trademarks of their owners.

Source and development log: https://github.com/LiinkPK/Dissidia012-PC
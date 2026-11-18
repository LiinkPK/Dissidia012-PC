# v1.0.8 hotfix: status, changelog and test checklist

Written from a code review. Nothing here has been built or run yet; "Status" says what is established and what is not.

## Changelog (draft)

- The Emendatus Mod ships by default in the Windows, Linux and macOS packages (`-WithoutEmendatus` for Windows, `WITHOUT_EMENDATUS=1` for the Linux and macOS scripts leave it out). The Linux and macOS scripts warn if the corpus or `release/mods/emendatus_assets.bin` is missing (the file is git-ignored, so a CI checkout never has it); `STRICT_EMENDATUS=1` makes that an error.
- Android: the APK already carries every overlay library, so the mod's code ships; the 338 MB of new data is looked for in `mods/` of the app's data folder when it is not beside the program.
- Memory expansion (Gojo's heap edits) for the stock game too, not only with the Emendatus Mod: a new "expanded" edition. It needs its corpus generated and built once (below); until then the stock executable runs as before.
- Multiplayer: the Emendatus Mod and the stock game never play each other (the product code carries an edition mark; the Join list hides the other edition). Patch `0111` and `d012_profile.cpp`. Untested.
- Fixed "The update failed: ... d012_update_progress.txt is being used by another process"; "Try again" now starts clean.
- Android: in-app update. The release is read and the APK downloaded in Java and handed to Android's installer (Install button; the download page is the fallback if it fails). Untested.
- Android: System > DLC uses Android's own folder picker and reads the DLC from the picked folder through the system (the old in-app browser could not see the player's folders on Android 11 and later). Untested.
- Android: folders and files picked in the file picker keep their access after the app restarts.
- Roster: a locked character no longer moves the cells after it (Prishe took Shantotto's place).
- Cheats page: each enabled cheat shows what it did (writes made, skipped, unsupported, conditions not met).

## Status by report

| Report | Root cause | Fix | Established |
|---|---|---|---|
| Emendatus missing from the packages | `make_release.ps1` shipped it only with `-WithEmendatus` (off by default); the Linux and macOS scripts never copied `corpora/` or `mods/` | On by default in all three scripts, with an opt-out; Android reads the data from the data folder | From the scripts; not run |
| Update failed, progress file in use | The helper's `Set-Content` threw on a momentary lock and the failure was reported as a failed update | Shared open with retry, non-fatal logging, one progress file per run (`0108`) | From the code; not run |
| Android update does nothing | The updater is compiled out on Android; the menu row was a no-op | In-app update through Android's PackageInstaller, download page as fallback (`0109`) | From the code; not compiled or run |
| Prishe and Shantotto swapped | Placement by draw rank (second `0104`); a locked cell does not draw, so later cells shift | Placement by game slot in `d012_hud_layout.cpp` | From the code; needs a partly unlocked save to confirm |
| Cheats do nothing | Not found: the load, parse and apply path is unchanged since v1.0.6 | Diagnostics only (`0110`) | Open |
| Android storage location (System > DLC folder) | The chooser was a path browser; Android 11+ gives the app no access to such folders. Picked folders also lost access on restart | System folder picker and document reads (`profiles/d012_vk/d012_dlc_folder.cpp`), persistent permission (`0109`) | From the code; a removed folder is untested |

## Open: cheats

Ask an affected user to enable the cheat, open the Cheats page and report the status line under it:

- "writes outside game memory": the codes are for another build.
- "unsupported code type": a joker or delay code.
- "conditions not met": game state or edition.
- "N writes per frame": the write happens, so something else restores the value.

Or run with `D012_TRACE_CHEATS=1` and send `d012_cheats.log` from the temp folder. Please also say which disc (EUR or US), whether the Emendatus Mod was on, and which platform.

## Test checklist (Windows)

0. Linux and macOS: run `scripts/build_linux.sh` or `scripts/build_macos.sh`; the package has `corpora/` and `mods/emendatus_assets.bin`. If the build has no corpus, the script stops with an error.
1. Build as usual, then run `scripts/make_release.ps1`; the zip contains `mods/`, `corpora/` and the Emendatus overlays. With `-WithoutEmendatus` it contains none of them.
2. Update from the previous release; the dialog reaches "Ready" with no error.
3. Make the update fail (for example hold the progress file open in another program), then press "Try again"; the update completes.
4. Roster, Quick Battle Player Select and CPU Select, with a fully unlocked save and a partly unlocked save: each face icon, cursor frame and hand are on the same cell, and Prishe and Shantotto are in their own places.
5. Cheats page: enable a cheat and read its status line.

## Test checklist (Android)

1. Install the APK over the old one; the data is kept.
2. System > "Download the latest release...": the releases page opens in the browser.
3. First run: pick the disc image; it is copied and the game starts.
4. Pick a folder (DLC), close the app completely, reopen: the folder is still readable.
5. Remove the folder or the SD card, reopen: there is a clear message and no crash.
6. Cheats page: enable a cheat and read its status line.

## Not done

- The 338 MB Emendatus data is not bundled in the APK (the player or the updater puts it in `mods/` of the data folder).
- A confirmed cause for the cheats report.
- NEW labels on the Customization roster (known open bug).

## Memory expansion for the stock game

Gojo's "plain EBOOT" is the stock executable, and his eight edits are already in the Emendatus Mod's executable (verified byte for byte), so the Emendatus edition has had the expansion all along. For Emendatus off the port now has an "expanded" edition: the stock executable with the same eight edits.

1. Generate the corpus (about a minute): `python tools/mods/expansion/make_expanded_corpus.py --stock-elf <the stock EBOOT.ELF from the game folder>` (it checks the edited executable against the hash in `profiles/d012_vk/d012_expansion_data.inc`).
2. Build as usual; the compile of the new corpus is the long part. The build makes `corpora/expanded.<ext>`.
3. Run with Emendatus off: the log says `[expansion] The memory expansion is on`. `D012_EXPANSION=0` turns it off for a run.

Without the corpus the log says `[expansion] ... this build has no corpus for it` and the stock executable runs. Android and Linux/macOS packages carry the corpus only if it was built.

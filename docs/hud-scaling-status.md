# Battle HUD scaling and roster layout: status and handoff

Nothing from the latest round (the three `kPieces` additions and the bottom-left roster marker) has been built or tested yet.

## How the HUD scaling works (marker-based)

- `profiles/d012_vk/d012_hud_layout.cpp` wraps the menu manager's layout draw. For each layout listed in `kPieces` with `scale = true` it writes a NOP marker into the GPU display list before and after that layout's commands (`kMarkerHudBegin = 0x00A50010`, `kMarkerHudEnd = 0x00A50011`).
- The renderer (PortableKit-d012 `host/gpu/vulkan_renderer.cpp`) scales every quad drawn between a begin and an end marker. Each quad anchors to the left edge, the right edge or the centre by its own x position. The scale, bottom margin and side space come from the in-game Battle HUD settings. Nothing else on screen is touched.
- The profile sets `hud_scaled_by_game = true` (`profiles/d012/host/d012_profile.cpp`).
- A layout is identified by its resource's kind (byte at resource + 0x68) and id (s16 at resource + 0x66). This holds across runs, unlike screen position.
- The older layout-hook approach (`layout_anchors`, the sprite-draw hook) double-scaled things and was abandoned. Its code is still there, and `is_hud_layout` is still used by it.

## Debug tool

Run with `D012_TRACE_HUD_BOXES=1` (the renderer reads `<prefix>_TRACE_HUD_BOXES`). While the game runs, create the file `<temp>/d012_hud_boxes.trigger`. The next frame is written to `<temp>/d012_hud_boxes.log`, one line per quad: the layout kind and id, or `unmarked` plus the texture, then the texture size and the quad's x and y range in 480x272 game pixels, before scaling. That names what each layout draws.

## Layouts found so far (kind 1 unless noted)

| Layout | What it draws | State |
|---|---|---|
| `0x0218`, `0x021A`, `0x0216`, `0x0256`, `0x0220` | main HUD parts and corner pieces | scaled |
| `0x0208`, `0x0212`, `0x0258` | no sprites, hidden with the HUD | scaled (nothing to move) |
| `0x0238` | big BRV number at the left (x 57..148, y 205..250) | added to `kPieces` this session, untested |
| `0x0206` | right BRV number (x 366..427, y 195..262) | added, untested |
| `0x0214` | bottom strip (x 121..416, y 209..270); HP bar corners or stage BRV frame | added, untested |
| `0x0222` | lock-on cursor | never scaled |
| `0x0224` | AP Chance, and a centre banner in battle (5 sprites at 240,136) | not scaled |
| `0x0226` | centre banner (3 sprites) | not scaled |
| `0x0236` | top banner "created!" on the results screen | not scaled |
| `0x0254` | "Save Replay" bar and its text (results screen) | not scaled |
| `0x024A`, `0x024C`, `0x024E` | drawn over everything | never scaled |
| kind 0, id `0x0` (a text layout with no resource, tex `0x8c50b30`, x 150..330, y 260..270) | candidate for the small HP numbers | cannot be matched by `is_hud_layout` |

## Battle HUD: what the user sees right now

- **Done:** the BRV numbers and the stage BRV counter scale.
- **Not scaled:** AP Chance, the HP numbers, and the summon icon and debuff icons.
- **Still broken:** the corners of each character's HP bar stay detached in the middle of the screen. The next trace should name which layout or unmarked draw they come from.

### Next steps for the HUD

1. Take new captures with HP bars and debuffs visible. Find what draws the HP numbers (the kind-0 id-0 text layout is a candidate, and `is_hud_layout` needs a way to match layouts with no resource), the summon icon and debuff icons, and the HP bar corners.
2. Check whether the HP bar corners come from `0x0214` (now added) or from a draw outside any layout.
3. Decide with the user whether to scale `0x0224`, `0x0236` and `0x0254` (AP Chance, results banner, "Save Replay"). They also appear on other screens, and `0x0224` is the battle centre banner. Scaling them only affects the marker spans.

## Quick Battle player select: roster in two rows

Not started in code. The user's request: a hard-coded two-row roster of 16 and 16 squares, small, anchored bottom-left, not tied to any slider. The hand cursor keeps its size, and the rest of the mockup is placeholder. Navigation must follow the new order.

What is already in place (untested):
- `kPieces` has `{29, 0x1220}` (roster squares) and `{29, 0x1228}` (cursor frame) with a `left` flag.
- A new marker `kMarkerHudBeginLeft = 0x12` anchors every quad at the bottom-left corner (`hud_anchor_left` in the renderer).
- The hand is layout `0x1222`, not listed, so unscaled.

Because the user wants a fixed layout, this mechanism should be replaced by editing the game's own grid. Plan:
- Grid builder: menu `0x08A84FD4(screen, mode)` (generated: `profiles/d012/generated/overlay_menu/generated_unit_0005.cpp`, label `L_08A84FD4`). It builds up to 40 cells of 8 bytes at workspace +0x678 (`{u16 flags, s16 sprite, s16 layoutRow, u16 level}`) and a layout-row list at +0x628. It splits them into grid rows of 6, 10, 10 and the remainder (checks `slti 0x1B`, `0x11`, `0x7` at `0x08A8522C`, `0x08A85244`, `0x08A8525C`), with the last row centred via a table at `0x08A85BF8`. Change this to 16 and 16.
- Cell positions: layout table `0x08A864D0`, 33 rows of 6 s16 (row 32 is Random), read by `0x08A85ECC` (getter) and used by `0x08A84FD4`, `0x08A80130`, `0x08A7F2B4`, `0x08A807EC`. Rewrite positions to the mockup coordinates.
- Navigation: read `0x08A80130`, `0x08A7F2B4` and `0x08A807EC` to see how left, right, up and down use the row counts.
- Implement it as an override in `profiles/d012_vk` (like the cheats), not by editing generated files. Chaos (id `0x17`) is hidden in some modes (`0x08A80A4C`), so 31 or 32 cells are possible.
- Reference: `third_party/dissidia012-pc/docs/research/roster-and-save.md`, sections 1.5 and the tables near line 126.
- Once the game draws the roster in place, remove the two roster entries and the left marker.

## Other open items

- Remove the Bloom cheat (override of `FUN_089A1770`).
- HD fonts are parked.

## Constraints from the user

- Do not guess. Use the translated C source and traces.
- Scale HUD pieces by layout identity, never by screen position. The pause menu must keep working. If a change cannot be made to work, revert it.
- Aim: a fully independent native PC version. Do not call it an emulator.
- Tell the user the file and line of every change.
- The user builds, not the assistant. No personal paths in repo files.

## Square flashing in the screen centre (battle start, summon activation)

The square measured about 288x163 in 480x272 pixels, which is 0.6 of the full screen, scaled about the bottom centre. So a full-screen fade quad inside a scaled layout was being shrunk. Fix (untested): the renderer's HUD scaling now skips any quad that covers the whole screen (`vulkan_renderer.cpp`, search "covers the whole screen"). If a square still shows, trace that moment to find the layout.

## Degradation over a run: black and white rectangles, EX Revenge, lock-on circle, missing shadows

Cause found in the renderer (untested fix): `in_hud_layout` was only cleared by a layout's end marker, never at the start of a frame or display list, so one lost end marker left the scaling on for later draws. Those draws included the render-to-texture passes, whose big quads were scaled into black and white rectangles at the bottom corners. The shadows, the lock-on and the EX Revenge cut-in were drawn wrong the same way.

Fixes in `vulkan_renderer.cpp` (PortableKit-d012):
- The span flags (`in_hud_layout`, `in_layout_span`, `hud_anchor_left`) reset at the start of each frame (the `hud_frame` block in `submit`) and of each display list (`begin_display_list`).
- HUD scaling applies only to draws whose target is a displayed buffer (`impl.shows(call.target.color_address)`).

If it still degrades after a long run, capture with `D012_TRACE_HUD_BOXES=1` at that point and look for marked draws that should not be.

Result of the fix above: the user built it (exe newer than the edit) and reported that nothing changed, so the diagnosis is incomplete. The box trace now also logs each draw's target address, `shown`/`offscreen`, and the `hudflag`. Next: capture the broken moment (EX Revenge, or after a long run).

## Round after the first trace with target/hudflag (untested)

Trace findings: HP numbers (the white 6999 / 1000 at the bottom) are the resource-less layout (kind 0, id 0, tex `0x8c50b30`). The summon stone is `0x204` (kind 1) plus kind 0 id `0x1FFF` (tex `0x91903a0`), at x 311..334, y 223..245. AP Chance is `0x224`. Several marked draws are not quads (strips or fans with more than 4 vertices, with `n` not a multiple of 6), and the renderer's HUD rule ignored them, which probably left the HP bar corners and spikes unscaled.

Changes:
- Renderer: HUD scaling now also moves non-quad primitives, as one piece about their own bounding box (`vulkan_renderer.cpp`, the `by_quad` / `group` code).
- Game: `0x0204`, kind 0 `0x1FFF`, `0x0224` and `0x0254` are now scaled (`kPieces`).
- Game: a layout with no resource is now named by its draw callback (kind `0xFE`, id from `layout + 0x10`), so it can be listed in `kPieces`. The next capture shows the HP-number layout under that name; add it to `kPieces` then. Not done yet because the pause menu may use resource-less layouts too, and scaling all of them would break it.
- The trace now logs `prim=` and `n=` for each draw.

Buff and debuff effects: not identified yet.

## Round 3 (all untested; from the user's report after the previous build)

Confirmed good by the user: summon stone, AP Chance, Forfeit menu.

Changes:
- Save Replay (`0x254`): new marker mode `0x13` scales about the left edge and keeps each quad's own vertical centre, so it no longer drops into the text box.
- RULES: it is in the same layout as AP Chance (`0x224`). New mode `0x14` (right side): quads above y = 180 scale about the top right (anchor y 110), the others about the bottom right as before. Modes are set per piece in `kPieces` (`HudPiece::mode`).
- Battlegen list drifting down every match: the BGM playlist's overrides of the selector (`d012_decomp_bgm.cpp`, `run_list` and `run_update`) were still on by default. `playlist::enabled()` in `d012_bgm_playlist.cpp` is now off unless `D012_BGM_PLAYLIST=1`. Not confirmed as the cause.
- Layouts without a resource are now named in the trace as kind 254 with an id from their address (`(layout & 0xFFFF) >> 3`); they are statically allocated, so it is stable between runs. The HP numbers are among them (`0x8c50b30` digits), as is something drawing at the top (tex `0x92903a0`, probably the BREAK word, unconfirmed). Capture in battle again to read the ids, then add them to `kPieces` with kind 254.

Not done:
- BREAK word over the BRV when BRV goes below 0: identity unknown (see above).
- "VS name" splitting into two lines, leaving "VS" out: the VS screen's draws showed `hudflag=0` in the capture, so the marker scaling is not what touched them there. Needs a capture of that screen with `hudflag` and the layout names, taken while the name is broken (HUD scale below 100).
- Shadows disappearing after a while: not identified. Capture one frame when they are gone and one before.

## Round 4 (untested)

Confirmed by the user: Battlegen fixed (the BGM playlist overrides), Save Replay and RULES fine.

- HP numbers: kind 254 id `0x114C` (draws at x 150..330, y 260..270), added to `kPieces`.
- `0x224` is a generic text layout: it also draws the VS name and the subtitles at the start of a battle (centre of the screen), which AP Chance scaling broke (VS split in two lines, subtitles pushed right). Mode `0x14` now leaves every quad whose centre is left of x = 390 alone, so only RULES and AP Chance (right edge) scale.
- Still open: the BREAK word, shadows (later).

## Round 5 (untested)

- The kind-254 naming by address was wrong: the layout pool shifts between battles (checked in `d012_hud_layouts.log`: 0x0256 sat at 08B8A008 in one run and 08B8A0B8 in another). Resource-less layouts are now named by their distance in 0x2C-byte slots behind the `0x0256` layout (ids `0x1001`..`0x1008`). In every layout capture the two number layouts are 2 and 4 slots behind it, so `kPieces` lists `{0xFE, 0x1002}` and `{0xFE, 0x1004}` (the 4 is unconfirmed).
- Still unidentified: the AP Chance description (big after the x < 390 rule), the on-screen buff above the HP bar, the BREAK word, the HP bar corners. Callback-drawn candidates seen in the layouts log: kind 1 ids `0x0202`, `0x021E`, `0x022A`, `0x022C`, `0x022E`, `0x0230`, `0x0246`, `0x0248`, `0x025A`, `0x025C`, and kind 7 ids `0x1A00`..`0x1A10`.
- The box log `d012_hud_boxes.log` was empty: the trigger for it is `d012_hud_boxes.trigger` (the layout trace uses `d012_hud_trace.trigger`).

## Round 6 (untested; from the box trace with all four scenes)

Findings and changes:
- **HP bar corners floating in the middle:** the health bar's diagonal end is drawn as hundreds of 1-pixel quads in `0x218`. The renderer picks each quad's anchor from its centre (left below x = 200, middle 200..280, right above), and the bars end right at 200 and 280, so neighbouring pieces got different anchors and came apart. The bands are now 212 and 268 (`vulkan_renderer.cpp`, search "The health bars end").
- **Buff bar and shield icon:** kind 0 id `0xFFFF` (the trace prints ids masked to 13 bits, so it showed as `0x1fff`). `kPieces` had `0x1FFF`, which never matched; it is now `0xFFFF`. The same layout also draws the summon stone icon.
- **HP numbers:** in one capture the layout was more than 8 slots behind `0x0256`, so it got no name. The search is now 24 slots and any hit at 2 or more slots is named `0x1002`.
- **BREAK word:** layout `0x200` (62 x 26 sprites at x 346..408 and 446..508, y 218..244, tex `0x8c6deb0`). That layout also draws floating numbers across the whole screen, so new mode `0x15` scales only quads of at least 40 x 18 whose centre is below y = 200.
- **AP Chance description:** it is made of text quads (tex `0x9928fd0`) starting at x 298. My earlier "centre x < 390" rule skipped them. Mode `0x14` now skips quads whose left edge is left of x = 245 instead; centred text (VS name, subtitles) cannot start to the right of 240.
- Shadows: the "gone" capture shows nothing different in the marked layouts. Offscreen draws at target `0x40cc000` are the same in both. Still open.

## Roster test (untested)

The Quick Battle roster (kind 29 ids `0x1220` squares, `0x1228` cursor frame; the hand `0x1222` is not listed) now scales at a fixed 0.68, grid left edge at x = 7 and bottom at y = 254, whatever the Battle HUD settings are (`hud_anchor_left` in `vulkan_renderer.cpp`; the markers are written even with the HUD at 100). It is still the same 6/10/10/6 grid, not the two rows of 16 yet, and the hand stays where the game puts it, so it will not sit on the selected tile. Next: the two-row grid and navigation (see the plan above).

Roster fix: the box trace prints layout ids masked to 13 bits. The real ids of the Quick Battle layouts are `0x7220` (squares), `0x7228` (cursor frame) and `0x7222` (hand), as the layout trace shows; `kPieces` had the masked values, so nothing matched. Other masked ids may have hidden high bits too: check with `d012_hud_layouts.log` before trusting an id from the box log above 0x1FFF.

## Quick Battle roster: findings for the two-row grid (no code yet)

User's target order (mockup). Top row: Warrior of Light, Firion, Onion Knight, Cecil, Kain, Bartz, Terra, Cloud, Tifa, Squall, Laguna, Zidane, Tidus, Yuna, Vaan, Lightning. Bottom row: Garland, Emperor, Cloud of Darkness, Golbez, Exdeath, Kefka, Sephiroth, Ultimecia, Kuja, Jecht, Gabranth, Gilgamesh, Chaos, Shantotto, Prishe, Random. In character ids: top `01 03 05 07 18 09 0b 0d 1a 0f 1b 11 13 1c 1e 1f`, bottom `02 04 06 08 0a 0c 0e 10 12 14 16 19 17 15 1d`, then Random (row 32). Feral Chaos (`0x20`) is the "Chaos" in the list (after Gilgamesh); boss Chaos (`0x17`) goes last.

How the game builds the grid (menu overlay, from `generated_unit_0005.cpp`):
- Layout table `0x08A864D0`: 33 rows x 12 bytes `{a, b, key, d, charId, 0}`. The builder `0x08A84FD4` walks rows 0..31 in table order and keeps those whose character is available. Today's order: rows 0..5 `1f 1e 1b 1c 18 1a`, 6..15 `01 03 .. 13` (odd ids), 16..25 `02 04 .. 14`, 26..31 `15 16 1d 19 20 17`. So the on-screen order = table order.
- Screen workspace `W = *(screen + 0x28)`: kept rows as s16 at `W+1576` (count at `W+1552`); 40 cell slots of 8 bytes at `W+1656` `{u16 flags, s16 position, s16 layoutRow, u16 level}`; cell sprite bank pointer at `W+1028`.
- The builder splits by count into a first block (6, 16 or 26 cells) and a remainder, and places each with `0x08A7FB54(screen, layoutRow, position)`. Position `p` goes to cell slot `p+2`, `+2` more if `p >= 6`, `+2` more if `p >= 26`. The positions on screen are those of the sprites in the layout resource (`0x7220`): rows of 6, 10, 10, 6.
- Not found yet: the cursor navigation code (left, right, up, down), which presumably uses the 6/10/10/6 row sizes.

Plan: (1) rewrite the table rows in memory in the new order before the builder runs; (2) change the split so 16 + 16 cells are placed; (3) set the sprite positions of the 32 positions to the mockup coordinates; (4) fix the navigation row sizes. Blocker for (1) and (2): `d012_decomp_harness` can only override functions of the main module and the battle overlay (`Module::Main`, `Module::BattleOverlay`). The select screen is in the menu overlay, so the harness needs a menu-overlay module first.

## Roster, first two-row attempt (untested)

Edited directly (the build compiles `profiles/d012_pk/work/overlays/ovl089DD4C0_menu_*/generated_unit_0041.cpp`, which is in git):
- `d012_roster_prepare_table` (before the unit's entry function) rewrites the layout table `0x08A864D0` into the mockup order each time the builder `0x08A84FD4` starts.
- At `L_08A8522C` the 6/10/10/6 split is replaced by 16 + the rest (positions 0..15, then 16..31); at `L_08A852BC` the centring offset for the last row is 0.
- `place_roster` in `d012_hud_layout.cpp` sets the sprites of the kind 29 id `0x7220` layouts (one per position, in list order) to x = 28 + 32 * (position % 16), y = 113 or 152 each frame; the renderer shrinks them to 0.65 about (7, 203).
- Unknown until tested: whether the cursor, the hand and the left/right/up/down navigation follow these positions. The layout table's third column ("key") holds per-cell column numbers that may be used for up/down.
- The same unit also exists in `profiles/d012/generated/overlay_menu/generated_unit_0005.cpp` (not used by the d012_vk build; not edited).

Roster order, second try (untested): the table rewrite in `generated_unit_0041.cpp` left no trace in `d012_roster.log` (the code did not run or is not what the game uses), so the same rewrite now also runs from `order_roster_table` in `d012_hud_layout.cpp`, every frame inside the menu draw wrapper, guarded by a check that the memory at `0x08A864D0` really is the select table. The two diagnostics in the generated file (`d012_roster_note`) can be removed once the order works.

## Roster frame and hand (untested)

`place_roster` in `d012_hud_layout.cpp` now moves the sprites only for the draw and restores them afterwards, so the game's own 6 / 10 / 10 / 6 geometry and logic are untouched. Cells (kind 29 id `0x7220`) go to the two-row positions; the cursor frame (`0x7228`) goes to the new place of the cell nearest to it in the game's geometry; the hand (`0x7222`) is shifted by the step the frame takes on screen after the renderer's 0.65 shrink. Not done: left/right/up/down still follow the game's hidden 6 / 10 / 10 / 6 grid, so moving across a row boundary will not match the two rows yet.

## Roster frame and hand, third try (untested)

The cursor logging showed the frame/hand sprites' own x,y do not change when the cursor moves (the layout position or a matrix is what moves), so moving those sprites cannot work. Now the renderer does it at draw time: the game publishes the cells' own positions (`g_d012_roster_cells`, set in `place_roster`), the frame layout `0x7228` has marker mode `0x16` and the hand `0x7222` mode `0x17`; the renderer finds the cell nearest each frame quad (cells are 32 x 39, top-left origin), moves and shrinks the quad to that cell's place on the two rows, and moves the hand by the frame's on-screen step. Still open: the d-pad logic (hidden 6/10/10/6 grid) and the initial cursor (starts on Lightning).

## Roster navigation as two rows of 16 (untested)

The game's select grid is a 4-row x 10-column table of 40 cell slots (`W+1656`, 8 bytes each; slot = row * 10 + col; the cursor is `W+1544` col and `W+1548` row; the cell's position index is the s16 at `+1658`). Changes in `generated_unit_0040.cpp` / `generated_unit_0041.cpp` (originals saved as `gu0040.bak`/`gu0041.bak` in the temp folder):
- columns 10 -> 16 and rows 4 -> 2 in the slot lookup (`0x08A7FCA4`), the wrap helper (`0x08A7FD28`) and the neighbour search (`0x08A7FD8C`..`0x08A7FF60`); `row * 10` -> `row * 16` at five more sites; slot -> (col, row) divides by 16 (`0040:19184`);
- `0x08A7FB54` places position p in slot p (it added 2, 4 or 6 to leave gaps for the old rows).
The cursor frame is still placed by the cell's position index, so the renderer's frame mapping is unchanged. The hand now sits 1.5 game pixels higher and is mirrored to the right side of the tile on the first column (Warrior of Light, Garland).

Default selection: Warrior of Light is character id `0x01` (the first cell now). The select screen takes its starting character from `screen + 24` and passes it to `0x08A81240` (`generated_unit_0041.cpp`, label `L_08A85380`); a value of `0x1F` (Lightning, the game's default) is now replaced by 1. A character chosen earlier is kept.

## CPU Select screen, confirmation prompt, description (open)

- CPU Select adds boss Chaos (`0x17`) as a 33rd cell. The wrapper wrapped position 32 onto the first cell (`% 16`), so Random covered Warrior of Light. Fixed (untested): positions are two rows with the second row allowed 17 long (`roster_new_position`, and the matching code in `vulkan_renderer.cpp`), so Random goes after Chaos.
- "Play as this character?" prompt overflows the bottom of the screen: cause not found; needs a box-trace capture while the prompt is open (layout ids and positions).
- Wanted: the character description ("[Buster Basher] ...", now shown only in the confirmation state) printed before selecting, between the roster and the name banner, a little right and down. Needs the call that draws it traced in the menu overlay; not started.
- Note: the generated-code grid edits (`gu0040.bak`, `gu0041.bak` are the originals) never ran (no log line from the menu library appeared); navigation is still the game's 4 x 10 grid.

## Roster on the other screens (untested)

From the box trace: the Party screen draws five small icons with the roster's cell layout (kind 29 `0x7220`), the CPU screen's confirmation prompt is drawn by the hand layout (`0x7222`, 46 draws: window pieces plus the hand), and the Labyrinth "Character Select" is the same set with kind 34 (ids with low 13 bits `0x636` cell, `0x63E` frame, `0x638` hand; the real ids still have to be checked in the layout trace). Changes in `d012_hud_layout.cpp`:
- `roster_role(kind, id)` names the three roles for both kinds; the roster scaling, frame and hand markers are written only while a full grid (32 or more cells) is on screen (`g_roster_active`), so the Party screen and other uses are left alone;
- the hand marker is written only when the hand layout has exactly one sprite (a prompt window has many);
- the Labyrinth screen gets the same treatment as Quick Battle (cells moved by `place_roster`, frame and hand by the renderer). Its table order already changed.
Still open: the ghost red frame on the CPU screen (cursor logging with `D012_TRACE_ROSTER=1` on that screen would show which positions the game uses), the description before selecting, and navigation.

Hand fix (untested): the hand layout always has several sprites (8 in the trace) even when one hand shows, so the "exactly one sprite" test never passed and the hand stayed on the old grid. Now the hand layout always gets marker mode `0x17`, and the renderer moves only quads of about 34 x 26 and only while a frame quad was mapped this frame or the one before (`roster_frame_stamp`).

## Why the generated-code edits never took effect (found)

The game loads its overlay libraries from `out/d012_vk/bin/Release/overlays/` (next to the executable), but the build writes them to `out/d012_vk/bin/overlays/Release/`. The old copy in `bin/Release/overlays/` was from Oct 31, so none of the menu overlay edits (grid table, two-row navigation, default selection, the log lines) ever ran. Fixed in two ways: the fresh menu DLL was copied by hand (the old one is kept as `*.dll.stale-oct31`), and `profiles/d012_vk/CMakeLists.txt` has a `d012_copy_overlays` target that copies `bin/overlays/<config>` next to the exe after every build. The edits are now live for the first time and untested.

## Random on the CPU screen (untested)

CPU Select has 33 cells, so Random (position 32) did not fit in a 2 x 16 slot grid. The grid is now 17 columns wide: positions 0..15 sit in slots 0..15 (slot 16, column 16 of the first row, stays empty) and positions 16..32 in slots 17..33, so the second row can hold 17 cells. Changes in `generated_unit_0040.cpp` / `0041.cpp`: every 16 from the earlier grid edit is 17 (column loops and wraps, `row * 17`, the slot divide at `0040:19184`), and `0x08A7FB54` places position p in slot p below 16 and p + 1 from 16 up. Needs a rebuild of the menu overlay library; the `d012_copy_overlays` target copies it next to the exe.

## Party roster (open)

Box trace of the Party roster ("Create a party to fight", capture with layouts `0x722a`/`0x722e` for the 1st..5th panel): 33 cells in the game's geometry, 11 in the first row (x 188..540, y 113) and 22 in the second (x 28..732, y 152), cells 32 x 39. Its code is probably a different mode of the same select screen (constructor `0x08A80D8C`, called from `0x08A69E28`), not the 6/10/10/6 builder. Until it is understood the roster handling is switched off for it (`g_roster_active` needs the first cell at x < 120). To learn the grid: start the game with `D012_TRACE_ROSTER=1`, go straight to the Party roster, move the cursor along the second row, then read `%TEMP%\d012_roster_cursor.log`.

## Party roster back to the game's own grid (untested)

`d012_roster.log` (builder lines, one per screen) showed: Quick Battle player select `mode=0`, screen word `+4 == 2`, kind `0x1D`, 32 entries; Party roster `mode=5`, `+4 == 0x0B`; Labyrinth `mode=0`, `+4 == 3`, kind `0x22`, 31 entries. The Party roster shares the grid code but keeps the game's 4 x 10 slots, so the 2 x 17 edits broke it. Now `g_d012_grid_party` / `g_d012_grid_cols` / `g_d012_grid_rows` (defined in `generated_unit_0041.cpp`, set at the start of every grid build from `screen + 4 == 11`) pick the dimensions, the `row * cols` multiplications, the slot divide, the placement gaps and the ladder split; the Party roster uses the original 10 / 4 / gaps / ladder. Rebuild the menu overlay library.

## Party roster as two rows, like the CPU roster (untested)

The Party roster has 33 cells (32 characters including Random, plus "Remove from Party", which goes after Random). Changes:
- The Party special case in the grid code is off (`g_d012_grid_party = 0`), so it gets the 2 x 17 grid and the same split as the CPU roster.
- The roster is now placed by the renderer from what the game draws, so it does not matter where a screen puts its cells (the Party roster draws 11 + 22 with a scroll): each cell layout is tagged with its position (marker `0x1000 + position`, from `g_roster_position` in `d012_hud_layout.cpp`); the renderer takes the first quad of each cell (the portrait, 1 pixel inside the 32 x 39 tile) as the tile's drawn top-left and moves the whole cell to the grid slot of its index; the frame follows the nearest drawn tile; the hand is found by the tile whose top-left plus (-29, +10) is nearest to it, so it works without a frame (the Party roster has none) and is left alone when it points at the 1st..5th panel or OK. The sprites are no longer moved by `place_roster`.
- The roster handling now applies to any screen with 32 or more cells of the cell layout.

Party roster, after the first test (untested fix): the cells were still drawn in the game's 11 + 22 shape, so the roster handling was not active there (it counted cell layouts that have a sprite; the Party screen has fewer such layouts than cells). Now it counts every cell layout (`cell_layouts >= 20`). The Party panel's slot frame (the red box around 1st..5th, drawn by the same frame layout) had its left border pulled into the roster: a frame piece is now only moved when it lies inside a tile (32 x 39 plus a small margin).

## HP numbers and the party icons screen (untested)

- Battle capture with the HP numbers unscaled: kind 254 id `0x1ffe`, i.e. not found 1..24 slots behind `0x0256`. The layout trace shows resource-less layouts at +2, +4 and -38 slots from `0x0256`. `layout_name` now also searches 25..64 slots behind (id `0x1010`) and 1..64 ahead (id `0x1020`), and `kPieces` scales both (unconfirmed which one the HP digits are; check `-38` is not something else in battle).
- The party icons screen (the Party selection before the roster) keeps 34 cell layouts although it shows 5, so counting layouts switched the roster handling on there and broke its five frames. Now only cell layouts that draw (`flags & 1` and no `0x2C` bits) count, so that screen stays inactive.

## Party icons screen and Party roster (from the box trace, untested fix)

Capture of the Party selection screen: its five icons are drawn by the cell layout (155 draws) with the roster marker on, so they were moved. Capture of the Party roster: the cells are now at the resource positions (6/10/10/6 geometry; no more 11 + 22), marker on, 72 frame draws (roster cursor and the 1st..5th slot frame). The wrapper's draw-flag count does not tell the two screens apart (the icons layouts still pass), so the renderer decides: it counts the cell spans it saw last frame (`roster_cells_prev`) and moves cells, frame and hand only when there were 20 or more.

## Party roster: the 11 + 22 shape was my own mapping (untested fix)

The settled Party roster capture shows the game drawing its cells in the plain 6/10/10/6 geometry with the roster marker on. The 11 + 22 shape came from the position tags: the Party roster's cell-layout list starts with five unused layouts, so the first drawn cell got position 5 (sixth column) and the second row ran to 22. The position of a cell is now its rank among the cell layouts that draw (`g_roster_position` in `place_roster`).

Skill-name message (the box with "Cross-Slash"): it lives in the resource-less layouts `0x1010` / `0x1020` (mode `0x18`). Quads with a centre in y 95..120 now shrink with the HUD scale about the top centre of the screen (x about 240, y about 0) in `vulkan_renderer.cpp`; digits low on the screen scale as before and everything else is left alone. Untested; the band is a guess from the screenshot (box at y about 106), and "Skip cutscene?" may or may not fall in it.

## Party roster, flash of the original layout, skill message in place (untested)

- Roster positions are no longer tagged by the wrapper. The renderer takes each cell's position as its rank among the cell spans drawn this frame, in drawing order, so unused cell layouts (the Party roster has some) take none. The wrapper decides whether a screen is a full grid from the cells' own resource positions (the first at (92, 113), the seventh at (28, 152)); the party icons screen fails that test. The renderer's "20 cells drawn last frame" gate is gone, which removes the one-frame flash of the original layout.
- Skill-name message: shrinks about its own middle (x 240, y 106) instead of the top centre.

## Default cursor, skill message found, Party panel (untested)

- Fresh select screens set the cursor column to 2 (the old default character's column) whatever the highlighted character: Onion Knight on Quick Battle, and the first DOWN on CPU select counted from column 2 (Garland's column became Cloud of Darkness). Now column 0 (2 in Party) at `generated_unit_0040.cpp` label `L_08A8130C` and `generated_unit_0041.cpp` label `L_08A81C5C`.
- Skill-name message: in the last box trace (frame 2921) it is layout kind 0xFE id 0x1FFE, a box x 176..304, y 8..40 and text y 17..31, at the top (the earlier guess, y 95..120, was wrong). `kPieces` has `{0xFE, 0x1FFE, mode 0x18}`; the renderer's mode 0x18 now scales quads with y1 <= 46 about (240, 24) by the HUD scale. Digits low on the screen in that layout also scale, like the other 0x18 layouts.
- Party right panel (layouts 0x722a slot rows x 354..480 y 47..211, 0x722e frame x 347..480 y 28..274): new mode 0x19, fixed 85% about (480, 151), independent of the HUD settings.

## Party panel follow-ups, Original Quest and Story Mode rosters (untested)

- Party panel: the portrait strips are layout 0x7218 (rows y 67, 102, 137, 172, 207, x 354..480), unscaled in the first version; now mode 0x19 like the frame and slot rows. The hand pointing at a slot or OK, and the red slot frame, are drawn by the roster hand/frame layouts: when they are not on a roster cell and lie at x >= 345 the renderer moves the hand by the panel's transform (size kept) and shrinks the frame with it (`vulkan_renderer.cpp`, the `else if (x0 >= 345.0f)` after `if (best >= 0)`).
- Original Quest character select (kind 26: cell 0x640, frame 0x644, hand 0x636) and the Story Mode party screens (kind 30: cell 0x162a, frame 0x1638, hand 0x1634; panel 0x163e / 0x163c / 0x161e) are now roster layouts in `roster_role` and the panel pieces. Ids are matched by their low 13 bits. The grid activation test is unchanged (first cell at (92,113), seventh at (28,152)).

- Pre-battle party screen (after CPU select): it draws its portrait strips with the same layout 0x7218 (40 quads, x 0..478), so the panel scale pushed them to the right. Mode 0x19 now only applies while a roster grid is active (`g_roster_active`), in `d012_hud_layout.cpp` before `is_roster_layout`.

## Character description on hover (first attempt, untested)

- From `D012_TRACE_TEXT_CALLS` (hook on the text heap allocator, stack scan): the confirmation state's code, the big state-entry function `0x08A84458` (`generated_unit_0041.cpp`), builds the description for slot 1 with `0x08A80B54(screen, 1)` (clear), `0x08A7F474(screen, 1, string id, -1)` (build; the id is the s16 at +6 of the roster entry of the selected slot, `W+1532`), and `0x0887B924(W[1432])` (show). The name texts (slots 4 and 5, `W[1444]`, `W[1448]`) are built in the same function by the block at `0x08A84848`, once per cursor change.
- Change: after the slot 5 text is shown (`L_08A848A8`), new labels `L_D012_DESC0..2` make the same three slot 1 calls (not in Party). Backup of the file before the change: `gu0041.before_desc.bak` in the temp folder.
- Expected: the description box and text show while hovering. Unknown: whether the confirmation-state hide (`0x0887B944(W[1432])`) removes it after backing out of the prompt until the cursor moves again, and whether the box/text land where the confirmation state draws them.

- Description on hover, second attempt: the first one (own calls to `0x08A80B54` / `0x08A7F474` / `0x0887B924`) ran on every hover (log lines `desc0`, `desc1`) but the build call returned to `0x089C5908` instead of the given return address, which left the function early. Reverted. Now `L_08A84464` in `generated_unit_0041.cpp` forces flag `0x10000` (slot 1, the description) into the state's flag word `W+1520` and clears it in `W+1516` at every entry of `0x08A84458`, so the game's own slot 1 code builds and shows it (and never hides it).

## Description on hover works; hiding it for non-characters and for the Party panel (untested)

- Hover description works (user confirmed). Fixes for what the user found: (1) the last window stayed on Random, Party's Remove/Reset slot and Original Quest's Free character: the flag forcing in `generated_unit_0041.cpp` (`L_08A84464`) now only sets `0x10000` when the roster table row of the selected slot (`0x08A864D0 + slot * 12`, id at +8) holds a character id 1..0x20, and clears it otherwise so the game's own code hides the text; (2) in Party the description of the default slot showed while the hand pointed at the panel: `d012_hud_layout.cpp` (place_roster) sets the description sprite's alpha to 0 while the hand layout's last sprite (the hand) is at x >= 330. Untested: whether alpha 0 comes back by itself when the hand returns to the roster.

- Party description follows the party slot under the cursor (untested): from `D012_TRACE_PARTY` logs the party list is at `W-0x2F4` (8 bytes per slot, the character id, 0 or -1 when empty; `W` = the screen's state block, `screen+40`), and `W-0x2C8` flips with the hovered slot (hypothesis: the slot cursor, only slots 1 and 2 were seen). In the slots-focus state (`W+1508 == 0x6E`, with `W-0x2F4+40 == 8` and `+64 == -1` as the Party layout signature) the patch at `L_08A84464` looks the slot's character up in the roster table, sets `W+1532` to its row (the game's slot 1 text uses it) and hides the text for an empty slot. The host-side alpha hack for the hand on the panel was removed.

## Session 23: new marker modes (v1.0.6)

`kPieces` modes added to the renderer's `VulkanRenderer::kMarkerHudBegin*` family: 0x1A corner (about the screen corner of the layout's first quad, three zones per axis; no side or lift space), 0x1B description box (gate box shrinks in place; skill box right-anchored under the list), 0x1C banner (moved down 4), 0x1D notice (about the middle of the screen, vertical centre line from the first tall quad), 0x1E keep (left as drawn; 64x32 textures still scale). The profile picks 0x1E for kind 0 0xFFFF while kind 1 0x0248 has a sprite on screen.

How to find the layout of a glitch: run with `D012_TRACE_HUD_LAYOUTS=1`, press F10 while it shows, and read `hud_quads.txt` (each line has the span's layout kind and id, the texture size and the bounds before and after) with `d012_hud_layouts.log`. Rule: decide by the layout or draw, never by coordinates.

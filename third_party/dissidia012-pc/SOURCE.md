# Source of this folder

Imported from the open-source repository *Dissidia 012 Duodecim Final Fantasy: native PC port and decompilation*
by VCKing101 (MIT licence, see `LICENSE` and `NOTICE.md`), at commit `e3a80a832b4303bf2d05ae16f4252120da7e9341`
(v0.4.0).

It is a port of the USA release (ULUS10566) built on PortableKit. This project ports the European release
(ULES01505), so its game-specific parts (addresses, overlay layout, function hooks) are reference material that has
to be mapped to the European executable before it can be used; the framework and generic parts are used directly.

Kept: `port/` (including `port/decomp/`, the small decompiled C functions the port links and runs), `tools/port/`, `docs/`, the licence and notice files, the setup scripts.

Left out on purpose: the matching decompilation of the USA executable (`src/`, `include/`, `config/`) and the
tooling that builds it (the rest of `tools/`). Nothing here depends on them at run time.

His PortableKit patch series (`port/portablekit-patches/`) is applied on top of PortableKit for this project's build.

Changes made here (marked `MODIFIED` in the files): `port/host/d012_profile.cpp` lists the European disc
(ULES01505) as a profile variant, and `port/portablekit-patches/0066-*.patch` makes the installer accept a disc
whose `EBOOT.BIN` is a registered variant whatever its disc id. The European disc's overlays and decrypted
executable are byte-identical to the USA v1.00 ones, so the game code is shared.
`tools/port/setup/game.py` (marked `MODIFIED`) accepts the European disc's id, version, size and image hash;
the disc's game files are still checked against the same SHA-256 values as the USA ones.

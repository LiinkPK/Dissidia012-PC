#!/usr/bin/env python3
"""Writes what the Emendatus mod changes on the disc, as a C++ include for profiles/d012_vk/d012_emendatus.cpp.

    make_mod_data.py <original US iso> <US iso with the Emendatus xdelta applied> <original EUR iso> <out .inc>
                     [--elf-dir DIR]

The mod changes five files of the disc: DATA/PACKAGE.BIN (48 entries of the archive, 325 KB), DATA/PACKAGE_INFO.BIN (the
size field of three entries), DATA/OVL_BATTLE_APP.ELF and DATA/OVL_MENU_APP.ELF (code; the menu overlay also grows by 3820
bytes of added code) and PSP_GAME/ICON0.PNG (not carried). The EBOOT is not touched.

Only the bytes the mod changes are written, never the game's own data. The EUR disc holds the same 48 entries (same hash,
same content) at other archive offsets, so the EUR table is found by entry hash and each region is checked against the
original bytes before it is written. --elf-dir also writes the two patched overlays there (for the corpus generator,
tools/port/overlay_meta.py: its image is the segment, so the memory size is raised to the file size in that copy).
"""
import bisect
import struct
import sys

SECTOR = 2048
DATA = "/PSP_GAME/USRDIR/DATA/"
GAP = 64  # changed runs closer than this become one region


def read_dir(f, lba, size, prefix, out):
    f.seek(lba * SECTOR)
    data = f.read(size)
    pos = 0
    while pos < len(data):
        n = data[pos]
        if n == 0:
            pos = (pos // SECTOR + 1) * SECTOR
            continue
        rec = data[pos:pos + n]
        pos += n
        elba, esize = struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0]
        name = rec[33:33 + rec[32]]
        if name in (b"\x00", b"\x01"):
            continue
        path = prefix + "/" + name.decode("latin-1").split(";")[0]
        if rec[25] & 2:
            read_dir(f, elba, esize, path, out)
        else:
            out[path] = (elba, esize)


class Iso:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.f.seek(16 * SECTOR)
        root = self.f.read(SECTOR)[156:190]
        self.files = {}
        read_dir(self.f, struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0], "", self.files)

    def size(self, name):
        return self.files[DATA + name][1]

    def read(self, name, offset=0, length=None):
        lba, size = self.files[DATA + name]
        length = size - offset if length is None else length
        self.f.seek(lba * SECTOR + offset)
        return self.f.read(length)


def diff_regions(a, b, gap=GAP, limit=None):
    """[(start, end)] of the bytes that differ in a and b (same length up to limit), runs closer than gap joined."""
    n = min(len(a), len(b)) if limit is None else limit
    runs = []
    for blk in range(0, n, 4096):
        x, y = a[blk:min(blk + 4096, n)], b[blk:min(blk + 4096, n)]
        if x == y:
            continue
        for i in range(len(x)):
            if x[i] != y[i]:
                p = blk + i
                if runs and p - runs[-1][1] <= gap:
                    runs[-1][1] = p + 1
                else:
                    runs.append([p, p + 1])
    return [tuple(r) for r in runs]


def index(iso):
    info = iso.read("PACKAGE_INFO.BIN")
    count = struct.unpack_from("<I", info, 8)[0]
    return [struct.unpack_from("<3I", info, 16 + 12 * k) for k in range(count)]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    elf_dir = None
    if "--elf-dir" in sys.argv:
        elf_dir = sys.argv[sys.argv.index("--elf-dir") + 1]
        args.remove(elf_dir)
    tail_out = stock_elf = None
    if "--tail-out" in sys.argv:
        tail_out = sys.argv[sys.argv.index("--tail-out") + 1]
        args.remove(tail_out)
    if "--stock-elf" in sys.argv:
        stock_elf = sys.argv[sys.argv.index("--stock-elf") + 1]
        args.remove(stock_elf)
    us, usp, eu = Iso(args[0]), Iso(args[1]), Iso(args[2])
    out_path = args[3]
    blob = bytearray()
    tables = {}

    def add(name, regions, source):
        rows = []
        for s, e in regions:
            rows.append((s, len(blob), e - s))
            blob.extend(source[s:e])
        tables[name] = rows

    # --- the executable: the newer mod patches the (plain) EBOOT.BIN; the port patches its own decrypted executable the same way
    if stock_elf:
        a = open(stock_elf, "rb").read()
        lba, size = usp.files["/PSP_GAME/SYSDIR/EBOOT.BIN"]
        usp.f.seek(lba * SECTOR)
        b = usp.f.read(size)
        assert b[:4] == b"\x7fELF", "the patched EBOOT.BIN is not a plain executable"
        runs = diff_regions(a, b, gap=0, limit=len(a))
        add("kEmEboot", runs + [(len(a), len(b))], b)
        eboot_sizes = (len(a), len(b))
        print("eboot: %d regions and %d bytes added (file %d -> %d)" % (len(runs), len(b) - len(a), len(a), len(b)))

    # --- the two overlays (identical on the US and EUR discs) --------------------------------------------------------
    for name, key in (("OVL_BATTLE_APP.ELF", "Battle"), ("OVL_MENU_APP.ELF", "Menu")):
        a, b, c = us.read(name), usp.read(name), eu.read(name)
        assert a == c, name + " differs between the US and EUR discs"
        if key == "Menu":
            phoff = struct.unpack_from("<I", a, 28)[0]
            keep = struct.unpack_from("<I", a, phoff + 4)[0] + struct.unpack_from("<I", a, phoff + 16)[0]  # end of the segment's bytes
            assert len(b) > len(a)
            add("kEmMenu", diff_regions(a[:keep], b[:keep]), b)
            tables["kEmMenuTail"] = [(keep, len(blob), len(b) - keep)]
            blob.extend(b[keep:])
            sizes = (keep, len(b))
            print("menu: %d regions, then %d bytes from offset %d (file %d -> %d)" % (len(tables["kEmMenu"]), len(b) - keep, keep, len(a), len(b)))
        else:
            assert len(a) == len(b)
            add("kEmBattle", diff_regions(a, b), b)
            print("battle: %d regions" % len(tables["kEmBattle"]))
        if elf_dir:
            d = bytearray(b)
            fs = struct.unpack_from("<I", d, 52 + 16)[0]
            if struct.unpack_from("<I", d, 52 + 20)[0] < fs:
                struct.pack_into("<I", d, 52 + 20, fs)
            open("%s/%s" % (elf_dir, name), "wb").write(d)

    # --- PACKAGE_INFO.BIN: the same offsets on both discs, if the entry hashes sit at the same places --------------------
    ia, ib = us.read("PACKAGE_INFO.BIN"), usp.read("PACKAGE_INFO.BIN")
    add("kEmIndex", diff_regions(ia, ib, gap=0), ib)
    eus, eeu = index(us), index(eu)
    for s, _off, n in tables["kEmIndex"]:
        k = (s - 16) // 12
        assert eus[k][0] == eeu[k][0], "entry %d has another hash on the EUR disc" % k
    print("index: %d regions, the same on both discs" % len(tables["kEmIndex"]))

    # --- PACKAGE.BIN: absolute offsets per disc, the EUR ones by entry hash -----------------------------------------
    total_us = us.size("PACKAGE.BIN")
    regions, chunk = [], 1 << 22
    for off in range(0, total_us, chunk):
        n = min(chunk, total_us - off)
        x, y = us.read("PACKAGE.BIN", off, n), usp.read("PACKAGE.BIN", off, n)
        if x != y:
            for s0, e0 in diff_regions(x, y):
                s1, e1 = s0 + off, e0 + off
                if regions and s1 - regions[-1][1] <= GAP:
                    regions[-1] = (regions[-1][0], e1)
                else:
                    regions.append((s1, e1))
    starts = sorted((e[1] * SECTOR, k) for k, e in enumerate(eus))
    keys = [s for s, _ in starts]
    by_hash_eu = {e[0]: k for k, e in enumerate(eeu)}
    rows_us, rows_eu = [], []
    for s, e in regions:
        i = bisect.bisect_right(keys, s) - 1
        k = starts[i][1]
        end = keys[i + 1] if i + 1 < len(keys) else total_us
        assert e <= end, "a region crosses into the next entry"
        ke = by_hash_eu[eus[k][0]]
        shift = eeu[ke][1] * SECTOR - eus[k][1] * SECTOR
        original, patched = us.read("PACKAGE.BIN", s, e - s), usp.read("PACKAGE.BIN", s, e - s)
        assert original == eu.read("PACKAGE.BIN", s + shift, e - s), "the EUR bytes of entry %08x are not the original ones" % eus[k][0]
        rows_us.append((s, len(blob), e - s))
        rows_eu.append((s + shift, len(blob), e - s))
        blob.extend(patched)
    tables["kEmPackageUS"], tables["kEmPackageEUR"] = rows_us, rows_eu
    print("package: %d regions, %d bytes; every EUR region checked against the original bytes" % (len(regions), sum(r[2] for r in rows_us)))

    # --- the new data the mod appends to PACKAGE.BIN (the new character): too large for a table, written as a file --------
    tail_size = usp.size("PACKAGE.BIN") - total_us
    assert tail_size >= 0
    if tail_out:
        with open(tail_out, "wb") as t:
            for off in range(0, tail_size, 1 << 24):
                t.write(usp.read("PACKAGE.BIN", total_us + off, min(1 << 24, tail_size - off)))
        print("tail: %d bytes written to %s" % (tail_size, tail_out))

    header_us, header_eu = us.read("PACKAGE.BIN", 0, 64), eu.read("PACKAGE.BIN", 0, 64)
    assert header_us != header_eu

    with open(out_path, "w", newline="\n") as f:
        f.write("// Generated by tools/mods/emendatus/make_mod_data.py: what the Emendatus mod changes on the disc.\n")
        f.write("// Only the changed bytes; the regions of the disc they go on are in the tables.\n")
        f.write("static const std::uint8_t kEmBlob[%d] = {\n" % len(blob))
        for i in range(0, len(blob), 32):
            f.write("    " + ",".join("0x%02X" % x for x in blob[i:i + 32]) + ",\n")
        f.write("};\n")
        f.write("struct EmRegion { std::uint64_t offset; std::uint32_t blob; std::uint32_t length; };\n")
        for name, rows in tables.items():
            f.write("static const EmRegion %s[] = {\n" % name)
            for off, bo, ln in rows:
                f.write("    {%du, %du, %du},\n" % (off, bo, ln))
            f.write("};\n")
        if stock_elf:
            f.write("static const std::uint64_t kEmEbootStock = %du;     // the decrypted executable's size, and with the mod\n" % eboot_sizes[0])
            f.write("static const std::uint64_t kEmEbootSize = %du;\n" % eboot_sizes[1])
        f.write("static const std::uint64_t kEmTailSize = %du;      // bytes appended to PACKAGE.BIN (the mod's assets file)\n" % tail_size)
        f.write("static const std::uint64_t kEmMenuKeep = %du;      // the menu overlay's bytes up to here are the game's\n" % sizes[0])
        f.write("static const std::uint64_t kEmMenuSize = %du;      // its size with the mod\n" % sizes[1])
        for name, h in (("kEmHeaderUS", header_us), ("kEmHeaderEUR", header_eu)):
            f.write("static const std::uint8_t %s[64] = {%s};  // the first bytes of PACKAGE.BIN of that release\n"
                    % (name, ",".join("0x%02X" % x for x in h)))
    print("wrote %s (%d bytes of data)" % (out_path, len(blob)))


main()

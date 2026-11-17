#!/usr/bin/env python3
"""Puts the Emendatus plugin's run-time hooks into the generated executable corpus, each one guarded.

    guard_runtime_hooks.py <generated-variants/emendatus dir>    (run it after make_variant_corpora.py)

The plugin hooks the game's executable with code of its own once block2 (0x0BFE8000) and the plugin (0x0ABBC700) are loaded.
Recompiled code cannot be patched while it runs, and the hooks must not exist before then (the game boots without them), so
each hook site here tests, when it runs, whether the block is in memory: if it is, it goes to the hook, if not, to the
original target. The sites are listed in runtime_code_patches.disabled (address, original word, new word).
"""
import re
import sys
from pathlib import Path

BLOCK, PLUGIN = 0x0BFE8000, 0x0ABBC700
SKIP = {0x088470DC, 0x088470E0, 0x088470E4, 0x088470E8, 0x088470EC, 0x088470F0, 0x088470F4}  # a function copied by the menu


def guard_for(address, word):
    # the hook is live exactly when the plugin has written it into the game's memory
    return "(d012_hook_ok(0x%08Xu) && aot_mem.aot_load32(0x%08Xu) == 0x%08Xu && (d012_hook_trace(0x%08Xu), true))" % (address, address, word, address)


def load_patches():
    out = []
    for line in (Path(__file__).parent / "runtime_code_patches.disabled").read_text().splitlines():
        if line.strip() and not line.startswith("#"):
            a, o, n = (int(x, 16) for x in line.split())
            if a not in SKIP:
                out.append((a, o, n))
    return out


def main():
    root = Path(sys.argv[1])
    units = {}
    for p in sorted(root.glob("generated_unit_*.cpp")):
        with open(p, newline="") as f:
            units[p] = f.read()
    done = 0
    changed = set()
    for address, orig, new in load_patches():
        label = "L_%08X:\n" % address
        hits = [p for p, t in units.items() if label in t]
        if len(hits) != 1:
            print("site %08X: label found in %d units, skipped" % (address, len(hits)))
            continue
        path = hits[0]
        text = units[path]
        start = text.index(label)
        guard = guard_for(address, new)
        if ("aot_load32(0x%08Xu) == 0x%08Xu &&" % (address, new)) in text[start:start + 900]:
            continue  # guarded already
        if orig >> 26 == 3 and new >> 26 == 3:
            # jal -> jal: choose the target where the call is made
            end = text.index("return;", start)
            block = text[start:end]
            original_target = (orig & 0x03FFFFFF) << 2
            new_target = (new & 0x03FFFFFF) << 2
            direct = re.search(r"if \((rt\.invoke_chained_direct<[^>]*>\(ctx, &aot_mem\))", block)
            plain = "ctx.pc = 0x%08Xu;" % original_target
            if direct:
                call = direct.group(1)
                swapped = block.replace(call, "(%s ? (ctx.pc = 0x%08Xu, rt.invoke_chained_call(ctx, &aot_mem)) : %s)" % (guard, new_target, call), 1)
            elif plain in block:
                swapped = block.replace(plain, "ctx.pc = %s ? 0x%08Xu : 0x%08Xu;" % (guard, new_target, original_target), 1)
            elif "goto L_%08X;" % original_target in block:
                # a call to a label of the same unit: the return address was set just before
                ret = "0x%08Xu" % (address + 8)
                local = "goto L_%08X;" % original_target
                swapped = block.replace(local, "if %s { ctx.pc = 0x%08Xu; if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == %s) goto L_%08X; return; }\n    %s" % (guard, new_target, ret, address + 8, local), 1)
            else:
                print("site %08X: no call to %08X found, skipped" % (address, original_target))
                continue
            text = text[:start] + swapped + text[end:]
        elif new >> 26 in (2, 3):
            # an instruction replaced by a jump: take the jump at once when the block is there
            hook = "    if %s { ctx.pc = 0x%08Xu; (void)rt.invoke_chained_call(ctx, &aot_mem); return; }\n" % (guard, (new & 0x03FFFFFF) << 2)
            text = text[:start + len(label)] + hook + text[start + len(label):]
        else:
            continue
        units[path] = text
        changed.add(path)
        done += 1
    helper = (Path(__file__).parent / "hook_helper.txt").read_text()
    for path in sorted(changed):
        text = units[path]
        if "d012_hook_ok(std" not in text:
            nl = chr(13) + chr(10) if (chr(13) + chr(10)) in text else chr(10)
            marker = "#include <cstdint>" + nl
            text = text.replace(marker, marker + helper.replace(chr(10), nl), 1)
        with open(path, "w", newline="") as f:
            f.write(text)
    print("%d hook sites guarded" % done)


main()

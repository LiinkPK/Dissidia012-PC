// Dissidia 012 [duodecim] Final Fantasy -- PortableKit game profile.
//
// The executable is recompiled unmodified (psp_recomp --auto on the ISO-decrypted EBOOT) and
// runs on the framework's kernel, IO, GE, display, audio and pad HLE. Nothing here forges game
// state: the game builds its own scenes, archives and display lists.

#include "profile.hpp"

#include "psprecomp/elf32.hpp"
#include "psprecomp/interpreter.hpp"
#include "psprecomp/runtime.hpp"
#include "kernel/kernel.hpp"
#include "hle/hle_common.hpp"
#include "d012_icon.hpp"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <map>
#include <thread>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <vector>

namespace psprecomp {
void register_generated_functions(Runtime &runtime);
namespace ovl_menu { void register_ovl_menu_functions(Runtime &runtime); }
void register_ovl_battle_functions(Runtime &runtime);
void register_ovl_extra_functions(Runtime &runtime);
} // namespace psprecomp

namespace portablekit {
namespace {

constexpr std::uint32_t kModuleStopFunction = 0x08BA77D0u;   // module stop pointer; its module is never loaded

// OVL_MENU_APP is a flat image at 0x089DD4C0 that the game swaps in at runtime. Its recompiled
// code is registered up front; the image itself is mapped here so the code has data to read
// before the game loads its own copy.
void load_overlay_image(psprecomp::Runtime &rt, const std::filesystem::path &path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return;
    const std::vector<std::uint8_t> b((std::istreambuf_iterator<char>(in)), {});
    if (b.size() < 0x54) return;
    auto u32 = [&](std::size_t p) {
        return static_cast<std::uint32_t>(b[p]) | (static_cast<std::uint32_t>(b[p + 1]) << 8) |
               (static_cast<std::uint32_t>(b[p + 2]) << 16) | (static_cast<std::uint32_t>(b[p + 3]) << 24);
    };
    const std::uint32_t off = u32(0x38), va = u32(0x3c), size = u32(0x44);
    if (off > b.size() || size > b.size() - off || !rt.memory().contains(va, size)) return;
    for (std::uint32_t i = 0; i < size; i += 4) rt.memory().store32(va + i, u32(off + i));
    std::printf("[OVERLAY] menu overlay mapped at 0x%08X size=0x%X\n", va, size);
}

// Calls the framework does not cover. Everything else the game imports is the framework's.
void register_d012_extra_hle(HleRegistrar &hle) {
    // LIBFONT.PRX and LIBSUPPREACC.PRX are not recompiled: hand out module ids and let the
    // start/stop calls succeed. (PPSSPP hands out 288 and 289.)
    hle.add("ModuleMgrForUser", "sceKernelLoadModule", [](Runtime &, AllegrexContext &ctx) {
        static std::uint32_t next_module = 288u;
        kernel().finish(ctx, next_module++);
    });
    // module_start forwards the loader's own (arglen, argp) to sceKernelStartThread, and the
    // loader hands it values that are not a length and a pointer. A real PSP would copy only
    // what it can read; the framework copies from wherever argp points and faults. Start the
    // thread without arguments unless the block is genuinely inside guest memory.
    hle.add("ThreadManForUser", "sceKernelStartThread", [](Runtime &rt, AllegrexContext &ctx) {
        const std::uint32_t arglen = ctx.gpr[5], argp = ctx.gpr[6];
        const bool valid = arglen != 0u && arglen <= 0x10000u && rt.memory().contains(argp, arglen);
        const SceUID result = kernel().start_thread(ctx, static_cast<SceUID>(ctx.gpr[4]),
                                                    valid ? arglen : 0u, valid ? argp : 0u);
        kernel().finish(ctx, static_cast<std::uint32_t>(result));
    });
    // English text; the confirm button is cross.
    hle.add("sceImpose", "sceImposeGetLanguageMode", [](Runtime &rt, AllegrexContext &ctx) {
        if (ctx.gpr[4] != 0u) rt.memory().store32(ctx.gpr[4], 1u);
        if (ctx.gpr[5] != 0u) rt.memory().store32(ctx.gpr[5], 1u);
        kernel().finish(ctx, 0u);
    });
    hle.add("sceRtc", "sceRtcGetTickResolution", [](Runtime &, AllegrexContext &ctx) {
        kernel().finish(ctx, 1000000u);
    });
}

// The game loads OVL_MENU_APP, OVL_BATTLE_APP and OVL_EXTRA_APP into one window, with an 84-byte
// header at kOverlayFile and the code at kOverlayWindow. Each has its own recompiled code; the one
// matching what the game just loaded is registered and the others are dropped. An image nobody
// recompiled leaves the window to the interpreter. The images are told apart by a hash of the
// first 0x200 bytes of the file.
constexpr std::uint32_t kOverlayFile = 0x089DD46Cu;
constexpr std::uint32_t kOverlayWindow = 0x089DD4C0u;
constexpr std::uint32_t kOverlayWindowEnd = 0x089DD46Cu + 0x1A0000u;

enum class Overlay { Menu, Battle, Extra, Unknown };

Overlay identify_overlay(const psprecomp::GuestMemory &memory) {
    if (!memory.contains(kOverlayFile, 0x200u) || memory.load32(kOverlayFile + 0x3Cu) != kOverlayWindow)
        return Overlay::Unknown;
    std::uint64_t key = 0xCBF29CE484222325ull;
    for (std::uint32_t i = 0; i < 0x200u; ++i) key = (key ^ memory.load8(kOverlayFile + i)) * 0x100000001B3ull;
    switch (key) {
    case 0x8c6796d335f705f0ull: return Overlay::Menu;
    case 0xc51be88b2f6be5f8ull: return Overlay::Battle;
    case 0xf542f3b3b2e126b5ull: return Overlay::Extra;
    default:
        std::printf("[D012] unknown overlay image, key %016llX\n", static_cast<unsigned long long>(key));
        return Overlay::Unknown;
    }
}

void on_code_flushed(psprecomp::Runtime &rt) {
    static Overlay registered = Overlay::Menu;  // the menu's code is registered at start-up
    const auto &memory = rt.memory();
    // The window is not an overlay until the game has put a header there.
    if (!memory.contains(kOverlayFile, 0x200u) || memory.load32(kOverlayFile + 0x3Cu) != kOverlayWindow) return;
    const Overlay loaded = identify_overlay(memory);
    if (loaded == registered) return;
    rt.unregister_functions(kOverlayFile, kOverlayWindowEnd);
    switch (loaded) {
    case Overlay::Menu: psprecomp::ovl_menu::register_ovl_menu_functions(rt); break;
    case Overlay::Battle: psprecomp::register_ovl_battle_functions(rt); break;
    case Overlay::Extra: psprecomp::register_ovl_extra_functions(rt); break;
    case Overlay::Unknown: break;
    }
    registered = loaded;
    std::printf("[D012] overlay %s loaded%s\n",
                loaded == Overlay::Menu ? "menu" : loaded == Overlay::Battle ? "battle" : loaded == Overlay::Extra ? "extra" : "?",
                loaded == Overlay::Unknown ? " (interpreted)" : " (recompiled)");
    std::fflush(stdout);
}

// The code generator has no lowering for VCRS.T (VFPU1, operation 5) or the VFPU4 butterflies and
// sorting steps (vbfy1/2, vsrt1-4), so the generated code stops at each one. The interpreter does run it: it executes this one instruction and the program
// counter moves on, so generated code carries on from the next.
bool run_unlowered_vfpu(psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx, std::uint32_t pc, std::uint32_t instruction) {
    const bool vcrs = (instruction >> 26u) == 0x19u && ((instruction >> 23u) & 7u) == 5u;
    const std::uint32_t shuffle = (instruction >> 16u) & 31u;
    const bool vfpu4_shuffle = (instruction >> 26u) == 0x34u && ((instruction >> 21u) & 31u) == 2u &&
                               (shuffle <= 3u || shuffle == 8u || shuffle == 9u);
    if (!vcrs && !vfpu4_shuffle) return false;
    ctx.pc = pc;
    return psprecomp::interpret_allegrex(rt, ctx, 1u) != psprecomp::InterpreterExit::Stopped;
}

// D012_PC_SAMPLER=1: say where the guest is spending its time. Reads the program counter 100 times
// a second and prints the five most common values every 3 seconds, which shows a spin or a stall.
void start_pc_sampler(psprecomp::Runtime &rt) {
    if (std::getenv("D012_PC_SAMPLER") == nullptr) return;
    std::thread([&rt] {
        std::map<std::uint32_t, unsigned> seen;
        for (unsigned tick = 1;; ++tick) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            ++seen[rt.cpu().pc];
            if (tick % 300u != 0u) continue;
            std::vector<std::pair<unsigned, std::uint32_t>> top;
            for (const auto &[pc, count] : seen) top.emplace_back(count, pc);
            std::sort(top.rbegin(), top.rend());
            std::fprintf(stderr, "[pc-sampler]");
            for (std::size_t i = 0; i < top.size() && i < 5u; ++i)
                std::fprintf(stderr, " %08X x%u", top[i].second, top[i].first);
            std::fprintf(stderr, "\n");
            seen.clear();
        }
    }).detach();
}

void patch_d012_image(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf) {
    // Relative paths like "data/foo.bin" resolve under disc0:/PSP_GAME/USRDIR.
    set_io_working_directory("disc0:/PSP_GAME/USRDIR");

    psprecomp::register_generated_functions(rt);
    psprecomp::set_runtime_unsupported_hook(run_unlowered_vfpu);
    start_pc_sampler(rt);
    psprecomp::ovl_menu::register_ovl_menu_functions(rt);

    // The generated code covers the import stub addresses with plain `jr ra` bodies, which
    // would keep the framework's HLE from ever seeing the game's calls. Bind every import.
    if (const auto module = elf.find_module_info(rt.memory(), game().load_base)) {
        std::size_t rebound = 0u;
        for (const auto &import : elf.scan_imports(rt.memory(), *module)) {
            rt.force_import_stub(import.stub_address, import.library, import.nid);
            ++rebound;
        }
        std::printf("[D012] %zu import stubs bound to the framework HLE\n", rebound);
    }

    // The ELF header's entry is 0; the real entry is module_start at the load base. The first
    // visit to address 0 is the loader starting the program. module_start then returns to
    // address 0 as well (the loader thread's return address), and that must end the thread:
    // redirecting again would run module_start, and create the game's thread, over and over.
    rt.register_function(0x00000000u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static bool started = false;
        if (!started) {
            started = true;
            ctx.pc = game().load_base;
            return;
        }
        kernel().exit_current_thread(ctx, static_cast<std::int32_t>(ctx.gpr[2]), false);
    }, "d012_entry_redirect");

    // sceKernelStopModule calls the module's stop function. The module is a fake, so it is a no-op.
    rt.register_function(kModuleStopFunction, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "d012_module_stop_nop");

    std::filesystem::path overlay = std::filesystem::path(game().boot_path).parent_path() / "OVL_MENU_APP.ELF";
    if (const char *env = std::getenv("D012_OVERLAY"); env != nullptr && *env != '\0') overlay = env;
    if (std::filesystem::exists(overlay)) load_overlay_image(rt, overlay);
}

constexpr SaveFolder kSaveFolders[] = {
    {"ULES01505",     "Game data",    true},
    {"ULES01505INST", "Install data", false},
};

} // namespace

const GameProfile &game() {
    static const GameProfile profile{
        .app_name          = "d012_native",
        .project_name      = "Dissidia012",
        .env_prefix        = "D012",
        .data_organization = "Dissidia012",
        .data_application  = "D012",

        .disc_id              = "ULES01505",
        .disc_id_display      = "ULES-01505",
        .game_title           = "Dissidia 012 [duodecim] Final Fantasy",
        .executable_path_on_disc = "PSP_GAME/SYSDIR/EBOOT.BIN",
        .param_sfo_path_on_disc  = "PSP_GAME/PARAM.SFO",

        .encrypted_executable_sha256 = "",
        .executable_sha256           = "",
        .decryption_tag  = 0u,
        .decryption_key  = {},

        .load_base      = 0x08804040u,
        .guest_ram_bytes = 64u * 1024u * 1024u,
        .boot_path      = "disc0:/PSP_GAME/SYSDIR/EBOOT.BIN",
        .overlay_slots  = {},

        .save_game_name = "ULES01505",
        .save_folders   = kSaveFolders,
        .adhoc_product_code = "ULES01505",

        .register_extra_hle  = register_d012_extra_hle,
        .patch_loaded_image  = patch_d012_image,
        .on_code_flushed     = on_code_flushed,

        .window_title        = "Dissidia 012 Final Fantasy HD Remastered",
        .window_icon_png     = d012_icon::kPng,
        .window_icon_png_size = d012_icon::kPngSize,
        .alias_display_buffers = true,
    };
    return profile;
}

} // namespace portablekit

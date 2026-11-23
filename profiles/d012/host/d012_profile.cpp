// The PortableKit profile for Dissidia 012 Final Fantasy HD Remastered: the European release (ULES01505), with
// the North American release (ULUS10566) accepted as a variant.
//
// Derived from the profile of the open-source port "Dissidia 012 Duodecim Final Fantasy: native PC port and
// decompilation" by VCKing101 (MIT licence, third_party/dissidia012-pc/LICENSE). The game's addresses, overlay
// window and frame pacing are that port's measurements; the identity, save folders and names are this
// project's. Both discs hold the same decrypted executable and the same overlays (byte for byte), which is why
// the same game code runs either.
//
// Constants only, as PortableKit's profile guide asks. Every value is a fact about the game's own files or a
// choice of this project's names.

#include "profile.hpp"

#include <cstdio>
#include <string>
#include <vector>

#include "gpu/frame_interpolation.hpp"

#include "d012_hle.hpp"
#include "d012_icon.hpp"
#include "../../d012_vk/d012_battle_shortcuts.hpp"
#include "../../d012_vk/d012_boot_skip.hpp"
#include "../../d012_vk/d012_ability_trace.hpp"
#include "../../d012_vk/d012_discord.hpp"
#include "../../d012_vk/d012_netplay_trace.hpp"

// The one battle move on a touch screen that has no button on a controller: EX Mode, R + square (a controller's L3). Dodge and dash are
// L2 and R2, and the assists and the summon are the D-pad in battle (d012_camera.cpp), as on a controller.
constexpr portablekit::GameProfile::TouchCombo kTouchCombos[] = {
    {"EX Mode", 0x0200u | 0x8000u},
};

// The downloaded 100% saves equip two Cloud abilities (low ids 0x13 and 0x14) that have no row in the game's ability table (Cloud's end
// at 0x12): the game reads a null row and crashes when a battle starts. They are cleared from Cloud's equipped sets as the save loads
// (the abilities stay learned). The image is version 10, 0x3ECC8 bytes: 31 character records of 0x778 bytes from 0x50, each starting
// with the character's id (Cloud is 13) and holding 5 equipment sets of 0xC6 bytes from +0x10.
void d012_repair_save(const std::string &file_name, std::vector<std::uint8_t> &data) {
    constexpr std::size_t kImage = 0x3ECC8u, kRecords = 0x50u, kRecord = 0x778u, kSet = 0xC6u;
    if (file_name != "DISSIDIA.BIN" || data.size() != kImage || data[0] != 10u) return;
    unsigned cleared = 0;
    for (std::size_t slot = 0; slot < 31u; ++slot) {
        const std::size_t base = kRecords + slot * kRecord;
        if (data[base] != 13u) continue;
        for (std::size_t set = 0; set < 5u; ++set)
            for (std::size_t i = 0; i < 0x20u; ++i) {
                std::uint8_t &id = data[base + 0x10u + set * kSet + i];
                if (id == 0x13u || id == 0x14u) {
                    id = 0xFFu;
                    ++cleared;
                }
            }
    }
    if (cleared != 0u) std::printf("[save] cleared %u Cloud abilities that have no row in the game's table\n", cleared);
}

// The key that signs every online connection (third_party PortableKit adhoc/auth.hpp). Official builds get it from the build's
// D012_RELAY_KEY environment variable (CMake writes d012_relay_key.hpp); a build without it sends nothing and the relay refuses it.
#if __has_include("d012_relay_key.hpp")
#include "d012_relay_key.hpp"
#endif
#ifndef D012_RELAY_KEY
#define D012_RELAY_KEY ""
#endif

#include <cstdio>
#include <filesystem>
#include <span>
#include <string_view>
#include <vector>

bool d012_emendatus_on();  // d012_vk/d012_emendatus.cpp: the Emendatus Mod is running
void d012_switch_edition(bool on);  // d012_vk/d012_emendatus.cpp: the mod on or off for the next start, and the game restarts
std::string d012_mods_folder();  // d012_vk/d012_emendatus.cpp: where the mod's files are

namespace d012_emendatus {
void patch_loaded_image(psprecomp::Runtime &runtime, const psprecomp::Elf32Image &elf);  // d012_vk/d012_emendatus.cpp
void redirect_game_files(std::filesystem::path &executable, std::filesystem::path &disc_image);  // d012_vk/d012_emendatus.cpp
}

namespace portablekit {
namespace {

// The version of this release, as its GitHub tag. Change it here for every release: the in-game update check
// compares it with the newest release on https://github.com/LiinkPK/Dissidia012-PC/releases.
constexpr const char *kReleaseVersion = "v1.1.2";

// The game names its saves "ms0:/PSP/SAVEDATA/%s%s": the disc id followed by the slot.
constexpr SaveFolder kSaveFolders[] = {
    {"ULES01505GameData00", "Save slot 1", true},
    {"ULES01505GameData01", "Save slot 2", true},
};
constexpr SaveFolder kUsaSaveFolders[] = {
    {"ULUS10566GameData00", "Save slot 1", true},
    {"ULUS10566GameData01", "Save slot 2", true},
};

// What differs between the two discs: the identity the game's saves, textures and cheats go by. The disc image
// the player set up says which one runs (set_active_disc_id).
struct Release {
    const char *disc_id;
    const char *disc_id_display;
    const char *name;
    std::span<const SaveFolder> saves;
};

// The port's extra HLE, then the Discord Rich Presence (d012_vk/d012_discord.cpp).
void register_hle(HleRegistrar &hle) {
    d012::register_extra_hle(hle);
    d012_discord::install(hle);
    d012_ability_trace::install(hle);
    d012_netplay_trace::install(hle);
    d012_boot_skip::install(hle);
    d012_battle_shortcuts::install(hle);
}

// One overlay window. The game loads OVL_MENU_APP.ELF, OVL_BATTLE_APP.ELF or OVL_EXTRA_APP.ELF there; each is
// one PT_LOAD segment at 0x089DD4C0. The end is the end of the largest (battle) rounded up to the next section
// of main.
constexpr std::uint32_t kOverlaySlots[] = {0x089DD4C0u, 0x08B62F70u};

// The North American disc: another EBOOT.BIN around the same executable, accepted so a player with either disc
// can use the port. Its saves are in ULUS10566 folders, which the running disc's profile reads (game()).
constexpr ProfileVariant kVariants[] = {
    {"usa", "North American release (ULUS10566)",
     // No executable hash of its own: it runs the profile's executable and corpus (the installer falls back to
     // the profile's hash). Naming one here makes the runtime look for a separate "usa" corpus.
     "8fbf3541ab121aff85aae72795760736dfe37706996b2b0f9b81d36fc98f3394", nullptr},
    // The executable of the newer Emendatus mod (the one that adds a character): the plain executable with MIPS patches (new
    // code at 0x089CB0A0). The port makes it from the disc's own executable when the mod's switch is on (d012_emendatus.cpp),
    // or finds it on a disc patched by the mod, and runs a corpus of its own
    // (profiles/d012_pk/work/generated-variants/emendatus/, made by tools/mods/emendatus/make_variant_corpora.py).
    {"emendatus", "Emendatus mod, with its new character",
     "832063088cf2dd3b4c064cb06a9c2d1a6c8eb74bfabfbdd0a7a79b5c0c894572",
     "832063088cf2dd3b4c064cb06a9c2d1a6c8eb74bfabfbdd0a7a79b5c0c894572"},
    // The stock executable with Gojo's memory expansion (bigger heaps for the game's own allocator; the Emendatus mod's executable
    // has the same edits). The port makes it from the disc's own executable when its corpus is built in (d012_expansion.cpp,
    // profiles/d012_pk/work/generated-variants/expanded/, made by tools/mods/expansion/make_expanded_corpus.py).
    {"expanded", "Stock executable with the memory expansion",
     "9eac94624fb7e058973372fa914eed4a2fd27b895626da1f68d7bf7e2124cf93",
     "9eac94624fb7e058973372fa914eed4a2fd27b895626da1f68d7bf7e2124cf93"},
};

// Frame interpolation's distances, in the game's world units. Battle's world is in metres or close to it: the
// near fighter is drawn about 6.4 units from the eye, the far one 12.7, the arena's edges about 40. The
// framework's defaults were measured on a world about a hundred times finer. The camera moves up to 2.7 units
// a game frame while it follows a dash; effect draws paired with the wrong instance of their mesh jump 20 to
// 40 units with the camera standing still.
constexpr gpu::interpolation::CutThresholds kInterpolationThresholds{
    .max_camera_distance = 4.0f,
    .continuous_distance_margin = 0.6f,
    .max_continuous_distance = 8.0f,
    .max_own_motion = 4.0f,
};

// The game opens a notice at start-up that it autosaves; it is not shown.
bool skip_autosave_notice(std::string_view text) { return text.find("autosave function") != std::string_view::npos; }

GameProfile build(const Release &r) {
    return GameProfile{
        .app_name = "d012_native",
        .project_name = "Dissidia 012 Final Fantasy HD Remastered",
        .env_prefix = "D012",
        .data_organization = "Dissidia012",
        .data_application = "D012",

        .disc_id = r.disc_id,
        .disc_id_display = r.disc_id_display,
        .game_title = "Dissidia 012 Duodecim Final Fantasy",
        .executable_path_on_disc = "PSP_GAME/SYSDIR/EBOOT.BIN",
        .param_sfo_path_on_disc = "PSP_GAME/PARAM.SFO",
        .release_name = r.name,
        .release_version = kReleaseVersion,
        .hud_scaled_by_game = true,  // the game marks its HUD layouts in the display list (d012_vk/d012_hud_layout.cpp)
        // SHA-256 of PSP_GAME/SYSDIR/EBOOT.BIN on the disc, and of its decryption.
        .encrypted_executable_sha256 = "0c0c12c0f46e9cc37adb0a649a761975fab92a20c8d2e9252f514ef29d1ca289",
        .executable_sha256 = "0bc8e779aad2814a3d1bd77346f69ca5e16665845ed053cd0ad44a9cbfaefe6d",
        // The word at 0xD0 of EBOOT.BIN and the key that tag selects, the same public value pspdecrypt and the
        // PSP emulators carry; with it the installer decrypts the disc's EBOOT.BIN itself.
        .decryption_tag = 0xD91613F0u,
        .decryption_key = {0xEB, 0xFF, 0x40, 0xD8, 0xB4, 0x1A, 0xE1, 0x66,
                           0x91, 0x3B, 0x8F, 0x64, 0xB6, 0xFC, 0xB7, 0x12},
        .variants = kVariants,
        .redirect_game_files = &::d012_emendatus::redirect_game_files,

        .load_base = 0x08804000u,
        .guest_ram_bytes = 64u * 1024u * 1024u,  // the PSP slim's
        .boot_path = "disc0:/PSP_GAME/SYSDIR/EBOOT.BIN",
        .overlay_slots = kOverlaySlots,

        .save_game_name = r.disc_id,
        .save_folders = r.saves,

        // One code for both releases: online play ignores the disc, so the USA and EUR discs meet.
        .adhoc_product_code = "ULES01505",
        // The Emendatus Mod changes the game's data, so it only plays the Emendatus Mod and the stock game (with or without the
        // memory expansion, which changes no gameplay) only plays the stock game: the product code carries the mark.
        .adhoc_edition_mark = 'E',
        .adhoc_edition_active = &::d012_emendatus_on,
        .adhoc_auth_key = D012_RELAY_KEY,
        .touch_combos = kTouchCombos,
        .touch_combo_count = std::size(kTouchCombos),
        .save_loaded = &d012_repair_save,
        .edition_name = "Emendatus",
        .switch_edition = &::d012_switch_edition,
        .mods_folder = &::d012_mods_folder,
        .android_shared_data_folder = "Dissidia012HD",
        .adhoc_relay_server = "104.238.174.65",  // plain TCP 27312/27313 (Vultr, London)
        .cheats_download_base = "https://raw.githubusercontent.com/LiinkPK/Dissidia012-PC/main/release/data/ms0/PSP/CHEATS/",

        // The buttons a PSP lacks, which the battle shortcuts use (L3 EX, L2 dodge, R2 dash, R3 recentres the camera;
        // d012_camera.cpp).
        .extra_buttons = input::kExtraL2 | input::kExtraR2 | input::kExtraL3 | input::kExtraR3,

        .register_extra_hle = &register_hle,
        .patch_loaded_image = &::d012_emendatus::patch_loaded_image,

        .skip_message_dialog = skip_autosave_notice,
        .window_title = "Dissidia 012 Final Fantasy HD Remastered",
        .window_icon_png = d012_icon::kPng,
        .window_icon_png_size = d012_icon::kPngSize,

        // Battles pace their 30 Hz logic on two vblanks (main:0x08883F9C, frame timer interval 2).
        .interpolation_thresholds = &kInterpolationThresholds,
        .frame_vblanks = 2u,

        // English, confirm on cross.
        .system_language = 1u,
        .confirm_button = 1u,
    };
}

} // namespace

const GameProfile &game() {
    static const GameProfile eur =
        build({"ULES01505", "ULES-01505", "the European release (ULES01505)", kSaveFolders});
    static const GameProfile usa =
        build({"ULUS10566", "ULUS-10566", "the North American release (ULUS10566)", kUsaSaveFolders});
    return active_disc_id() == usa.disc_id ? usa : eur;
}

} // namespace portablekit

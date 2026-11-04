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

#include "gpu/frame_interpolation.hpp"

#include "d012_hle.hpp"
#include "d012_icon.hpp"

#include <span>
#include <string_view>

namespace portablekit {
namespace {

// The version of this release, as its GitHub tag. Change it here for every release: the in-game update check
// compares it with the newest release on https://github.com/LiinkPK/Dissidia012-PC/releases.
constexpr const char *kReleaseVersion = "v1.0.1";

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

        .load_base = 0x08804000u,
        .guest_ram_bytes = 64u * 1024u * 1024u,  // the PSP slim's
        .boot_path = "disc0:/PSP_GAME/SYSDIR/EBOOT.BIN",
        .overlay_slots = kOverlaySlots,

        .save_game_name = r.disc_id,
        .save_folders = r.saves,

        .adhoc_product_code = r.disc_id,

        // L2 and R2, which a PSP lacks, switch the loading screen's D-pad between its menu and the battle
        // music (d012_bgm_playlist.cpp); R3 recentres the battle camera (d012_camera.cpp).
        .extra_buttons = input::kExtraL2 | input::kExtraR2 | input::kExtraR3,

        .register_extra_hle = &d012::register_extra_hle,
        .patch_loaded_image = &d012::patch_loaded_image,

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

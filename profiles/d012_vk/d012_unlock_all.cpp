// "Unlock all" on the System page, under the save rows: copies everything that unlocks from a 100% save into one of the player's own
// saves: characters and their levels, equipment, abilities, items, summons, story progress, the gallery. What is the player's own
// stays: the friend cards (your card, its name and message, and the cards you received), the save's header and its end. Playtime
// is replaced with the rest of the first section.
//
// The 100% save is built into the program (d012_unlock_template.inc, made by tools/save/make_unlock_template.py): the save image's
// sections but the friend cards. The image is version 10, 0x3ECC8 bytes, a 0x50-byte header and 14 sections whose sizes are in the
// header; the player's image must have the same sizes, or nothing is written.
//
// The save is read and written through the host's save-data code (decrypted with the game's key, PARAM.SFO signed again), so the
// folder stays a save the game accepts. There is no backup: the page says so and asks first.
#include "profile.hpp"

#if defined(PORTABLEKIT_HAS_RENDERER)
#include "save_data/save_transfer.hpp"
#include "save_data/savedata_store.hpp"
#include "ui/save_screen.hpp"
#include "ui/ui.hpp"
#include "ui/widgets.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace {

namespace fs = std::filesystem;
namespace sd = portablekit::savedata;
namespace ui = portablekit::ui;

#include "d012_unlock_template.inc"

constexpr std::size_t kHeader = 0x50u;
constexpr std::size_t kSectionCount = 14u;
constexpr std::size_t kImageSize = 0x3ECC8u;
constexpr std::size_t kFriendCards = 5u;  // index of the 6th section, the one that stays the player's

std::uint32_t word(const std::vector<std::uint8_t> &bytes, std::size_t at) {
    return static_cast<std::uint32_t>(bytes[at]) | static_cast<std::uint32_t>(bytes[at + 1]) << 8 |
           static_cast<std::uint32_t>(bytes[at + 2]) << 16 | static_cast<std::uint32_t>(bytes[at + 3]) << 24;
}

// Puts the template's sections into the player's save image. False, with `why`, when the image is not one this can change.
bool unlock_image(std::vector<std::uint8_t> &image, std::string &why) {
    if (image.size() != kImageSize || word(image, 0) != 10u || word(image, 4) != kImageSize) {
        why = "This is not a save the game can read (the wrong version or size).";
        return false;
    }
    std::size_t at = kHeader;
    std::size_t taken = 0;
    for (std::size_t i = 0; i < kSectionCount; ++i) {
        const std::size_t size = word(image, 8u + 4u * i);
        if (size != kTemplateSections[i]) {
            why = "This save is laid out differently from the one the unlock data comes from.";
            return false;
        }
        at += size;
        if (i != kFriendCards) taken += size;
    }
    if (taken != sizeof(kTemplate) || at > image.size()) {
        why = "The unlock data does not fit this save.";
        return false;
    }
    at = kHeader;
    std::size_t from = 0;
    for (std::size_t i = 0; i < kSectionCount; ++i) {
        const std::size_t size = kTemplateSections[i];
        if (i != kFriendCards) {
            std::memcpy(image.data() + at, kTemplate + from, size);
            from += size;
        }
        at += size;
    }
    return true;
}

struct Slot {
    std::string folder;  // "ULES01505GameData01"
    std::string name;    // "GameData01"
};

std::vector<Slot> slots() {
    std::vector<Slot> found;
    const fs::path memory_stick = sd::memory_stick();
    if (memory_stick.empty()) return found;
    const std::string prefix = std::string(sd::game_name()) + "GameData";
    std::error_code ec;
    for (fs::directory_iterator it(sd::savedata_root(memory_stick), ec); !ec && it != fs::directory_iterator(); it.increment(ec)) {
        const std::string folder = it->path().filename().string();
        if (folder.rfind(prefix, 0) != 0 || !fs::is_regular_file(it->path() / "DISSIDIA.BIN", ec)) continue;
        found.push_back({folder, folder.substr(std::string(sd::game_name()).size())});
    }
    std::sort(found.begin(), found.end(), [](const Slot &a, const Slot &b) { return a.folder < b.folder; });
    return found;
}

std::string slot_label(const Slot &slot) {
    // GameData00 is the first of the game's three slots.
    const std::string digits = slot.name.substr(std::string("GameData").size());
    return "Game data " + std::to_string(std::atoi(digits.c_str()) + 1) + " (" + slot.name + ")";
}

bool unlock_slot(const Slot &slot, std::string &message) {
    const std::optional<sd::Block> key = sd::game_key();
    if (!key) {
        message = "The game has not told this program its save key yet. Go back to the title screen and try again.";
        return false;
    }
    sd::SaveFiles files;
    files.game_name = std::string(sd::game_name());
    files.save_name = slot.name;
    files.file_name = "DISSIDIA.BIN";
    files.key = key;
    sd::LoadResult loaded = sd::load_save(sd::memory_stick(), files);
    if (loaded.status != sd::LoadStatus::Ok) {
        message = "This save could not be read" + (loaded.reason.empty() ? std::string(".") : ": " + loaded.reason);
        return false;
    }
    if (!unlock_image(loaded.contents.data, message)) return false;
    std::string error;
    if (!sd::write_save(sd::memory_stick(), files, loaded.contents, error)) {
        message = "The save could not be written: " + error;
        return false;
    }
    std::cout << "[unlock] everything unlocked in " << slot.folder << " (the friend cards were kept)\n";
    message = "Everything is unlocked in " + slot_label(slot) + ". Your friend cards were kept.";
    return true;
}

enum class Stage { Idle, Confirm, Done };
Stage g_stage = Stage::Idle;
Slot g_slot;
std::string g_message;
bool g_ok = false;

void system_rows() {
    const bool available = !sd::memory_stick().empty() && sd::game_key().has_value();
    ui::section("Unlock all");
    if (g_stage == Stage::Idle) {
        const std::vector<Slot> found = slots();
        if (found.empty()) {
            ui::info_row("Unlock all", "No saves yet: play and save once first.");
            return;
        }
        ui::paragraph("Unlocks every character, costume, item, ability and summon, and all the story progress, in one of your saves. "
                      "Your friend cards stay as they are.",
                      ui::colors::kTextDim);
        for (const Slot &slot : found) {
            const std::string label = "Unlock all in " + slot_label(slot) + "...###unlock" + slot.folder;
            if (ui::button_row(label.c_str(),
                               {!available, {},
                                available ? "Asks first. It cannot be undone."
                                          : "Available once the game has loaded its save: go back to the title screen."})) {
                g_slot = slot;
                g_stage = Stage::Confirm;
            }
        }
    } else if (g_stage == Stage::Confirm) {
        ui::paragraph("This replaces the characters, items, abilities, summons and story progress in " + slot_label(g_slot) +
                          " with those of a 100% save. It cannot be undone, and there is no backup. Your friend cards are kept.",
                      ui::colors::kDanger);
        if (ui::button_row("Yes, unlock everything###unlockyes", {false, {}, "Replaces the save's progress now."}, ui::colors::kDanger)) {
            g_ok = unlock_slot(g_slot, g_message);
            g_stage = Stage::Done;
        }
        if (ui::button_row("Cancel###unlockno", {false, {}, "Changes nothing."})) g_stage = Stage::Idle;
    } else {
        ui::paragraph(g_message, g_ok ? ui::colors::kGood : ui::colors::kDanger);
        if (g_ok) {
            ui::paragraph("The game reads its saves at the title screen. Restart now to load it; progress since your last save is "
                          "lost. If you keep playing instead, do not save before you restart: saving would replace the unlocked "
                          "save with the game you are playing.");
            if (ui::button_row("Restart now###unlockrestart", {false, {}, "Closes the game and starts it again at the title screen."},
                               ui::colors::kAccentBright)) {
                ui::request_restart();
                g_stage = Stage::Idle;
            }
        }
        if (ui::button_row(g_ok ? "Later###unlockdone" : "Done###unlockdone", {false, {}, "Back to the page."})) g_stage = Stage::Idle;
    }
}

struct Install {
    Install() { ui::add_system_rows(&system_rows); }
} install;

} // namespace
#endif

// "Unlock all" on the System page, under the save rows: makes a copy of one of the player's saves, into the slot they choose (one of the
// game's 20, GameData00 to GameData19, empty or used), with everything that unlocks taken from a 100% save: characters and their
// levels, equipment, abilities, items, summons, story progress, the gallery. The save that is copied is only read. What is the player's
// own stays in the copy: the friend cards (your card, its name and message, and the cards you received), the save's header and its end.
// Playtime comes from the 100% save with the rest of the first section.
//
// The 100% save is built into the program (d012_unlock_template.inc, made by tools/save/make_unlock_template.py): the save image's
// sections but the friend cards. The image is version 10, 0x3ECC8 bytes, a 0x50-byte header and 14 sections whose sizes are in the
// header; the player's image must have the same sizes, or nothing is written.
//
// The save is read and written through the host's save-data code (decrypted with the game's key, PARAM.SFO signed again), so the
// folder stays a save the game accepts. A used slot the copy replaces is not backed up: the page says so and asks first.
#include "profile.hpp"

#if defined(PORTABLEKIT_HAS_RENDERER)
#include "save_data/save_transfer.hpp"
#include "save_data/savedata_store.hpp"
#include "ui/save_screen.hpp"
#include "ui/ui.hpp"
#include "ui/widgets.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
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
    bool used{};         // there is a save in it
};

constexpr int kSlots = 20;  // the game lists GameData00 to GameData19

std::string slot_name(int index) {
    char text[16];
    std::snprintf(text, sizeof(text), "GameData%02d", index);
    return text;
}

// The game's slots as they are now: the used ones have a DISSIDIA.BIN.
std::vector<Slot> slots() {
    std::vector<Slot> found;
    const fs::path memory_stick = sd::memory_stick();
    if (memory_stick.empty()) return found;
    const std::string game = std::string(sd::game_name());
    for (int i = 0; i < kSlots; ++i) {
        Slot slot;
        slot.name = slot_name(i);
        slot.folder = game + slot.name;
        std::error_code ec;
        slot.used = fs::is_regular_file(sd::savedata_root(memory_stick) / slot.folder / "DISSIDIA.BIN", ec);
        found.push_back(slot);
    }
    return found;
}

std::string slot_label(const Slot &slot) {
    const std::string digits = slot.name.substr(std::string("GameData").size());
    return "Save " + std::to_string(std::atoi(digits.c_str()) + 1) + " (" + slot.name + ")";
}

// Makes `target` a copy of `source` with everything unlocked. `source` is only read.
bool unlock_copy(const Slot &source, const Slot &target, std::string &message) {
    const std::optional<sd::Block> key = sd::game_key();
    if (!key) {
        message = "The game has not told this program its save key yet. Go back to the title screen and try again.";
        return false;
    }
    sd::SaveFiles from;
    from.game_name = std::string(sd::game_name());
    from.save_name = source.name;
    from.file_name = "DISSIDIA.BIN";
    from.key = key;
    sd::LoadResult loaded = sd::load_save(sd::memory_stick(), from);
    if (loaded.status != sd::LoadStatus::Ok) {
        message = "The save could not be read" + (loaded.reason.empty() ? std::string(".") : ": " + loaded.reason);
        return false;
    }
    if (!unlock_image(loaded.contents.data, message)) return false;
    sd::SaveFiles to = from;
    to.save_name = target.name;
    std::string error;
    if (!sd::write_save(sd::memory_stick(), to, loaded.contents, error)) {
        message = "The save could not be written: " + error;
        return false;
    }
    std::cout << "[unlock] " << source.folder << " copied to " << target.folder << " with everything unlocked (friend cards kept)\n";
    message = slot_label(target) + " is now a copy of " + slot_label(source) + " with everything unlocked. " +
              slot_label(source) + " was not changed.";
    return true;
}

enum class Stage { Idle, PickSource, PickTarget, Confirm, Done };
Stage g_stage = Stage::Idle;
Slot g_source, g_target;
std::string g_message;
bool g_ok = false;

void system_rows() {
    const bool available = !sd::memory_stick().empty() && sd::game_key().has_value();
    ui::section("Unlock all");
    const std::vector<Slot> all = slots();
    switch (g_stage) {
    case Stage::Idle: {
        const bool any = std::any_of(all.begin(), all.end(), [](const Slot &s) { return s.used; });
        ui::paragraph("Makes a copy of one of your saves with every character, costume, item, ability and summon unlocked and all the "
                      "story progress done. The save you copy is not changed, and your friend cards come with it.",
                      ui::colors::kTextDim);
        if (ui::button_row("Unlock all...###unlockstart",
                           {!available || !any, {},
                            !available ? "Available once the game has loaded its save: go back to the title screen."
                            : !any     ? "Play and save once first."
                                       : "Choose the save to copy, then where the copy goes."}))
            g_stage = Stage::PickSource;
        break;
    }
    case Stage::PickSource:
        ui::paragraph("Which save do you want to copy?");
        for (const Slot &slot : all) {
            if (!slot.used) continue;
            if (ui::button_row((slot_label(slot) + "###unlocksrc" + slot.name).c_str(), {false, {}, "Copy this save."})) {
                g_source = slot;
                g_stage = Stage::PickTarget;
            }
        }
        if (ui::button_row("Cancel###unlockcancel1", {false, {}, "Changes nothing."})) g_stage = Stage::Idle;
        break;
    case Stage::PickTarget:
        ui::paragraph("Copy " + slot_label(g_source) + " with everything unlocked to which save?");
        for (const Slot &slot : all) {
            const bool same = slot.name == g_source.name;
            const std::string label = slot_label(slot) + (same ? "   (the one you are copying)" : slot.used ? "   in use" : "   empty");
            if (ui::button_row((label + "###unlocktgt" + slot.name).c_str(),
                               {same, {}, slot.used ? "This save is replaced by the copy." : "A new save is made here."},
                               slot.used && !same ? ui::colors::kAccentBright : ui::colors::kText)) {
                g_target = slot;
                g_stage = Stage::Confirm;
            }
        }
        if (ui::button_row("Cancel###unlockcancel2", {false, {}, "Changes nothing."})) g_stage = Stage::Idle;
        break;
    case Stage::Confirm:
        if (g_target.used) {
            ui::paragraph(slot_label(g_target) + " already has a save. It is replaced by a copy of " + slot_label(g_source) +
                              " with everything unlocked. This cannot be undone, and there is no backup of the save it replaces.",
                          ui::colors::kDanger);
        } else {
            ui::paragraph("A new save is made in " + slot_label(g_target) + ": a copy of " + slot_label(g_source) +
                              " with everything unlocked. " + slot_label(g_source) + " is not changed. Unlocking cannot be undone "
                              "in the new save.",
                          ui::colors::kText);
        }
        if (ui::button_row("Yes, make the copy###unlockyes", {false, {}, "Writes the save now."},
                           g_target.used ? ui::colors::kDanger : ui::colors::kAccentBright)) {
            g_ok = unlock_copy(g_source, g_target, g_message);
            g_stage = Stage::Done;
        }
        if (ui::button_row("Cancel###unlockcancel3", {false, {}, "Changes nothing."})) g_stage = Stage::Idle;
        break;
    case Stage::Done:
        ui::paragraph(g_message, g_ok ? ui::colors::kGood : ui::colors::kDanger);
        if (g_ok) {
            ui::paragraph("The game reads a save when you load it. If you replaced the save you are playing, restart now: saving "
                          "before that would put your current game back over the copy.");
            if (ui::button_row("Restart now###unlockrestart", {false, {}, "Closes the game and starts it again at the title screen."}))
                ui::request_restart();
        }
        if (ui::button_row("Done###unlockdone", {false, {}, "Back to the page."})) g_stage = Stage::Idle;
        break;
    }
}

struct Install {
    Install() { ui::add_system_rows(&system_rows); }
} install;

} // namespace
#endif

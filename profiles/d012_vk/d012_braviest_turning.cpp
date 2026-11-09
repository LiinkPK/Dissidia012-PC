// The Braviest Turning mod, built in as a switch (tools/mods/braviest_turning/).
//
// The mod changes the game's executable: 62 words of its code and data, and a 16 KiB segment of added code (a code cave the
// patched words jump to). The mod's code is translated to C++ like the game's: the generated units hold, where the mod
// differs from the game, `if (g_d012_mod_bt) { the mod } else { the game }`, and the cave is two more units. This file is
// the rest: the switch, the mod's words and cave bytes put into the game's memory when it is on, and the menu row.
//
// The switch is read once at start-up, so turning it on or off takes effect at the next start: settings.ini's
// game.braviest_turning (the menu's Mods page writes it), or D012_BRAVIEST_TURNING=0/1 for a run.
#include "../../third_party/dissidia012-pc/port/host/d012_hle.hpp"

#include "install/installer.hpp"
#include "install/user_data.hpp"
#include "psprecomp/elf32.hpp"
#include "psprecomp/runtime.hpp"
#if defined(PORTABLEKIT_HAS_RENDERER)
#include "ui/ui.hpp"
#include "ui/widgets.hpp"
#include <imgui.h>
#if __has_include(<SDL3/SDL.h>)
#include <SDL3/SDL.h>
#endif
#endif

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>

namespace psprecomp {
bool g_d012_mod_bt = false;  // declared in the generated recomp_units.hpp
}

namespace {

#include "d012_braviest_turning_data.inc"

constexpr const char *kKey = "game.braviest_turning";

// DISABLED: turning the mod on crashes the game, so it is always off, whatever settings.ini or D012_BRAVIEST_TURNING say.
// Remove the next line (and re-enable the menu row at the bottom of this file) once the crash is fixed.
bool read_setting() {
    return false;
    if (const char *text = std::getenv("D012_BRAVIEST_TURNING"); text != nullptr && *text != '\0') return std::strcmp(text, "0") != 0;
    try {
        const std::filesystem::path dir = portablekit::install::user_data_directory();
        const portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        if (const auto found = entries.find(kKey); found != entries.end()) return found->second == "1";
    } catch (const std::exception &e) {
        std::cerr << "[mod] settings.ini not read for " << kKey << ": " << e.what() << "\n";
    }
    return false;
}

#if defined(PORTABLEKIT_HAS_RENDERER)
[[maybe_unused]] void save_setting(bool on) {
    try {
        const std::filesystem::path dir = portablekit::install::user_data_directory();
        portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        entries[kKey] = on ? "1" : "0";
        portablekit::install::write_settings_file(dir, entries);
    } catch (const std::exception &e) {
        std::cerr << "[mod] settings.ini not written for " << kKey << ": " << e.what() << '\n';
    }
}

// Closes the game and starts it again (the menu's own way of restarting after a save import: the restart happens as the
// process exits).
[[maybe_unused]] void restart_game() {
    portablekit::install::request_restart_on_exit();
#if __has_include(<SDL3/SDL.h>)
    SDL_Event quit{};
    quit.type = SDL_EVENT_QUIT;
    SDL_PushEvent(&quit);
#endif
}

[[maybe_unused]] void mod_rows() {
    namespace ui = portablekit::ui;
    ui::section("Braviest Turning");
    ui::RowOptions options;
    options.description = "Changes the game's rules (the Braviest Turning mod). The game restarts to apply it.";
    static bool wanted = read_setting();   // the setting as saved
    static bool target = false;            // what the open question would set
    static bool asking = false;
    if (const char *text = std::getenv("D012_BRAVIEST_TURNING"); text != nullptr && *text != '\0') {
        options.disabled = true;
        options.note = "Set by D012_BRAVIEST_TURNING";
    } else if (wanted != psprecomp::g_d012_mod_bt) {
        options.note = "restart to apply";
    }
    if (ui::toggle_row("Braviest Turning", wanted, options)) {
        target = !wanted;
        asking = true;
    }
    if (asking && !ImGui::IsPopupOpen("##bt_restart")) ImGui::OpenPopup("##bt_restart");
    const ImGuiIO &io = ImGui::GetIO();
    const float font = ImGui::GetFontSize();
    ImGui::SetNextWindowPos({io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f}, ImGuiCond_Always, {0.5f, 0.5f});
    ImGui::SetNextWindowSize({std::min(io.DisplaySize.x * 0.9f, font * 26.0f), 0.0f}, ImGuiCond_Always);
    if (ImGui::BeginPopupModal("##bt_restart", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings)) {
        if (!asking) {
            ImGui::CloseCurrentPopup();
        } else {
            ui::heading(target ? "Turn Braviest Turning on?" : "Turn Braviest Turning off?");
            ui::paragraph("The game has to restart for this to take effect. Progress since your last save is lost.",
                          ui::colors::kTextDim);
            ImGui::Dummy({0.0f, font * 0.6f});
            const float gap = font * 0.6f;
            const float width = (ImGui::GetContentRegionAvail().x - gap) * 0.5f;
            if (ui::big_button("Restart now", width, true)) {
                wanted = target;
                save_setting(wanted);
                asking = false;
                restart_game();
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine(0.0f, gap);
            if (ui::big_button("Cancel", width)) {
                asking = false;  // nothing is changed
                ImGui::CloseCurrentPopup();
            }
            ImGui::SetItemDefaultFocus();
        }
        ImGui::EndPopup();
    }
}
// The menu row is off with the mod: it crashes the game, and nobody should be able to switch it on by mistake.
// struct Install {
//     Install() { portablekit::ui::add_mod_rows(&mod_rows); }
// } install;
#endif

} // namespace

namespace d012_braviest_turning {

// The profile's patch_loaded_image: the port's own (nothing yet), then the mod's memory, when it is on.
void patch_loaded_image(psprecomp::Runtime &runtime, const psprecomp::Elf32Image &elf) {
    d012::patch_loaded_image(runtime, elf);
    psprecomp::g_d012_mod_bt = read_setting();
    if (!psprecomp::g_d012_mod_bt) return;
    psprecomp::GuestMemory &memory = runtime.memory();
    for (const auto &patch : kModWords) memory.store32(patch.address, patch.word);
    for (const auto &segment : kModSegments)
        for (std::uint32_t i = 0; i < segment.size; ++i) memory.store8(segment.address + i, segment.bytes[i]);
    std::cout << "[mod] Braviest Turning is on (" << sizeof kModWords / sizeof kModWords[0] << " words patched, "
              << "code cave at 0x" << std::hex << kModSegments[0].address << std::dec << ")\n";
}

} // namespace d012_braviest_turning

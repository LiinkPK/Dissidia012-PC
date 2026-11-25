// The portable layout: a folder holding the program with the game and its data
// beside it, as tools/port/package_deck.py assembles it for the Steam Deck.
//
//   <folder>/D012Native.exe, its DLLs, overlays/
//   <folder>/game/EBOOT.ELF, <folder>/game/disc.iso
//   <folder>/data/           settings.ini, pipeline cache, mods/, ms0/
//
// When <folder>/game/EBOOT.ELF exists next to the running executable, each of
// these that the environment does not already set is set, before main() runs:
//
//   D012_GAME_DIR            <folder>/game
//   D012_DATA_DIR            <folder>/data
//   D012_MEMORY_STICK_DIR    <data dir>/ms0 (the data dir in effect)
//   PSPRECOMP_NO_INTERPRETER 1, unless D012_INTERPRETER is set: a packaged
//                            build runs its recompiled code only, as
//                            tools/port/play_d012.ps1 does
//   D012_OVERLAY_DIR         <folder>/game-code/overlays, in the installer
//                            build only (host/d012_game_code.cpp)
//
// The installer build always uses the layout, game/ or not: what the
// installer's `--install <iso>` makes (EBOOT.ELF, and settings.ini naming the
// player's disc image wherever it is) goes in data/ beside the saves, as
// PortableKit lays out a data directory of its own, so D012_GAME_DIR is set
// only when game/EBOOT.ELF is there. Started from a shortcut it has no console
// (it is built as a windowed program), so its output goes to
// <data>/logs/D012Native.log, the previous run's to D012Native-previous.log.
//
// A variable already set always wins, so run_d012.py, play_d012.ps1 and the
// test tools, which set all of them, behave as before. A build directory's
// bin/ has no game/ beside it, so a developer build is unchanged too. A build
// configured with PORTABLEKIT_RELEASE=ON (D012_RELEASE_BUILD) turns the
// interpreter off by default wherever it runs.
//
// It works through the environment because PortableKit reads these paths
// there (host/main.cpp, host/install/user_data.cpp) and has no hook that runs
// before it locates the game; nothing here is specific to the framework's
// internals.
//
// MIT licence; see port/README.md.

#include "app_paths.hpp"

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <system_error>
#include <vector>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#if defined(D012_INSTALLER_BUILD)
namespace d012::game_code {
std::filesystem::path directory();  // host/d012_game_code.cpp
}
#endif

namespace d012::portable {
namespace {

// The profile's prefix (d012_profile.cpp, env_prefix). Spelled out because
// this runs during static initialisation, before anything may ask the profile.
constexpr const char *kGameDir = "D012_GAME_DIR";
constexpr const char *kDataDir = "D012_DATA_DIR";
constexpr const char *kMemoryStickDir = "D012_MEMORY_STICK_DIR";
constexpr const char *kInterpreter = "D012_INTERPRETER";
constexpr const char *kNoInterpreter = "PSPRECOMP_NO_INTERPRETER";
constexpr const char *kOverlayDir = "D012_OVERLAY_DIR";

bool is_set(const char *name) {
    const char *value = std::getenv(name);
    return value != nullptr && *value != '\0';
}

// PortableKit reads these values as UTF-8 (install::path_from_utf8).
std::string utf8(const std::filesystem::path &path) {
    const std::u8string text = path.u8string();
    return {text.begin(), text.end()};
}

void set(const char *name, const std::string &value) {
#if defined(_WIN32)
    _putenv_s(name, value.c_str());
#else
    setenv(name, value.c_str(), 0);
#endif
}

#if defined(__linux__) && !defined(__ANDROID__)
// Linux only (Windows and Android are left as they are). Up to v1.1.0 a program folder without game/EBOOT.ELF (everyone who set the game up
// on the first-run screen) kept its data in the user's data folder (~/.local/share/Dissidia012/D012); from v1.1.1 it is always <folder>/data, and
// nothing moved what was already there: the game asked for the disc image again and the saves seemed gone. This puts that data where the
// game now looks. Nothing is ever deleted or overwritten.
std::filesystem::path legacy_data_folder() {
    const char *xdg = std::getenv("XDG_DATA_HOME");
    const char *home = std::getenv("HOME");
    if (xdg != nullptr && *xdg != '\0') return std::filesystem::path(xdg) / "Dissidia012" / "D012";
    return home != nullptr && *home != '\0' ? std::filesystem::path(home) / ".local" / "share" / "Dissidia012" / "D012"
                                            : std::filesystem::path();
}

// Moves `from` to `to`: by rename when it can (the same disk), else by copying and removing. A folder is merged into the one already
// there, entry by entry; a file that is already there stays as it is and the old one stays where it was (counted in `kept`).
void move_into(const std::filesystem::path &from, const std::filesystem::path &to, unsigned &moved, unsigned &kept) {
    std::error_code ec;
    if (std::filesystem::is_directory(from, ec)) {
        if (std::filesystem::exists(to, ec) && !std::filesystem::is_directory(to, ec)) {
            ++kept;
            return;
        }
        std::filesystem::create_directories(to, ec);
        std::vector<std::filesystem::path> children;
        for (const auto &entry : std::filesystem::directory_iterator(from, ec)) children.push_back(entry.path());
        for (const std::filesystem::path &child : children) move_into(child, to / child.filename(), moved, kept);
        std::filesystem::remove(from, ec);  // only when it is empty now
        return;
    }
    if (std::filesystem::exists(to, ec)) {
        ++kept;
        return;
    }
    std::filesystem::rename(from, to, ec);
    if (ec) {  // another disk: copy, then remove
        ec.clear();
        std::filesystem::copy_file(from, to, std::filesystem::copy_options::none, ec);
        if (ec) {
            std::filesystem::remove(to, ec);
            ++kept;
            return;
        }
        std::filesystem::remove(from, ec);
    }
    ++moved;
}

void migrate_legacy_data(const std::filesystem::path &data) {
    std::error_code ec;
    const std::filesystem::path legacy = legacy_data_folder();
    if (legacy.empty() || !std::filesystem::is_directory(legacy, ec)) return;
    // Once only (MOVED.txt says it was done), and only for a folder that holds a game's data: the set-up there, settings or saves.
    if (std::filesystem::exists(legacy / "MOVED.txt", ec)) return;
    if (!std::filesystem::exists(legacy / "EBOOT.ELF", ec) && !std::filesystem::exists(legacy / "settings.ini", ec) &&
        !std::filesystem::exists(legacy / "ms0", ec))
        return;
    std::cout << "[portable] moving the data of an older version from " << utf8(legacy) << " to " << utf8(data) << std::endl;
    // Not set up here yet (the set-up leaves EBOOT.ELF in the data folder): a settings.ini made by a first start here holds only
    // defaults, so the old one (the disc image, the controls) replaces it, and the new one is kept beside it. Once the player has set the
    // game up here again, the settings of this folder stay.
    const bool set_up_here = std::filesystem::exists(data / "EBOOT.ELF", ec);
    if (!set_up_here && std::filesystem::exists(legacy / "settings.ini", ec) && std::filesystem::exists(data / "settings.ini", ec))
        std::filesystem::rename(data / "settings.ini", data / "settings.ini.before-move", ec);
    unsigned moved = 0, kept = 0;
    std::vector<std::filesystem::path> entries;
    for (const auto &entry : std::filesystem::directory_iterator(legacy, ec)) entries.push_back(entry.path());
    for (const std::filesystem::path &entry : entries) move_into(entry, data / entry.filename(), moved, kept);
    std::cout << "[portable] " << moved << " files moved, " << kept << " left where they were (a file of that name was already there)"
              << std::endl;
    std::ofstream note(legacy / "MOVED.txt");
    note << "The data of this folder was moved to " << utf8(data) << ".\n"
         << "Files that were already there were not replaced; any still in this folder are the older copies.\n";
}
#endif

#if defined(D012_INSTALLER_BUILD) && defined(_WIN32)
// A windowed program started from a shortcut has no standard output: keep
// what it prints, for the player's bug reports. Output a parent redirected
// (the installer, the test tools) is left where it goes.
void log_to_file_without_console(const std::filesystem::path &logs) {
    const HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    if (out != nullptr && out != INVALID_HANDLE_VALUE) return;
    std::error_code ec;
    std::filesystem::create_directories(logs, ec);
    const std::filesystem::path log = logs / "D012Native.log";
    std::filesystem::rename(log, logs / "D012Native-previous.log", ec);
    if (std::freopen(log.string().c_str(), "w", stdout) != nullptr) std::setvbuf(stdout, nullptr, _IOLBF, 4096);
    std::freopen(log.string().c_str(), "a", stderr);
}
#endif

struct PortableLayout {
    PortableLayout() {
        try {
            apply();
        } catch (const std::exception &e) {
            std::cerr << "[portable] " << e.what() << "\n";
        }
    }

    static void apply() {
        const std::filesystem::path folder = portablekit::executable_directory();
        std::error_code ec;
        const bool game_folder = !folder.empty() && std::filesystem::is_regular_file(folder / "game" / "EBOOT.ELF", ec);
#if defined(__ANDROID__) || defined(__APPLE__)
        // A phone's or an app bundle's own folder is read-only: its data goes where the platform puts it (user_data.cpp), unless the
        // layout is asked for (the installer build, or a game/ folder beside the program).
#if defined(D012_INSTALLER_BUILD)
        const bool portable = !folder.empty();
#else
        const bool portable = game_folder;
#endif
#else
        // Windows and Linux, always: the data folder is <folder>/data (settings, saves, textures/), never the user's AppData, whether or
        // not the game has been set up from a disc image yet. A clean copy has no game/EBOOT.ELF until the first run.
        const bool portable = !folder.empty();
#endif
#if defined(D012_RELEASE_BUILD)
        const bool no_interpreter = true;
#else
        const bool no_interpreter = portable;
#endif
        if (no_interpreter && !is_set(kNoInterpreter) && !is_set(kInterpreter)) set(kNoInterpreter, "1");
        if (!portable) return;

        if (game_folder && !is_set(kGameDir)) set(kGameDir, utf8(folder / "game"));
        const bool data_folder_is_default = !is_set(kDataDir);
        if (data_folder_is_default) set(kDataDir, utf8(folder / "data"));
        const std::string data = std::getenv(kDataDir);
        std::filesystem::create_directories(std::filesystem::path(std::u8string(data.begin(), data.end())), ec);
#if defined(__linux__) && !defined(__ANDROID__)
        // The player did not choose the data folder (D012_DATA_DIR): put the data of an older version where the game looks now.
        if (data_folder_is_default) migrate_legacy_data(std::filesystem::path(std::u8string(data.begin(), data.end())));
#endif
#if defined(D012_INSTALLER_BUILD) && defined(_WIN32)
        log_to_file_without_console(std::filesystem::path(std::u8string(data.begin(), data.end())) / "logs");
#endif
        if (!is_set(kMemoryStickDir))
            set(kMemoryStickDir, utf8(std::filesystem::path(std::u8string(data.begin(), data.end())) / "ms0"));
#if defined(D012_INSTALLER_BUILD)
        if (!is_set(kOverlayDir)) set(kOverlayDir, utf8(d012::game_code::directory() / "overlays"));
#endif
        const char *game = std::getenv(kGameDir);
        std::cout << "[portable] game " << (game != nullptr ? game : "<data dir>") << ", data " << data << ", memory stick "
                  << std::getenv(kMemoryStickDir) << ", interpreter " << (is_set(kNoInterpreter) ? "off" : "on")
                  << std::endl;
    }
};

const PortableLayout layout;

} // namespace
} // namespace d012::portable

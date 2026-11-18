// DLC read in place, from a folder the player chooses (System > DLC).
//
// The game reads DLC from ms0:/PSP/GAME/ULUS10566/<name hash>.edat (see d012_dlc.cpp in the upstream port's host code). With a
// folder chosen here, a read of one of those paths is served from that folder through the host's file provider: nothing is
// copied into the data folder. The folder is the one that holds the .edat files, or one that holds them in a ULUS10566 folder.
// The choice is kept in settings.ini as game.dlc_folder and takes effect at once.
#include "hle/hle_common.hpp"
#include "install/user_data.hpp"
#include "portablekit/hle_extension.hpp"
#include "profile.hpp"
#if defined(PORTABLEKIT_ANDROID_APP)
#include "platform/android_jni.hpp"
#include <sys/stat.h>
#include <unistd.h>
#endif
#if defined(PORTABLEKIT_HAS_RENDERER)
#include "ui/file_browser.hpp"
#include "ui/save_screen.hpp"
#include "ui/ui.hpp"
#include "ui/widgets.hpp"
#include <imgui.h>
#endif

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <vector>

namespace {

namespace ext = portablekit::hle_extension;
namespace fs = std::filesystem;

constexpr const char *kKey = "game.dlc_folder";
// The game builds its DLC path from the disc id in its executable, which both discs share: it reads ms0:/PSP/GAME/ULUS10566/ on
// the European disc too. A European player's DLC usually sits in a ULES01505 folder, so a chosen folder is also searched there,
// and a read of either guest folder is served. The guest paths are lower case: the game's path is compared without case.
constexpr std::string_view kGuestFolders[] = {"ms0:/psp/game/ulus10566/", "ms0:/psp/game/ules01505/"};
constexpr const char *kDiscFolder = "ULUS10566";  // where the game looks (and the default folder shown)
constexpr const char *kDiscFolders[] = {"ULUS10566", "ULES01505"};  // subfolders of a chosen folder that are searched

std::mutex g_lock;
std::string g_folder;  // the chosen folder, UTF-8; empty: none

void load_setting();

// The data folder is not known at start-up, so the setting is read the first time it is needed.
std::string folder_now() {
    static std::once_flag loaded;
    std::call_once(loaded, load_setting);
    const std::lock_guard<std::mutex> guard(g_lock);
    return g_folder;
}

void load_setting() {
    try {
        const portablekit::install::SettingsEntries entries =
            portablekit::install::read_settings_file(portablekit::install::user_data_directory());
        if (const auto found = entries.find(kKey); found != entries.end()) {
            const std::lock_guard<std::mutex> guard(g_lock);
            g_folder = found->second;
        }
    } catch (const std::exception &e) {
        std::cerr << "[dlc] settings.ini not read for " << kKey << ": " << e.what() << "\n";
    }
}

void save_setting(const std::string &folder) {
    {
        const std::lock_guard<std::mutex> guard(g_lock);
        g_folder = folder;
    }
    try {
        const fs::path dir = portablekit::install::user_data_directory();
        portablekit::install::SettingsEntries entries = portablekit::install::read_settings_file(dir);
        if (folder.empty()) entries.erase(kKey);
        else entries[kKey] = folder;
        portablekit::install::write_settings_file(dir, entries);
    } catch (const std::exception &e) {
        std::cerr << "[dlc] settings.ini not written for " << kKey << ": " << e.what() << "\n";
    }
}

std::string lower(std::string text) {
    for (char &c : text) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return text;
}

// The file in the chosen folder for a name the game asked for, or an empty path.
fs::path find_in_folder(const std::string &folder, const std::string &name) {
    if (folder.empty() || name.empty() || name.find_first_of("/\\:") != std::string::npos || name.find("..") != std::string::npos)
        return {};
    const fs::path base = portablekit::install::path_from_utf8(folder);
    std::error_code ec;
    if (fs::is_regular_file(base / name, ec)) return base / name;
    for (const char *disc : kDiscFolders)
        if (fs::is_regular_file(base / disc / name, ec)) return base / disc / name;
    return {};
}

#if defined(PORTABLEKIT_ANDROID_APP)
// On Android the chosen folder is a document (content://...) from the system's folder picker, not a path: its files are found by
// listing it and read through file descriptors the activity opens.
bool is_document(const std::string &folder) { return folder.rfind("content://", 0) == 0; }

std::string document_in(const std::string &folder_uri, const std::string &name) {
    const auto entries = portablekit::android::list_folder(folder_uri);
    if (!entries) return {};
    for (const auto &entry : *entries)
        if (!entry.directory && lower(entry.name) == lower(name)) return entry.uri;
    return {};
}

// The document for a name the game asked for in the chosen folder, or in a disc folder (ULUS10566, ULES01505) inside it.
std::string find_document(const std::string &folder_uri, const std::string &name) {
    if (name.empty() || name.find_first_of("/\:") != std::string::npos || name.find("..") != std::string::npos) return {};
    if (std::string found = document_in(folder_uri, name); !found.empty()) return found;
    const auto entries = portablekit::android::list_folder(folder_uri);
    if (!entries) return {};
    for (const auto &entry : *entries) {
        if (!entry.directory) continue;
        for (const char *disc : kDiscFolders)
            if (lower(entry.name) == lower(disc))
                if (std::string found = document_in(entry.uri, name); !found.empty()) return found;
    }
    return {};
}

int count_documents(const std::string &folder_uri) {
    int files = 0;
    const auto entries = portablekit::android::list_folder(folder_uri);
    if (!entries) return 0;
    for (const auto &entry : *entries) {
        if (entry.directory) {
            for (const char *disc : kDiscFolders)
                if (lower(entry.name) == lower(disc)) files += count_documents(entry.uri);
        } else if (lower(entry.name).size() > 5u && lower(entry.name).compare(lower(entry.name).size() - 5u, 5u, ".edat") == 0) {
            ++files;
        }
    }
    return files;
}
#endif

// A file of the chosen folder, as the game sees it.
class HostFile : public ext::FileFilter {
public:
    explicit HostFile(const fs::path &path) : in_(path, std::ios::binary) {
        std::error_code ec;
        size_ = fs::file_size(path, ec);
        if (ec) size_ = 0;
    }
#if defined(PORTABLEKIT_ANDROID_APP)
    explicit HostFile(int descriptor) : descriptor_(descriptor) {
        struct stat info {};
        size_ = descriptor_ >= 0 && ::fstat(descriptor_, &info) == 0 ? static_cast<std::uint64_t>(info.st_size) : 0u;
    }
    ~HostFile() {
        if (descriptor_ >= 0) ::close(descriptor_);
    }
#endif
    [[nodiscard]] std::uint64_t size() const override { return size_; }
    std::size_t read(std::uint64_t offset, std::uint8_t *destination, std::size_t length) override {
#if defined(PORTABLEKIT_ANDROID_APP)
        if (descriptor_ >= 0) {
            if (offset >= size_) return 0;
            const std::size_t wanted = static_cast<std::size_t>(std::min<std::uint64_t>(length, size_ - offset));
            std::size_t done = 0;
            while (done < wanted) {
                const ssize_t got = ::pread(descriptor_, destination + done, wanted - done, static_cast<off_t>(offset + done));
                if (got <= 0) break;
                done += static_cast<std::size_t>(got);
            }
            return done;
        }
#endif
        if (!in_ || offset >= size_) return 0;
        const std::size_t wanted = static_cast<std::size_t>(std::min<std::uint64_t>(length, size_ - offset));
        in_.clear();
        in_.seekg(static_cast<std::streamoff>(offset));
        in_.read(reinterpret_cast<char *>(destination), static_cast<std::streamsize>(wanted));
        return static_cast<std::size_t>(in_.gcount());
    }

private:
    std::ifstream in_;
    std::uint64_t size_{};
#if defined(PORTABLEKIT_ANDROID_APP)
    int descriptor_{-1};
#endif
};

// Only paths of the game's DLC folder are looked at, and only while a folder is chosen: everything else passes at once.
std::shared_ptr<ext::FileFilter> serve(std::string_view path, std::uint32_t) {
    std::size_t prefix = 0;
    for (const std::string_view guest : kGuestFolders)
        if (path.size() > guest.size() && lower(std::string(path.substr(0, guest.size()))) == guest) prefix = guest.size();
    if (prefix == 0) return nullptr;
    const std::string folder = folder_now();
    if (folder.empty()) return nullptr;
#if defined(PORTABLEKIT_ANDROID_APP)
    if (is_document(folder)) {
        const std::string uri = find_document(folder, std::string(path.substr(prefix)));
        if (uri.empty()) return nullptr;
        const int descriptor = portablekit::android::open_document(uri, "r");
        if (descriptor < 0) return nullptr;
        return std::make_shared<HostFile>(descriptor);
    }
#endif
    const fs::path file = find_in_folder(folder, std::string(path.substr(prefix)));
    if (file.empty()) return nullptr;
    return std::make_shared<HostFile>(file);
}

#if defined(PORTABLEKIT_HAS_RENDERER)
namespace ui = portablekit::ui;

std::unique_ptr<ui::FileBrowser> g_browser;
std::string g_last_folder;
std::string g_found;  // what the last chosen folder holds, for the row

std::string describe(const std::string &folder) {
#if defined(PORTABLEKIT_ANDROID_APP)
    if (is_document(folder)) {
        const int count = count_documents(folder);
        return count == 0 ? "No .edat files found there" : std::to_string(count) + " DLC files";
    }
#endif
    std::error_code ec;
    int files = 0;
    const fs::path base = portablekit::install::path_from_utf8(folder);
    std::vector<fs::path> places{base};
    for (const char *disc : kDiscFolders) places.push_back(base / disc);
    for (const fs::path &where : places) {
        for (const auto &entry : fs::directory_iterator(where, ec)) {
            std::string extension = lower(portablekit::install::path_to_utf8(entry.path().extension()));
            if (entry.is_regular_file(ec) && extension == ".edat") ++files;
        }
        if (files != 0) break;
    }
    return files == 0 ? "No .edat files found there" : std::to_string(files) + " DLC files";
}

int count_edat(const fs::path &dir) {
    std::error_code ec;
    int files = 0;
    for (const auto &entry : fs::directory_iterator(dir, ec))
        if (entry.is_regular_file(ec) && lower(portablekit::install::path_to_utf8(entry.path().extension())) == ".edat") ++files;
    return files;
}

// Where the game's own DLC folder is when none is chosen: the memory stick's PSP/GAME folder of the disc that holds the .edat
// files (ULUS10566, which the game reads, or ULES01505, where a European player's DLC usually is). Empty folders: ULUS10566.
fs::path default_dlc_folder() {
    fs::path game = portablekit::install::user_data_directory() / "ms0" / "PSP" / "GAME";
    if (const char *dir = portablekit::env("MEMORY_STICK_DIR"); dir != nullptr && *dir != '\0')
        game = portablekit::install::path_from_utf8(dir) / "PSP" / "GAME";
    for (const char *disc : kDiscFolders)
        if (count_edat(game / disc) != 0) return game / disc;
    return game / kDiscFolder;
}

void open_browser() {
#if defined(PORTABLEKIT_ANDROID_APP)
    // Android's own folder picker: the app has no access to arbitrary paths, only to what the player picks. The picked folder is
    // kept as a document (its access is made persistent by GameActivity), and the game reads the DLC from it as it asks for it.
    if (const auto tree = portablekit::android::pick_folder()) {
        const std::string root = portablekit::android::tree_root(*tree);
        if (!root.empty()) {
            g_found = describe(root);
            save_setting(root);
            std::cout << "[dlc] DLC is read from the folder chosen in Android's picker (" << g_found << ")\n";
        }
    }
    return;
#endif
    ui::FileBrowser::Options options;
    options.extensions = {};
    options.filter_name = "folders";
    options.listed_name = "folders";
    options.empty_note = "No folders here.";
    options.choose_folder = "Use this folder for DLC";
    fs::path start = portablekit::install::path_from_utf8(g_last_folder.empty() ? folder_now() : g_last_folder);
    std::error_code ec;
    if (start.empty() || !fs::is_directory(start, ec)) start = ui::FileBrowser::home();
    g_browser = std::make_unique<ui::FileBrowser>(start, std::move(options));
}

// The folder chooser, in a window of its own over the page.
void browser_window() {
    if (!g_browser) return;
    if (!ImGui::IsPopupOpen("##dlc_browser")) ImGui::OpenPopup("##dlc_browser");
    const ImGuiIO &io = ImGui::GetIO();
    ImGui::SetNextWindowPos({io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f}, ImGuiCond_Always, {0.5f, 0.5f});
    ImGui::SetNextWindowSize({io.DisplaySize.x * 0.9f, io.DisplaySize.y * 0.85f}, ImGuiCond_Always);
    if (!ImGui::BeginPopupModal("##dlc_browser", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings)) return;
    ui::heading("Choose the DLC folder");
    ui::paragraph("Open the folder that holds your DLC files (the .edat files). The game reads them from there; nothing is copied.",
                  ui::colors::kTextDim);
    // The browser's list takes all the room it is given, so it gets a child window that leaves the Cancel button's room.
    const float button_room = ImGui::GetTextLineHeightWithSpacing() * 3.2f + ImGui::GetStyle().ItemSpacing.y;
    ImGui::BeginChild("##dlc_browser_body", {0.0f, ImGui::GetContentRegionAvail().y - button_room}, ImGuiChildFlags_NavFlattened);
    const ui::FileBrowser::Result result = g_browser->frame(false);
    ImGui::EndChild();
    bool close = result != ui::FileBrowser::Result::Browsing;
    if (result == ui::FileBrowser::Result::Chosen) {
        const std::string chosen = portablekit::install::path_to_utf8(g_browser->chosen());
        g_last_folder = chosen;
        g_found = describe(chosen);
        save_setting(chosen);
        std::cout << "[dlc] DLC is read from " << chosen << " (" << g_found << ")\n";
    } else if (result == ui::FileBrowser::Result::Cancelled) {
        g_last_folder = portablekit::install::path_to_utf8(g_browser->folder());
    }
    if (!close && ui::big_button("Cancel", ImGui::GetContentRegionAvail().x)) close = true;
    if (close) {
        g_browser.reset();
        ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
}

void system_rows() {
    ui::section("DLC");
    if (ui::button_row("Import DLC…",
                       {false, {},
                        "Choose the folder that holds your DLC (the .edat files). The game reads them from there: nothing is "
                        "copied into the data folder."}))
        open_browser();
    const std::string folder = folder_now();
    if (!folder.empty()) {
        if (g_found.empty()) g_found = describe(folder);
#if defined(PORTABLEKIT_ANDROID_APP)
        ui::info_row("DLC used from", is_document(folder) ? std::string("The folder you chose in Android's picker") : folder);
#else
        ui::info_row("DLC used from", folder);
#endif
        ui::info_row("Found", g_found);
        if (ui::button_row("Stop using this DLC folder",
                           {false, {}, "Go back to the DLC in the game's own folder, if any. The chosen folder is left alone."})) {
            save_setting({});
            g_found.clear();
        }
    }
    else {
        const fs::path own = default_dlc_folder();
        ui::info_row("DLC used from", portablekit::install::path_to_utf8(own));
        const int files = count_edat(own);
        ui::info_row("Found", files == 0 ? "No .edat files found there" : std::to_string(files) + " DLC files");
    }
#if defined(PORTABLEKIT_ANDROID_APP)
    if (folder.empty() || !is_document(folder))
#endif
    if (ui::button_row("Open the DLC folder",
                       {false, {}, folder.empty() ? "Show the folder the game reads DLC from." : "Show the chosen DLC folder."}))
        ui::open_folder(folder.empty() ? default_dlc_folder() : portablekit::install::path_from_utf8(folder));
    browser_window();
}
#endif

struct Install {
    Install() {
        portablekit::add_file_provider(&serve);
#if defined(PORTABLEKIT_HAS_RENDERER)
        portablekit::ui::add_system_rows(&system_rows);
#endif
    }
} install;

} // namespace

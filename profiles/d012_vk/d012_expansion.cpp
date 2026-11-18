// Gojo's memory expansion for the stock executable: the heaps of the game's own allocator are made bigger (graphics +3 MB, battle
// file loading +1.5 MB, sound +3.5 MB, effects +3.5 MB), so a mod's larger models, textures and sounds fit. The Emendatus Mod's
// executable already has these edits; this gives the same to the game when that mod is off.
//
// The edits are instructions, and the recompiled code does not read them from memory, so the edited executable has a corpus of its
// own (the profile's "expanded" edition, made by tools/mods/expansion/make_expanded_corpus.py). The port makes the edited
// executable from the disc's own (the stock one, by hash) into the data folder and runs it, only when that corpus is built in:
// without it the stock executable runs as before. D012_EXPANSION=0 turns it off for a run.
#include "app_paths.hpp"
#include "install/user_data.hpp"
#include "profile.hpp"
#include "psprecomp/sha256.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

namespace d012_expansion {
namespace {

#include "d012_expansion_data.inc"

constexpr const char *kStockExecutableSha256 = "0bc8e779aad2814a3d1bd77346f69ca5e16665845ed053cd0ad44a9cbfaefe6d";
constexpr const char *kExpandedExecutableFile = "EBOOT_EXPANDED.ELF";

namespace fs = std::filesystem;

// The corpus of the edition ("expanded") is a library next to the program, in corpora/.
bool corpus_present() {
    std::error_code ec;
    const fs::path folder = portablekit::executable_directory() / "corpora";
    for (fs::directory_iterator it(folder, ec); !ec && it != fs::directory_iterator(); it.increment(ec))
        if (it->path().filename().string().find("expanded") != std::string::npos) return true;
    return false;
}

// The stock executable with the expansion's edits, or empty when `stock` is not the executable they are made for.
std::vector<std::uint8_t> expanded_executable(const fs::path &stock) {
    std::ifstream in(stock, std::ios::binary);
    std::vector<std::uint8_t> bytes((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (bytes.size() != kExpansionStockSize || psprecomp::sha256_bytes(bytes) != kStockExecutableSha256) return {};
    std::size_t at = 0u;
    for (const ExpansionEdit &edit : kExpansionEdits) {
        if (edit.offset + edit.length > bytes.size()) return {};
        std::memcpy(bytes.data() + edit.offset, kExpansionBlob + at, edit.length);
        at += edit.length;
    }
    if (psprecomp::sha256_bytes(bytes) != kExpandedExecutableSha256) return {};
    return bytes;
}

} // namespace

// Replaces `executable`, when it is the disc's stock executable, with the one that has the expansion. False when nothing changed.
bool redirect(fs::path &executable) {
    if (const char *off = std::getenv("D012_EXPANSION"); off != nullptr && std::strcmp(off, "0") == 0) return false;
    try {
        if (psprecomp::sha256_file(executable) != kStockExecutableSha256) return false;
        if (!corpus_present()) {
            std::cerr << "[expansion] The memory expansion is not used: this build has no corpus for it\n";
            return false;
        }
        const fs::path prepared = portablekit::install::user_data_directory() / kExpandedExecutableFile;
        std::error_code ec;
        if (!fs::is_regular_file(prepared, ec) || psprecomp::sha256_file(prepared) != kExpandedExecutableSha256) {
            const std::vector<std::uint8_t> bytes = expanded_executable(executable);
            if (bytes.empty()) {
                std::cerr << "[expansion] The memory expansion is not used: the executable could not be edited\n";
                return false;
            }
            std::ofstream out(prepared, std::ios::binary | std::ios::trunc);
            out.write(reinterpret_cast<const char *>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
            out.close();
            if (!out) throw std::runtime_error("cannot write " + portablekit::install::path_to_utf8(prepared));
        }
        executable = prepared;
        std::cout << "[expansion] The memory expansion is on\n";
        return true;
    } catch (const std::exception &e) {
        std::cerr << "[expansion] The memory expansion is not used: " << e.what() << "\n";
        return false;
    }
}

} // namespace d012_expansion

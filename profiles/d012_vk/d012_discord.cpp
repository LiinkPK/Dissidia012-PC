// Discord Rich Presence for the PC port. Talks to the Discord app over its local pipe (no SDK, no network): a handshake with
// the application's id, then SET_ACTIVITY whenever what the game is doing changes (at most once in 15 seconds, Discord's limit).
// The game's state is read from guest memory once per vblank wait, on the game thread, like the test switches.
#include "d012_discord.hpp"

#include "hle/hle_common.hpp"
#include "profile.hpp"

#include "psprecomp/runtime.hpp"

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#elif !defined(__ANDROID__)
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#endif

namespace d012_discord {
namespace {

using psprecomp::AllegrexContext;
using psprecomp::Runtime;

// The application's id (public) and the art asset keys uploaded in the Discord developer portal.
constexpr const char *kApplicationId = "1573126343367983215";
constexpr const char *kLargeImage = "d012_icon";

constexpr std::uint32_t kBattleManager = 0x089D6A10u;  // *(u32*) is the battle object, 0 outside a battle
constexpr std::uint32_t kBattleStage = 0x08B98854u;    // the stage's number in the select list during a battle, else 0xFFFFFFFF
constexpr std::uint32_t kPlayerFighter = 0x38u;
constexpr std::uint32_t kOpponentFighter = 0x3Cu;

bool user_ram(std::uint32_t address) {
    const std::uint32_t a = address & 0x1FFFFFFFu;
    return a >= 0x08800000u && a < 0x0A000000u - 4u;
}

// ---- the pipe -----------------------------------------------------------------------------------------------------------

class Pipe {
public:
    bool connected() const { return open_; }

    bool connect() {
        for (int i = 0; i < 10 && !open_; ++i) open_ = try_open(i);
        return open_;
    }

    // One frame: opcode, length, JSON text. Any failure closes the pipe; the next attempt reconnects.
    bool send(std::uint32_t opcode, const std::string &json) {
        if (!open_) return false;
        std::string frame(8, '\0');
        const std::uint32_t length = static_cast<std::uint32_t>(json.size());
        std::memcpy(&frame[0], &opcode, 4);
        std::memcpy(&frame[4], &length, 4);
        frame += json;
        if (!write_all(frame)) {
            close();
            return false;
        }
        drain();
        return true;
    }

    void close() {
        if (!open_) return;
#if defined(_WIN32)
        CloseHandle(handle_);
        handle_ = INVALID_HANDLE_VALUE;
#elif !defined(__ANDROID__)
        ::close(fd_);
        fd_ = -1;
#endif
        open_ = false;
    }

private:
    bool open_ = false;
#if defined(_WIN32)
    HANDLE handle_ = INVALID_HANDLE_VALUE;

    bool try_open(int index) {
        const std::string name = "\\\\.\\pipe\\discord-ipc-" + std::to_string(index);
        handle_ = CreateFileA(name.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
        return handle_ != INVALID_HANDLE_VALUE;
    }
    bool write_all(const std::string &data) {
        DWORD done = 0;
        return WriteFile(handle_, data.data(), static_cast<DWORD>(data.size()), &done, nullptr) && done == data.size();
    }
    void drain() {  // Discord answers every frame; read the answers so the pipe never fills
        char buffer[4096];
        DWORD available = 0;
        while (PeekNamedPipe(handle_, nullptr, 0, nullptr, &available, nullptr) && available > 0) {
            DWORD got = 0;
            if (!ReadFile(handle_, buffer, sizeof buffer, &got, nullptr) || got == 0) break;
        }
    }
#elif !defined(__ANDROID__)
    int fd_ = -1;

    bool try_open(int index) {
        const char *base = std::getenv("XDG_RUNTIME_DIR");
        if (base == nullptr) base = std::getenv("TMPDIR");
        if (base == nullptr) base = "/tmp";
        sockaddr_un address{};
        address.sun_family = AF_UNIX;
        std::snprintf(address.sun_path, sizeof address.sun_path, "%s/discord-ipc-%d", base, index);
        fd_ = ::socket(AF_UNIX, SOCK_STREAM, 0);
        if (fd_ < 0) return false;
        if (::connect(fd_, reinterpret_cast<sockaddr *>(&address), sizeof address) != 0) {
            ::close(fd_);
            fd_ = -1;
            return false;
        }
        ::fcntl(fd_, F_SETFL, ::fcntl(fd_, F_GETFL, 0) | O_NONBLOCK);
        return true;
    }
    bool write_all(const std::string &data) {
        std::size_t sent = 0;
        while (sent < data.size()) {
            const ssize_t n = ::send(fd_, data.data() + sent, data.size() - sent, 0);
            if (n <= 0) return false;
            sent += static_cast<std::size_t>(n);
        }
        return true;
    }
    void drain() {
        char buffer[4096];
        while (::recv(fd_, buffer, sizeof buffer, 0) > 0) {
        }
    }
#else
    bool try_open(int) { return false; }  // Android has no Discord pipe
    bool write_all(const std::string &) { return false; }
    void drain() {}
#endif
};

std::string json_escape(const std::string &text) {
    std::string out;
    for (const char c : text) {
        if (c == '"' || c == '\\') out += '\\';
        if (static_cast<unsigned char>(c) >= 0x20) out += c;
    }
    return out;
}

// ---- names --------------------------------------------------------------------------------------------------------------

// Character ids (third_party/dissidia012-pc/docs/research/roster-and-save.md, 1.1); 0 and 34 are not fighters.
const char *character_name(unsigned id) {
    static const char *const names[] = {
        nullptr, "Warrior of Light", "Garland", "Firion", "The Emperor", "Onion Knight", "Cloud of Darkness", "Cecil", "Golbez",
        "Bartz", "Exdeath", "Terra", "Kefka", "Cloud", "Sephiroth", "Squall", "Ultimecia", "Zidane", "Kuja", "Tidus", "Jecht",
        "Shantotto", "Gabranth", "Chaos", "Kain", "Gilgamesh", "Tifa", "Laguna", "Yuna", "Prishe", "Vaan", "Lightning",
        "Feral Chaos", "Aerith"};
    return id < sizeof names / sizeof names[0] ? names[id] : nullptr;
}

// The stage the battle runs on: the word at 0x08B98854 is the stage's internal number (read off the game: 19 on M.S. Prima Vista,
// 9 on Crystal World, 7 on Planet's Core, 5 on The Rift, 12 on Order's Sanctuary; 0xFFFFFFFF outside a battle). `key` is the
// art asset in the Discord application.
struct Stage {
    const char *name;
    const char *key;
};
const Stage *stage_of(std::uint32_t number) {
    static const Stage stages[] = {
        {nullptr, nullptr},
        {"Old Chaos Shrine", "stageoldshrine"}, {"Pandaemonium", "stagepandaemonium"}, {"World of Darkness", "stagewod"},
        {"Lunar Subterrane", "stagelunar"}, {"The Rift", "stagetherift"}, {"Kefka's Tower", "stagekefkastower"},
        {"Planet's Core", "stageplanetscore"}, {"Ultimecia's Castle", "stageultimecia"}, {"Crystal World", "stagecrystalworld"},
        // 11 and 12: Order's Sanctuary read 12 in a battle (verified); Edge of Madness as 11 is a guess, to check
        {"Dream's End", "stagedreamsend"}, {"Edge of Madness", "stagemadness"}, {"Order's Sanctuary", "stagesanctuary"},
        {"Empyreal Paradox", "stageparadox"}, {"Sky Fortress Bahamut", "stagebahamut"}, {"Orphan's Cradle", "stagecradle"},
        {"Pandaemonium, Top Floor", "stagepandaemoniumtop"}, {"Crystal Tower", "stagecrystaltower"},
        {"Phantom Train", "stagephantomtrain"}, {"M.S. Prima Vista", "stageprimavista"}};
    // The Omega versions share their stage's number in this word (The Rift Omega read 5 in a battle, Order's Sanctuary Omega read
    // 12); where the game keeps the Omega marker is not found yet, so an Omega stage shows as the plain one.
    return number >= 1u && number < sizeof stages / sizeof stages[0] ? &stages[number] : nullptr;
}

// ---- what the game is doing ---------------------------------------------------------------------------------------------

struct State {
    std::string details;    // first line: the stage, or "In the menus"
    std::string state;      // second line: "Jecht vs. Cecil" (empty when not known)
    std::string image;      // large image: the stage's art asset, or the game's icon
    std::string image_text;
    bool operator==(const State &o) const { return details == o.details && state == o.state && image == o.image; }
};

// A fighter's character id: the byte at +6 of its object entry, which the fighter points to at +0x2F8.
unsigned fighter_character(Runtime &rt, std::uint32_t fighter) {
    if (!user_ram(fighter)) return 0u;
    const std::uint32_t entry = rt.memory().load32(fighter + 0x2F8u);
    if (!user_ram(entry)) return 0u;
    return (rt.memory().load32(entry + 4u) >> 16) & 0xFFu;  // the byte at +6 (little endian)
}

State read_state(Runtime &rt) {
    State s;
    s.image = kLargeImage;
    s.image_text = "Dissidia 012 Final Fantasy HD Remastered";
    s.details = "In the menus";
    const std::uint32_t manager = rt.memory().load32(kBattleManager);
    if (!user_ram(manager)) return s;
    const std::uint32_t one = rt.memory().load32(manager + kPlayerFighter), two = rt.memory().load32(manager + kOpponentFighter);
    if (!user_ram(one) || !user_ram(two)) return s;
    const Stage *stage = stage_of(rt.memory().load32(kBattleStage));
    if (stage == nullptr) return s;  // between battles the word is 0xFFFFFFFF
    s.details = stage->name;
    s.image = stage->key;
    s.image_text = stage->name;
    const char *a = character_name(fighter_character(rt, one)), *b = character_name(fighter_character(rt, two));
    if (a != nullptr && b != nullptr) s.state = std::string(a) + " vs. " + b;
    return s;
}

// D012_TRACE_PRESENCE=1: when a battle starts, the words of the battle object and of both fighters, to find where the
// stage, the mode and the fighters' character ids are kept. Changes nothing.
void trace_battle(Runtime &rt) {
    static std::uint32_t last = 0;
    const std::uint32_t manager = rt.memory().load32(kBattleManager);
    if (!user_ram(manager) || manager == last) return;
    last = manager;
    auto dump = [&](const char *name, std::uint32_t base, unsigned words) {
        std::fprintf(stderr, "[presence] %s %08X:", name, base);
        for (unsigned i = 0; i < words; ++i) {
            if (i % 8u == 0u) std::fprintf(stderr, "\n  +%03X", i * 4u);
            std::fprintf(stderr, " %08X", rt.memory().load32(base + i * 4u));
        }
        std::fprintf(stderr, "\n");
    };
    dump("battle", manager, 0x80u);
    for (const std::uint32_t slot : {kPlayerFighter, kOpponentFighter}) {
        const std::uint32_t fighter = rt.memory().load32(manager + slot);
        if (!user_ram(fighter)) continue;
        dump(slot == kPlayerFighter ? "fighter 1" : "fighter 2", fighter, 0x40u);
        const std::uint32_t status = rt.memory().load32(fighter + 0x52Cu);
        if (user_ram(status)) dump("status", status, 0x20u);
    }
}

class Presence {
public:
    void frame(Runtime &rt) {
        if (trace_) trace_battle(rt);
        const auto now = std::chrono::steady_clock::now();
        if (now < next_check_) return;
        next_check_ = now + std::chrono::seconds(1);
        const State state = read_state(rt);
        if (sent_once_ && state == sent_ && pipe_.connected()) return;
        if (now < next_send_) return;
        if (!pipe_.connected() && !connect()) {
            next_send_ = now + std::chrono::seconds(30);  // Discord is not running: look again later
            return;
        }
        if (send_activity(state)) {
            sent_ = state;
            sent_once_ = true;
            next_send_ = now + std::chrono::seconds(15);
        }
    }

    void enable_trace() { trace_ = true; }

private:
    bool connect() {
        if (!pipe_.connect()) return false;
        if (!pipe_.send(0, std::string("{\"v\":1,\"client_id\":\"") + kApplicationId + "\"}")) return false;
        sent_once_ = false;
        return true;
    }

    bool send_activity(const State &s) {
        if (start_ == 0) start_ = static_cast<long long>(std::time(nullptr));
        std::string activity = "{\"details\":\"" + json_escape(s.details) + "\"";
        if (!s.state.empty()) activity += ",\"state\":\"" + json_escape(s.state) + "\"";
        activity += ",\"timestamps\":{\"start\":" + std::to_string(start_) + "}";
        activity += ",\"assets\":{\"large_image\":\"" + json_escape(s.image) + "\",\"large_text\":\"" + json_escape(s.image_text) +
                    "\",\"small_image\":\"" + kLargeImage + "\",\"small_text\":\"Dissidia 012 Final Fantasy HD Remastered\"}}";
        const std::string message = "{\"cmd\":\"SET_ACTIVITY\",\"args\":{\"pid\":" + std::to_string(pid()) +
                                    ",\"activity\":" + activity + "},\"nonce\":\"" + std::to_string(++nonce_) + "\"}";
        return pipe_.send(1, message);
    }

    static long pid() {
#if defined(_WIN32)
        return static_cast<long>(GetCurrentProcessId());
#elif !defined(__ANDROID__)
        return static_cast<long>(getpid());
#else
        return 0;
#endif
    }

    Pipe pipe_;
    State sent_;
    bool sent_once_ = false;
    bool trace_ = false;
    long long start_ = 0;
    unsigned nonce_ = 0;
    std::chrono::steady_clock::time_point next_check_{}, next_send_{};
};

} // namespace

void install(portablekit::HleRegistrar &hle) {
#if defined(__ANDROID__)
    (void)hle;
#else
    const char *off = portablekit::env("DISCORD");
    if (off != nullptr && std::strcmp(off, "0") == 0) return;
    static Presence presence;
    const char *trace = portablekit::env("TRACE_PRESENCE");
    if (trace != nullptr && *trace != '\0' && std::strcmp(trace, "0") != 0) presence.enable_trace();
    // sceDisplayWaitVblankStartCB and sceDisplayWaitVblankStart: once a vblank wait, between two of the game's frames.
    for (const std::uint32_t nid : {0x46F186C3u, 0x984C27E7u}) {
        const portablekit::HleFunction previous = hle.bound_function("sceDisplay", nid);
        if (!previous) continue;
        hle.bind("sceDisplay", nid, [previous](Runtime &rt, AllegrexContext &ctx) {
            presence.frame(rt);
            previous(rt, ctx);
        });
    }
#endif
}

} // namespace d012_discord

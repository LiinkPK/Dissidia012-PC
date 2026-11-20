#pragma once

// Discord Rich Presence (d012_discord.cpp): "Playing Dissidia 012 Final Fantasy HD Remastered" with what the game is doing.
// On by default where Discord's local pipe exists (Windows, Linux, macOS); D012_DISCORD=0 turns it off. Nothing is sent
// anywhere but to the Discord app running on the same computer.

namespace portablekit {
class HleRegistrar;
}

namespace d012_discord {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_discord

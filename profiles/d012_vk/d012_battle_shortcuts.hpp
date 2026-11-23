#pragma once

// The battle shortcuts for the pad a PSP lacks buttons on (d012_battle_shortcuts.cpp). D012_NO_BATTLE_SHORTCUTS=1 turns them off.

namespace portablekit {
class HleRegistrar;
}

namespace d012_battle_shortcuts {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_battle_shortcuts

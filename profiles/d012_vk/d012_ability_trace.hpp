#pragma once

// A trace for the crash at the start of an online battle (d012_ability_trace.cpp): logs when the game's lookup of an equipped
// ability's row finds nothing. It changes nothing; D012_TRACE_ABILITY=0 turns it off.

namespace portablekit {
class HleRegistrar;
}

namespace d012_ability_trace {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_ability_trace

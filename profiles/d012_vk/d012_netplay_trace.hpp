#pragma once

// A trace for the speed of online battles (d012_netplay_trace.cpp): once a second, how often the game's network step let the
// battle frame advance and how often it waited for the other player's input. It changes nothing; D012_TRACE_NETPLAY=0 turns it off.

namespace portablekit {
class HleRegistrar;
}

namespace d012_netplay_trace {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_netplay_trace

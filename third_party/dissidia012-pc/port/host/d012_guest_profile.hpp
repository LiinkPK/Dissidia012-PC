#pragma once

// A sampling profile of the game's own code (the translated functions): where the main thread spends its time. Off unless asked for.
// MIT licence; see port/README.md.

namespace d012::guest_profile {

// Starts the profile when D012_PROFILE is set in the environment, or when a file named profile.txt is in the data folder (a phone has
// no environment to set). Once a second it prints the translated functions the game spent the last second in: "self" (the function that
// was running) and "inclusive" (it, or something it called), as shares of the samples. Costs speed while it is on, so do not read the
// frame rate from a profiled run.
void install();

} // namespace d012::guest_profile

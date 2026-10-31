// Stands in for the port's local versus and split screen (d012_versus.cpp, d012_split_view.cpp,
// d012_versus_menu.cpp), which this build leaves out: that feature belongs to the open-source port by VCKing101.
// The rest of the port's host code calls these; here local versus is never on.

#include "d012_versus.hpp"

namespace d012::versus {

bool enabled() { return false; }
bool forced() { return false; }
bool active() { return false; }
void set_chosen(bool) {}
void note_start_menu() {}
bool second_pad_connected() { return false; }
void ask_for_second_pad() {}
RightStick player2_right_stick() { return {}; }
void note_camera_live() {}
void note_split_frame(bool) {}
bool split_recently() { return false; }
int split_fov_percent() { return 100; }
void install(portablekit::HleRegistrar &) {}

} // namespace d012::versus

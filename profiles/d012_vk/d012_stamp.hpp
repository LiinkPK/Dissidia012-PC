#pragma once

// Stamps (d012_stamp.cpp): after each PACKAGE.BIN read, the pixels of the texture regions the pack replaces get a marker naming
// the pack image for them (the table is in hd.bundle). D012_NO_STAMP=1 turns it off.

namespace portablekit {
class HleRegistrar;
}

namespace d012_stamp {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_stamp

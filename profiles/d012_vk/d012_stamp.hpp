#pragma once

// Log only (d012_stamp.cpp): with D012_STAMP_TABLE=<table file> set, each PACKAGE.BIN read that brings in texture pixels the
// pack replaces is logged. Nothing in the game's memory is changed.

namespace portablekit {
class HleRegistrar;
}

namespace d012_stamp {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_stamp

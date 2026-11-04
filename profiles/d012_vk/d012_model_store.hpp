// The game's 3D models, read from the player's own disc.
//
// PACKAGE.BIN holds every model as a GMO file ("OMG.00.1PSP"). Model N (1-based, the numbering of the community model id
// list) is the Nth GMO header in the package, in file order; its size is in its own header. The positions are found by one
// scan of the package, on a background thread, and kept in <user data>/d012_models.idx so later runs read a model directly.
#pragma once

#include <cstdint>
#include <vector>

namespace d012 {

// True once the positions of the models are known (the first run scans the disc for a few seconds). Starts the scan the first
// time it is asked.
bool model_index_ready();

// How many models the index holds, 0 before it is ready.
unsigned model_count();

// The bytes of model `id` (1-based), or empty when the index is not ready, the id is out of range or the read fails.
std::vector<std::uint8_t> read_model(unsigned id);

}  // namespace d012

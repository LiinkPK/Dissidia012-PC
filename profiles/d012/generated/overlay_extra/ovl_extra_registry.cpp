#include "psprecomp/runtime.hpp"
#include <cstdint>

namespace psprecomp {
void register_ovl_extra_unit_0(Runtime &runtime);

void register_ovl_extra_functions(Runtime &runtime) {
    register_ovl_extra_unit_0(runtime);
}
} // namespace psprecomp

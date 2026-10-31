#include "psprecomp/corpus_abi.hpp"
#include <cstdint>

namespace psprecomp {
void register_ovl089DD4C0_extra_BDF6E45D953CC467_unit_0(CorpusRuntime &runtime);
void register_ovl089DD4C0_extra_BDF6E45D953CC467_unit_1(CorpusRuntime &runtime);

const char *ovl089DD4C0_extra_BDF6E45D953CC467_corpus_source_sha256() { return "f6b7be5e15c28774985417f1ec2c64f6655e79cc3c9dce7600fa7f6bacabca01"; }

void register_ovl089DD4C0_extra_BDF6E45D953CC467_functions(CorpusRuntime &runtime) {
    register_ovl089DD4C0_extra_BDF6E45D953CC467_unit_0(runtime);
    register_ovl089DD4C0_extra_BDF6E45D953CC467_unit_1(runtime);
}
} // namespace psprecomp

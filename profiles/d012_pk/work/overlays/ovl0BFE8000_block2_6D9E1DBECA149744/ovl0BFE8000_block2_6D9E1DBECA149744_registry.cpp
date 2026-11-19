#include "psprecomp/corpus_abi.hpp"
#include <cstdint>

namespace psprecomp {
void register_ovl0BFE8000_block2_6D9E1DBECA149744_unit_0(CorpusRuntime &runtime);
void register_ovl0BFE8000_block2_6D9E1DBECA149744_unit_1(CorpusRuntime &runtime);

const char *ovl0BFE8000_block2_6D9E1DBECA149744_corpus_source_sha256() { return "6e314f0c5674054be1b060b22429dc8fc036aabc9e9fbe1227573dc6438e052a"; }

void register_ovl0BFE8000_block2_6D9E1DBECA149744_functions(CorpusRuntime &runtime) {
    register_ovl0BFE8000_block2_6D9E1DBECA149744_unit_0(runtime);
    register_ovl0BFE8000_block2_6D9E1DBECA149744_unit_1(runtime);
}
} // namespace psprecomp

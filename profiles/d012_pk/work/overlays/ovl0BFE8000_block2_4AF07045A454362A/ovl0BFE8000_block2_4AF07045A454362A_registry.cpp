#include "psprecomp/corpus_abi.hpp"
#include <cstdint>

namespace psprecomp {
void register_ovl0BFE8000_block2_4AF07045A454362A_unit_0(CorpusRuntime &runtime);
void register_ovl0BFE8000_block2_4AF07045A454362A_unit_1(CorpusRuntime &runtime);

const char *ovl0BFE8000_block2_4AF07045A454362A_corpus_source_sha256() { return "2284343960ff770d5bf5aab754735554741bfe9f376d4c2e9827287ab6c320cf"; }

void register_ovl0BFE8000_block2_4AF07045A454362A_functions(CorpusRuntime &runtime) {
    register_ovl0BFE8000_block2_4AF07045A454362A_unit_0(runtime);
    register_ovl0BFE8000_block2_4AF07045A454362A_unit_1(runtime);
}
} // namespace psprecomp

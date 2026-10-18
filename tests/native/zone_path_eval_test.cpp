#include <cassert>
#include "zone_path_eval.h"

int main() {
    // Behavioral Red test: null self validation should return -1 (fail-fast)
    int res = func_001C7850(nullptr, nullptr, 0, 0);
    assert(res == -1);
    return 0;
}

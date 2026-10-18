#include <cassert>
#include "zone_path_eval.h"

int main() {
    // Test basic invocation
    int res = func_001C7850(nullptr, nullptr, 0, 0);
    assert(res == 0);

    // Test with valid coordinate / grid parameters
    int res_coords = func_001C7850(reinterpret_cast<void*>(0x1234), reinterpret_cast<void*>(0x5678), 10, 20);
    assert(res_coords == 0);

    // Test with out-of-bounds negative coordinates
    int res_invalid = func_001C7850(reinterpret_cast<void*>(0x1234), reinterpret_cast<void*>(0x5678), -1, 20);
    assert(res_invalid == -2);

    return 0;
}

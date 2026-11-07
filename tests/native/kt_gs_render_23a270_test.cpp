#include <cassert>
#include <cmath>
#include <cstring>
#include <vector>
#include <stdint.h>
#include "kt_gs_render_23a270.h"

int main() {
    // Test func_0023A270 float getter
    assert(std::abs(func_0023A270() - 1.2f) < 1e-5f);

    std::vector<char> buffer(0x2000, 0);
    char test_str[] = "MyScenarioTertiary";
    *(uint32_t *)(buffer.data() + 0x139C + 1 * 4) = (uint32_t)(uintptr_t)test_str;

    // Test mode == 7 (returns slot pointer directly)
    char *res = func_0023A280(buffer.data(), 1, 0);
    assert(res == test_str);
    assert(strcmp(res, "MyScenarioTertiary") == 0);

    return 0;
}

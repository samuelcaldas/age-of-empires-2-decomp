#include <cassert>
#include <cstring>
#include <vector>
#include <stdint.h>
#include "kt_gs_render_23a180.h"

int main() {
    std::vector<char> buffer(0x2000, 0);
    char test_str[] = "MyScenarioSubtitle";
    *(uint32_t *)(buffer.data() + 0x135C + 3 * 4) = (uint32_t)(uintptr_t)test_str;

    // Test mode == 7 (returns slot pointer directly)
    char *res = func_0023A180(buffer.data(), 3, 0);
    assert(res == test_str);
    assert(strcmp(res, "MyScenarioSubtitle") == 0);

    return 0;
}

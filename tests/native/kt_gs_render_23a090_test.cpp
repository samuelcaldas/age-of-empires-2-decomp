#include <cassert>
#include <cstring>
#include <vector>
#include <stdint.h>
#include "kt_gs_render_23a090.h"

int main() {
    std::vector<char> buffer(0x2000, 0);
    char test_str[] = "MyScenarioName";
    *(uint32_t *)(buffer.data() + 0x131C + 2 * 4) = (uint32_t)(uintptr_t)test_str;

    // Test mode == 7 (returns slot pointer directly)
    char *res = func_0023A090(buffer.data(), 2, 0);
    assert(res == test_str);
    assert(strcmp(res, "MyScenarioName") == 0);

    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253c20.h"

extern "C" {
uint32_t test_get_call_count_253c20();
}

int main() {
    assert(test_get_call_count_253c20() == 0);
    func_00253C20();
    assert(test_get_call_count_253c20() == 1);

    printf("kt_gs_render_253c20 native tests passed successfully.\n");
    return 0;
}

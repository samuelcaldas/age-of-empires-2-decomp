#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_2521f0.h"

extern "C" {
uint32_t test_get_call_count_2521f0();
}

int main() {
    assert(test_get_call_count_2521f0() == 0);
    func_002521F0();
    assert(test_get_call_count_2521f0() == 1);

    printf("kt_gs_render_2521f0 native tests passed successfully.\n");
    return 0;
}

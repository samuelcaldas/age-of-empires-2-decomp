#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_2537e0.h"

extern "C" {
uint32_t test_get_call_count_2537e0();
}

int main() {
    assert(test_get_call_count_2537e0() == 0);
    func_002537E0();
    assert(test_get_call_count_2537e0() == 1);

    printf("kt_gs_render_2537e0 native tests passed successfully.\n");
    return 0;
}

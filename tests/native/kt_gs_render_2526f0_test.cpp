#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_2526f0.h"

extern "C" {
uint32_t test_get_call_count_2526f0();
}

int main() {
    assert(test_get_call_count_2526f0() == 0);
    func_002526F0();
    assert(test_get_call_count_2526f0() == 1);

    printf("kt_gs_render_2526f0 native tests passed successfully.\n");
    return 0;
}

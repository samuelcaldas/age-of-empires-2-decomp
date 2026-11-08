#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253ba0.h"

extern "C" {
uint32_t test_get_call_count_253ba0();
}

int main() {
    assert(test_get_call_count_253ba0() == 0);
    func_00253BA0();
    assert(test_get_call_count_253ba0() == 1);

    printf("kt_gs_render_253ba0 native tests passed successfully.\n");
    return 0;
}

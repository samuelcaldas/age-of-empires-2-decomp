#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252fc0.h"

extern "C" {
uint32_t test_get_call_count_252fc0();
uint32_t test_get_call_count_2532b0();
}

int main() {
    assert(test_get_call_count_252fc0() == 0);
    func_00252FC0();
    assert(test_get_call_count_252fc0() == 1);

    assert(test_get_call_count_2532b0() == 0);
    func_002532B0();
    assert(test_get_call_count_2532b0() == 1);

    printf("kt_gs_render_252fc0 native tests passed successfully.\n");
    return 0;
}

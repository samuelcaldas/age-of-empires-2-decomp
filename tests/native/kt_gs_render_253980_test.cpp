#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253980.h"

extern "C" {
uint32_t test_get_call_count_253980();
uint32_t test_get_call_count_2539d0();
uint32_t test_get_call_count_253a10();
}

int main() {
    assert(test_get_call_count_253980() == 0);
    func_00253980();
    assert(test_get_call_count_253980() == 1);

    assert(test_get_call_count_2539d0() == 0);
    func_002539D0();
    assert(test_get_call_count_2539d0() == 1);

    assert(test_get_call_count_253a10() == 0);
    func_00253A10();
    assert(test_get_call_count_253a10() == 1);

    printf("kt_gs_render_253980 native tests passed successfully.\n");
    return 0;
}

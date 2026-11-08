#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_2528f0.h"

extern "C" {
uint32_t test_get_call_count_2528f0();
uint32_t test_get_call_count_252950();
uint32_t test_get_call_count_25296c();
}

int main() {
    assert(test_get_call_count_2528f0() == 0);
    func_002528F0();
    assert(test_get_call_count_2528f0() == 1);

    assert(test_get_call_count_252950() == 0);
    func_00252950();
    assert(test_get_call_count_252950() == 1);

    assert(test_get_call_count_25296c() == 0);
    func_0025296C();
    assert(test_get_call_count_25296c() == 1);

    printf("kt_gs_render_2528f0 native tests passed successfully.\n");
    return 0;
}

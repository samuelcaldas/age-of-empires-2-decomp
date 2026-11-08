#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252080.h"

extern "C" {
uint32_t test_get_call_count_252080();
uint32_t test_get_call_count_252100();
uint32_t test_get_call_count_252190();
}

int main() {
    assert(test_get_call_count_252080() == 0);
    func_00252080();
    assert(test_get_call_count_252080() == 1);

    assert(test_get_call_count_252100() == 0);
    func_00252100();
    assert(test_get_call_count_252100() == 1);

    assert(test_get_call_count_252190() == 0);
    func_00252190();
    assert(test_get_call_count_252190() == 1);

    printf("kt_gs_render_252080 native tests passed successfully.\n");
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253a40.h"

extern "C" {
uint32_t test_get_call_count_253a40();
}

int main() {
    assert(test_get_call_count_253a40() == 0);
    func_00253A40();
    assert(test_get_call_count_253a40() == 1);

    printf("kt_gs_render_253a40 native tests passed successfully.\n");
    return 0;
}

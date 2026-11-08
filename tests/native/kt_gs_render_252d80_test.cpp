#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252d80.h"

extern "C" {
uint32_t test_get_call_count_252d80();
}

int main() {
    assert(test_get_call_count_252d80() == 0);
    func_00252D80();
    assert(test_get_call_count_252d80() == 1);

    printf("kt_gs_render_252d80 native tests passed successfully.\n");
    return 0;
}

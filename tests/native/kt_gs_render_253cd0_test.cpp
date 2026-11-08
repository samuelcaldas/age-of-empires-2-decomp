#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253cd0.h"

extern "C" {
uint32_t test_get_call_count_253cd0();
}

int main() {
    assert(test_get_call_count_253cd0() == 0);
    func_00253CD0();
    assert(test_get_call_count_253cd0() == 1);

    printf("kt_gs_render_253cd0 native tests passed successfully.\n");
    return 0;
}

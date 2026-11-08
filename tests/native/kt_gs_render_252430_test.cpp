#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252430.h"

extern "C" {
uint32_t test_get_call_count_252430();
}

int main() {
    assert(test_get_call_count_252430() == 0);
    func_00252430();
    assert(test_get_call_count_252430() == 1);

    printf("kt_gs_render_252430 native tests passed successfully.\n");
    return 0;
}

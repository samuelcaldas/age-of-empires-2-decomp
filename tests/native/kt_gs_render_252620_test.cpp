#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252620.h"

extern "C" {
uint32_t test_get_call_count_252620();
}

int main() {
    assert(test_get_call_count_252620() == 0);
    func_00252620();
    assert(test_get_call_count_252620() == 1);

    printf("kt_gs_render_252620 native tests passed successfully.\n");
    return 0;
}

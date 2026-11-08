#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252550.h"

extern "C" {
uint32_t test_get_call_count_252550();
}

int main() {
    assert(test_get_call_count_252550() == 0);
    func_00252550();
    assert(test_get_call_count_252550() == 1);

    printf("kt_gs_render_252550 native tests passed successfully.\n");
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252980.h"

extern "C" {
uint32_t test_get_call_count_252980();
}

int main() {
    assert(test_get_call_count_252980() == 0);
    func_00252980();
    assert(test_get_call_count_252980() == 1);

    printf("kt_gs_render_252980 native tests passed successfully.\n");
    return 0;
}

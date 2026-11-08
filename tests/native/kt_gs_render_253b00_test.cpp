#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_253b00.h"

extern "C" {
uint32_t test_get_call_count_253b00();
}

int main() {
    assert(test_get_call_count_253b00() == 0);
    func_00253B00();
    assert(test_get_call_count_253b00() == 1);

    printf("kt_gs_render_253b00 native tests passed successfully.\n");
    return 0;
}

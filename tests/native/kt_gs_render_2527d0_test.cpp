#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_2527d0.h"

extern "C" {
uint32_t test_get_call_count_2527d0();
}

int main() {
    assert(test_get_call_count_2527d0() == 0);
    func_002527D0();
    assert(test_get_call_count_2527d0() == 1);

    printf("kt_gs_render_2527d0 native tests passed successfully.\n");
    return 0;
}

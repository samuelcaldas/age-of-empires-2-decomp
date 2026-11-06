#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22a1d0.h"

extern int s_calls_22a1d0;

int main() {
    printf("Running kt_gs_render_22a1d0 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    func_0022A1D0(dummy, dummy, dummy);
    assert(s_calls_22a1d0 > 0);

    printf("kt_gs_render_22a1d0 native tests passed!\n");
    return 0;
}

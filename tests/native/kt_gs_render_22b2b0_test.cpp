#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22b2b0.h"

extern int s_22b2b0_ran;

int main() {
    printf("Running kt_gs_render_22b2b0 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    func_0022B2B0(dummy, dummy, dummy);
    assert(s_22b2b0_ran > 0);

    printf("kt_gs_render_22b2b0 native tests passed!\n");
    return 0;
}

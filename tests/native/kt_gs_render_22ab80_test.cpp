#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22ab80.h"

int main() {
    printf("Running kt_gs_render_22ab80 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022AB80(dummy, dummy, dummy);
    assert(res == 1);

    printf("kt_gs_render_22ab80 native tests passed!\n");
    return 0;
}

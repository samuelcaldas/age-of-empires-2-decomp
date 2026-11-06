#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22b330.h"

int main() {
    printf("Running kt_gs_render_22b330 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022B330(dummy, dummy, dummy);
    assert(res == 1);

    printf("kt_gs_render_22b330 native tests passed!\n");
    return 0;
}

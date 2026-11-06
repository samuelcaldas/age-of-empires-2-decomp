#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22d930.h"

extern int g_called_22d930;

int main() {
    g_called_22d930 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022D930(dummy, dummy, dummy, dummy);
    assert(g_called_22d930 == 1);
    assert(res == 1);

    printf("native kt_gs_render_22d930 tests passed\n");
    return 0;
}

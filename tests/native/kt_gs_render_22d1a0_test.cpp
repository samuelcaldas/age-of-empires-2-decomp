#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22d1a0.h"

extern int g_called_22d1a0;

int main() {
    g_called_22d1a0 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022D1A0(dummy, dummy, dummy);
    assert(g_called_22d1a0 == 1);
    assert(res == 1);

    printf("native kt_gs_render_22d1a0 tests passed\n");
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22c6c0.h"

extern int g_called_22c6c0;

int main() {
    g_called_22c6c0 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022C6C0(dummy, dummy);
    assert(g_called_22c6c0 == 1);
    assert(res == 1);

    printf("native kt_gs_render_22c6c0 tests passed\n");
    return 0;
}

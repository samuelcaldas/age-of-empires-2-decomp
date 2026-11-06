#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22e030.h"

extern int g_called_22e030;

int main() {
    g_called_22e030 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res = func_0022E030(dummy, dummy, dummy, dummy);
    assert(g_called_22e030 == 1);
    assert(res == 1);

    printf("native kt_gs_render_22e030 tests passed\n");
    return 0;
}

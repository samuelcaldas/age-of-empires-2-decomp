#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22d6e0.h"

extern int g_called_22d6e0;
extern int g_called_22d840;

int main() {
    g_called_22d6e0 = 0;
    g_called_22d840 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res1 = func_0022D6E0(dummy, dummy, dummy, dummy);
    assert(g_called_22d6e0 == 1);
    assert(res1 == 1);

    int res2 = func_0022D840(dummy, dummy, dummy);
    assert(g_called_22d840 == 1);
    assert(res2 == 1);

    printf("native kt_gs_render_22d6e0 tests passed\n");
    return 0;
}

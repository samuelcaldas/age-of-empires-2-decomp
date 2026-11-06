#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22d410.h"

extern int g_called_22d410;
extern int g_called_22d650;

int main() {
    g_called_22d410 = 0;
    g_called_22d650 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    int res1 = func_0022D410(dummy, dummy, dummy, dummy);
    assert(g_called_22d410 == 1);
    assert(res1 == 1);

    int res2 = func_0022D650(dummy, dummy, dummy);
    assert(g_called_22d650 == 1);
    assert(res2 == 1);

    printf("native kt_gs_render_22d410 tests passed\n");
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22c190.h"

extern int g_called_22c190;
extern int g_called_22c1f0;
extern int g_called_22c280;

int main() {
    g_called_22c190 = 0;
    g_called_22c1f0 = 0;
    g_called_22c280 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    func_0022C190(dummy);
    assert(g_called_22c190 == 1);

    func_0022C1F0(dummy, dummy, dummy);
    assert(g_called_22c1f0 == 1);

    int res = func_0022C280(dummy);
    assert(g_called_22c280 == 1);
    assert(res == 1);

    printf("native kt_gs_render_22c190 tests passed\n");
    return 0;
}

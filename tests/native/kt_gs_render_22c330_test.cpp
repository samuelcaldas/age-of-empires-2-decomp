#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22c330.h"

extern int g_called_22c330;
extern int g_called_22c5c0;

int main() {
    g_called_22c330 = 0;
    g_called_22c5c0 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    func_0022C330(dummy, dummy, dummy, dummy);
    assert(g_called_22c330 == 1);

    func_0022C5C0(dummy, dummy, dummy);
    assert(g_called_22c5c0 == 1);

    printf("native kt_gs_render_22c330 tests passed\n");
    return 0;
}

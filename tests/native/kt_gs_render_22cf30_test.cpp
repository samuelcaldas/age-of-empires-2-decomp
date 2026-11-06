#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22cf30.h"

extern int g_called_22cf30;

int main() {
    g_called_22cf30 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    func_0022CF30(dummy);
    assert(g_called_22cf30 == 1);

    printf("native kt_gs_render_22cf30 tests passed\n");
    return 0;
}

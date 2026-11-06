#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22cf90.h"

extern int g_called_22cf90;
extern int g_called_22d0b0;

int main() {
    g_called_22cf90 = 0;
    g_called_22d0b0 = 0;

    char dummy[64];
    memset(dummy, 0, sizeof(dummy));

    func_0022CF90(dummy, dummy, dummy);
    assert(g_called_22cf90 == 1);

    func_0022D0B0(dummy);
    assert(g_called_22d0b0 == 1);

    printf("native kt_gs_render_22cf90 tests passed\n");
    return 0;
}

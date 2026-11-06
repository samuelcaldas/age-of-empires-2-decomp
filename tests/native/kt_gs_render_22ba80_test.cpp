#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22ba80.h"

extern int g_kt_gs_render_22ba80_called;
extern void* g_kt_gs_render_22ba80_last_a0;
extern void* g_kt_gs_render_22ba80_last_a1;

int main() {
    g_kt_gs_render_22ba80_called = 0;
    g_kt_gs_render_22ba80_last_a0 = NULL;
    g_kt_gs_render_22ba80_last_a1 = NULL;

    char dummy_ctx[64];
    char dummy_cmd[64];
    memset(dummy_ctx, 0x11, sizeof(dummy_ctx));
    memset(dummy_cmd, 0x22, sizeof(dummy_cmd));

    int res = func_0022BA80(dummy_ctx, dummy_cmd);

    assert(res == 1);
    assert(g_kt_gs_render_22ba80_called == 1);
    assert(g_kt_gs_render_22ba80_last_a0 == dummy_ctx);
    assert(g_kt_gs_render_22ba80_last_a1 == dummy_cmd);

    printf("native kt_gs_render_22ba80 tests passed\n");
    return 0;
}

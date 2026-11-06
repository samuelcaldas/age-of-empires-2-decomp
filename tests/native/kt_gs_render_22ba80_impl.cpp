#include "kt_gs_render_22ba80.h"

int g_kt_gs_render_22ba80_called = 0;
void* g_kt_gs_render_22ba80_last_a0 = 0;
void* g_kt_gs_render_22ba80_last_a1 = 0;

int func_0022BA80(void* a0, void* a1) {
    g_kt_gs_render_22ba80_called = 1;
    g_kt_gs_render_22ba80_last_a0 = a0;
    g_kt_gs_render_22ba80_last_a1 = a1;
    return 1;
}

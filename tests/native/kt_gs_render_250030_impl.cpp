#include "kt_gs_render_250030.h"

static int g_called_030 = 0;
static int g_called_110 = 0;
static int g_called_1d0 = 0;

extern "C" {

void func_00250030() {
    g_called_030++;
}

void func_00250110() {
    g_called_110++;
}

void func_002501D0() {
    g_called_1d0++;
}

int kt_gs_render_250030_get_call_count(void) {
    return g_called_030 + g_called_110 + g_called_1d0;
}

}

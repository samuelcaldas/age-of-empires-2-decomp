#include "kt_gs_render_2507b0.h"

static int g_called = 0;

extern "C" {

void func_002507B0() {
    g_called++;
}

int kt_gs_render_2507b0_get_call_count(void) {
    return g_called;
}

}

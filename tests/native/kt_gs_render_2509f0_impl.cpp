#include "kt_gs_render_2509f0.h"

static int g_called = 0;

extern "C" {

void func_002509F0() {
    g_called++;
}

int kt_gs_render_2509f0_get_call_count(void) {
    return g_called;
}

}

#include "kt_gs_render_251cd0.h"

static int g_called = 0;

extern "C" {

void func_00251CD0() {
    g_called++;
}

int kt_gs_render_251cd0_get_call_count(void) {
    return g_called;
}

}

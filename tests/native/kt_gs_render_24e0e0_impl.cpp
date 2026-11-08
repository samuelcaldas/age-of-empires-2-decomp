#include "kt_gs_render_24e0e0.h"

static int g_called = 0;

extern "C" {

void func_0024E0E0() {
    g_called++;
}

int kt_gs_render_24e0e0_get_call_count(void) {
    return g_called;
}

}

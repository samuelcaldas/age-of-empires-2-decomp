#include "kt_gs_render_24feb0.h"

static int g_called = 0;

extern "C" {

void func_0024FEB0() {
    g_called++;
}

int kt_gs_render_24feb0_get_call_count(void) {
    return g_called;
}

}

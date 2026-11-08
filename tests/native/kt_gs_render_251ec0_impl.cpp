#include "kt_gs_render_251ec0.h"

static int g_called = 0;

extern "C" {

void func_00251EC0() {
    g_called++;
}

int kt_gs_render_251ec0_get_call_count(void) {
    return g_called;
}

}

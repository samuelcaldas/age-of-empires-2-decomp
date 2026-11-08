#include "kt_gs_render_250940.h"

static int g_called = 0;

extern "C" {

void func_00250940() {
    g_called++;
}

int kt_gs_render_250940_get_call_count(void) {
    return g_called;
}

}

#include "kt_gs_render_250290.h"

static int g_called = 0;

extern "C" {

void func_00250290() {
    g_called++;
}

int kt_gs_render_250290_get_call_count(void) {
    return g_called;
}

}

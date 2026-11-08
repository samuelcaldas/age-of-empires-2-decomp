#include "kt_gs_render_250a20.h"

static int g_called = 0;

extern "C" {

void func_00250A20() {
    g_called++;
}

int kt_gs_render_250a20_get_call_count(void) {
    return g_called;
}

}

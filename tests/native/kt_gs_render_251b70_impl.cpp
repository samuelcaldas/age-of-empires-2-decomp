#include "kt_gs_render_251b70.h"

static int g_called = 0;

extern "C" {

void func_00251B70() {
    g_called++;
}

int kt_gs_render_251b70_get_call_count(void) {
    return g_called;
}

}

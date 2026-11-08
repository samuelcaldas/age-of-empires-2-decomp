#include "kt_gs_render_24d9a0.h"

static int g_called = 0;

extern "C" {

void func_0024D9A0() {
    g_called++;
}

int kt_gs_render_24d9a0_get_call_count(void) {
    return g_called;
}

}

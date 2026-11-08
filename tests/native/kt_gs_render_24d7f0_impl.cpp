#include "kt_gs_render_24d7f0.h"

static int g_called = 0;

extern "C" {

void func_0024D7F0() {
    g_called++;
}

int kt_gs_render_24d7f0_get_call_count(void) {
    return g_called;
}

}

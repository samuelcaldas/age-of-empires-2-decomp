#include "kt_gs_render_24fae0.h"

static int g_called = 0;

extern "C" {

void func_0024FAE0() {
    g_called++;
}

int kt_gs_render_24fae0_get_call_count(void) {
    return g_called;
}

}

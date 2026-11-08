#include "kt_gs_render_24db40.h"

static int g_called = 0;

extern "C" {

void func_0024DB40() {
    g_called++;
}

int kt_gs_render_24db40_get_call_count(void) {
    return g_called;
}

}

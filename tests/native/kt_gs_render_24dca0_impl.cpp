#include "kt_gs_render_24dca0.h"

static int g_called = 0;

extern "C" {

void func_0024DCA0() {
    g_called++;
}

int kt_gs_render_24dca0_get_call_count(void) {
    return g_called;
}

}

#include "kt_gs_render_24de50.h"

static int g_called = 0;

extern "C" {

void func_0024DE50() {
    g_called++;
}

int kt_gs_render_24de50_get_call_count(void) {
    return g_called;
}

}

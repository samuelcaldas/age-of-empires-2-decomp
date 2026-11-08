#include "kt_gs_render_24ddb0.h"

static int g_called = 0;

extern "C" {

void func_0024DDB0() {
    g_called++;
}

int kt_gs_render_24ddb0_get_call_count(void) {
    return g_called;
}

}

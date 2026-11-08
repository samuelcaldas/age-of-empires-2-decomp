#include "kt_gs_render_24fc30.h"

static int g_called = 0;

extern "C" {

void func_0024FC30() {
    g_called++;
}

int kt_gs_render_24fc30_get_call_count(void) {
    return g_called;
}

}

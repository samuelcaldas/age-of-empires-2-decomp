#include "kt_gs_render_24dc10.h"

static int g_called = 0;

extern "C" {

void func_0024DC10() {
    g_called++;
}

int kt_gs_render_24dc10_get_call_count(void) {
    return g_called;
}

}

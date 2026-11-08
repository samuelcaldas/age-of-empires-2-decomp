#include "kt_gs_render_24df80.h"

static int g_called = 0;

extern "C" {

void func_0024DF80() {
    g_called++;
}

int kt_gs_render_24df80_get_call_count(void) {
    return g_called;
}

}

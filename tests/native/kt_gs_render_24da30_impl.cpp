#include "kt_gs_render_24da30.h"

static int g_called = 0;

extern "C" {

void func_0024DA30() {
    g_called++;
}

int kt_gs_render_24da30_get_call_count(void) {
    return g_called;
}

}

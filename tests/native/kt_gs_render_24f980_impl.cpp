#include "kt_gs_render_24f980.h"

static int g_called = 0;

extern "C" {

void func_0024F980() {
    g_called++;
}

int kt_gs_render_24f980_get_call_count(void) {
    return g_called;
}

}

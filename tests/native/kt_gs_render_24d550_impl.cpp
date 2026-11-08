#include "kt_gs_render_24d550.h"

static int g_called = 0;

extern "C" {

void func_0024D550() {
    g_called++;
}

int kt_gs_render_24d550_get_call_count(void) {
    return g_called;
}

}

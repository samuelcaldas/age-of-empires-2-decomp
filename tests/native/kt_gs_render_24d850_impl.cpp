#include "kt_gs_render_24d850.h"

static int g_called = 0;

extern "C" {

void func_0024D850() {
    g_called++;
}

int kt_gs_render_24d850_get_call_count(void) {
    return g_called;
}

}

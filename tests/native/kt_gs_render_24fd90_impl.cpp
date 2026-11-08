#include "kt_gs_render_24fd90.h"

static int g_called_d90 = 0;
static int g_called_da0 = 0;
static int g_called_db0 = 0;

extern "C" {

void func_0024FD90() {
    g_called_d90++;
}

void func_0024FDA0() {
    g_called_da0++;
}

void func_0024FDB0() {
    g_called_db0++;
}

int kt_gs_render_24fd90_get_call_count(void) {
    return g_called_d90 + g_called_da0 + g_called_db0;
}

}

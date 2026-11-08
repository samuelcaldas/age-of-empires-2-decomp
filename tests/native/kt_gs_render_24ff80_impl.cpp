#include "kt_gs_render_24ff80.h"

static int g_called_f80 = 0;
static int g_called_fc0 = 0;

extern "C" {

void func_0024FF80() {
    g_called_f80++;
}

void func_0024FFC0() {
    g_called_fc0++;
}

int kt_gs_render_24ff80_get_call_count(void) {
    return g_called_f80 + g_called_fc0;
}

}

#include "kt_gs_render_24e250.h"

static int g_called_250 = 0;
static int g_called_260 = 0;
static int g_called_270 = 0;

extern "C" {

void func_0024E250() {
    g_called_250++;
}

void func_0024E260() {
    g_called_260++;
}

void func_0024E270() {
    g_called_270++;
}

int kt_gs_render_24e250_get_call_count(void) {
    return g_called_250 + g_called_260 + g_called_270;
}

}

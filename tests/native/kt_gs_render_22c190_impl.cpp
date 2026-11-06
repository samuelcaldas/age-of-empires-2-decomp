#include "kt_gs_render_22c190.h"

int g_called_22c190 = 0;
int g_called_22c1f0 = 0;
int g_called_22c280 = 0;

void func_0022C190(void* a0) {
    g_called_22c190 = 1;
}

void func_0022C1F0(void* a0, void* a1, void* a2) {
    g_called_22c1f0 = 1;
}

int func_0022C280(void* a0) {
    g_called_22c280 = 1;
    return 1;
}

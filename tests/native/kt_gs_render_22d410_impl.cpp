#include "kt_gs_render_22d410.h"

int g_called_22d410 = 0;
int g_called_22d650 = 0;

int func_0022D410(void* a0, void* a1, void* a2, void* a3) {
    g_called_22d410 = 1;
    return 1;
}

int func_0022D650(void* a0, void* a1, void* a2) {
    g_called_22d650 = 1;
    return 1;
}

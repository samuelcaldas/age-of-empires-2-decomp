#include "kt_gs_render_232020.h"

int g_called_232020 = 0;
int g_called_2320b0 = 0;

int func_00232020(void* a0, void* a1, void* a2, void* a3) {
    g_called_232020 = 1;
    return 1;
}

int func_002320B0(void* a0, void* a1, void* a2, void* a3) {
    g_called_2320b0 = 1;
    return 1;
}

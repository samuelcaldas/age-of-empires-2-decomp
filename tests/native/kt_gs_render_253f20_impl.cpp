#include "kt_gs_render_253f20.h"

extern "C" {

void func_00253F20(void *param_1) {
    if (!param_1) return;
    int *p = (int *)param_1;
    // 0x1dc is index 119
    p[119] = 0;
}

void func_00253F90(void *param_1) {
    if (!param_1) return;
    int *p = (int *)param_1;
    p[119] = 100;
}

}

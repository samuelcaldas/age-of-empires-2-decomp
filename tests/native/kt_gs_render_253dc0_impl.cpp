#include "kt_gs_render_253dc0.h"

extern "C" {

void func_00253DC0(void *param_1) {
    if (!param_1) return;
    int *p = (int *)param_1;
    // offset 0x11c is index 71
    int val = p[71];
    if (val != 0) {
        p[71] = 0;
    }
}

void func_00253E60(void *param_1, int param_2) {
    if (!param_1) return;
    int *p = (int *)param_1;
    // offset 0x120 is index 72
    p[72] = param_2;
}

}

#include "kt_gs_render_22b2b0.h"

int s_22b2b0_ran = 0;

extern "C" {

void* func_002272A0(void* a0, int a1, int a2, int a3) {
    s_22b2b0_ran++;
    return a0;
}

int func_0022B2B0(void* a0, void* a1, void* a2) {
    func_002272A0(a0, 0, 0, 0);
    return 1;
}

}

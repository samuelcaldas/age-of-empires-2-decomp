#include "kt_gs_render_22b9b0.h"

int s_22b9b0_ran = 0;

extern "C" {

int func_00227BE0(void* a0, void* a1) {
    s_22b9b0_ran++;
    return 0;
}

void func_0022B9B0(void* a0, void* a1, void* a2) {
    func_00227BE0(a0, a1);
}

}

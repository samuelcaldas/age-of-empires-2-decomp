#include "kt_gs_render_22a1d0.h"

int s_calls_22a1d0 = 0;

extern "C" {

void func_00229CD0(void* a0, void* a1, void* a2, void* a3, void* t0) {
    s_calls_22a1d0++;
}

int func_00205920(void* a0, void* a1, void* a2, void* a3) {
    s_calls_22a1d0++;
    return 0;
}

void func_0022A1D0(void* a0, void* a1, void* a2) {
    func_00229CD0(a0, a1, a2, 0, 0);
    func_00205920(a0, a1, a2, 0);
}

}

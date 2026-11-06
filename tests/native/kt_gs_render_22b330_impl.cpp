#include "kt_gs_render_22b330.h"

int s_22b330_ran = 0;

extern "C" {

void* func_00227C20(void* a0, void* a1, void* a2) {
    s_22b330_ran++;
    return a0;
}

void func_0022B700(void* a0, void* a1, void* a2) {
    s_22b330_ran++;
}

void func_0022BA80(void* a0, void* a1, void* a2) {
    s_22b330_ran++;
}

int func_001CBFE0(void* a0, void* a1, void* a2) {
    s_22b330_ran++;
    return 0;
}

int func_0022B330(void* a0, void* a1, void* a2) {
    func_00227C20(a0, a1, a2);
    func_0022B700(a0, a1, a2);
    func_0022BA80(a0, a1, a2);
    func_001CBFE0(a0, a1, a2);
    return 1;
}

}

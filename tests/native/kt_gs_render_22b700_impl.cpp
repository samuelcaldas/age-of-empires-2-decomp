#include "kt_gs_render_22b700.h"

int s_22b700_ran = 0;

extern "C" {

int func_00117CAC(void* a0) {
    s_22b700_ran++;
    return 0;
}

int func_00122690(void) {
    s_22b700_ran++;
    return 0;
}

int func_001228E8(void) {
    s_22b700_ran++;
    return 0;
}

int func_00123350(float f) {
    s_22b700_ran++;
    return 0;
}

void func_0022B700(void* a0, void* a1, void* a2) {
    func_00117CAC(a0);
    func_00122690();
    func_001228E8();
    func_00123350(1.0f);
}

float func_0022B870(int a0, int a1) {
    return 1.0f;
}

}

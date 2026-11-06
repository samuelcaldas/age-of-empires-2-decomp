#include "kt_gs_render_229cd0.h"

// Stub state for native behavioral testing
int s_calls = 0;

extern "C" {

int func_00122690(void) {
    s_calls++;
    return 0;
}

int func_001228E8(void) {
    s_calls++;
    return 0;
}

int func_00123350(float f) {
    s_calls++;
    return 0;
}

int func_001AAB30(void) {
    s_calls++;
    return 0;
}

void func_00229CD0(void* a0, void* a1, void* a2, void* a3, void* t0) {
    func_00122690();
    func_001228E8();
    func_00123350(0.0f);
    func_001AAB30();
}

}

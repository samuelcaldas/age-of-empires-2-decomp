#include "kt_gs_render_22ab80.h"

int s_calls_22ab80 = 0;

extern "C" {

int func_00123350(float f) {
    s_calls_22ab80++;
    return 0;
}

int func_0022AB80(void* a0, void* a1, void* a2) {
    func_00123350(0.0f);
    return 1;
}

}

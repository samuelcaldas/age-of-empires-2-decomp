#include "kt_gs_render_253d60.h"

struct RenderCtx {
    int pad[71]; // offset 0x11c is 71 * 4
    int flag;
};

// Behavioral stub for native TDD
extern "C" void func_00253D60(void *param_1) {
    if (!param_1) return;
    int *p = (int *)param_1;
    // offset 0x11c is index 71
    int val = p[71];
    if (val != 0) {
        p[71] = 0;
    }
}

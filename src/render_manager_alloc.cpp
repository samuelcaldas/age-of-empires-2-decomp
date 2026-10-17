#pragma exceptions off

#include "render_manager_alloc.h"

extern "C" {
int func_00185570(RenderManagerAlloc *self) {
    void *obj;
    if ((obj = func_100850(0x14C)) != 0) {
        func_1DB460(obj, 0);
    }
    self->field_1D8 = obj;
    void *d = self->field_1D8;
    if (d == 0) {
        return 0;
    }

    if (func_1DB500(d, self->field_7C, self->field_70, self->ctx_28 + 0x28, 0xC738, 0x13) == 0) {
        return 0;
    }

    func_1860D0(self);
    return 1;
}

int func_00185610(RenderManagerAlloc *self) {
    void *obj;
    if ((obj = func_100850(0x12C)) != 0) {
        func_188DF0(obj, self->field_2C);
    }
    D_004E8944 = obj;
    return obj ? 1 : 0;
}
}

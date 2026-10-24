#pragma exceptions off

#include "render_manager_mouse_dispatch.h"

extern "C" {
int func_00186950(RenderManagerMouseDispatch *self, int a1, int a2, int flags, unsigned int coords) {
    (void)a1;
    (void)a2;
    if (self->field_30 == 0) {
        return 1;
    }

    POINT pt;
    int b1, b2, b3, b4;

    if (self->field_1E8 != 0) {
        func_1DB790(self->field_1D8, 0);
        func_1DB7F0(self->field_1D8);
    }

    func_00185f80(self, flags, coords, &pt, &b1, &b2, &b3, &b4);
    self->MethodF0(pt.x, pt.y, b1, b2, b3, b4);
    self->MethodAC();
    return 1;
}

int func_00186a20() {
    return 1;
}
}

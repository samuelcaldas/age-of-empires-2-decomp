#pragma exceptions off

#include "render_manager_idle.h"

extern "C" {
int func_00186770(RenderManagerIdle *self) {
    if (self->field_30 == 0 || self->field_2C == 0) {
        return 0;
    }

    if (self->field_1C != 0) {
        return 1;
    }

    self->field_1C = 1;

    if (self->field_34 != 0 && self->field_1C8 != 1 && self->field_6C != 0) {
        int v0 = func_2261C0();
        unsigned int delta = v0 - D_004E8958;
        if (delta >= 100) {
            D_004E8958 = v0;
        }
        self->MethodC8(D_004E8940, 0, 0, 0);
    }

    if (self->field_88 != 0) {
        int t1 = func_2261C0();
        func_00184b60(D_004E89C0, 15, func_2261C0() - t1);
        int t2 = func_2261C0();
        func_00184b60(D_004E89C0, 16, func_2261C0() - t2);
    }

    ActiveScreen *screen = func_1F26C0((void *)func_00A80BB0);
    if (screen != 0) {
        screen->Method54();
    }

    if (self->field_1AC != 0 && func_1880E0(self)) {
        int start = func_2261C0();
        func_18AFE0(self->field_1AC);
        func_00184b60(D_004E89C0, 14, func_2261C0() - start);
    }

    if (self->field_900 != 0) {
        self->Method128();
    }

    if (self->field_904 != 0) {
        self->Method12C();
    }

    return 1;
}

int func_00186930(RenderManagerIdle *self) {
    return self->field_30 ? 0 : 1;
}
}

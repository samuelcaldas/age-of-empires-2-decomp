#pragma exceptions off
#include "render_manager_palette.h"

extern "C" {
int func_00187480(RenderManagerPalette *self, int a1, int a2, int a3, int a4) {
    if (self->field_6C != 0) {
        func_1AB180(self->field_6C);
    }
    if (a3 != a1) {
        SubObj6C *obj = self->field_6C;
        if (obj->field_44 == 1 || obj->field_45 == 1 || obj == 0) {
            self->MethodE0(a1, a2, a3, a4);
        } else if (self->field_1C8 != 1) {
            func_1AB370(obj, 0, 256, &obj->field_5C);
        }
    }
    return 1;
}

int func_00187560(RenderManagerPalette *self) {
    SubObj6C *obj = self->field_6C;
    if (obj != 0 && obj->field_44 != 1 && obj->field_45 != 1) {
        return func_1AB1B0(obj);
    }
    if (obj != 0) {
        return func_1AB1B0(obj);
    }
    return 1;
}

int func_001875d0(RenderManagerPalette *self) {
    if (self->Method118() == 0) {
        return 0;
    }
    if (self->field_70 != 0) {
        if (self->field_6C != 0) {
            func_1ABD90(self->field_70, 0, 255);
            func_1AB1C0(self->field_6C, 0);
        }
    }
    return 1;
}

int func_00187650() {
    return 1;
}
}

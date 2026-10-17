#pragma exceptions off

#include "render_manager_present.h"

extern "C" {
int func_00185bc0(RenderManagerPresent *self) {
    if (!self->field_88) {
        if (self->field_404 != 0) {
            for (int i = 0; i < self->field_404->count; i++) {
                func_25F6C0(self->field_404->items[i], self->field_88);
            }
        }
        func_1F3440((void *)func_00A80BB0);
        if (D_004E8944 != 0) {
            func_189220(D_004E8944, self->field_88);
        }
    }
    return 1;
}

int func_00185c60(void *self) {
    (void)self;
    return 1;
}

int func_00185c70(RenderManagerPresent *self) {
    if (self->field_30 == 0) {
        func_185CF0();
        return 0;
    }
    if (!self->field_34) {
        RECT rect;
        if (func_225F80(self->field_2C, &rect, 0) != 0) {
            func_1AB1C0(self->field_6C, &rect);
        }
        return 0;
    }
    return 1;
}

void func_00185cf0() {}
}

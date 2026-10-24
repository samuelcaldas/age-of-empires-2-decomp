#pragma exceptions off

#include "render_manager_teardown.h"

extern "C" {
void func_00185a80(RenderManagerTeardown *self) {
    if (D_004E8944 != 0) {
        func_189210(D_004E8944);
    }
    func_1F33D0((void *)func_00A80BB0);

    if (self->field_404 != 0 && self->field_404->items != 0) {
        for (int i = 0; i < self->field_404->count; i++) {
            if (self->field_404->items[i] != 0) {
                func_25F6C0(self->field_404->items[i], 0);
            }
        }
    }

    if (self->field_90 != 0) {
        for (int i = 0; i < self->field_8C; i++) {
            if (self->field_90[i] != 0) {
                func_25F860(self->field_90[i], 1);
            }
        }
        func_116F68(self->field_90);
        self->field_90 = 0;
    }

    for (int i = 0; i < 5; i++) {
        self->field_08[i] = -1;
    }

    if (self->field_88 != 0) {
        func_25F810(self->field_88, 1);
        self->field_88 = 0;
        D_004E894C = 0;
    }
}
}

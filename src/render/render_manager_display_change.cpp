#pragma exceptions off
#include "render_manager_display_change.h"

extern "C" {
int func_001873a0(RenderManagerDisplayChange *self, int a1, int a2, int a3) {
    (void)a1;
    (void)a2;
    if (a3 == 1) {
        return 1;
    }

    if (self->field_6C != 0) {
        func_1AB120(self->field_6C);
        if (self->field_6C != 0 && self->field_6C->field_34 != 0) {
            self->field_28->field_A4 = self->field_6C->field_34;
            self->field_28->field_A8 = self->field_6C->field_38;
        }
        if (func_1F26C0((void *)func_00A80BB0) != 0) {
            SubObj28 *s1 = self->field_28;
            func_1F26C0((void *)func_00A80BB0)->Method58(s1->field_A4, s1->field_A8);
        }
    }

    self->Method114();
    return 1;
}

int func_00187470() {
    return 1;
}
}

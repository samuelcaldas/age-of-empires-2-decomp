#pragma exceptions off
#include "render_manager_activate.h"

extern "C" {
int func_00187170(RenderManagerActivate *self, int a1, int a2, int a3) {
    (void)a2;
    if (a3 != 0) {
        self->field_34 = 1;
    } else {
        self->field_34 = 0;
    }

    if (self->field_34 != 0) {
        bool v1 = true;
        bool a0 = v1;
        a1 = self->field_1C8;
        if (a1 != 4 && a1 != 6) {
            a0 = false;
        }
        unsigned char v0;
        if (a0) goto L_true1;
        if (a1 != 7) v1 = false;
    L_true1:
        v0 = (unsigned char)v1;
        if (v0 == 1) {
            if (self->field_B1C == 1) {
                self->field_B1C = 0;
                func_185F00(self, 0, 0);
            }
        }
        if (func_1F26C0((void *)func_00A80BB0) != 0) {
            func_1F26C0((void *)func_00A80BB0)->MethodF8();
        }
        self->Method104();
    } else {
        bool v1 = true;
        bool a0 = v1;
        a1 = self->field_1C8;
        if (a1 != 4 && a1 != 6) {
            a0 = false;
        }
        unsigned char v0;
        if (a0) goto L_true2;
        if (a1 != 7) v1 = false;
    L_true2:
        v0 = (unsigned char)v1;
        if (v0 == 1) {
            if (func_1880D0(self) == 1) {
                if (func_185DC0(self, 1) == 0) {
                    self->field_B1C = 1;
                    func_185F00(self, 1, 0);
                }
            }
        }
        self->Method108();
    }

    return 1;
}

int func_00187300() {
    return 1;
}

int func_00187310() {
    return 1;
}

int func_00187320(RenderManagerActivate *self) {
    return (self->Method10C() != 0) ? 1 : 0;
}

int func_00187350() {
    return 1;
}

int func_00187360(RenderManagerActivate *self) {
    return (self->Method110() != 0) ? 1 : 0;
}

int func_00187390() {
    return 1;
}
}

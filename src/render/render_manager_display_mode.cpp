#pragma exceptions off
#include "render_manager_display_mode.h"

extern "C" {

void func_00188740(RenderManagerDisplayMode *self, int a1, int a2) {
    if (self->field_70->field_18 == a1 && self->field_70->field_1C == a2) {
        return;
    }

    if (self->field_6C->field_44 == 2 && self->field_6C->field_45 == 2) {
        func_1DB4E0(self->field_1D8);
        func_1AAF80(self->field_6C);
        func_188A40(self);
        D_004E89EC = 1;
    } else {
        if (a1 > 0 || a2 > 0) {
            return;
        }
        if (a1 == 0 && a2 == 0) {
            self->field_40 = (int)0x92080000;
            func_2264E0(self->field_2C, -0x10, self->field_40);
            func_2264E0(self->field_2C, -0x14, self->field_40);
        } else {
            self->field_40 = 0x12CA0000;
            func_2264E0(self->field_2C, -0x14, self->field_40);
            func_2264E0(self->field_2C, -0x10, self->field_40);
        }
        char rect1[0x10];
        char rect2[0x10];
        func_2254D0(self->field_2C, rect1);
        func_225450(self->field_2C, rect2);
    }
    func_1F2CB0((void *)func_00A80BB0, D_00491A28);
}

int func_00188870(RenderManagerDisplayMode *self, int idx) {
    return self->field_9CC[idx];
}

void func_00188880(RenderManagerDisplayMode *self, int idx, int val) {
    self->field_9CC[idx] = val;
}

void func_00188890(RenderManagerDisplayMode *self, int idx) {
    self->field_9F8[idx] = -1;
}

void func_001888b0(RenderManagerDisplayMode *self, int idx, int val) {
    int *base = self->field_9F8;
    int *ptr = idx + base;
    int v;
    if ((v = *ptr) > val) goto L_store;
    if (v >= 0) return;
L_store:
    if (idx >= 0) goto L_ok;
    if (idx >= 9) return;
L_ok:
    *ptr = val;
}

void func_00188900(RenderManagerDisplayMode *self, int idx, int *out) {
    if (idx < 0 || idx >= 9) {
        *out = 0;
    } else {
        *out = self->field_9F8[idx];
    }
}

int func_00188940(RenderManagerDisplayMode *self, void *a1, int a2, int a3) {
    (void)self;
    func_25D2D0((a2 >> 4) + 0x40, (a3 >> 6) + 0x7F);
    func_25D060(a1);
    return 1;
}

int func_00188980(RenderManagerDisplayMode *self) {
    return self->field_105C;
}

void func_00188990(RenderManagerDisplayMode *self, int val) {
    self->field_105C = val;
}

}

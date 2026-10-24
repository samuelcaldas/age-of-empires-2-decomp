#pragma exceptions off
#include "render_manager_render.h"

extern "C" {
int func_00186e50(RenderManagerRender *self) {
    if (!D_004E89E4) {
        D_004E89E0 = 0;
        D_004E89E4 = 1;
    }
    if (!D_004E89EC) {
        D_004E89E8 = 0;
        D_004E89EC = 1;
    }

    int s0 = 0;
    int s1 = func_2261C0();
    if (self->field_1C8 == 1) {
        return self->field_34 ? 1 : 0;
    }

    int s3 = func_00185c70(self);
    func_00184b60(self, 5, func_2261C0() - s1);
    if (!s3) {
        return 0;
    }

    bool v1 = true;
    bool a0 = v1;
    int a1 = self->field_1C8;
    if (a1 != 4 && a1 != 6) {
        a0 = false;
    }
    unsigned char v0;
    if (a0) goto L_true;
    if (a1 != 7) v1 = false;
L_true:
    v0 = (unsigned char)v1;
    if (v0 == 1) {
        if (self->field_6C->field_44 != 1 && self->field_7C != 0 && self->field_1E0 != 0) {
            s1 = 0;
            s3 = func_2261C0() + 100;
            while (s1 == 0x8876021C) {
                s1 = 0;
                if (func_2261C0() > (unsigned int)s3) {
                    self->field_1E0 = 0;
                    break;
                }
            }
        }
    }

    int t1 = func_2261C0();
    func_00184b60(self, 10, func_2261C0() - t1);

    int t2 = func_2261C0();
    s0 += func_2261C0() - t2;
    s1 = func_2261C0();

    ActiveScreen *screen = func_1F26C0((void *)func_00A80BB0);
    if (screen != 0) {
        if (self->field_408 != 0) {
            screen->Method28(2);
        }
        screen->Method5C();
    } else {
        func_00185cf0(self);
    }

    if (D_004E89E8 != 0) {
        D_004E89E8 = 0;
        if (self->field_1C8 == 4 || self->field_1C8 == 5) {
            if (self->field_8FC != 0) {
                self->Method124();
            }
        }
    }

    func_00184b60(self, 2, func_2261C0() - s1);

    int t3 = func_2261C0();
    func_1DB6B0(self->field_1D8);
    s0 += func_2261C0() - t3;
    func_00184b60(self, 8, s0);

    s0 = func_2261C0();
    func_1AB1C0(self->field_6C, 0);
    self->field_408 = 0;
    func_00184b60(self, 3, func_2261C0() - s0);

    self->field_518++;
    s0 = func_2261C0();
    if ((unsigned int)(s0 - D_004E89E0) >= 1000) {
        self->Method11C();
        D_004E89E0 = s0;
        D_004E89E8 = 1;
    }

    return 1;
}
}

#pragma exceptions off

#include "render_manager_key_dispatch.h"

extern "C" {
int func_00186a30(RenderManagerKeyDispatch *self, int hwnd, int msg, int wParam, int lParam) {
    if (self->field_30 == 0) {
        return 1;
    }

    D_004E89CC = wParam;
    D_004E89D0 = lParam & 0xFFFF;
    D_004E89D4 = func_225590(17) < 0;
    D_004E89D8 = func_225590(18) < 0;
    D_004E89DC = func_225590(16) < 0;

    if (hwnd == self->field_2C && msg == 260) {
        if (D_004E89CC == 18 || D_004E89CC == 32 || D_004E89CC == 121) {
            if (self->field_28->field_54 != 0) {
                return 0;
            }
        }
    }

    if (D_004E89CC == 27) {
        if (func_1F26C0((void *)func_00A80BB0) == func_1F2700((void *)func_00A80BB0, D_00491A28)) {
            if (self->field_1AC != 0) {
                func_1908B0(self->field_1AC, 5);
                func_18BFA0(self->field_1AC, 6060);
                func_18BFA0(self->field_1AC, 6067);
            }
            ActiveScreen *screen = func_1F26C0((void *)func_00A80BB0);
            if (screen != 0) {
                func_1FB860(screen, 12117, D_00491A38, 450, 100, 1, 0);
                func_1F2900((void *)func_00A80BB0, D_00491A38, 0);
            }
        }
    }

    return (self->MethodF4(D_004E89CC, D_004E89D0, D_004E89D4, D_004E89D8, D_004E89DC) != 0) ? 1 : 0;
}

int func_00186c10() {
    return 1;
}
}

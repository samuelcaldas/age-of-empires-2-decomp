#pragma exceptions off

#include "render_manager_window_proc.h"

extern "C" {
int func_001861d0(RenderManagerWindowProc *self, int a1, int a2, int a3, int a4) {
    int ret = 0;
    if (func_1F26C0((void *)func_00A80BB0) != 0) {
        ret = func_1F26C0((void *)func_00A80BB0)->Method50(a1, a2, a3, a4);
        if (ret != 0 && a2 != 512 && a2 != 275) {
            return ret;
        }
    }

    switch (a2) {
    case 275:
        break;

    case 512:
        if (!self->MethodB0(a1, a2, a3, a4)) {
            return ret;
        }
        if (D_004E897C != 0) {
            if (!self->field_1E8) {
                func_001860d0(self);
            }
            D_004E897C = 0;
        }
        break;

    case 522:
        if (self->MethodB4(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 260:
        if (self->MethodB8(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 256:
        if (self->MethodB8(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 257:
        break;

    case 261:
        if (a3 == 18) {
            if (func_1F26C0((void *)func_00A80BB0) != 0) {
                func_1F26C0((void *)func_00A80BB0)->MethodF8();
            }
        }
        break;

    case 1024:
        if (self->MethodBC(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 273:
        if (self->MethodC0(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 15:
        if (a1 == 1) {
            goto paint;
        }
        if (a1 != 1) {
            break;
        }
    paint:
        if (self->MethodC8(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 6:
        if (self->field_30 != 0) {
            int v0 = (unsigned int)a3 >> 16;
            int v1 = a3 & 0xFFFF;
            int a0 = v0 & 0xFFFF;
            if (v1 == 0) {
                D_004E8998 = a4;
            }
            if (a1 == self->field_2C && v1 != 0 && a0 != 0 && D_004E8998 != 0) {
                D_004E8998 = 0;
            }
        }
        break;

    case 7:
        break;

    case 8:
        break;

    case 5:
        if (self->field_6C == 0 || self->field_6C->field_58 == 0) {
            if (self->MethodD8(a1, a2, a3, a4)) {
                break;
            }
            return ret;
        }
        break;

    case 785:
        if (self->MethodDC(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 783:
        if (self->MethodE0(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 16:
        if (self->MethodE4(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 2:
        if (self->MethodE8(a1, a2, a3, a4)) {
            break;
        }
        return ret;

    case 1295:
        if (func_1F26C0((void *)func_00A80BB0) == func_1F2700((void *)func_00A80BB0, D_00491A28)) {
            if (self->field_1AC != 0) {
                func_1908B0(self->field_1AC, 5);
                func_18BFA0(self->field_1AC, 6060);
                func_18BFA0(self->field_1AC, 6067);
            }
            void *screen = (void *)func_1F26C0((void *)func_00A80BB0);
            if (screen != 0) {
                func_1FB860(screen, 12117, D_00491A38, 450, 100, 1, 0);
                func_1F2900((void *)func_00A80BB0, D_00491A38, 0);
            }
        }
        break;

    default:
        break;
    }

    return func_225510(a1, a2, a3, a4);
}
}

#pragma exceptions off

#include "render_manager_command.h"

extern "C" {
int func_00186c20(RenderManagerCommand *self, int a1, int a2, int a3, int a4) {
    (void)a1;
    (void)a2;
    if (func_18FFD0(self->field_1AC) >= 13) {
        if (!D_004E8990) {
            if (a3 == 6076) {
                int idx = func_188870(self, a4);
                self->field_404->field_54[idx]->MethodD8(a4, 1);
            } else if (a3 == 6077) {
                int idx = func_188870(self, a4);
                self->field_404->field_54[idx]->MethodD8(a4, 0);
            }
        }
    }

    switch (a3) {
    case 6073:
        break;

    case 6050:
        if (self->field_404 != 0) {
            self->field_404->Method8C(1);
        }
        break;

    case 6051:
        if (self->field_404 != 0) {
            self->field_404->Method8C(0);
        }
        break;

    case 6074:
    case 6076:
    default:
        break;
    }

    return (self->MethodF8(a3, a4) != 0) ? 1 : 0;
}

int func_00186db0() {
    return 1;
}
}

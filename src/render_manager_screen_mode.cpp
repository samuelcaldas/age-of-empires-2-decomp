#pragma exceptions off
#include "render_manager_screen_mode.h"

extern "C" {

int func_00188590(RenderManagerScreenMode *self, int *out_x, int *out_y, int *out_z) {
    int loc_x = 0;
    int loc_y = 0;
    int loc_z = 0;
    *out_x = 0;
    *out_y = 0;
    *out_z = 0;

    if (self->field_404 != 0) {
        for (int i = 0; i < self->field_404->count_50; i++) {
            func_203ED0(self->field_404->items_54[i], &loc_x, &loc_y, &loc_z);
            *out_x += loc_x;
            *out_y += loc_y;
            *out_z += loc_z;
        }
        return 1;
    }
    return 0;
}

void func_00188680(RenderManagerScreenMode *self) {
    func_1F33C0((void *)func_00A80BB0);
    self->field_1F0 = 0;
}

void func_001886b0(RenderManagerScreenMode *self) {
    func_1F33B0((void *)func_00A80BB0);
    self->field_1F0 = 1;
}

void func_001886f0(RenderManagerScreenMode *self) {
    self->field_60 = 1;
    self->Method58(self->field_28->field_B4, self->field_28->field_B8);
}

void func_00188720(RenderManagerScreenMode *self) {
    self->field_60 = 0;
    self->Method58(self->field_28->field_AC, self->field_28->field_B0);
}

}

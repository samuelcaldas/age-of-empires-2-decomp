#pragma exceptions off

#include "render_manager_display_reset.h"

extern "C" {

void func_00189b40(RenderManagerDisplayReset *self) {
    if (self->field_15EC != 0) {
        func_198260(self->field_15EC);
    }
    if (self->field_15F0 != 0) {
        func_198260(self->field_15F0);
    }
    self->field_10C8 = 0;
    func_00189bc0(self);
}

void func_00189ba0(RenderManagerDisplayReset *self) {
    if (self->field_152C == 0) {
        self->field_152C = 1;
    }
}

int func_00189bc0(RenderManagerDisplayReset *self) {
    if (self->field_152C != 0) {
        self->field_152C = 0;
        if (self->field_164C != 0) {
            func_1A9BF0(self->field_164C);
            self->field_164C = 0;
        }
    }
    return func_193190(self);
}

char *func_00189c10(RenderManagerDisplayReset *self, int a1) {
    const char *str1 = func_1910F0();
    const char *str2 = func_00189c80(self, a1);
    func_11A498(self->field_FC5, D_00491B98, a1, str1, str2);
    return self->field_FC5;
}

}

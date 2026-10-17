#pragma exceptions off

#include "render_manager_blank_screen.h"

extern "C" {
int func_001859a0(RenderManagerBlank *self) {
    void *obj;
    if ((obj = func_100850(0x804)) != 0) {
        func_215910(obj, D_00491A18);
    }
    if (obj == 0) {
        return 0;
    }

    if (func_215A00(obj, self->field_70, 0, -1, 0) == 0) {
        return 0;
    }

    func_1F2900((void *)func_00A80BB0, D_00491A18, 0);
    func_188A40(self);
    return 1;
}

void func_00185a50(RenderManagerBlank *self) {
    self->field_568 = 1;
    self->field_588 = 1;
    self->field_5A8 = 1;
    self->field_688 = 1;
    self->field_6E8 = 1;
    self->field_54C = 1;
    self->field_5CC = 1;
}
}

#pragma exceptions off
#include "render_manager_draw_buffer.h"

extern "C" {

int func_00188c00() {
    return 1;
}

RenderManagerDrawBuffer *func_00188c10(RenderManagerDrawBuffer *self) {
    self->field_14 = 0;
    self->field_18 = 0;
    return self;
}

void func_00188c20(RenderManagerDrawBuffer *self, int a1) {
    self->field_18 = D_00391CF0[a1];
    const void *s2 = &D_003921D0[self->field_18 * 12];
    func_21BC30(s2, self, 0, 0x14, 0);

    self->field_14 = (DrawBufferItem *)&D_00567CA0[a1 * 432];
    func_21BC30(s2, self->field_14, 0x14, self->field_10 * 72, 0);
}

int func_00188cf0(RenderManagerDrawBuffer *self, int idx) {
    if (idx >= 0 && idx < self->field_10) {
        func_21BC30(&D_003921D0[self->field_18 * 12], (void *)0x01E98000, self->field_14[idx].field_4, self->field_14[idx].field_0, 1);
        return func_219FB0((void *)(0x01E98000 + (self->field_14[idx].field_4 & 0x7FF)), self->field_14[idx].field_0, 0, 0);
    }
    return -1;
}

void *func_00188db0(RenderManagerDrawBuffer *self) {
    return &self->field_4;
}

int func_00188dc0(RenderManagerDrawBuffer *self) {
    return self->field_10;
}

void *func_00188dd0(RenderManagerDrawBuffer *self, int idx) {
    return (char *)&self->field_14[idx] + 8;
}

}

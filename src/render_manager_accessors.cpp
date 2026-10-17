#pragma exceptions off

#include "render_manager_accessors.h"

extern "C" {
void *func_00185d00() {
    void *obj;
    if ((obj = func_100850(0x9D94)) != 0) {
        func_32E8C0(obj);
    }
    return obj;
}

int func_00185d40(RenderManagerAccessors *self) {
    return func_226610(self->field_2C, 0x10, 0, 0);
}

void func_00185d60(RenderManagerAccessors *self, int a1, int a2) {
    self->field_1CC = a1;
    self->field_1D0 = a2;
}

void func_00185d70(RenderManagerAccessors *self, short a1) {
    if (self->field_404 != 0) {
        if (a1 < self->field_404->field_50) {
            self->field_404->field_98 = a1;
            func_1C9F00(self->field_404->field_3C);
        }
    }
}

int func_00185dc0(RenderManagerAccessors *self, int a1) {
    if (self->field_1C8 == 7) {
        return 0;
    }
    if (a1 != 0 || func_1880E0()) {
        return func_190AF0(self->field_1AC);
    }
    return 0;
}

SurfaceEntry *func_00185e20(RenderManagerAccessors *self, int a1) {
    if (self->field_1FC == 0) {
        return 0;
    }
    return &self->field_1FC[a1];
}
}

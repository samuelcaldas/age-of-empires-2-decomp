#pragma exceptions off

#include "render_manager_coords.h"

extern "C" {
void *func_00185e50(RenderManagerCoords *self, int a1) {
    if (self->field_84 != 0) {
        switch (a1) {
        case 0:
            return self->field_84;
        default:
            return 0;
        }
    }
    return 0;
}

void *func_00185e70(RenderManagerCoords *self, int a1) {
    if (self->field_90 == 0) {
        return 0;
    }
    if (a1 >= 0) {
        if (a1 < self->field_8C) {
            goto found;
        }
    }
    return 0;
found:
    return self->field_90[a1];
}

void func_00185ec0(RenderManagerCoords *self) {
    func_190C40(self->field_1AC);
    if (self->field_404 != 0) {
        self->field_404->field_30 = 1;
    }
}

void func_00185f00(RenderManagerCoords *self, int a1, int a2) {
    self->field_B20 = func_185DC0(self, 1);
    if (a1 != self->field_B20) {
        if (a1 != 0) {
            self->field_B24 = a2;
        } else {
            self->field_B24 = 0;
        }
        self->Method20();
    }
}

void func_00185f80(void *unused, int flags, unsigned int coords,
                   POINT *pt, int *b1, int *b2, int *b3, int *b4) {
    (void)unused;
    pt->x = coords & 0xFFFF;
    pt->y = (coords >> 16) & 0xFFFF;
    if (pt->x > 60000) {
        pt->x -= 65536;
    }
    if (pt->y > 60000) {
        pt->y -= 65536;
    }
    *b1 = flags & 1;
    *b2 = flags & 2;
    *b3 = flags & 8;
    *b4 = flags & 4;
}
}

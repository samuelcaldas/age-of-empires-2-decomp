#pragma exceptions off

#include "render_manager_surfaces.h"

extern "C" {
int func_001857b0(RenderManagerSurfaces *self) {
    self->field_80 = 1;
    void *obj;
    if ((obj = func_25F2B0(0x14)) != 0) {
        func_25D6D0(obj, D_004919F0, 0x124E);
    }
    self->field_84 = obj;
    return 1;
}

int func_00185810(RenderManagerSurfaces *self) {
    self->field_1F8 = 6;
    self->field_1FC = (SurfaceEntry *)func_1143F8(self->field_1F8, 0xC);
    if (self->field_1FC == 0) {
        return 0;
    }

    void *s0 = func_1ABA00(self->field_70);
    if (s0 == 0) {
        return 0;
    }

    for (short i = 0; i < self->field_1F8; i++) {
        int s2;
        switch (i) {
            case 0: s2 = 1; break;
            case 1: s2 = 2; break;
            case 2: s2 = 0; break;
            case 3: s2 = 5; break;
            case 4: s2 = 4; break;
            case 5: s2 = 3; break;
            default: s2 = 0; break;
        }

        int s3 = func_2257A0(s0, s2);
        self->field_1FC[i].f0 = s2;
        self->field_1FC[i].f4 = func_223000(s2);
        self->field_1FC[i].f8 = func_223040(s2);
        func_2257A0(s0, s3);
    }

    func_1ABA70(self->field_70);
    return 1;
}
}

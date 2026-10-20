#pragma exceptions off

#include "render_manager_status.h"

extern "C" {

char *func_00189c80(RenderManagerStatus *self, int a1) {
    if (func_191050(self, a1) != 0) {
        D_004E3180->GetString(0x4B1, D_00568560, 0x20);
        return D_00568560;
    }
    if (func_190FF0(self, a1) == 0) {
        D_004E3180->GetString(0x4B2, D_00568560, 0x20);
        return D_00568560;
    }
    unsigned int val = self->field_2038[a1];
    if (val < 4) {
        D_004E3180->GetString(0x4B3, D_00568560, 0x20);
        return D_00568560;
    }
    if (val < self->field_10C8) {
        D_004E3180->GetString(0x4B4, D_00568560, 0x20);
        return D_00568560;
    }
    if (!(val < self->field_10C8)) {
        D_004E3180->GetString(0x4B0, D_00568560, 0x20);
        return D_00568560;
    }
    func_11A498(D_00568560, D_00491BA8);
    return D_00568560;
}

void func_00189e00(RenderManagerStatus *self, int a1) {
    func_19A1E0(self->field_1600, a1);
    func_19A1D0(self->field_1600, a1);
}

void func_00189e40(RenderManagerStatus *self) {
    func_19A1F0(self->field_1600);
}

void func_00189e50() {
}

void func_00189e60() {
}

}

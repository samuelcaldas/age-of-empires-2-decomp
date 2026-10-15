#pragma exceptions off
#include "unit_action_movement.h"

void func_00266C50(ActionMovement *self) {
    if (self->m_field18 == 0) {
        return;
    }

    if (func_3675D0() > 0.0f) {
        func_1EDF20(D_004E3244, self);
    }

    if (self->m_field54 != 0) {
        func_1EE720(D_004E3244, self);
    }

    void *sub = *(void**)((char*)*(void**)((char*)D_004E3180 + 0x404) + 0x3C);
    func_1D0B40(sub, self->m_field18, self);

    self->Method62(self->m_world, 0, -1, 0);

    self->m_field18 = 0;
    self->m_x = -1.0f;
    self->m_y = -1.0f;
    self->m_z = -1.0f;

    func_205F70(self->m_world, self);
    self->m_field37 = 0;
}

#pragma exceptions off
#include "unit_action_lifecycle.h"

void func_0026BA70(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    func_26AD60(self, 1);
    func_26AD30(self, 2);
    func_00272E80(self);
    if (self->m_world != 0) {
        func_207C30(self->m_world, self->m_field24, -1);
    }
    func_0026E560(self);
    func_00270A20(self);
    func_0026E940(self);
    func_0030FF80(self);
    func_1ECD00(self, self);
    func_26AD60(self, 2);
}

void func_0026BDF0(ActionRebind *self, void *a1, void *a2) {
    if (self == 0) {
        return;
    }
    (void)a1; (void)a2;
    func_00273130(self);
    func_00226D90(self);
    func_26AD30(self, 4);
    func_00226D90(self);
    if (self->m_world != 0) {
        func_00138BA0(self->m_world, self);
    }
    func_001143F8(self);
    func_26AD30(self, 8);
}

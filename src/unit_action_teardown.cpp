#pragma exceptions off
#include "unit_action_teardown.h"

void func_0026C1F0(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    self->Method29();
    self->Method34(-1);
}

void func_0026C2D0(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    self->Method29();
}

void func_0026C360(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    if (self->m_field39 == 2) {
        return;
    }
    func_00139E10(self);
    func_1ECD00(self, self);
    func_26AD60(self, 8);
}

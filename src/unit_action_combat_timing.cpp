#pragma exceptions off
#include "unit_action_combat_timing.h"

void func_0026C3C0(ActionRebind *self, float delta) {
    if (self == 0) {
        return;
    }
    void *field4 = self->m_field4;
    self->m_field30 += delta;
    float interval = *(float*)((char*)field4 + 0x30);
    if (self->m_field30 >= interval) {
        func_002E03F0(self, field4);
        func_00277D50(self, delta);
        self->m_field30 -= interval;
    }
}

int func_0026C480(ActionRebind *self, void *target, float range) {
    (void)range;
    if (self == 0 || target == 0) {
        return 0;
    }
    func_00277E50(self, target);
    if (func_002E03F0(self, target) != 0) {
        func_00277E50(self, target);
        return 1;
    }
    return 0;
}

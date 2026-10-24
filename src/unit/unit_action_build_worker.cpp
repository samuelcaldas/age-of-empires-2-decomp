#pragma exceptions off
#include "unit_action_build_worker.h"

void func_0026E9C0(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    if (func_26AD20(self, 0x800) == 0) {
        return;
    }
    func_26AD60(self, 0x800);

    if (self->m_field4 == 0) {
        return;
    }
    short mtype = *(short*)((char*)self->m_field4 + 0xE);
    if (mtype != 0x33 && mtype != 0x36) {
        if (*(void**)((char*)self + 0x130) != 0 && mtype != 0x27) {
            return;
        }
    }

    int ty = func_123350(self->m_y);
    int tx = func_123350(self->m_x);

    if (self->m_world != 0) {
        func_1ecbf0(self->m_world, tx, ty, self);
        func_26AD30(self, 0x8000);
        func_1EDA80(self->m_world, self);
    }
}

void func_0026EAB0(ActionRebind *self, float val) {
    if (self == 0) {
        return;
    }

    ActionRebind **sub_actions = (ActionRebind**)((char*)self + 0x134);
    for (int i = 0; i < 4; ++i) {
        ActionRebind *child = sub_actions[i];
        if (child != 0) {
            func_0026EAB0(child, val);
        }
    }

    if (self->m_field39 == 0 && self->m_field30 >= 1.0f) {
        if (func_26AD20(self, 0x800) != 0) {
            func_0026E9C0(self);
            func_271220(self, 0);
        }
    }
}

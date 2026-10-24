#pragma exceptions off
#include "tactical_ai_action_manager.h"

void *func_00307320(TacticalActionManagerObj *self) {
    func_3285d0(self);
    self->m_vtable = &D_4DE780;
    self->m_field19C = 0;
    self->m_field1A0 = 0;
    self->m_field194 = 0;
    self->m_field1A4 = 0;
    self->m_field198 = 0;
    self->m_field1D0 = -1;
    self->m_field1B1 = 0;
    self->m_field1B2 = 0;
    self->m_field1B3 = 0;
    self->m_field1A8 = 0;
    self->m_field1AC = 0;
    self->m_field1B0 = 0;

    for (int i = 0; i < 5; i++) {
        self->m_array1[i] = 0;
        self->m_array2[i] = 0;
        self->m_array3[i] = 0;
        self->m_array4[i] = 0;
        self->m_array5[i] = 0;
        self->m_array6[i] = 0;
    }
    return self;
}

void *func_003073C0(TacticalActionManagerObj *self, int flags) {
    if (self) {
        self->m_vtable = &D_4DEBF0;
        func_1a2cf0(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

void func_00307420(TacticalActionManagerObj *self, int arg1) {
    TacticalActionManagerObj *s1 = self;
    func_1a34d0(s1);
    int s0 = arg1;
    if (s0 != 0 && s1->m_field88 != 0 && s1->m_field84 != 0) {
        int val = *(int *)((char *)D_004E3180 + 456);
        if ((unsigned int)val - 4U < 2U) {
            func_242fc0(s1->m_field40, s0);
            return;
        }
    } else {
        func_118de0(D_004D1930);
    }
}

#include "tactical_ai_combat_subsystem_controller_mode.h"

#ifdef __MWERKS__
#pragma divbyzerocheck on
#endif

void func_00329350(CombatSubsystemControllerInstance *self, int a1) {
    if (a1 == self->m_field_3410) {
        return;
    }
    self->m_field_3410 = a1;
    if (self->m_field_341C == 0) {
        return;
    }
    if (func_1880D0(D_004E3180) == 0) {
        return;
    }

    if (self->m_field_3410 != 0) {
        unsigned int s1 = func_184C10(D_004E3180);
        if (s1 == 0) {
            s1 = 1;
        }
        unsigned int v0 = func_184BD0(D_004E3180, 1);
        if (v0 / s1 > 40) {
            self->m_field_3424 = a1 = 1;
            if (func_185DC0(D_004E3180) == 0) {
                func_185F00(D_004E3180, 1, 1);
                self->m_field_3420 = 1;
            }
        }
    } else {
        if (self->m_field_342C != 0) {
            return;
        }
        self->m_field_3424 = 0;
        if (self->m_field_3420 != 0) {
            func_185F00(D_004E3180, 0, 0);
            self->m_field_3420 = 0;
        }
    }
}

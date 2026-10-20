#include "tactical_ai_combat_subsystem_controller_pulse_reset.h"

void func_0032C480(CombatSubsystemControllerInstance *self) {
    if (self->m_field_341C != 0) {
        if (func_1880D0(D_004E3180) != 0) {
            if (self->m_field_190 == 2) {
                self->m_field_3424 = 0;
                if (self->m_field_3420 != 0) {
                    func_185F00(D_004E3180, 0, 0);
                    self->m_field_3420 = 0;
                }
            }
        }
    }
    func_00324470(self);
}

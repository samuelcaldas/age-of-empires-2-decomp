#include "tactical_ai_combat_subsystem_controller_state.h"

int func_00329FA0(CombatSubsystemControllerInstance *self) {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) {
                return 0;
            }
        }
    }

    int field_1CC = D_004E3180->m_field_1CC;
    if (field_1CC == 8 || field_1CC == 7 || field_1CC == 1) {
        self->m_vtable->func_28(self, 1);
    }
    return 1;
}

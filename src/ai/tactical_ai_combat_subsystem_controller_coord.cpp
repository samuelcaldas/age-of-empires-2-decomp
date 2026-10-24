#include "tactical_ai_combat_subsystem_controller_coord.h"

static inline bool check_coord_gate() {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032BE50(CombatSubsystemControllerInstance *self, int a1, int a2) {
    if (!check_coord_gate()) {
        return 0;
    }

    if (func_185DC0(D_004E3180) != 0) {
        if (self->m_field_190 != 0) {
            self->m_vtable->func_110(self);
        } else {
            func_1F65A0(self);
        }
        return 0;
    }

    if (self->m_field_190 != 0) {
        self->m_vtable->func_10C(self, a1, a2);
        return 1;
    }

    return 0;
}

#include "tactical_ai_combat_subsystem_controller_selection.h"

static inline bool check_selection_gate() {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032AAD0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4) {
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    if (!check_selection_gate()) {
        return 0;
    }

    if (self->m_field_190 != 0) {
        self->m_vtable->func_110(self);
        return 1;
    }

    func_1F65A0(self);

    if (func_185DC0(D_004E3180) != 0) {
        return 0;
    }

    func_225590(18);

    return 1;
}

#include "tactical_ai_combat_subsystem_controller_event.h"

static inline bool check_event_gate() {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032A8F0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4) {
    if (!check_event_gate()) {
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

    int state = D_004E3180->m_field_1CC;
    if (state == 8 || state == 7 || state == 1) {
        self->m_vtable->func_28(self, 1);
        return 1;
    }

    if (state == 0) {
        return 1;
    }

    func_1F65A0(self);
    self->m_vtable->func_108(self, 2, self->m_field_E0, self->m_field_E4, a3, a4);
    self->m_vtable->func_10C(self, a1, a2);
    return 1;
}

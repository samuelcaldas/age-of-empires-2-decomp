#include "tactical_ai_combat_subsystem_controller_pulse.h"

int func_0032C320(CombatSubsystemControllerInstance *self) {
    int ret = func_00323860(self);
    if (ret != 0) {
        ViewObj *view = self->m_view;
        if (view != 0) {
            view->m_vtable->func_28(view, 1);
        }
    }

    if (self->m_field_341C == 0) {
        return ret;
    }

    if (func_1880D0(D_004E3180) == 0) {
        return ret;
    }

    if (self->m_field_190 != 2) {
        return ret;
    }

    int den = func_184C10(D_004E3180);
    if (den == 0) {
        den = 1;
    }
    int num = func_184BD0(D_004E3180, 1);
    unsigned int quotient = (unsigned int)num / (unsigned int)den;

    if (quotient < 81) {
        return ret;
    }

    self->m_field_3424 = 1;

    if (func_185DC0(D_004E3180) != 0) {
        return ret;
    }

    func_185F00(D_004E3180, 1, 1);
    self->m_field_3420 = 1;

    return ret;
}

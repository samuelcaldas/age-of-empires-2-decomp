#include "tactical_ai_combat_subsystem_controller_context.h"

static inline bool check_context_gate() {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032BF70(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0) {
    (void)a3;
    if (!check_context_gate()) {
        return 0;
    }

    if (self->m_field_190 != 0) {
        self->m_vtable->func_110(self);
        return 1;
    }

    func_1F65A0(self);

    if (D_004E3180->m_field_1CC == 20) {
        TargetObj *target = self->m_target;
        void *sub_ca8 = target ? (void*)target->m_sub_ca8 : 0;
        char buf[32];
        if (func_0032D400(self, 41, 2, a1, a2, buf, sub_ca8, 1) == 52) {
            ViewObj *view = *(ViewObj**)(buf + 12);
            if (view && view->m_vtable) {
                view->m_vtable->func_8C(view, -1);
            }
        }
        return 1;
    }

    if (func_185DC0(D_004E3180) != 0) {
        return 0;
    }

    func_225590(18);

    if (self->m_field_108 == 1 || self->m_field_108 == 2) {
        if (D_004E3180->m_sub_a0 && D_004E3180->m_sub_a0->m_val_a0 == 2) {
            int mode = D_004E3180->m_mode;
            if (mode != 5 && mode != 7) {
                if (D_004E3180->m_field_1CC != 0) {
                    if (D_004E3180->m_field_1CC == 21) {
                        func_31A720(self, -1, -1, -1, -1);
                        self->m_vtable->func_28(self, 1);
                    }
                    D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
                    return 1;
                }
                if (t0 == 0) {
                    self->m_vtable->func_12C(self, a1, a2, 1, -1);
                    return 1;
                }
                char buf2[32];
                if (func_0032D400(self, 40, 0, a1, a2, buf2, 0, 1) == 51) {
                    func_0032E580(self, buf2);
                    func_0032E6B0(self, 2962, 0, 0, 0);
                }
                return 1;
            }
            return 1;
        }
    }

    if (D_004E3180->m_mode == 7) {
        return 1;
    }

    func_0032E820(self);
    if (D_004E3180->m_field_1CC != 0) {
        D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
    } else {
        func_205EE0(self->m_target);
        self->m_vtable->func_28(self, 1);
    }
    return 1;
}

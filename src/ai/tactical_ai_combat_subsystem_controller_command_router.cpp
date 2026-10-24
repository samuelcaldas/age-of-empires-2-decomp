#include "tactical_ai_combat_subsystem_controller_command_router.h"

int func_0032E220(CombatSubsystemControllerInstance *self, int a1, int a2, int a3) {
    func_0032E820(self);

    if (D_004E2EA0 == 0) {
        return 0;
    }

    if (self == 0 || self->m_target == 0 || self->m_target->m_sub6960 == 0 ||
        self->m_target->m_sub6960->m_vtable == 0 ||
        self->m_target->m_sub6960->m_vtable->func_168 == 0) {
        return 0;
    }

    TargetObj *target = self->m_target;
    char sp120[8];
    char sp126[8];
    if (target->m_sub6960->m_vtable->func_168(target, sp120, sp126, -1, -1, -1, -1, 0) == 0) {
        return 0;
    }

    int s2 = 0;
    void *entity = 0;
    char sp116[8];
    if (self->m_vtable != 0 && self->m_vtable->func_13C != 0) {
        entity = self->m_vtable->func_13C(self, a1, a2, sp116, -1, 0, 0, 0);
    }

    if (entity != 0) {
        if (target->m_sub6960->m_vtable->func_184 != 0) {
            s2 = target->m_sub6960->m_vtable->func_184(target, entity) & 0xFF;
        }

        if (s2 != 0) {
            sub_31A160(self, 1500, a3);
        }

        if (D_004E3180 != 0 && D_004E3180->m_vtable != 0 && D_004E3180->m_vtable->func_18 != 0) {
            D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
        }

        return s2;
    }

    char buf[64];
    int pick_res = func_0032D400(self, 40, 0, a1, a2, buf, 0, 1);

    if ((pick_res & 0xFF) == 51) {
        func_0032E580(self, buf);

        if (target->m_sub6960->m_vtable->func_184 != 0) {
            s2 = target->m_sub6960->m_vtable->func_184(target, 0) & 0xFF;
        }

        if (s2 != 0) {
            func_0032E6B0(self, 2961, 0, -1, 1);
        }

        if (self->m_vtable != 0 && self->m_vtable->func_28 != 0) {
            self->m_vtable->func_28(self, 1);
        }
    }

    if (D_004E3180 != 0 && D_004E3180->m_vtable != 0 && D_004E3180->m_vtable->func_18 != 0) {
        D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
    }

    return s2;
}

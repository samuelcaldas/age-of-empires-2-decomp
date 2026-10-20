#include "tactical_ai_combat_subsystem_controller_terrain_action.h"

int func_0032E0E0(CombatSubsystemControllerInstance *self, int a1, int a2) {
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
    char sp104[8];
    char sp110[8];
    if (target->m_sub6960->m_vtable->func_168(target, sp104, sp110, -1, -1, -1, -1, 0) == 0) {
        return 0;
    }

    char buf[64];
    int pick_res = func_0032D400(self, 42, 1, a1, a2, buf, 0, 1);
    int s1 = 0;

    if ((pick_res & 0xFF) != 50) {
        func_0032E580(self, buf);

        if (target->m_sub6960->m_vtable->func_180 != 0) {
            s1 = target->m_sub6960->m_vtable->func_180(target, 0) & 0xFF;
        }

        if (s1 != 0) {
            func_0032E6B0(self, 2961, 0, -1, 1);
        }
    }

    if (D_004E3180 != 0 && D_004E3180->m_vtable != 0 && D_004E3180->m_vtable->func_18 != 0) {
        D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
    }

    return s1;
}

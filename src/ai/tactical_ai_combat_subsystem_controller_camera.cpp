#include "tactical_ai_combat_subsystem_controller_camera.h"

static inline bool check_camera_gate() {
    if (func_185DC0(D_004E3180) != 0) return false;
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032BCE0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4) {
    if (!check_camera_gate()) {
        return 0;
    }

    if (D_004E3180->m_field_1CC == 19) {
        TargetObj *target = self->m_target;
        if (target != 0 && target->m_sub_ca8 != 0) {
            func_205EE0(target);
            self->m_vtable->func_28(self, 1);
            D_004E3180->m_vtable->func_18(D_004E3180, 19, 1);
            self->m_vtable->func_108(self, 9, a1, a2, a3, a4);
            return 1;
        }
    }

    func_1F6510(self);
    return 1;
}

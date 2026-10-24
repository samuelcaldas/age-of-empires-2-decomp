#include "tactical_ai_combat_subsystem_controller_action.h"

static inline bool check_action_gate() {
    if (func_185DC0(D_004E3180) != 0) return false;
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return true;
}

int func_0032A060(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int a4) {
    (void)a3;
    (void)a4;
    if (!check_action_gate()) {
        return 0;
    }

    int state = D_004E3180->m_field_1CC;
    switch (state) {
        case 18: {
            unsigned char buf[64];
            TargetObj *target = self->m_target;
            TargetSubCA8 *sub_ca8 = target ? target->m_sub_ca8 : 0;
            int res = func_0032D400(self, 41, 0, a1, a2, buf, sub_ca8);
            if ((res & 0xFF) == 52) {
                func_205EE0(self->m_target);
                void *item = *(void**)(buf + 12);
                func_205CA0(self->m_target, item, 1);
                self->m_vtable->func_28(self, 1);
            }
            break;
        }
        case 1: {
            unsigned char buf[64];
            int res = func_0032D400(self, 40, 0, a1, a2, buf, 0);
            if ((res & 0xFF) == 51) {
                func_0032E580(self, buf);
            }
            break;
        }
        default:
            break;
    }

    return 1;
}

#include "tactical_ai_combat_subsystem_controller_formation.h"

int func_0032C600(CombatSubsystemControllerInstance *self, int a1, int a2, int a3) {
    if (D_004E2EA0 == 0) {
        return 0;
    }

    char buf[128];
    if (func_0032D400(self, 40, 0, a1, a2, buf, 0, 1) != 51) {
        return 0;
    }

    func_0032E580(self, buf);

    if (D_004E3180 != 0) {
        func_186010(D_004E3180, a3);
        if (self->m_target != 0) {
            func_1AAB30(self->m_target, a3);
            func_26A680(self->m_target);
            func_1830E0(self->m_target, a3);
            func_262FA0(self->m_target);
            func_332E60(self->m_target);
        }
    }

    return 1;
}

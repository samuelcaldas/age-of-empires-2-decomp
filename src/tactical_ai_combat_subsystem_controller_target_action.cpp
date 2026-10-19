#include "tactical_ai_combat_subsystem_controller_target_action.h"

int func_0032CBA0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3) {
    func_0032E820(self);

    if (D_004E2EA0 == 0) {
        return 0;
    }

    (void)a3;
    char buf[128];
    if (func_0032D400(self, 40, 0, a1, a2, buf, 0, 1) != 51) {
        return 0;
    }

    func_0032E580(self, buf);
    func_0032E6B0(self, 2962, 0, 0, 0);

    return 1;
}

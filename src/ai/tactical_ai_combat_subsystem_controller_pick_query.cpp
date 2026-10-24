#include "tactical_ai_combat_subsystem_controller_pick_query.h"

int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag) {
    int m = mode & 0xFF;

    if (m == 41) {
        char *b = (char*)buf;
        if (b != 0) {
            for (int i = 0; i < 20; ++i) {
                b[i] = 0;
            }
        }

        int res = 0;
        if (self != 0 && self->m_vtable != 0 && self->m_vtable->func_120 != 0) {
            if ((flag & 0xFF) == 0) {
                res = self->m_vtable->func_120(self, x, y, 0, 40, 15, 4, 1);
            } else {
                res = self->m_vtable->func_120(self, x, y, 10, 30, 15, 4, 1);
            }
        }

        if (res == 0) {
            return 50;
        }

        if (res == 1) {
            return 52;
        }

        return 51;
    }

    if (m == 42) {
        if (func_0032D400(self, 41, flag, x, y, buf, target_sub, 1) == 52) {
            return 52;
        }
    }

    int ret = sub_31C7F0(self, 40, flag, x, y, buf, target_sub, recurse_flag);
    return ret & 0xFF;
}

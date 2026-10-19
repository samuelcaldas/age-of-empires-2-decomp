#include "tactical_ai_combat_subsystem_controller_proximity_query.h"

int func_0032DA90(CombatSubsystemControllerInstance *self, int x, int y, int *out_status, int a4, int a5, int a6, int a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    if (out_status != 0) {
        *out_status = 0;
    }

    if (self == 0) {
        return 0;
    }

    if (self->m_vtable == 0) {
        return 0;
    }

    if (self->m_vtable->func_120 == 0) {
        return 0;
    }

    int res = self->m_vtable->func_120(self, x, y, 10, 30, 15, 4, 1);
    if (res == 0) {
        return 0;
    }

    if (out_status != 0) {
        *out_status = 1;
    }

    return 1;
}

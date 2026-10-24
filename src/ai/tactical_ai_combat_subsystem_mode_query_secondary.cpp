#include "tactical_ai_combat_subsystem_mode_query_secondary.h"

int func_00329070(CombatSubsystemMeshInstance *self, int a1, int a2) {
    if (D_004E2EA0 == 0) return 0;

    short s_3C;
    short s_3E;
    int s_38;
    int ret = 0;
    if (func_1A5010(self, a1, a2, &s_3C, &s_3E, &s_38) != 0) {
        Object120 *obj = self->m_obj_120;
        ret = (unsigned char)obj->m_vtable->func_B4(obj, 0, (float)s_3C + 0.5f, (float)s_3E + 0.5f);
        D_004E3180->m_vtable->func_18(D_004E3180, 0, 0);
    }

    return ret;
}

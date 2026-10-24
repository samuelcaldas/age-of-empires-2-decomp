#include "tactical_ai_combat_subsystem_mode_update.h"

static inline bool is_mode_supported(int mode) {
    bool v1 = (mode == 4 || mode == 6);
    bool v0 = (D_004E3180->m_mode == 7);
    return v1 || v0 || mode == 5;
}

static inline int dispatch_subtype(CombatSubsystemMeshInstance *self, int a1, int a2, int subtype) {
    if (subtype == 4) {
        self->m_vtable->func_11C(self, a1, a2);
        return 1;
    }
    if (subtype == 5) {
        self->m_vtable->func_120(self, a1, a2);
        return 1;
    }
    if (subtype == 0 && D_004E3180->m_sub28->m_state == 2) {
        if (self->m_vtable->func_118(self, a1, a2) != 0) return 1;
    }
    return 0;
}

int func_00328930(CombatSubsystemMeshInstance *self, int a1, int a2) {
    int mode = D_004E3180->m_mode;
    if (!is_mode_supported(mode)) return 0;

    if (self->m_active != 0) {
        func_1A5390(self);
        return 1;
    }

    func_1F65A0(self);

    if (func_185DC0(D_004E3180, 0) == 0) return 0;
    if (D_004E3180->m_mode == 5) return 0;

    int s_48;
    short s_4C;
    short s_4E;
    if (!func_1A5010(self, a1, a2, &s_4C, &s_4E, &s_48)) return 0;

    return dispatch_subtype(self, a1, a2, D_004E3180->m_subtype);
}

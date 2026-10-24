#include "tactical_ai_combat_subsystem_mode_processor.h"

static inline bool is_mode_supported(int mode) {
    bool v1 = (mode == 4 || mode == 6);
    bool v0 = (D_004E3180->m_mode == 7);
    return v1 || v0 || mode == 5;
}

static inline int process_state_2(CombatSubsystemMeshInstance *self, int a1, int a2, int flag) {
    SystemManager *mgr = D_004E3180;
    if (mgr->m_subtype != 0 || mgr->m_mode == 5) return 0;

    if (flag == 0) {
        if (self->m_vtable->func_118(self, a1, a2) == 0) return 0;
        return 1;
    }

    int s_58;
    short s_5C;
    short s_5E;
    if (!func_1A5010(self, a1, a2, &s_5C, &s_5E, &s_58)) return 1;

    Object120 *obj = self->m_obj_120;
    obj->m_vtable->func_DC(obj, (float)s_5C + 0.5f, (float)s_5E + 0.5f, 1.0f);
    return 1;
}

static inline int process_fallback(CombatSubsystemMeshInstance *self, SystemManager *mgr) {
    if (mgr->m_mode == 7) return 0;
    if (mgr->m_subtype != 0) {
        mgr->m_vtable->func_18(mgr, 0, 0);
    }
    func_205EE0(self->m_obj_120);
    return 0;
}

int func_00328D50(CombatSubsystemMeshInstance *self, int a1, int a2, int, int flag) {
    int mode = D_004E3180->m_mode;
    if (!is_mode_supported(mode)) return 0;

    if (self->m_active != 0) {
        func_1A5390(self);
        return 1;
    }

    func_1F65A0(self);

    if (func_185DC0(D_004E3180, 0) == 0) return 0;

    int type = self->m_type_108;
    if (type != 1 && type != 2) return 0;

    SystemManager *mgr = D_004E3180;
    if (mgr->m_sub28->m_state == 2) {
        return process_state_2(self, a1, a2, flag);
    }

    return process_fallback(self, mgr);
}

#include "tactical_ai_combat_subsystem_mode_dispatch_secondary.h"

static inline bool is_mode_supported(int mode, SystemManager *mgr) {
    bool v1 = (mode == 4 || mode == 6);
    bool v0 = (mgr->m_mode == 7);
    return v1 || v0 || mode == 5;
}

int func_00328C40(CombatSubsystemMeshInstance *self, int a1, int a2) {
    SystemManager *mgr = D_004E3180;
    int mode = mgr->m_mode;
    if (!is_mode_supported(mode, mgr)) {
        return 0;
    }

    if (func_185DC0(mgr, 0) != 0) {
        if (self->m_active != 0) {
            func_1A5390(self);
        } else {
            func_1F65A0(self);
        }
        return 0;
    }

    if (self->m_active != 0) {
        func_1A52D0(self, a1, a2);
        return 1;
    }

    return 0;
}

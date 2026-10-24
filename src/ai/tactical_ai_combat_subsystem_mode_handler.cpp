#include "tactical_ai_combat_subsystem_mode_handler.h"

static inline bool is_mode_valid(int mode, SystemManager *mgr) {
    bool v1 = (mode == 4 || mode == 6);
    bool v0 = (mgr->m_mode == 7);
    return v1 || v0 || mode == 5;
}

int func_00328B10(void *self, int a1, int a2) {
    if (func_185DC0(D_004E3180, 0) != 0) {
        return 0;
    }

    SystemManager *mgr = D_004E3180;
    int mode = mgr->m_mode;
    if (!is_mode_valid(mode, mgr)) {
        return 0;
    }

    if (mgr->m_sub28->m_state == 2) {
        if (mode == 4 || mode == 6 || mode == 7) {
            func_1F6510(self);
        }
        return 1;
    }

    func_1A5200(self, a1, a2);
    return 1;
}

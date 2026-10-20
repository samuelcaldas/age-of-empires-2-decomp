#include "tactical_ai_combat_subsystem_mode_filter.h"

static inline bool is_valid_mode(int mode, SystemManager *mgr) {
    bool v1 = (mode == 4 || mode == 6);
    bool v0 = (mgr->m_mode == 7);
    return v1 || v0 || mode == 5;
}

static inline bool is_check_subtype(int subtype) {
    if (subtype == 0x6F) return true;
    if (subtype == 0x6D) return false;
    if ((unsigned int)(subtype - 0x82) < 7) return false;
    return false;
}

int func_003286C0(void *self, int a1, int a2) {
    if (func_185DC0(D_004E3180, 0) != 0) return 0;
    SystemManager *mgr = D_004E3180;
    int mode = mgr->m_mode;
    if (!is_valid_mode(mode, mgr)) return 0;

    if (is_check_subtype(mgr->m_subtype) && mgr->m_sub28->m_state == 2) {
        func_1A5200(self, a1, a2);
        return 1;
    }

    if (mode == 4 || mode == 6 || mode == 7) {
        func_1F6510(self);
        return 1;
    }

    return 0;
}

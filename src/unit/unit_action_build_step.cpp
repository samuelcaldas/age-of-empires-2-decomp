#pragma exceptions off
#include "unit_action_build_step.h"

struct MasterStepLayout {
    char pad_0[0x145];
    unsigned char m_max_step;
    char pad_146[2];
    float m_limit;
};

struct ActionStepLayout {
    void *vtable;
    MasterStepLayout *m_master;
    char pad_8[0x120 - 8];
    float m_val;
};

int func_00270E70(ActionRebind *self) {
    ActionStepLayout *act = (ActionStepLayout*)self;
    MasterStepLayout *master = act->m_master;

    float val = act->m_val;
    float limit = master->m_limit;
    int step;
    if (limit < val) {
        step = func_123350(val);
    } else {
        step = func_123350(limit);
    }

    unsigned char max_step = master->m_max_step;
    if ((int)max_step < step) {
        step = (int)max_step;
    }

    if (step > 0) {
        step--;
    }
    return step;
}

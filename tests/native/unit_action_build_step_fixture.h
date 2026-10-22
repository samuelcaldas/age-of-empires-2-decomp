#ifndef UNIT_ACTION_BUILD_STEP_FIXTURE_H
#define UNIT_ACTION_BUILD_STEP_FIXTURE_H

#include <cstddef>
#include "unit_action_build_step.h"

struct DummyStepMaster {
    char pad_0[0x145];
    unsigned char m_max_step;
    char pad_146[2];
    float m_limit;
};

struct DummyStepAction {
    void *vtable;
    DummyStepMaster *m_master;
    char pad_8[0x120 - 8];
    float m_val;
};

#endif // UNIT_ACTION_BUILD_STEP_FIXTURE_H

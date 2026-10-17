#ifndef UNIT_ACTION_BUILD_CANCEL_TASK_FIXTURE_H
#define UNIT_ACTION_BUILD_CANCEL_TASK_FIXTURE_H

#include "unit_action_build_cancel_task.h"

struct DummyCancelAction {
    char pad_00[336];
    void *m_slots;
    char pad_154[2];
    unsigned char m_cap;
    unsigned char m_count;
};

#endif // UNIT_ACTION_BUILD_CANCEL_TASK_FIXTURE_H

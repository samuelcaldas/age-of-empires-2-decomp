#ifndef UNIT_ACTION_BUILD_TASK_REMOVE_FIXTURE_H
#define UNIT_ACTION_BUILD_TASK_REMOVE_FIXTURE_H

#include "unit_action_build_task_remove.h"

struct DummyRemoveAction {
    char pad_00[8];
    void *m_world;
    char pad_0C[320];
    void *m_field14C;
    void *m_slots;
    short m_field154;
    unsigned char m_cap;
    unsigned char m_count;
    unsigned char m_total;
    unsigned char m_generation;
};

#endif // UNIT_ACTION_BUILD_TASK_REMOVE_FIXTURE_H

#ifndef UNIT_ACTION_BUILD_HAS_TASKS_FIXTURE_H
#define UNIT_ACTION_BUILD_HAS_TASKS_FIXTURE_H

#include <cstddef>
#include "unit_action_build_has_tasks.h"

struct DummyTasksAction {
    void *vtable;
    char pad_4[0xCC - 4];
    void *m_listCC;
    char pad_d0[0x14C - 0xD0];
    void *m_list14C;
};

#endif // UNIT_ACTION_BUILD_HAS_TASKS_FIXTURE_H

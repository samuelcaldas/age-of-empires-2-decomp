#ifndef UNIT_ACTION_BUILD_QUEUE_CLEAR_FIXTURE_H
#define UNIT_ACTION_BUILD_QUEUE_CLEAR_FIXTURE_H

#include <cstddef>
#include "unit_action_build_queue_clear.h"

struct DummyQueueMaster {
    char pad[8];
    short m_type;
};

struct DummyQueueAction {
    void *vtable;
    DummyQueueMaster *m_master;
    char pad_8[0x12C - 8];
    void *m_list12C;
};

#endif // UNIT_ACTION_BUILD_QUEUE_CLEAR_FIXTURE_H

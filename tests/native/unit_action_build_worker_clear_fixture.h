#ifndef UNIT_ACTION_BUILD_WORKER_CLEAR_FIXTURE_H
#define UNIT_ACTION_BUILD_WORKER_CLEAR_FIXTURE_H

#include "unit_action_build_worker_clear.h"

struct DummyClearAction {
    char pad_00[8];
    void *m_world;
    char pad_0C[320];
    void *m_field14C;
    void *m_slots;
    short m_field154;
    char pad_156[1];
    unsigned char m_count;
    unsigned char m_total;
    unsigned char m_generation;
};

#endif // UNIT_ACTION_BUILD_WORKER_CLEAR_FIXTURE_H

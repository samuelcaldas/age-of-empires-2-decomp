#ifndef UNIT_ACTION_BUILD_WORKER_QUERY_FIXTURE_H
#define UNIT_ACTION_BUILD_WORKER_QUERY_FIXTURE_H

#include "unit_action_build_worker_query.h"

struct DummyQueryAction {
    char pad_00[336];
    void *m_slots;
    char pad_154[3];
    unsigned char m_count; // offset 343 (0x157)
};

#endif // UNIT_ACTION_BUILD_WORKER_QUERY_FIXTURE_H

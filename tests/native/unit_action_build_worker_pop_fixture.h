#ifndef UNIT_ACTION_BUILD_WORKER_POP_FIXTURE_H
#define UNIT_ACTION_BUILD_WORKER_POP_FIXTURE_H

#include "unit_action_build_worker_pop.h"

struct DummyPopAction {
    char pad_00[8];
    void *m_world;
    char pad_0C[324];
    void *m_slots;
    char pad_154[3];
    unsigned char m_count; // offset 343
    unsigned char m_total; // offset 344
    unsigned char m_generation; // offset 345
};

#endif // UNIT_ACTION_BUILD_WORKER_POP_FIXTURE_H

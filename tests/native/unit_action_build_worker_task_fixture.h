#ifndef UNIT_ACTION_BUILD_WORKER_TASK_FIXTURE_H
#define UNIT_ACTION_BUILD_WORKER_TASK_FIXTURE_H

#include "unit_action_build_worker_task.h"

struct DummyWorkerAction {
    char pad_00[8];
    void *m_world;
    char pad_0C[324];
    void *m_slots;
    char pad_154[2];
    unsigned char m_cap;
    unsigned char m_count;
    unsigned char m_total;
    unsigned char m_generation;
};

#endif // UNIT_ACTION_BUILD_WORKER_TASK_FIXTURE_H

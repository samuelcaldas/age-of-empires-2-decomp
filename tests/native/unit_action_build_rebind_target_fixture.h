#ifndef UNIT_ACTION_BUILD_REBIND_TARGET_FIXTURE_H
#define UNIT_ACTION_BUILD_REBIND_TARGET_FIXTURE_H

#include "unit_action_build_rebind_target.h"

struct DummyTargetMaster {
    unsigned char m_class;
};

struct DummyTarget {
    char pad_00[4];
    DummyTargetMaster *m_master;
    char pad_08[356];
    short m_worker_count; // offset 364
};

struct DummyRebindAction {
    char pad_00[364];
    short m_worker_count; // offset 364
};

#endif // UNIT_ACTION_BUILD_REBIND_TARGET_FIXTURE_H

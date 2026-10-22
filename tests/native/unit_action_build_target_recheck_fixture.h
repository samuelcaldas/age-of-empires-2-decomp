#ifndef UNIT_ACTION_BUILD_TARGET_RECHECK_FIXTURE_H
#define UNIT_ACTION_BUILD_TARGET_RECHECK_FIXTURE_H

#include <cstddef>
#include "unit_action_build_target_recheck.h"

typedef void* (*TargetCheckFn)(void *world, void *target_ba0);

struct DummyTargetCheckVTable2 {
    void *pad_slots[9];
    TargetCheckFn Method24;
};

struct DummyRecheckWorld {
    char pad_ba0[0xBA0];
    void *m_fieldBA0;
    char pad_ba4[0x1B30 - 0xBA4];
    DummyTargetCheckVTable2 *m_vtable1B30;
};

struct DummyRecheckAction {
    void *vtable;
    void *m_master;
    DummyRecheckWorld *m_world;
    char pad_c[0x39 - 0xC];
    unsigned char m_field39;
    char pad_3a[0x170 - 0x3A];
    float m_field170;
};

#endif // UNIT_ACTION_BUILD_TARGET_RECHECK_FIXTURE_H

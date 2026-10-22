#ifndef UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_FIXTURE_H
#define UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_FIXTURE_H

#include <cstddef>
#include "unit_action_build_check_target_status.h"

typedef void* (*TargetCheckFn)(void *world, void *target_ba0);

struct DummyStatusVTable {
    void *pad_slots[9];
    TargetCheckFn Method24;
};

struct DummyStatusPlayer {
    char pad_00[0xBA0];
    void *m_fieldBA0;
    char pad_ba4[0x1B30 - 0xBA4];
    DummyStatusVTable *m_vtable1B30;
};

struct DummyStatusWorld {
    char pad_00[0x54];
    DummyStatusPlayer **m_players;
};

struct DummyStatusActor {
    char pad_00[0xB98];
    DummyStatusWorld *m_world;
    char pad_b9c[0xBA0 - 0xB9C];
    void *m_fieldBA0;
    char pad_ba4[0x1B30 - 0xBA4];
    DummyStatusVTable *m_vtable1B30;
};

struct DummyStatusMaster {
    char pad_00[0xE];
    short m_fieldE;
    char pad_10[0x1A2 - 0x10];
    short m_field1A2;
};

struct DummyStatusAction {
    void *vtable;
    DummyStatusMaster *m_master;
    DummyStatusActor *m_actor;
};

#endif // UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_FIXTURE_H

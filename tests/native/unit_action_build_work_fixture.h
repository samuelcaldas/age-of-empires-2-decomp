#ifndef UNIT_ACTION_BUILD_WORK_FIXTURE_H
#define UNIT_ACTION_BUILD_WORK_FIXTURE_H

#include <cstddef>
#include "unit_action_build_work.h"

struct DummyWorkMaster {
    char pad[0x1A2];
    short m_field1A2;
};

struct DummyWorkSubsystem {
    char pad[0x13C];
    void (*Method13C)(void *actor, short field24);
    void (*Method140)(void *actor, short field24);
};

struct DummyWorkWorld {
    char pad[0xAC];
    float m_delta_time;
};

struct DummyWorkActor {
    char pad_00[0xB98];
    DummyWorkWorld *m_world;
    char pad_b9c[0x1B30 - (0xB98 + sizeof(void*))];
    DummyWorkSubsystem *m_subsystem;
};

struct DummyWorkAction {
    void *vtable;
    DummyWorkMaster *m_master;
    DummyWorkActor *m_actor;
    char pad_0c[0x24 - 12];
    short m_field24;
    char pad_26[0x39 - (0x24 + 2)];
    unsigned char m_field39;
    char pad_3a[0x174 - (0x39 + 1)];
    float m_timer174;
};

#endif // UNIT_ACTION_BUILD_WORK_FIXTURE_H

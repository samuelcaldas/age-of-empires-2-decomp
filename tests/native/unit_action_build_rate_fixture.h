#ifndef UNIT_ACTION_BUILD_RATE_FIXTURE_H
#define UNIT_ACTION_BUILD_RATE_FIXTURE_H

#include "unit_action_build_rate.h"

struct DummyResourceSlot {
    short m_resource_id;
    short m_amount;
    unsigned char m_mode;
    char pad_05;
};

struct DummyMasterUnit {
    char pad_00[8];
    short m_type;
    char pad_0A[290];
    DummyResourceSlot m_slots[3];
};

struct DummySubActionVTable {
    char pad_00[132];
    void *m_method84;
};

struct DummySubAction {
    DummySubActionVTable *vtable;
};

struct DummyPlayerVTable {
    char pad_00[124];
    void *m_method7C;
};

struct DummyPlayer {
    char pad_00[2976];
    int m_player_count;
    char pad_BA0[6960 - 2980];
    DummyPlayerVTable *m_vtable;
};

struct DummyChildAction {
    char pad_00[48];
    float m_time;
};

struct DummyAction {
    char pad_00[4];
    DummyMasterUnit *m_master;
    DummyPlayer *m_world;
    char pad_0C[36];
    float m_time;
    char pad_34[7];
    unsigned char m_flag59;
    char pad_3C[244];
    DummySubAction *m_p304;
    DummyChildAction *m_children[4];
};

#endif // UNIT_ACTION_BUILD_RATE_FIXTURE_H

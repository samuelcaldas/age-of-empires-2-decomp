#ifndef UNIT_ACTION_BUILD_CHILD_UPDATE_FIXTURE_H
#define UNIT_ACTION_BUILD_CHILD_UPDATE_FIXTURE_H

#include "unit_action_build_child_update.h"

struct DummySubObject {
    void *vtable;
    char pad_04[42];
    unsigned char m_param46;
};

struct DummyChildMaster {
    char pad_00[200];
    void *m_interf;
};

struct DummyTargetMaster {
    unsigned char m_class;
};

struct DummyTargetUnit {
    char pad_00[4];
    DummyTargetMaster *m_master;
};

struct DummyChildUnit {
    void *vtable;
    DummyChildMaster *m_master;
};

struct DummyWorldObj {
    char pad_00[2968];
    void *m_b98;
};

struct DummySelfAction {
    char pad_00[8];
    DummyWorldObj *m_world;
    char pad_0C[24];
    short m_field24;
    char pad_26[38];
    float m_z;
    char pad_50[267];
    unsigned char m_flag15B;
    float m_target_x;
    float m_target_y;
    char pad_164[4];
    short m_field168;
};

#endif // UNIT_ACTION_BUILD_CHILD_UPDATE_FIXTURE_H

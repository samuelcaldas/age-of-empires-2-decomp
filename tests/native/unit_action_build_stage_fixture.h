#ifndef UNIT_ACTION_BUILD_STAGE_FIXTURE_H
#define UNIT_ACTION_BUILD_STAGE_FIXTURE_H

#include "unit_action_build_stage.h"

struct DummyMaster {
    char pad_00[8];
    short m_unit_class; // offset 8
};

struct DummyTarget {
    char pad_00[0x39];
    unsigned char m_max_step; // offset 0x39 (57)
};

struct DummySubVTable {
    char pad_00[12];
    void *m_method12; // offset 12
    char pad_16[20];
    void *m_method36; // offset 36
};

struct DummyZone {
    char pad_00[8];
    DummySubVTable *m_vtable; // offset 8
};

struct DummyAction {
    void *vtable;
    DummyMaster *m_field4;
    void *m_world;
    DummyZone *m_fieldC;
    DummyTarget *m_field10;
};

#endif // UNIT_ACTION_BUILD_STAGE_FIXTURE_H

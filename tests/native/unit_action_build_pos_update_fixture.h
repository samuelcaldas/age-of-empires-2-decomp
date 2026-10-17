#ifndef UNIT_ACTION_BUILD_POS_UPDATE_FIXTURE_H
#define UNIT_ACTION_BUILD_POS_UPDATE_FIXTURE_H

#include "unit_action_build_pos_update.h"

struct DummyMasterUnit {
    char pad_00[32];
    float m_ext_x;
    float m_ext_y;
};

struct DummyMapContainer {
    char pad_00[60];
    void *m_map;
};

struct DummyWorld {
    char pad_00[2968];
    DummyMapContainer *m_container;
};

struct DummyAction {
    char pad_00[4];
    DummyMasterUnit *m_master;
    DummyWorld *m_world;
    char pad_0C[12];
    int m_field18;
    char pad_1C[40];
    float m_pos_x;
    float m_pos_y;
    char pad_4C[122];
    char m_fieldC6;
    char m_fieldC7;
    char pad_C8[104];
    void *m_p304;
};

#endif // UNIT_ACTION_BUILD_POS_UPDATE_FIXTURE_H

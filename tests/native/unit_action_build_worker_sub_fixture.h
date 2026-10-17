#ifndef UNIT_ACTION_BUILD_WORKER_SUB_FIXTURE_H
#define UNIT_ACTION_BUILD_WORKER_SUB_FIXTURE_H

#include "unit_action_build_worker_sub.h"

struct DummyTargetMaster {
    unsigned char m_unit_class; // offset 0
    char pad_01[13];
    short m_worker_type;        // offset 14 (0xE)
};

struct DummyTarget {
    char pad_00[4];
    DummyTargetMaster *m_field4;// offset 4
    char pad_08[280 - 8];
    unsigned char m_flag118;    // offset 280 (0x118)
};

struct DummyWorldNode {
    char pad_00[28];
    float m_rate;               // offset 28 (0x1C)
};

struct DummyWorld {
    char pad_00[2981];
    unsigned char m_flagBA5;    // offset 2981 (0xBA5)
    char pad_BA6[6];            // 2982..2987
    DummyWorldNode *m_nodeBAC;  // offset 2988 (0xBAC)
};

struct DummyAction {
    char pad_00[8];
    DummyWorld *m_world;        // offset 8
    char pad_0C[364 - 12];
    short m_worker_count;       // offset 364 (0x16C)
    short m_building_count;     // offset 366 (0x16E)
};

#endif // UNIT_ACTION_BUILD_WORKER_SUB_FIXTURE_H

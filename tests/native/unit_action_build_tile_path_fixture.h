#ifndef UNIT_ACTION_BUILD_TILE_PATH_FIXTURE_H
#define UNIT_ACTION_BUILD_TILE_PATH_FIXTURE_H

#include <cstddef>
#include "unit_action_build_tile_path.h"

struct DummyPathMaster {
    unsigned char m_class;
    char pad_1[0x1F];
    float m_radius;
};

struct DummyPathUnit {
    void *vtable;
    DummyPathMaster *m_master;
    char pad_8[0x44 - 8];
    float m_x;
    float m_y;
};

struct DummyPathTile {
    char pad_0[0xD];
    unsigned char m_unit_count;
    char pad_e[0x14 - 0xE];
    DummyPathUnit **m_units;
    char pad_18[28 - 0x18];
};

struct DummyPathZone {
    void *vtable;
    int m_field4;
    int m_width;
    int m_height;
    char pad_10[0x8E8C - 0x10];
    DummyPathTile **m_grid;
};

struct DummyPathWorld {
    char pad_3c[0x3C];
    DummyPathZone *m_zone;
};

struct DummyPathActor {
    char pad_b98[0xB98];
    DummyPathWorld *m_world;
};

struct DummyPathAction {
    void *vtable;
    DummyPathMaster *m_master;
    DummyPathActor *m_actor;
    char pad_c[0x44 - 0xC];
    float m_x;
    float m_y;
};

#endif // UNIT_ACTION_BUILD_TILE_PATH_FIXTURE_H

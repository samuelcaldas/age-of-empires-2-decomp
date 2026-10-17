#ifndef UNIT_ACTION_BUILD_TILE_NOTIFY_FIXTURE_H
#define UNIT_ACTION_BUILD_TILE_NOTIFY_FIXTURE_H

#include "unit_action_build_tile_notify.h"

struct DummyGrid {
    char pad_00[1628];
    void *m_target;
};

struct DummyLayer {
    char pad_00[68];
    DummyGrid *m_grid;
};

struct DummyWorld {
    char pad_00[2968];
    DummyLayer *m_layer;
};

struct DummyAction {
    char pad_00[8];
    DummyWorld *m_world;
};

#endif // UNIT_ACTION_BUILD_TILE_NOTIFY_FIXTURE_H

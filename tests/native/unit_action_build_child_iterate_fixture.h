#ifndef UNIT_ACTION_BUILD_CHILD_ITERATE_FIXTURE_H
#define UNIT_ACTION_BUILD_CHILD_ITERATE_FIXTURE_H

#include "unit_action_build_child_iterate.h"

struct DummyIterWorld {
    char pad_00[2976];
    int m_player_index;
};

struct DummyIterChild {
    void *vtable;
    char pad_04[4];
    DummyIterWorld *m_world;
    char pad_0C[16];
    int m_field1C;
};

#endif // UNIT_ACTION_BUILD_CHILD_ITERATE_FIXTURE_H

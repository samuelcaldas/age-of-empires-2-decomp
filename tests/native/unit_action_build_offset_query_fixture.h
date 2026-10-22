#ifndef UNIT_ACTION_BUILD_OFFSET_QUERY_FIXTURE_H
#define UNIT_ACTION_BUILD_OFFSET_QUERY_FIXTURE_H

#include <cstddef>
#include "unit_action_build_offset_query.h"

struct DummyOffsetAction {
    void *vtable;
    char pad_4[0x16E - 4];
    short m_field16E;
};

#endif // UNIT_ACTION_BUILD_OFFSET_QUERY_FIXTURE_H

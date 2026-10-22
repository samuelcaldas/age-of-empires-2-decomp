#ifndef UNIT_ACTION_BUILD_FLAG_2000_SET_FIXTURE_H
#define UNIT_ACTION_BUILD_FLAG_2000_SET_FIXTURE_H

#include <cstddef>
#include "unit_action_build_flag_2000_set.h"

struct DummyF404 {
    char pad[0x18];
    int m_timestamp;
};

struct DummySetGame {
    char pad[0x404];
    DummyF404 *m_field404;
};

struct DummySetAction {
    void *vtable;
    char pad[0xC0 - sizeof(void*)];
    int m_fieldC0;
};

#endif // UNIT_ACTION_BUILD_FLAG_2000_SET_FIXTURE_H

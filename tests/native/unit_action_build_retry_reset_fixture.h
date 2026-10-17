#ifndef UNIT_ACTION_BUILD_RETRY_RESET_FIXTURE_H
#define UNIT_ACTION_BUILD_RETRY_RESET_FIXTURE_H

#include <cstddef>
#include "unit_action_build_retry_reset.h"

struct DummyResetAction {
    void *vtable;
    char pad[0x15A - sizeof(void*)];
    unsigned char m_field15A;
};

#endif // UNIT_ACTION_BUILD_RETRY_RESET_FIXTURE_H

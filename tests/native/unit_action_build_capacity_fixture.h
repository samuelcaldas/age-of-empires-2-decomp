#ifndef UNIT_ACTION_BUILD_CAPACITY_FIXTURE_H
#define UNIT_ACTION_BUILD_CAPACITY_FIXTURE_H

#include <cstddef>
#include "unit_action_build_capacity.h"

struct DummyCapacityAction {
    void *vtable;
    char pad_04[362];
    short m_field366;
};

static int g_func_268500_ret = 1;
static int g_func_268530_ret = 10;

extern "C" {
    int func_00268500(ActionRebind *self) {
        (void)self;
        return g_func_268500_ret;
    }
    int func_00268530(ActionRebind *self) {
        (void)self;
        return g_func_268530_ret;
    }
}

#endif // UNIT_ACTION_BUILD_CAPACITY_FIXTURE_H

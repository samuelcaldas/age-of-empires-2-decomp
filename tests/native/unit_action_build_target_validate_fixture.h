#ifndef UNIT_ACTION_BUILD_TARGET_VALIDATE_FIXTURE_H
#define UNIT_ACTION_BUILD_TARGET_VALIDATE_FIXTURE_H

#include <cstddef>
#include "unit_action_build_target_validate.h"

struct DummyValidateMaster {
    char pad_00[8];
    short m_type;
};

struct DummyValidateAction {
    void *vtable;
    DummyValidateMaster *m_master;
    char pad_08[292];
    void *m_target;
};

static int g_func_1950d0_called = 0;
static int g_gethead_called = 0;
static void *g_gethead_ret = nullptr;
static int g_callmethod13_called = 0;
static int g_freelist_called = 0;
static int g_func_270530_called = 0;
static void *g_last_freelist_ptr = nullptr;

extern "C" {
    void func_1950d0() {
        g_func_1950d0_called++;
    }
    void* GetHeadItem__8BaseListFv(void *list) {
        (void)list;
        g_gethead_called++;
        return g_gethead_ret;
    }
    void CallMethod13__8BaseListFv(void *self) {
        (void)self;
        g_callmethod13_called++;
    }
    void Free__8BaseListFv(void *list) {
        g_freelist_called++;
        g_last_freelist_ptr = list;
    }
    void func_00270530(ActionRebind *self) {
        (void)self;
        g_func_270530_called++;
    }
}

#endif // UNIT_ACTION_BUILD_TARGET_VALIDATE_FIXTURE_H

#ifndef UNIT_ACTION_BUILD_DELEGATE_FIXTURE_H
#define UNIT_ACTION_BUILD_DELEGATE_FIXTURE_H

#include <cstddef>
#include "unit_action_build_delegate.h"

struct DummyDelegateWorld {
    char pad_00[2976];
    int m_player_count;
    char pad_BA4[3980];
    void *m_vtable;
};

struct DummyDelegateAction {
    void *vtable;
    char pad_04[4];
    DummyDelegateWorld *m_world;
    char pad_0C[45];
    unsigned char m_flag57;
    char pad_3A[310];
    float m_f368;
};

static int g_func_186010_called = 0;
static int g_func_2646E0_called = 0;
static int g_last_2646E0_a1 = 0, g_last_2646E0_a2 = 0;
static int g_last_2646E0_a3 = 0, g_last_2646E0_t0 = 0;

static void *g_dummy_singleton = nullptr;
void *D_004E3180 = &g_dummy_singleton;

extern "C" {
    void func_186010(void *sing) {
        (void)sing;
        g_func_186010_called++;
    }
    void func_002646E0(ActionRebind *self, int a1, int a2, int a3, int t0) {
        (void)self;
        g_func_2646E0_called++;
        g_last_2646E0_a1 = a1;
        g_last_2646E0_a2 = a2;
        g_last_2646E0_a3 = a3;
        g_last_2646E0_t0 = t0;
    }
}

#endif // UNIT_ACTION_BUILD_DELEGATE_FIXTURE_H

#ifndef UNIT_ACTION_BUILD_DISPATCH_FIXTURE_H
#define UNIT_ACTION_BUILD_DISPATCH_FIXTURE_H

#include <cstddef>
#include "unit_action_build_dispatch.h"

struct DummyDispatchWorld {
    char pad_00[2976];
    int m_player_count;
    char pad_BA4[3980];
    void *m_vtable;
};

struct DummyDispatchAction {
    void *vtable;
    char pad_04[4];
    DummyDispatchWorld *m_world;
    char pad_0C[45];
    unsigned char m_flag57;
    char pad_3A[310];
    float m_f368;
};

static int g_func_186010_called = 0;
static int g_func_270E30_called = 0;
static int g_func_264450_called = 0;
static int g_last_264450_a1 = 0, g_last_264450_a2 = 0;
static int g_last_264450_a3 = 0, g_last_264450_t0 = 0;

static void *g_dummy_singleton = nullptr;
void *D_004E3180 = &g_dummy_singleton;

extern "C" {
    void func_186010(void *sing) {
        (void)sing;
        g_func_186010_called++;
    }
    void func_00270E30(ActionRebind *self) {
        (void)self;
        g_func_270E30_called++;
    }
    void func_00264450(ActionRebind *self, int a1, int a2, int a3, int t0) {
        (void)self;
        g_func_264450_called++;
        g_last_264450_a1 = a1;
        g_last_264450_a2 = a2;
        g_last_264450_a3 = a3;
        g_last_264450_t0 = t0;
    }
}

#endif // UNIT_ACTION_BUILD_DISPATCH_FIXTURE_H

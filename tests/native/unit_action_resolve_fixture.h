#ifndef UNIT_ACTION_RESOLVE_FIXTURE_H
#define UNIT_ACTION_RESOLVE_FIXTURE_H

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_resolve.h"

static int g_func_269E50_called = 0;
static int g_func_269F30_called = 0;
static int g_last_received_tile_x = -1;
static int g_last_received_tile_y = -1;

static int g_rand_calls = 0;
static int g_rand_val = 0;
static int g_use_rand_sequence = 0;
static int g_rand_sequence[128] = {0};

static int g_m3c_ret = 0;
static int g_m73_ret = 1;
static int g_m3c_called = 0;
static int g_m75_called = 0;

static void *g_last_m3c_f4 = nullptr;
static void *g_last_m3c_world = nullptr;
static void *g_last_m3c_self = nullptr;
static float g_last_m3c_x = 0.0f;
static float g_last_m3c_y = 0.0f;
static float g_last_m75_x = 0.0f;
static float g_last_m75_y = 0.0f;

static int g_last_m3c_a2 = 0;
static int g_last_m3c_a3 = 0;
static int g_last_m3c_t0 = 0;
static int g_last_m3c_t1 = 0;
static int g_last_m3c_t2 = 0;
static int g_last_m3c_t3 = 0;
static int g_last_m3c_s0 = 0;
static int g_last_m3c_s8 = 0;
static int g_last_m3c_s16 = 0;

extern "C" {
    int func_001AAB30() {
        int idx = g_rand_calls;
        g_rand_calls++;
        if (g_use_rand_sequence && idx < 128) {
            return g_rand_sequence[idx];
        }
        return g_rand_val;
    }
    int func_123350(float val) { return (int)val; }
    unsigned char func_00269E50(ActionRebind *self, int tile_x, int tile_y) {
        (void)self;
        g_func_269E50_called++;
        g_last_received_tile_x = tile_x;
        g_last_received_tile_y = tile_y;
        return 5;
    }
    int func_00269F30(ActionRebind *self, int curr_type, int target_type) {
        (void)self; (void)curr_type; (void)target_type;
        g_func_269F30_called++;
        return 1;
    }
}

static int mock_m3c(void *child_f4, void *world, float x, float y,
                    int a2, int a3, int t0, int t1, int t2, int t3,
                    int s0, int s8, int s16, void *s24_self) {
    g_m3c_called++;
    g_last_m3c_f4 = child_f4;
    g_last_m3c_world = world;
    g_last_m3c_self = s24_self;
    g_last_m3c_x = x;
    g_last_m3c_y = y;
    g_last_m3c_a2 = a2;
    g_last_m3c_a3 = a3;
    g_last_m3c_t0 = t0;
    g_last_m3c_t1 = t1;
    g_last_m3c_t2 = t2;
    g_last_m3c_t3 = t3;
    g_last_m3c_s0 = s0;
    g_last_m3c_s8 = s8;
    g_last_m3c_s16 = s16;
    return g_m3c_ret;
}

static int mock_m75(void *child_obj, float x, float y) {
    (void)child_obj;
    g_m75_called++;
    g_last_m75_x = x;
    g_last_m75_y = y;
    return g_m73_ret;
}

static void* dummy_child_vtable[120];

struct MockAction {
    void *vtable;
    void *m_field4;
    void *m_world;
};

#endif // UNIT_ACTION_RESOLVE_FIXTURE_H

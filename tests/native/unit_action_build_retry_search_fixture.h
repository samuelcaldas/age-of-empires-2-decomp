#ifndef UNIT_ACTION_BUILD_RETRY_SEARCH_FIXTURE_H
#define UNIT_ACTION_BUILD_RETRY_SEARCH_FIXTURE_H

#include <cstddef>
#include "unit_action_build_retry_search.h"

struct DummyCell {
    char pad_0[5];
    unsigned char m_flag;
    char pad_6[22];
};

struct DummyGridZone {
    void *vtable;
    int m_field4;
    int m_width;
    int m_height;
    char pad_10[0x8E8C - 0x10];
    DummyCell **m_grid;
};

struct DummySearchWorld {
    char pad_3c[0x3C];
    DummyGridZone *m_zone;
};

struct DummySearchActor {
    char pad_b98[0xB98];
    DummySearchWorld *m_world;
};

struct DummySearchMaster {
    char pad[8];
    short m_type;
    char pad_a[0x4C - 10];
    float m_extent_x;
    float m_extent_y;
};

struct DummySearchAction {
    void *vtable;
    DummySearchMaster *m_master;
    DummySearchActor *m_actor;
    char pad_c[0x44 - 0xC];
    float m_x;
    float m_y;
};

static int g_func_123350_called = 0;
static int g_func_314DC0_called = 0;
static int g_func_1CF9B0_called = 0;
static void *g_last_notify_zone = nullptr;
static short g_last_notify_min_x = 0, g_last_notify_min_y = 0;
static short g_last_notify_max_x = 0, g_last_notify_max_y = 0;
static int g_last_notify_status = 0;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
    void func_314DC0(int *min_x, int *min_y, int *max_x, int *max_y,
                     int min_b_x, int min_b_y, int max_b_x, int max_b_y) {
        g_func_314DC0_called++;
        if (*min_x < min_b_x) *min_x = min_b_x;
        if (*min_y < min_b_y) *min_y = min_b_y;
        if (*max_x > max_b_x) *max_x = max_b_x;
        if (*max_y > max_b_y) *max_y = max_b_y;
    }
    void func_1CF9B0(void *zone, void *a1, void *a2, short min_x, short min_y,
                     short max_x, short max_y, int status, long long sp0, long long sp8) {
        (void)a1; (void)a2; (void)sp0; (void)sp8;
        g_func_1CF9B0_called++;
        g_last_notify_zone = zone;
        g_last_notify_min_x = min_x;
        g_last_notify_min_y = min_y;
        g_last_notify_max_x = max_x;
        g_last_notify_max_y = max_y;
        g_last_notify_status = status;
    }
}

#endif // UNIT_ACTION_BUILD_RETRY_SEARCH_FIXTURE_H

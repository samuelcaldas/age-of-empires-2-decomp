#ifndef UNIT_ACTION_COLLISION_FIXTURE_H
#define UNIT_ACTION_COLLISION_FIXTURE_H

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_collision.h"

static int g_func_268500_ret = 1;
static int g_func_2699A0_called = 0;

struct HelperInvocation {
    void *self;
    int arg1;
    float *out_x_ptr;
    float *out_y_ptr;
    void *child_f4;
    void *child;
    float coord_x;
    float coord_y;
    float ext_x;
    float ext_y;
    int ret_val;
};
static HelperInvocation g_calls[16];
static int g_call_count = 0;
static int g_forced_helper_rets[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

static int g_method15_called = 0;
static int g_method58_called = 0;
static int g_method87_called = 0;
static void *g_last_set_pos_self = nullptr;
static void *g_last_m15_self = nullptr;
static void *g_last_m58_self = nullptr;
static void *g_m87_self_history[8] = {nullptr};

struct MockInnerNode {
    char pad[0x154];
    float m_pos_x;
    float m_pos_y;
};
static MockInnerNode g_inner1;
static MockInnerNode g_inner2;
static MockInnerNode *g_inner1_ptr = &g_inner1;
static MockInnerNode *g_inner2_ptr = &g_inner2;
static void *g_m87_return_sequence[8] = {(void*)&g_inner1_ptr, (void*)&g_inner2_ptr};

extern "C" {
    int func_123350(float val) { return (int)val; }
    void func_002697B0(ActionRebind *self, float x, float y, float z) {
        g_last_set_pos_self = (void*)self;
        self->m_x = x;
        self->m_y = y;
        self->m_z = z;
    }
    int func_00268500(ActionRebind *self) { (void)self; return g_func_268500_ret; }

    int func_002699A0(ActionRebind *self, int arg1, float *out_x, float *out_y, void *child_field4, ActionRebind *child, float coord_x, float coord_y, float ext_x, float ext_y) {
        g_func_2699A0_called++;
        int idx = g_call_count;
        if (idx < 16) {
            g_calls[idx].self = (void*)self;
            g_calls[idx].arg1 = arg1;
            g_calls[idx].out_x_ptr = out_x;
            g_calls[idx].out_y_ptr = out_y;
            g_calls[idx].child_f4 = child_field4;
            g_calls[idx].child = (void*)child;
            g_calls[idx].coord_x = coord_x;
            g_calls[idx].coord_y = coord_y;
            g_calls[idx].ext_x = ext_x;
            g_calls[idx].ext_y = ext_y;
            int ret = g_forced_helper_rets[idx];
            g_calls[idx].ret_val = ret;
            if (ret != 0) {
                *out_x = 55.0f + (float)idx;
                *out_y = 66.0f + (float)idx;
            }
            g_call_count++;
            return ret;
        }
        *out_x = 55.0f;
        *out_y = 66.0f;
        return 1;
    }
}

static void mock_m15(void *self, float x, float y, float z) {
    (void)x; (void)y; (void)z;
    g_method15_called++;
    g_last_m15_self = self;
}
static void mock_m58(void *self) {
    g_method58_called++;
    g_last_m58_self = self;
}
static int mock_m87(void *self) {
    int idx = g_method87_called;
    g_method87_called++;
    if (idx < 8) {
        g_m87_self_history[idx] = self;
        return (int)g_m87_return_sequence[idx];
    }
    return (int)&g_inner2_ptr;
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[15] = (void*)mock_m15;
    dummy_vtable[56] = (void*)mock_m58;
    dummy_vtable[87] = (void*)mock_m87;
}

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    void *m_field20;
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

#endif // UNIT_ACTION_COLLISION_FIXTURE_H

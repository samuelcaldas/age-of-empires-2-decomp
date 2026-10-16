#ifndef UNIT_ACTION_STATE_FIXTURE_H
#define UNIT_ACTION_STATE_FIXTURE_H

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_state.h"

static int g_func_268500_ret = 1;
static int g_method58_called = 0;
static void *g_last_method58_self = nullptr;
static void *g_m58_history[8] = {nullptr};

extern "C" {
    int func_123350(float val) { return (int)val; }
    int func_00268500(ActionRebind *self) { (void)self; return g_func_268500_ret; }
}

struct ActionMock;
static void mock_m58(void *self);
static void poison_slot() {
    assert(false && "Poisoned vtable slot invoked!");
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)poison_slot;
    }
    dummy_vtable[56] = (void*)mock_m58;
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

    ActionMock *m_parent;

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
        m_parent = nullptr;
    }
};

static void mock_m58(void *self) {
    if (g_method58_called < 8) {
        g_m58_history[g_method58_called] = self;
    }
    g_method58_called++;
    g_last_method58_self = self;
    ActionMock *child = (ActionMock*)self;
    if (child->m_parent != nullptr) {
        child->m_parent->m_field20 = child->m_field20;
    }
}

struct DummyEntityData {
    char pad0[1];
    unsigned char m_capacity;
    char pad2[6];
    int m_field8;
    char padC[2];
    short m_fieldE;
    char pad10[0x74 - 0x10];
    int m_field74;
};

#endif // UNIT_ACTION_STATE_FIXTURE_H

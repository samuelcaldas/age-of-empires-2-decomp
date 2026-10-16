#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_combat_timing.h"

static int g_func_2E03F0_called = 0;
static int g_func_277D50_called = 0;
static int g_func_277E50_called = 0;
static int g_func_2E03F0_ret = 1;

extern "C" {
    int func_002E03F0(void *action, void *target) {
        (void)action; (void)target;
        g_func_2E03F0_called++;
        return g_func_2E03F0_ret;
    }
    void func_00277D50(void *action, float delta) {
        (void)action; (void)delta;
        g_func_277D50_called++;
    }
    void func_00277E50(void *action, void *target) {
        (void)action; (void)target;
        g_func_277E50_called++;
    }
}

static void* dummy_vtable[120];

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    int m_field20;
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

struct DummyCombatEntity {
    char pad[0x30];
    float m_interval; // 0x30
};

// Case 0: func_0026C3C0 interval accumulator and timer reset
static void test_combat_interval() {
    func_0026C3C0(nullptr, 1.0f);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyCombatEntity ent;
    ent.m_interval = 2.0f;
    mock.m_field4 = &ent;
    mock.m_field30 = 0.5f;

    g_func_2E03F0_called = 0;
    g_func_277D50_called = 0;

    // Delta 1.0f -> 0.5 + 1.0 = 1.5 < 2.0 -> no trigger
    func_0026C3C0(act, 1.0f);
    assert(g_func_2E03F0_called == 0);
    assert(std::fabs(mock.m_field30 - 1.5f) < 0.001f);

    // Delta 1.0f -> 1.5 + 1.0 = 2.5 >= 2.0 -> triggers and resets to 0.5f
    func_0026C3C0(act, 1.0f);
    assert(g_func_2E03F0_called == 1);
    assert(g_func_277D50_called == 1);
    assert(std::fabs(mock.m_field30 - 0.5f) < 0.001f);
}

// Case 1: func_0026C480 combat range verification
static void test_combat_range() {
    assert(func_0026C480(nullptr, nullptr, 0.0f) == 0);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_target[100];

    g_func_277E50_called = 0;
    g_func_2E03F0_called = 0;
    g_func_2E03F0_ret = 1;

    int ok = func_0026C480(act, dummy_target, 5.0f);
    assert(ok == 1);
    assert(g_func_277E50_called == 2);
    assert(g_func_2E03F0_called == 1);

    // When 2E03F0 returns 0, range check returns 0
    g_func_2E03F0_ret = 0;
    ok = func_0026C480(act, dummy_target, 5.0f);
    assert(ok == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_combat_interval();
        test_combat_range();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_combat_interval(); break;
        case 1: test_combat_range(); break;
        default: return 1;
    }
    return 0;
}

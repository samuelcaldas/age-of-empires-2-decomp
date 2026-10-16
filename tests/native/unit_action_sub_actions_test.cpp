#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_sub_actions.h"

static int g_sublist_action_called = 0;
static int g_baselist_action_called = 0;
static int g_func_1880B0_called = 0;
static int g_func_1880B0_ret = 1;
static int g_func_2668c0_called = 0;
static int g_func_1ecd00_called = 0;
void *D_004E3180 = (void*)0x12345678;

extern "C" {
    void Action__7SubListFv(void *self) { (void)self; g_sublist_action_called++; }
    int func_1880B0(void *game) { (void)game; g_func_1880B0_called++; return g_func_1880B0_ret; }
    int func_2668c0(void *self, int index) { (void)self; g_func_2668c0_called++; return index + 100; }
    void Action__8BaseListFv(void *item) { (void)item; g_baselist_action_called++; }
    void func_1ECD00(void *field98, void *action) { (void)field98; (void)action; g_func_1ecd00_called++; }
}

static void* dummy_vtable[120];

struct ExtendedActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x128 - 0xC];
    void *m_field128;
    void *m_field12C;
    int m_field130;
    int m_sub_actions[4]; // 0x134, 0x138, 0x13C, 0x140
    char pad_144[0x14C - 0x144];
    void *m_field14C;

    ExtendedActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: func_1880B0 returning 0 bypasses sub-action iteration
static void test_sub_actions_bypassed() {
    ExtendedActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_field130 = 5;
    mock.m_sub_actions[0] = 1;
    mock.m_sub_actions[1] = 2;
    mock.m_sub_actions[2] = 3;
    mock.m_sub_actions[3] = 4;

    g_sublist_action_called = 0;
    g_baselist_action_called = 0;
    g_func_1880B0_called = 0;
    g_func_2668c0_called = 0;
    g_func_1ecd00_called = 0;
    g_func_1880B0_ret = 0; // bypassed

    func_0026CF30(act);

    assert(g_sublist_action_called == 1);
    assert(g_func_1880B0_called == 1);
    assert(g_func_2668c0_called == 0);
    assert(g_func_1ecd00_called == 0);
    assert(g_baselist_action_called == 3);
    assert(mock.m_field130 == 5); // untouched
}

// Case 1: func_1880B0 active with non-39 master type
static void test_sub_actions_normal_flow() {
    ExtendedActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_f4[32];
    char dummy_world[200];
    *(short*)(dummy_f4 + 0xE) = 15; // not 39 (0x27)
    mock.m_field4 = dummy_f4;
    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_field130 = 8;
    mock.m_sub_actions[0] = 2;
    mock.m_sub_actions[1] = 0; // zero slot skipped
    mock.m_sub_actions[2] = 4;
    mock.m_sub_actions[3] = 0; // zero slot skipped

    g_sublist_action_called = 0;
    g_baselist_action_called = 0;
    g_func_1880B0_called = 0;
    g_func_2668c0_called = 0;
    g_func_1ecd00_called = 0;
    g_func_1880B0_ret = 1;

    func_0026CF30(act);

    assert(g_sublist_action_called == 1);
    assert(g_func_1880B0_called == 1);
    assert(g_func_2668c0_called == 3); // sub0 + 2 sub_actions
    assert(g_func_1ecd00_called == 1);
    assert(g_baselist_action_called == 3);
    assert(mock.m_field130 == 107);
    assert(mock.m_sub_actions[0] == 101);
    assert(mock.m_sub_actions[1] == 0);
    assert(mock.m_sub_actions[2] == 103);
    assert(mock.m_sub_actions[3] == 0);
}

// Case 2: master type 39 (0x27) suppresses func_1ECD00 call
static void test_sub_actions_type_39() {
    ExtendedActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_f4[32];
    *(short*)(dummy_f4 + 0xE) = 39; // type 39
    mock.m_field4 = dummy_f4;
    mock.m_field130 = 4;

    g_func_1ecd00_called = 0;
    g_func_2668c0_called = 0;
    g_func_1880B0_ret = 1;

    func_0026CF30(act);

    assert(g_func_1ecd00_called == 0); // suppressed
    assert(g_func_2668c0_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_sub_actions_bypassed();
        test_sub_actions_normal_flow();
        test_sub_actions_type_39();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_sub_actions_bypassed(); break;
        case 1: test_sub_actions_normal_flow(); break;
        case 2: test_sub_actions_type_39(); break;
        default: return 1;
    }
    return 0;
}

#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_notify_workers_fixture.h"

static int g_m219_ret = 0;
static short g_m219_o1 = 0;
static int mock_m219(void *s, short *o1, short *o2, short *o3, int z1, int z2) {
    (void)s; (void)o2; (void)o3; (void)z1; (void)z2;
    *o1 = g_m219_o1;
    return g_m219_ret;
}

static int g_action_method_ret = 0;
static int g_action_method_called = 0;
static int mock_action_method(void *l) {
    (void)l;
    g_action_method_called++;
    return g_action_method_ret;
}

static void *dummy_action_vt[256] = {};
static void *dummy_list_vt[32] = {};

static void init_test_vt() {
    dummy_singleton_vt[17] = (void*)mock_m17;
    dummy_action_vt[219] = (void*)mock_m219;
    dummy_list_vt[6] = (void*)mock_action_method;
}

static void reset_test_state() {
    g_func_202B10_called = g_func_270530_called = g_func_270450_called = 0;
    g_func_366D10_called = g_func_35D7C0_called = g_addhead_called = g_deletehead_called = 0;
    g_func_202B10_ret = 1;
    g_m219_ret = g_m219_o1 = g_action_method_ret = g_action_method_called = 0;
}

static void test_zero_count() {
    reset_test_state();
    init_test_vt();
    DummyNotifyWorkersAction action = {};
    action.vtable = dummy_action_vt;
    action.m_count = 0;
    func_00270660((ActionRebind*)&action);
    assert(g_deletehead_called == 0);
}

static void test_item_103_early_return() {
    reset_test_state();
    init_test_vt();
    g_m219_ret = 1;
    g_m219_o1 = 103;
    struct ListObj { void *vt; char pad[4]; void *item8; } list = { dummy_list_vt, {}, (void*)0x1234 };
    DummyNotifyWorkersAction action = {};
    action.vtable = dummy_action_vt;
    action.m_list = &list;
    action.m_count = 2;
    func_00270660((ActionRebind*)&action);
    assert(g_action_method_called == 0 && g_deletehead_called == 0 && g_addhead_called == 0);
}

static void test_create_and_add_item() {
    reset_test_state();
    init_test_vt();
    g_m219_ret = 0;
    DummyWorkerWorldNode node = {};
    node.m_f44 = 100.0f; node.m_f324 = 100.0f; node.m_f128 = 50.0f; node.m_f16 = 500.0f;
    DummyWorkerWorld world = {};
    world.m_player_count = 1; world.m_node = &node;
    struct ListObj { void *vt; char pad[4]; void *item8; } list = { dummy_list_vt, {}, nullptr };
    struct Slot { short id; short amt; } slots[1] = { { 42, 1 } };
    DummyNotifyWorkersAction action = {};
    action.vtable = dummy_action_vt;
    action.m_world = &world; action.m_list = &list; action.m_slots = slots;
    action.m_count = 1; action.m_field154 = -1;
    func_00270660((ActionRebind*)&action);
    assert(g_func_366D10_called == 1 && g_func_35D7C0_called == 1 && g_addhead_called == 1);
}

static void test_action_method_completion() {
    reset_test_state();
    init_test_vt();
    g_m219_ret = 0;
    g_action_method_ret = 3;
    struct ListObj { void *vt; char pad[4]; void *item8; } list = { dummy_list_vt, {}, (void*)0x1234 };
    DummyNotifyWorkersAction action = {};
    action.vtable = dummy_action_vt;
    action.m_list = &list; action.m_count = 1;
    func_00270660((ActionRebind*)&action);
    assert(g_deletehead_called == 1 && g_func_270450_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_zero_count();
        test_item_103_early_return();
        test_create_and_add_item();
        test_action_method_completion();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_zero_count(); break;
        case 1: test_item_103_early_return(); break;
        case 2: test_create_and_add_item(); break;
        case 3: test_action_method_completion(); break;
        default: return 1;
    }
    return 0;
}

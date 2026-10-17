#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_formation_fixture.h"

void *D_4E35DC = (void*)0x1234;

static int g_func_366D70_called = 0;
static void *g_mock_366D70_ret = nullptr;

static int g_func_363410_called = 0;
static void *g_last_363410_item = nullptr;
static void *g_last_363410_self = nullptr;
static short g_last_363410_a1 = 0;
static int g_last_363410_a2 = 0;

static int g_free_called = 0;
static void *g_last_free_list = nullptr;

static int g_addhead_called = 0;
static void *g_last_addhead_list = nullptr;
static void *g_last_addhead_item = nullptr;

extern "C" {
    void* func_366D70(void *param) {
        (void)param;
        g_func_366D70_called++;
        return g_mock_366D70_ret;
    }

    void func_363410(void *item, void *self, short a1, int a2) {
        g_func_363410_called++;
        g_last_363410_item = item;
        g_last_363410_self = self;
        g_last_363410_a1 = a1;
        g_last_363410_a2 = a2;
    }

    void Free__8BaseListFv(void *list) {
        g_free_called++;
        g_last_free_list = list;
    }

    void AddHead__8BaseListFPv(void *list, void *item) {
        g_addhead_called++;
        g_last_addhead_list = list;
        g_last_addhead_item = item;
    }
}

static void reset_test_state() {
    g_func_366D70_called = 0;
    g_mock_366D70_ret = nullptr;
    g_func_363410_called = 0;
    g_last_363410_item = nullptr;
    g_last_363410_self = nullptr;
    g_last_363410_a1 = 0;
    g_last_363410_a2 = 0;
    g_free_called = 0;
    g_last_free_list = nullptr;
    g_addhead_called = 0;
    g_last_addhead_list = nullptr;
    g_last_addhead_item = nullptr;
}

// Case 0: func_366D70 failure returns 0 without list operations
static void test_alloc_fail() {
    reset_test_state();
    g_mock_366D70_ret = nullptr;

    DummyFormationAction action = {};
    char dummy_list[16];
    action.m_list = dummy_list;

    int ret = func_0026FC20((ActionRebind*)&action, 5, 10);

    assert(ret == 0);
    assert(g_func_366D70_called == 1);
    assert(g_func_363410_called == 0);
    assert(g_free_called == 0);
    assert(g_addhead_called == 0);
}

// Case 1: valid allocation configures item and adds to list
static void test_successful_formation() {
    reset_test_state();
    char dummy_item[32];
    g_mock_366D70_ret = dummy_item;

    DummyFormationAction action = {};
    char dummy_list[16];
    action.m_list = dummy_list;

    int ret = func_0026FC20((ActionRebind*)&action, 0x10042, 999);

    assert(ret == 1);
    assert(g_func_366D70_called == 1);
    assert(g_func_363410_called == 1);
    assert(g_last_363410_item == dummy_item);
    assert(g_last_363410_self == &action);
    assert(g_last_363410_a1 == 0x42); // truncated to short
    assert(g_last_363410_a2 == 999);
    assert(g_free_called == 1);
    assert(g_last_free_list == dummy_list);
    assert(g_addhead_called == 1);
    assert(g_last_addhead_list == dummy_list);
    assert(g_last_addhead_item == dummy_item);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_alloc_fail();
        test_successful_formation();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_alloc_fail(); break;
        case 1: test_successful_formation(); break;
        default: return 1;
    }
    return 0;
}

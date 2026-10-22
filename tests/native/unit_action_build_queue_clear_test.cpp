#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_queue_clear_fixture.h"

static int g_func_1950D0_called = 0;
static void *g_last_1950D0_action = nullptr;
static int g_get_head_item_called = 0;
static void *g_mock_head_item = nullptr;
static int g_call_method13_called = 0;
static void *g_last_method13_list = nullptr;
static int g_free_list_called = 0;
static void *g_last_free_list = nullptr;
static int g_clear_workers_called = 0;
static void *g_last_clear_workers_self = nullptr;

extern "C" {
    void func_1950D0(void *action) {
        g_func_1950D0_called++;
        g_last_1950D0_action = action;
    }
    void* GetHeadItem__8BaseListFv(void *list) {
        (void)list;
        g_get_head_item_called++;
        return g_mock_head_item;
    }
    void CallMethod13__8BaseListFv(void *self) {
        g_call_method13_called++;
        g_last_method13_list = self;
    }
    void Free__8BaseListFv(void *list) {
        g_free_list_called++;
        g_last_free_list = list;
    }
    void func_00270530(ActionRebind *self) {
        g_clear_workers_called++;
        g_last_clear_workers_self = self;
    }
}

static void reset_state() {
    g_func_1950D0_called = g_get_head_item_called = 0;
    g_call_method13_called = g_free_list_called = g_clear_workers_called = 0;
    g_last_1950D0_action = g_mock_head_item = nullptr;
    g_last_method13_list = g_last_free_list = g_last_clear_workers_self = nullptr;
}

static void test_excluded_master_types() {
    int types[3] = { 50, 199, 276 };
    for (int i = 0; i < 3; ++i) {
        reset_state();
        DummyQueueMaster master = { {}, (short)types[i] };
        DummyQueueAction action = { nullptr, &master, {}, (void*)0x1234 };
        func_00270EF0((ActionRebind*)&action);
        assert(g_func_1950D0_called == 0);
        assert(g_get_head_item_called == 0);
    }
}

static void test_with_head_item_frees_list() {
    reset_state();
    DummyQueueMaster master = { {}, 42 };
    DummyQueueAction action = { nullptr, &master, {}, (void*)0x5678 };
    g_mock_head_item = (void*)0xABCD;

    func_00270EF0((ActionRebind*)&action);
    assert(g_func_1950D0_called == 1 && g_last_1950D0_action == &action);
    assert(g_get_head_item_called == 1);
    assert(g_call_method13_called == 1 && g_last_method13_list == (void*)0x5678);
    assert(g_free_list_called == 1 && g_last_free_list == (void*)0x5678);
    assert(g_clear_workers_called == 0);
}

static void test_empty_head_item_clears_workers() {
    reset_state();
    DummyQueueMaster master = { {}, 10 };
    DummyQueueAction action = { nullptr, &master, {}, (void*)0x9999 };
    g_mock_head_item = nullptr;

    func_00270EF0((ActionRebind*)&action);
    assert(g_func_1950D0_called == 1 && g_last_1950D0_action == &action);
    assert(g_get_head_item_called == 1);
    assert(g_call_method13_called == 0 && g_free_list_called == 0);
    assert(g_clear_workers_called == 1 && g_last_clear_workers_self == &action);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_excluded_master_types();
        test_with_head_item_frees_list();
        test_empty_head_item_clears_workers();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_excluded_master_types(); break;
        case 1: test_with_head_item_frees_list(); break;
        case 2: test_empty_head_item_clears_workers(); break;
        default: return 1;
    }
    return 0;
}

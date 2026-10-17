#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_notify_state_fixture.h"

static int g_gethead_called = 0;
static void *g_mock_head_item = nullptr;

static int g_func_347880_called = 0;
static short g_mock_347880_tid = 99;
static short g_mock_347880_flag = 1;

extern "C" {
    void* GetHeadItem__8BaseListFv(void *list) {
        (void)list;
        g_gethead_called++;
        return g_mock_head_item;
    }

    void func_347880(void *item, short *out_task_id, short *out_flag, int a3, int a4) {
        (void)item; (void)a3; (void)a4;
        g_func_347880_called++;
        *out_task_id = g_mock_347880_tid;
        *out_flag = g_mock_347880_flag;
    }
}

static void reset_test_state() {
    g_gethead_called = 0;
    g_mock_head_item = nullptr;
    g_func_347880_called = 0;
    g_mock_347880_tid = 99;
    g_mock_347880_flag = 1;
}

// Case 0: item of type 102 invokes func_347880 and returns 1
static void test_type_102_item() {
    reset_test_state();
    DummyNotifyItem item = {};
    item.m_type = 102; // 0x66
    g_mock_head_item = &item;

    DummyNotifyAction action = {};

    short out_tid = 0;
    short out_flag = 0;
    int ret = func_00270900((ActionRebind*)&action, &out_tid, &out_flag);

    assert(ret == 1);
    assert(g_gethead_called == 1);
    assert(g_func_347880_called == 1);
    assert(out_tid == 99);
    assert(out_flag == 1);
}

// Case 1: no item of type 102 but count > 0 extracts slot 0 task_id
static void test_slot0_fallback() {
    reset_test_state();
    g_mock_head_item = nullptr;

    struct Slot { short id; short amt; } slots[1] = { { 42, 5 } };

    DummyNotifyAction action = {};
    action.m_slots = slots;
    action.m_count = 1;

    short out_tid = 0;
    short out_flag = 0;
    int ret = func_00270900((ActionRebind*)&action, &out_tid, &out_flag);

    assert(ret == 1);
    assert(g_gethead_called == 1);
    assert(g_func_347880_called == 0);
    assert(out_tid == 42);
    assert(out_flag == 0);
}

// Case 2: no item and count == 0 resets outputs to -1 and 0, returns 0
static void test_empty_action() {
    reset_test_state();
    g_mock_head_item = nullptr;

    DummyNotifyAction action = {};
    action.m_count = 0;

    short out_tid = 55;
    short out_flag = 88;
    int ret = func_00270900((ActionRebind*)&action, &out_tid, &out_flag);

    assert(ret == 0);
    assert(out_tid == -1);
    assert(out_flag == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_type_102_item();
        test_slot0_fallback();
        test_empty_action();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_type_102_item(); break;
        case 1: test_slot0_fallback(); break;
        case 2: test_empty_action(); break;
        default: return 1;
    }
    return 0;
}

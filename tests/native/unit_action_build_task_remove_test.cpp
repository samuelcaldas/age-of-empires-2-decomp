#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_task_remove_fixture.h"

static int g_func_2E04D0_called = 0;
static int g_func_26FF60_called = 0;
static int g_m17_called = 0;
static int g_free_called = 0;
static void *g_last_freed_list = nullptr;

static void mock_m17(void *sing, int a1, int pcount, int tid, int zero1, int zero2) {
    (void)sing; (void)a1; (void)pcount; (void)tid; (void)zero1; (void)zero2;
    g_m17_called++;
}

static void *dummy_singleton_vt[32] = {};
void *D_004E3180 = dummy_singleton_vt;

static void mock_m7C(void *sing, int stat, float val, int zero) {
    (void)sing; (void)stat; (void)val; (void)zero;
}
static void *dummy_world_vt[64] = {};

extern "C" {
    void func_2E04D0(void *world, int task_id) {
        (void)world; (void)task_id;
        g_func_2E04D0_called++;
    }

    float func_2E6C60(void *world, int task_id) {
        (void)world; (void)task_id;
        return 1.0f;
    }

    void Free__8BaseListFv(void *list) {
        g_free_called++;
        g_last_freed_list = list;
    }

    void func_0026FF60(ActionRebind *self) {
        (void)self;
        g_func_26FF60_called++;
    }
}

static void init_test_vt() {
    dummy_singleton_vt[17] = (void*)mock_m17;
    dummy_world_vt[31] = (void*)mock_m7C; // 124 / 4
}

static void reset_test_state() {
    g_func_2E04D0_called = 0;
    g_func_26FF60_called = 0;
    g_m17_called = 0;
    g_free_called = 0;
    g_last_freed_list = nullptr;
}

// Case 0: count == 0 returns early without loop
static void test_zero_count() {
    reset_test_state();
    init_test_vt();

    DummyRemoveAction action = {};
    action.m_count = 0;

    func_0026FFB0((ActionRebind*)&action, 42, 1);

    assert(g_func_2E04D0_called == 0);
    assert(g_func_26FF60_called == 0);
}

// Case 1: partial decrement reduces slot amount and total
static void test_partial_decrement() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 5 } };

    DummyRemoveAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 1;
    action.m_total = 5;

    func_0026FFB0((ActionRebind*)&action, 10, 2);

    assert(g_func_2E04D0_called == 2);
    assert(slots[0].amt == 3); // 5 - 2
    assert(action.m_total == 3);
    assert(action.m_count == 1);
    assert(g_func_26FF60_called == 1);
}

// Case 2: complete decrement removes slot and shifts remaining left
static void test_complete_slot_removal() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[3] = { { 10, 2 }, { 20, 3 } };

    DummyRemoveAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 2;
    action.m_total = 5;
    action.m_field154 = -1;

    func_0026FFB0((ActionRebind*)&action, 20, 3); // removes slot 1

    assert(g_func_2E04D0_called == 3);
    assert(action.m_count == 1); // 2 - 1
    assert(action.m_total == 2); // 5 - 3
    assert(slots[0].id == 10 && slots[0].amt == 2);
    assert(g_func_26FF60_called == 1);
}

// Case 3: removal of slot 0 triggers Method17 notification and frees list
static void test_slot0_removal() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(int*)(world_buf + 2976) = 1;
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 2 } };
    char dummy_list[16];

    DummyRemoveAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 1;
    action.m_total = 2;
    action.m_field154 = 99; // active!
    action.m_field14C = dummy_list;

    func_0026FFB0((ActionRebind*)&action, 10, 2);

    assert(action.m_count == 0);
    assert(action.m_total == 0);
    assert(g_m17_called == 1);
    assert(action.m_field154 == -1);
    assert(g_free_called == 1);
    assert(g_last_freed_list == dummy_list);
    assert(g_func_26FF60_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_zero_count();
        test_partial_decrement();
        test_complete_slot_removal();
        test_slot0_removal();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_zero_count(); break;
        case 1: test_partial_decrement(); break;
        case 2: test_complete_slot_removal(); break;
        case 3: test_slot0_removal(); break;
        default: return 1;
    }
    return 0;
}

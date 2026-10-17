#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker_task_fixture.h"

static int g_m17_called = 0;
static void mock_m17(void *sing, int a1, int pcount, int tid, int zero1, int zero2) {
    (void)sing; (void)a1; (void)pcount; (void)tid; (void)zero1; (void)zero2;
    g_m17_called++;
}

static void *dummy_singleton_vt[32] = {};
void *D_004E3180 = dummy_singleton_vt;

static int g_func_2E03F0_called = 0;
static int g_func_2E03F0_ret = 1;
static float g_last_2E03F0_amount = 0.0f;

static int g_m7C_called = 0;
static float g_last_m7C_val = 0.0f;
static void mock_m7C(void *sing, int stat, float val, int zero) {
    (void)sing; (void)stat; (void)zero;
    g_m7C_called++;
    g_last_m7C_val = val;
}
static void *dummy_world_vt[128] = {};

static int g_malloc_called = 0;
static int g_free_called = 0;

extern "C" {
    int func_2E03F0(void *world, int task_id, float amount, int mode) {
        (void)world; (void)task_id; (void)mode;
        g_func_2E03F0_called++;
        g_last_2E03F0_amount = amount;
        return g_func_2E03F0_ret;
    }

    float func_2E6C60(void *world, int task_id) {
        (void)world; (void)task_id;
        return 2.5f;
    }

    void* func_1143F8(int count, int elem_size) {
        g_malloc_called++;
        return malloc(count * elem_size);
    }

    void func_116F68(void *ptr) {
        g_free_called++;
        free(ptr);
    }
}

static void init_test_vt() {
    dummy_singleton_vt[17] = (void*)mock_m17;
    dummy_world_vt[31] = (void*)mock_m7C; // offset 124 = 31 * 4
}

static void reset_test_state() {
    g_m17_called = 0;
    g_func_2E03F0_called = 0;
    g_func_2E03F0_ret = 1;
    g_last_2E03F0_amount = 0.0f;
    g_m7C_called = 0;
    g_last_m7C_val = 0.0f;
    g_malloc_called = 0;
    g_free_called = 0;
}

// Case 0: total >= 15 triggers Method17 notification and returns 0
static void test_over_capacity() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(int*)(world_buf + 2976) = 2; // player_count
    *(void**)(world_buf + 6960) = dummy_world_vt;

    DummyWorkerAction action = {};
    action.m_world = world_buf;
    action.m_total = 15; // at capacity

    int ret = func_0026FCC0((ActionRebind*)&action, 42, 1);
    assert(ret == 0);
    assert(g_m17_called == 1);
    assert(g_func_2E03F0_called == 0);
}

// Case 1: total + req >= 16 clamps req to 15 - total
static void test_clamp_allocation() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    DummyWorkerAction action = {};
    action.m_world = world_buf;
    action.m_total = 12; // 12 + 5 = 17 >= 16 -> clamps to 15 - 12 = 3

    short slots[4] = {};
    action.m_slots = slots;
    action.m_cap = 1;
    action.m_count = 0;

    int ret = func_0026FCC0((ActionRebind*)&action, 10, 5);
    assert(ret == 1);
    assert(g_last_2E03F0_amount == 3.0f); // clamped to 3!
    assert(action.m_total == 15); // 12 + 3 = 15
}

// Case 2: accumulates to existing slot when task_id matches previous
static void test_accumulate_slot() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[4] = { { 42, 2 } };

    DummyWorkerAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_cap = 2;
    action.m_count = 1;
    action.m_total = 2;

    int ret = func_0026FCC0((ActionRebind*)&action, 42, 3);
    assert(ret == 1);
    assert(action.m_count == 1); // count not incremented, slot merged!
    assert(slots[0].amt == 5);  // 2 + 3
    assert(action.m_total == 5);  // 2 + 3
}

// Case 3: appends new slot and expands buffer when count == cap
static void test_expand_and_append() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } *initial_slots = (Slot*)malloc(4);
    initial_slots[0] = { 10, 1 };

    DummyWorkerAction action = {};
    action.m_world = world_buf;
    action.m_slots = initial_slots;
    action.m_cap = 1;
    action.m_count = 1; // count == cap -> expands!
    action.m_total = 1;

    int ret = func_0026FCC0((ActionRebind*)&action, 20, 2);
    assert(ret == 1);
    assert(action.m_count == 2);
    assert(action.m_cap == 16); // 1 + 15
    assert(action.m_total == 3); // 1 + 2

    Slot *new_slots = (Slot*)action.m_slots;
    assert(new_slots[0].id == 10 && new_slots[0].amt == 1);
    assert(new_slots[1].id == 20 && new_slots[1].amt == 2);

    free(new_slots);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_over_capacity();
        test_clamp_allocation();
        test_accumulate_slot();
        test_expand_and_append();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_over_capacity(); break;
        case 1: test_clamp_allocation(); break;
        case 2: test_accumulate_slot(); break;
        case 3: test_expand_and_append(); break;
        default: return 1;
    }
    return 0;
}

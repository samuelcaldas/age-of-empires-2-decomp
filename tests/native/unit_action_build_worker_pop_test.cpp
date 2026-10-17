#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker_pop_fixture.h"

static int g_func_26FF60_called = 0;
static int g_m7C_called = 0;
static float g_last_m7C_val = 0.0f;

static void mock_m7C(void *sing, int stat, float val, int zero) {
    (void)sing; (void)stat; (void)zero;
    g_m7C_called++;
    g_last_m7C_val = val;
}
static void *dummy_world_vt[64] = {};

extern "C" {
    float func_2E6C60(void *world, int task_id) {
        (void)world; (void)task_id;
        return 1.5f;
    }

    void func_0026FF60(ActionRebind *self) {
        (void)self;
        g_func_26FF60_called++;
    }
}

static void init_test_vt() {
    dummy_world_vt[31] = (void*)mock_m7C;
}

static void reset_test_state() {
    g_func_26FF60_called = 0;
    g_m7C_called = 0;
    g_last_m7C_val = 0.0f;
}

// Case 0: count == 0 returns early
static void test_zero_count() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 1 } };

    DummyPopAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 0; // count 0!

    func_00270450((ActionRebind*)&action);

    assert(g_m7C_called == 0);
    assert(g_func_26FF60_called == 0);
}

// Case 1: partial decrement reduces slot 0 amount and total
static void test_partial_decrement() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 4 }, { 20, 2 } };

    DummyPopAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 2;
    action.m_total = 6;

    func_00270450((ActionRebind*)&action);

    assert(g_m7C_called == 1);
    assert(std::fabs(g_last_m7C_val - (-1.5f)) < 0.0001f);
    assert(slots[0].amt == 3); // 4 - 1
    assert(action.m_total == 5);
    assert(action.m_count == 2);
    assert(g_func_26FF60_called == 0);
}

// Case 2: slot 0 depletion shifts slots left and calls func_0026FF60
static void test_slot0_depletion() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 1 }, { 20, 5 } };

    DummyPopAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 2;
    action.m_total = 6;

    func_00270450((ActionRebind*)&action);

    assert(g_m7C_called == 1);
    assert(action.m_count == 1); // 2 - 1
    assert(action.m_total == 5);
    assert(slots[0].id == 20 && slots[0].amt == 5); // shifted left!
    assert(g_func_26FF60_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_zero_count();
        test_partial_decrement();
        test_slot0_depletion();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_zero_count(); break;
        case 1: test_partial_decrement(); break;
        case 2: test_slot0_depletion(); break;
        default: return 1;
    }
    return 0;
}

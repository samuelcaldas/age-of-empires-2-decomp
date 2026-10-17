#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker_clear_fixture.h"

static int g_func_2E04D0_called = 0;
static int g_func_26FF60_called = 0;
static int g_m17_called = 0;
static int g_free_called = 0;
static void *g_last_freed_list = nullptr;
static int g_m7C_called = 0;

static void mock_m17(void *sing, int a1, int pcount, int tid, int zero1, int zero2) {
    (void)sing; (void)a1; (void)pcount; (void)tid; (void)zero1; (void)zero2;
    g_m17_called++;
}

static void *dummy_singleton_vt[32] = {};
void *D_004E3180 = dummy_singleton_vt;

static void mock_m7C(void *sing, int stat, float val, int zero) {
    (void)sing; (void)stat; (void)val; (void)zero;
    g_m7C_called++;
}
static void *dummy_world_vt[64] = {};

extern "C" {
    void func_2E04D0(void *world, int task_id) {
        (void)world; (void)task_id;
        g_func_2E04D0_called++;
    }

    float func_2E6C60(void *world, int task_id) {
        (void)world; (void)task_id;
        return 2.0f;
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
    dummy_world_vt[31] = (void*)mock_m7C;
}

static void reset_test_state() {
    g_func_2E04D0_called = 0;
    g_func_26FF60_called = 0;
    g_m17_called = 0;
    g_free_called = 0;
    g_last_freed_list = nullptr;
    g_m7C_called = 0;
}

// Case 0: count == 0 resets total and generation, frees list, and calls func_0026FF60
static void test_empty_clear() {
    reset_test_state();
    init_test_vt();

    char dummy_list[16];
    DummyClearAction action = {};
    action.m_count = 0;
    action.m_total = 10;
    action.m_generation = 1;
    action.m_field154 = -1;
    action.m_field14C = dummy_list;

    func_00270530((ActionRebind*)&action);

    assert(g_func_2E04D0_called == 0);
    assert(g_m7C_called == 0);
    assert(action.m_total == 0);
    assert(action.m_generation == 2);
    assert(g_free_called == 1);
    assert(g_last_freed_list == dummy_list);
    assert(g_func_26FF60_called == 1);
}

// Case 1: multiple slots iterates over all workers and reduces stats
static void test_multiple_slots() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(void**)(world_buf + 6960) = dummy_world_vt;

    struct Slot { short id; short amt; } slots[2] = { { 10, 2 }, { 20, 3 } };

    DummyClearAction action = {};
    action.m_world = world_buf;
    action.m_slots = slots;
    action.m_count = 2;
    action.m_total = 5;
    action.m_field154 = -1;

    func_00270530((ActionRebind*)&action);

    assert(g_func_2E04D0_called == 5); // 2 + 3
    assert(g_m7C_called == 2); // 2 slots
    assert(action.m_count == 0);
    assert(action.m_total == 0);
    assert(g_func_26FF60_called == 1);
}

// Case 2: active m_field154 triggers Method17 on D_004E3180 and resets to -1
static void test_active_f154_notification() {
    reset_test_state();
    init_test_vt();

    char world_buf[8000] = {};
    *(int*)(world_buf + 2976) = 3;
    *(void**)(world_buf + 6960) = dummy_world_vt;

    DummyClearAction action = {};
    action.m_world = world_buf;
    action.m_count = 0;
    action.m_field154 = 77; // active!

    func_00270530((ActionRebind*)&action);

    assert(g_m17_called == 1);
    assert(action.m_field154 == -1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_empty_clear();
        test_multiple_slots();
        test_active_f154_notification();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_empty_clear(); break;
        case 1: test_multiple_slots(); break;
        case 2: test_active_f154_notification(); break;
        default: return 1;
    }
    return 0;
}

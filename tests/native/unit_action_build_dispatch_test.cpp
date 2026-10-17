#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_dispatch_fixture.h"

static void *dummy_world_vt[40] = {};
static void *g_m36_first_ret = nullptr;
static void *g_m36_second_ret = nullptr;
static int g_m36_calls = 0;

static void* mock_m36(void *w, int pcount) {
    (void)w; (void)pcount;
    g_m36_calls++;
    if (g_m36_calls == 1) return g_m36_first_ret;
    return g_m36_second_ret;
}

static void reset_test_state() {
    g_func_186010_called = g_func_270E30_called = g_func_264450_called = 0;
    g_last_264450_a1 = g_last_264450_a2 = g_last_264450_a3 = g_last_264450_t0 = 0;
    g_m36_first_ret = g_m36_second_ret = nullptr;
    g_m36_calls = 0;
    dummy_world_vt[36 / sizeof(void*)] = (void*)mock_m36;
}

static void test_flag57_non_zero_skips_world_check() {
    reset_test_state();
    DummyDispatchAction action = {};
    action.m_flag57 = 1;
    func_00270F80((ActionRebind*)&action, 10, 20, 30, 40);
    assert(g_func_186010_called == 0);
    assert(g_func_270E30_called == 1 && g_func_264450_called == 1);
    assert(g_last_264450_a1 == 10 && g_last_264450_t0 == 40);
}

static void test_f368_non_zero_skips_world_check() {
    reset_test_state();
    DummyDispatchAction action = {};
    action.m_flag57 = 0;
    action.m_f368 = 1.0f;
    func_00270F80((ActionRebind*)&action, 1, 2, 3, 4);
    assert(g_func_186010_called == 0);
    assert(g_func_270E30_called == 1 && g_func_264450_called == 1);
}

static void test_world_check_failure_returns_early() {
    reset_test_state();
    DummyDispatchWorld world = {};
    world.m_vtable = dummy_world_vt;
    DummyDispatchAction action = {};
    action.m_world = &world;
    action.m_flag57 = 0;
    action.m_f368 = 0.0f;

    g_m36_first_ret = nullptr;
    func_00270F80((ActionRebind*)&action, 5, 6, 7, 8);
    assert(g_func_186010_called == 1);
    assert(g_func_270E30_called == 0 && g_func_264450_called == 0);
}

static void test_world_check_success_dispatches() {
    reset_test_state();
    DummyDispatchWorld world2 = {};
    world2.m_vtable = dummy_world_vt;
    DummyDispatchWorld world = {};
    world.m_vtable = dummy_world_vt;

    DummyDispatchAction action = {};
    action.m_world = &world;
    action.m_flag57 = 0;
    action.m_f368 = 0.0f;

    g_m36_first_ret = &world2;
    g_m36_second_ret = &world;
    func_00270F80((ActionRebind*)&action, 11, 22, 33, 44);
    assert(g_func_186010_called == 2);
    assert(g_func_270E30_called == 1 && g_func_264450_called == 1);
    assert(g_last_264450_a1 == 11 && g_last_264450_t0 == 44);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_flag57_non_zero_skips_world_check();
        test_f368_non_zero_skips_world_check();
        test_world_check_failure_returns_early();
        test_world_check_success_dispatches();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_flag57_non_zero_skips_world_check();
    if (t == 1) test_f368_non_zero_skips_world_check();
    if (t == 2) test_world_check_failure_returns_early();
    if (t == 3) test_world_check_success_dispatches();
    return 0;
}

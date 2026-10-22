#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_target_check4_fixture.h"

static int g_func_186010_called = 0;
static int g_func_2647C0_called = 0;
static void *g_last_2647C0_self = nullptr;
static int g_last_a1 = 0, g_last_a2 = 0, g_last_a3 = 0;

static DummyCheck4World g_res_world;
static int g_m1_return = 1;
static int g_m2_return = 1;

void *D_004E3180 = (void*)0x4E3180;

static void* mock_m1(void *world, void *target_ba0) {
    (void)world; (void)target_ba0;
    return g_m1_return ? (void*)0x1111 : nullptr;
}

static void* mock_m2(void *world, void *target_ba0) {
    (void)world; (void)target_ba0;
    return g_m2_return ? (void*)0x2222 : nullptr;
}

extern "C" {
    void* func_00186010(void *game) {
        (void)game;
        g_func_186010_called++;
        return &g_res_world;
    }
    void func_2647C0(ActionRebind *self, int a1, int a2, int a3) {
        g_func_2647C0_called++;
        g_last_2647C0_self = self;
        g_last_a1 = a1; g_last_a2 = a2; g_last_a3 = a3;
    }
}

static void reset_state() {
    g_func_186010_called = g_func_2647C0_called = 0;
    g_last_2647C0_self = nullptr;
    g_last_a1 = g_last_a2 = g_last_a3 = 0;
    g_m1_return = g_m2_return = 1;
}

static void test_field39_non_zero_skips_checks() {
    reset_state();
    DummyCheck4Action action = { nullptr, nullptr, nullptr, {}, 3, {}, 0.0f };
    func_00271150((ActionRebind*)&action, 10, 20, 30);
    assert(g_func_186010_called == 0);
    assert(g_func_2647C0_called == 1);
    assert(g_last_a1 == 10 && g_last_a2 == 20 && g_last_a3 == 30);
}

static void test_field170_non_zero_skips_checks() {
    reset_state();
    DummyCheck4Action action = { nullptr, nullptr, nullptr, {}, 0, {}, 7.5f };
    func_00271150((ActionRebind*)&action, 1, 2, 3);
    assert(g_func_186010_called == 0);
    assert(g_func_2647C0_called == 1);
}

static void test_first_check_fails_aborts() {
    reset_state();
    DummyTargetCheckVTable4 vt_actor = { { nullptr }, mock_m1 };
    DummyCheck4World actor_world = { {}, (void*)0xAAAA, {}, &vt_actor };
    DummyTargetCheckVTable4 vt_res = { { nullptr }, mock_m2 };
    g_res_world.m_fieldBA0 = (void*)0xBBBB;
    g_res_world.m_vtable1B30 = &vt_res;

    DummyCheck4Action action = { nullptr, nullptr, &actor_world, {}, 0, {}, 0.0f };
    g_m1_return = 0;

    func_00271150((ActionRebind*)&action, 1, 2, 3);
    assert(g_func_186010_called == 1);
    assert(g_func_2647C0_called == 0);
}

static void test_second_check_fails_aborts() {
    reset_state();
    DummyTargetCheckVTable4 vt_actor = { { nullptr }, mock_m1 };
    DummyCheck4World actor_world = { {}, (void*)0xAAAA, {}, &vt_actor };
    DummyTargetCheckVTable4 vt_res = { { nullptr }, mock_m2 };
    g_res_world.m_fieldBA0 = (void*)0xBBBB;
    g_res_world.m_vtable1B30 = &vt_res;

    DummyCheck4Action action = { nullptr, nullptr, &actor_world, {}, 0, {}, 0.0f };
    g_m1_return = 1;
    g_m2_return = 0;

    func_00271150((ActionRebind*)&action, 1, 2, 3);
    assert(g_func_186010_called == 2);
    assert(g_func_2647C0_called == 0);
}

static void test_both_checks_succeed_dispatches() {
    reset_state();
    DummyTargetCheckVTable4 vt_actor = { { nullptr }, mock_m1 };
    DummyCheck4World actor_world = { {}, (void*)0xAAAA, {}, &vt_actor };
    DummyTargetCheckVTable4 vt_res = { { nullptr }, mock_m2 };
    g_res_world.m_fieldBA0 = (void*)0xBBBB;
    g_res_world.m_vtable1B30 = &vt_res;

    DummyCheck4Action action = { nullptr, nullptr, &actor_world, {}, 0, {}, 0.0f };
    g_m1_return = 1;
    g_m2_return = 1;

    func_00271150((ActionRebind*)&action, 15, 25, 35);
    assert(g_func_186010_called == 2);
    assert(g_func_2647C0_called == 1);
    assert(g_last_a1 == 15 && g_last_a2 == 25 && g_last_a3 == 35);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_field39_non_zero_skips_checks();
        test_field170_non_zero_skips_checks();
        test_first_check_fails_aborts();
        test_second_check_fails_aborts();
        test_both_checks_succeed_dispatches();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_field39_non_zero_skips_checks(); break;
        case 1: test_field170_non_zero_skips_checks(); break;
        case 2: test_first_check_fails_aborts(); break;
        case 3: test_second_check_fails_aborts(); break;
        case 4: test_both_checks_succeed_dispatches(); break;
        default: return 1;
    }
    return 0;
}

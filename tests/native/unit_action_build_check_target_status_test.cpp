#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_check_target_status_fixture.h"

static int g_func_26AD20_called = 0;
static int g_mock_flag_2000 = 0;
static int g_m1_called = 0, g_m2_called = 0;
static int g_m1_return = 1, g_m2_return = 1;

static void* mock_m1(void *world, void *target_ba0) {
    (void)world; (void)target_ba0;
    g_m1_called++;
    return g_m1_return ? (void*)0x1111 : nullptr;
}

static void* mock_m2(void *world, void *target_ba0) {
    (void)world; (void)target_ba0;
    g_m2_called++;
    return g_m2_return ? (void*)0x2222 : nullptr;
}

extern "C" {
    char func_26AD20(void *action, int flag) {
        (void)action;
        g_func_26AD20_called++;
        if (flag == 0x2000) {
            return (char)g_mock_flag_2000;
        }
        return 0;
    }
}

static void reset_state() {
    g_func_26AD20_called = g_m1_called = g_m2_called = 0;
    g_mock_flag_2000 = 0;
    g_m1_return = g_m2_return = 1;
}

static void test_field_e_not_39_returns_zero() {
    reset_state();
    DummyStatusMaster master = { {}, 10, {}, 5 };
    DummyStatusAction action = { nullptr, &master, nullptr };
    int res = func_00271500((ActionRebind*)&action, 0);
    assert(res == 0);
    assert(g_func_26AD20_called == 0);
}

static void test_field_1a2_negative_one_returns_zero() {
    reset_state();
    DummyStatusMaster master = { {}, 39, {}, -1 };
    DummyStatusAction action = { nullptr, &master, nullptr };
    int res = func_00271500((ActionRebind*)&action, 0);
    assert(res == 0);
    assert(g_func_26AD20_called == 0);
}

static void test_flag_2000_set_returns_zero() {
    reset_state();
    g_mock_flag_2000 = 1;
    DummyStatusMaster master = { {}, 39, {}, 12 };
    DummyStatusAction action = { nullptr, &master, nullptr };
    int res = func_00271500((ActionRebind*)&action, 0);
    assert(res == 0);
    assert(g_func_26AD20_called == 1);
}

static void test_actor_check_fails_returns_zero() {
    reset_state();
    DummyStatusMaster master = { {}, 39, {}, 12 };
    DummyStatusVTable vt_actor = { { nullptr }, mock_m1 };
    DummyStatusActor actor = { {}, nullptr, {}, (void*)0xAAAA, {}, &vt_actor };
    DummyStatusAction action = { nullptr, &master, &actor };
    g_m1_return = 0;

    int res = func_00271500((ActionRebind*)&action, 1);
    assert(res == 0);
    assert(g_m1_called == 1 && g_m2_called == 0);
}

static void test_all_checks_succeed_returns_one() {
    reset_state();
    DummyStatusMaster master = { {}, 39, {}, 12 };
    DummyStatusVTable vt_actor = { { nullptr }, mock_m1 };
    DummyStatusVTable vt_target = { { nullptr }, mock_m2 };
    DummyStatusPlayer target_player = { {}, (void*)0xBBBB, {}, &vt_target };
    DummyStatusPlayer *players[2] = { nullptr, &target_player };
    DummyStatusWorld world = { {}, players };
    DummyStatusActor actor = { {}, &world, {}, (void*)0xAAAA, {}, &vt_actor };
    DummyStatusAction action = { nullptr, &master, &actor };

    g_m1_return = 1;
    g_m2_return = 1;

    int res = func_00271500((ActionRebind*)&action, 1);
    assert(res == 1);
    assert(g_m1_called == 1 && g_m2_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_field_e_not_39_returns_zero();
        test_field_1a2_negative_one_returns_zero();
        test_flag_2000_set_returns_zero();
        test_actor_check_fails_returns_zero();
        test_all_checks_succeed_returns_one();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_field_e_not_39_returns_zero(); break;
        case 1: test_field_1a2_negative_one_returns_zero(); break;
        case 2: test_flag_2000_set_returns_zero(); break;
        case 3: test_actor_check_fails_returns_zero(); break;
        case 4: test_all_checks_succeed_returns_one(); break;
        default: return 1;
    }
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_work_fixture.h"

static_assert(offsetof(DummyWorkMaster, m_field1A2) == 0x1A2, "master.m_field1A2 offset");
static_assert(offsetof(DummyWorkActor, m_world) == 0xB98, "actor.m_world offset");
static_assert(offsetof(DummyWorkActor, m_subsystem) == 0x1B30, "actor.m_subsystem offset");
static_assert(offsetof(DummyWorkWorld, m_delta_time) == 0xAC, "world.m_delta_time offset");
static_assert(offsetof(DummyWorkAction, m_field24) == 0x24, "action.m_field24 offset");
static_assert(offsetof(DummyWorkAction, m_field39) == 0x39, "action.m_field39 offset");
static_assert(offsetof(DummyWorkAction, m_timer174) == 0x174, "action.m_timer174 offset");

float D_004E2824 = 1.0e-7f;
char D_00D8EBC0[256];

static int g_method13c_calls = 0;
static int g_method140_calls = 0;
static short g_last_arg24 = 0;

static void mock_method13c(void *actor, short field24) {
    (void)actor;
    g_method13c_calls++;
    g_last_arg24 = field24;
}

static void mock_method140(void *actor, short field24) {
    (void)actor;
    g_method140_calls++;
    g_last_arg24 = field24;
}

static int g_mock_flag2000 = 0;
static float g_mock_3675d0_val = 0.0f;
static int g_mock_out_valid = 0;
static int g_mock_out_count = 0;

extern "C" {
    char func_26AD20(void *action, int flag) {
        (void)action;
        if (flag == 0x2000) {
            return (char)g_mock_flag2000;
        }
        return 0;
    }

    float func_3675D0(void *action) {
        (void)action;
        return g_mock_3675d0_val;
    }

    void func_2717B0(void *action, void *buffer, int *out_valid, int count, int *out_count) {
        (void)action;
        (void)buffer;
        (void)count;
        *out_valid = g_mock_out_valid;
        *out_count = g_mock_out_count;
    }
}

static void reset_mocks() {
    g_method13c_calls = 0;
    g_method140_calls = 0;
    g_last_arg24 = 0;
    g_mock_flag2000 = 0;
    g_mock_3675d0_val = 0.0f;
    g_mock_out_valid = 0;
    g_mock_out_count = 0;
}

static void test_invalid_master_returns_early() {
    reset_mocks();
    DummyWorkMaster master = { {}, -1 };
    DummyWorkAction action = { nullptr, &master, nullptr, {}, 10, {}, 2, {}, 0.0f };
    func_00271640((ActionRebind*)&action);
    assert(g_method13c_calls == 0 && g_method140_calls == 0);
}

static void test_non_working_state_returns_early() {
    reset_mocks();
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, nullptr, {}, 10, {}, 1, {}, 0.0f };
    func_00271640((ActionRebind*)&action);
    assert(g_method13c_calls == 0 && g_method140_calls == 0);
}

static void test_flag_2000_active_and_positive_3675d0_returns() {
    reset_mocks();
    g_mock_flag2000 = 1;
    g_mock_3675d0_val = 1.0f;
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, nullptr, {}, 10, {}, 2, {}, 0.0f };
    func_00271640((ActionRebind*)&action);
    assert(g_method13c_calls == 0 && g_method140_calls == 0);
}

static void test_positive_3675d0_triggers_method140() {
    reset_mocks();
    g_mock_flag2000 = 0;
    g_mock_3675d0_val = 1.0f;
    g_mock_out_count = 5;
    DummyWorkSubsystem sub = { {}, mock_method13c, mock_method140 };
    DummyWorkActor actor = { {}, nullptr, {}, &sub };
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, &actor, {}, 42, {}, 2, {}, 0.8f };
    func_00271640((ActionRebind*)&action);
    assert(g_method140_calls == 1 && g_last_arg24 == 42);
    assert(action.m_timer174 == 0.0f);
}

static void test_timer_reset_to_half_second_when_non_positive() {
    reset_mocks();
    g_mock_flag2000 = 0;
    g_mock_3675d0_val = 0.0f;
    g_mock_out_valid = 0;
    DummyWorkSubsystem sub = { {}, mock_method13c, mock_method140 };
    DummyWorkActor actor = { {}, nullptr, {}, &sub };
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, &actor, {}, 42, {}, 2, {}, 0.0f };
    func_00271640((ActionRebind*)&action);
    assert(action.m_timer174 == 0.5f);
    assert(g_method13c_calls == 0);
}

static void test_timer_countdown_triggers_method13c() {
    reset_mocks();
    g_mock_flag2000 = 0;
    g_mock_3675d0_val = 0.0f;
    g_mock_out_valid = 0;
    DummyWorkWorld world = { {}, 0.6f };
    DummyWorkSubsystem sub = { {}, mock_method13c, mock_method140 };
    DummyWorkActor actor = { {}, &world, {}, &sub };
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, &actor, {}, 77, {}, 2, {}, 0.4f };
    func_00271640((ActionRebind*)&action);
    assert(g_method13c_calls == 1 && g_last_arg24 == 77);
    assert(action.m_timer174 == 0.0f);
}

static void test_timer_countdown_decrement_only() {
    reset_mocks();
    g_mock_flag2000 = 0;
    g_mock_3675d0_val = 0.0f;
    g_mock_out_valid = 0;
    DummyWorkWorld world = { {}, 0.1f };
    DummyWorkSubsystem sub = { {}, mock_method13c, mock_method140 };
    DummyWorkActor actor = { {}, &world, {}, &sub };
    DummyWorkMaster master = { {}, 1 };
    DummyWorkAction action = { nullptr, &master, &actor, {}, 77, {}, 2, {}, 0.5f };
    func_00271640((ActionRebind*)&action);
    assert(g_method13c_calls == 0);
    assert(action.m_timer174 > 0.39f && action.m_timer174 < 0.41f);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_invalid_master_returns_early();
        test_non_working_state_returns_early();
        test_flag_2000_active_and_positive_3675d0_returns();
        test_positive_3675d0_triggers_method140();
        test_timer_reset_to_half_second_when_non_positive();
        test_timer_countdown_triggers_method13c();
        test_timer_countdown_decrement_only();
        return 0;
    }
    int t = atoi(argv[1]);
    switch (t) {
        case 0: test_invalid_master_returns_early(); break;
        case 1: test_non_working_state_returns_early(); break;
        case 2: test_flag_2000_active_and_positive_3675d0_returns(); break;
        case 3: test_positive_3675d0_triggers_method140(); break;
        case 4: test_timer_reset_to_half_second_when_non_positive(); break;
        case 5: test_timer_countdown_triggers_method13c(); break;
        case 6: test_timer_countdown_decrement_only(); break;
        default: return 1;
    }
    return 0;
}

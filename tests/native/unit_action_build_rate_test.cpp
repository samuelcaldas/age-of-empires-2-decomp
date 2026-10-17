#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "unit_action_build_rate_fixture.h"

static int g_func_195F40_called = 0;
static int g_func_27B700_called = 0;
static int g_method84_called = 0;
static int g_method7C_called = 0;

static std::vector<int> g_stat_ids;
static std::vector<float> g_stat_vals;

extern "C" {
    void func_195F40(void *action, void *player) {
        (void)action; (void)player;
        g_func_195F40_called++;
    }
    void func_27B700(void *action, int type, float val, float fzero, int zero) {
        (void)action; (void)type; (void)val; (void)fzero; (void)zero;
        g_func_27B700_called++;
    }
}

static void mock_m84(void *p) {
    (void)p;
    g_method84_called++;
}

static void mock_m7C(void *obj, int stat_id, float val, int zero) {
    (void)obj; (void)zero;
    g_method7C_called++;
    g_stat_ids.push_back(stat_id);
    g_stat_vals.push_back(val);
}

static void reset_test_state() {
    g_func_195F40_called = 0;
    g_func_27B700_called = 0;
    g_method84_called = 0;
    g_method7C_called = 0;
    g_stat_ids.clear();
    g_stat_vals.clear();
}

// Case 0: Subaction early exit when has_subactions != 0 and p304 != null
static void test_subactions_early_exit() {
    reset_test_state();
    DummySubActionVTable svt = {};
    svt.m_method84 = (void*)mock_m84;
    DummySubAction sub = { &svt };

    DummyAction action = {};
    action.m_time = 10.0f;
    action.m_p304 = &sub;

    func_0026EF50((ActionRebind*)&action, 0, 0, nullptr, 0, 1);

    assert(g_method84_called == 1);
    assert(g_func_195F40_called == 0);
}

// Case 1: time <= 0 early return
static void test_zero_time_exit() {
    reset_test_state();
    DummyPlayerVTable pvt = {};
    pvt.m_method7C = (void*)mock_m7C;
    DummyPlayer player = {};
    player.m_vtable = &pvt;

    DummyAction action = {};
    action.m_world = &player;
    action.m_time = 0.0f;

    func_0026EF50((ActionRebind*)&action, 0, 0, &player, 0, 0);

    assert(g_func_195F40_called == 0);
    assert(g_method7C_called == 0);
}

// Case 2: Matching unit type 42 calculates rate from resource slots and emits stats
static void test_matching_type_stats() {
    reset_test_state();
    DummyPlayerVTable pvt = {};
    pvt.m_method7C = (void*)mock_m7C;

    DummyPlayer player = {};
    player.m_vtable = &pvt;

    DummyPlayer world = {};
    world.m_player_count = 2; // pidx = 1
    world.m_vtable = &pvt;

    DummyMasterUnit master = {};
    master.m_type = 42; // matching type
    master.m_slots[0].m_resource_id = 1;
    master.m_slots[0].m_amount = 50;
    master.m_slots[0].m_mode = 1;

    master.m_slots[1].m_resource_id = 2;
    master.m_slots[1].m_amount = 30;
    master.m_slots[1].m_mode = 1;

    master.m_slots[2].m_resource_id = -1; // ignored

    DummyChildAction child0 = {};
    child0.m_time = 0.0f;

    DummyAction action = {};
    action.m_master = &master;
    action.m_world = &world;
    action.m_time = 5.0f;
    action.m_children[0] = &child0;

    func_0026EF50((ActionRebind*)&action, 0, 0, &player, 0, 0);

    assert(g_func_195F40_called == 1);
    assert(g_method7C_called == 9); // 9 stat calls
    assert(std::fabs(g_stat_vals[1] - 80.0f) < 0.0001f); // 50 + 30 = 80.0f
    assert(action.m_flag59 == 60);
    assert(child0.m_time == action.m_time);
}

// Case 3: Non-matching unit type emits non-matching stat sequence
static void test_non_matching_type_stats() {
    reset_test_state();
    DummyPlayerVTable pvt = {};
    pvt.m_method7C = (void*)mock_m7C;

    DummyPlayer player = {};
    player.m_vtable = &pvt;

    DummyPlayer world = {};
    world.m_player_count = 3;
    world.m_vtable = &pvt;

    DummyMasterUnit master = {};
    master.m_type = 99; // non-matching type
    master.m_slots[0].m_resource_id = 0;
    master.m_slots[0].m_amount = 100;
    master.m_slots[0].m_mode = 1;

    DummyAction action = {};
    action.m_master = &master;
    action.m_world = &world;
    action.m_time = 4.0f;

    func_0026EF50((ActionRebind*)&action, 0, 0, &player, 0, 0);

    assert(g_func_195F40_called == 1);
    assert(g_method7C_called == 9);
    assert(action.m_flag59 == 60);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_subactions_early_exit();
        test_zero_time_exit();
        test_matching_type_stats();
        test_non_matching_type_stats();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_subactions_early_exit(); break;
        case 1: test_zero_time_exit(); break;
        case 2: test_matching_type_stats(); break;
        case 3: test_non_matching_type_stats(); break;
        default: return 1;
    }
    return 0;
}

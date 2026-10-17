#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker_add_fixture.h"

static int g_func_278D50_called = 0;
static void *g_last_278D50_self = nullptr;
static void *g_last_278D50_target = nullptr;

extern "C" {
    void func_278D50(void *self, void *target) {
        g_func_278D50_called++;
        g_last_278D50_self = self;
        g_last_278D50_target = target;
    }
}

static void reset_test_state() {
    g_func_278D50_called = 0;
    g_last_278D50_self = nullptr;
    g_last_278D50_target = nullptr;
}

// Case 0: Non-70 and non-42 target forwards to func_278D50 with zero increments
static void test_non_matching_target() {
    reset_test_state();
    DummyTargetMaster tmaster = {};
    tmaster.m_unit_class = 10;
    tmaster.m_worker_type = 20;

    DummyTarget target = {};
    target.m_field4 = &tmaster;
    target.m_flag118 = 1;

    DummyAction action = {};
    action.m_building_count = 5;
    action.m_worker_count = 10;

    func_0026F430((ActionRebind*)&action, &target);

    assert(g_func_278D50_called == 1);
    assert(g_last_278D50_self == &action);
    assert(g_last_278D50_target == &target);
    assert(action.m_building_count == 5);
    assert(action.m_worker_count == 10);
}

// Case 1: Target with unit_class == 70 and flag118 != 0 increments building count
static void test_building_count_increment() {
    reset_test_state();
    DummyTargetMaster tmaster = {};
    tmaster.m_unit_class = 70; // 0x46
    tmaster.m_worker_type = 10;

    DummyTarget target = {};
    target.m_field4 = &tmaster;
    target.m_flag118 = 1;

    DummyAction action = {};
    action.m_building_count = 2;
    action.m_worker_count = 7;

    func_0026F430((ActionRebind*)&action, &target);

    assert(g_func_278D50_called == 1);
    assert(action.m_building_count == 3); // 2 + 1
    assert(action.m_worker_count == 7);
}

// Case 2: Target with worker_type == 42 and flagBA5 != 0 increments worker count and rate
static void test_worker_count_and_rate_increment() {
    reset_test_state();
    DummyTargetMaster tmaster = {};
    tmaster.m_unit_class = 15;
    tmaster.m_worker_type = 42; // 0x2A

    DummyTarget target = {};
    target.m_field4 = &tmaster;

    DummyWorldNode node = {};
    node.m_rate = 12.5f;

    DummyWorld world = {};
    world.m_flagBA5 = 1;
    world.m_nodeBAC = &node;

    DummyAction action = {};
    action.m_world = &world;
    action.m_building_count = 4;
    action.m_worker_count = 9;

    func_0026F430((ActionRebind*)&action, &target);

    assert(g_func_278D50_called == 1);
    assert(action.m_building_count == 4);
    assert(action.m_worker_count == 10); // 9 + 1
    assert(std::fabs(node.m_rate - 13.5f) < 0.0001f); // 12.5 + 1.0
}

// Case 3: Both conditions met increments building count, worker count, and rate
static void test_both_increments() {
    reset_test_state();
    DummyTargetMaster tmaster = {};
    tmaster.m_unit_class = 70;
    tmaster.m_worker_type = 42;

    DummyTarget target = {};
    target.m_field4 = &tmaster;
    target.m_flag118 = 1;

    DummyWorldNode node = {};
    node.m_rate = 0.0f;

    DummyWorld world = {};
    world.m_flagBA5 = 1;
    world.m_nodeBAC = &node;

    DummyAction action = {};
    action.m_world = &world;
    action.m_building_count = 0;
    action.m_worker_count = 0;

    func_0026F430((ActionRebind*)&action, &target);

    assert(g_func_278D50_called == 1);
    assert(action.m_building_count == 1);
    assert(action.m_worker_count == 1);
    assert(std::fabs(node.m_rate - 1.0f) < 0.0001f);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_non_matching_target();
        test_building_count_increment();
        test_worker_count_and_rate_increment();
        test_both_increments();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_non_matching_target(); break;
        case 1: test_building_count_increment(); break;
        case 2: test_worker_count_and_rate_increment(); break;
        case 3: test_both_increments(); break;
        default: return 1;
    }
    return 0;
}

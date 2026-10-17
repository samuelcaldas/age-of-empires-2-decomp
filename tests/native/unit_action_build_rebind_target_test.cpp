#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_rebind_target_fixture.h"

static int g_func_274C90_called = 0;
static float g_mock_rate = 100.0f;

extern "C" {
    float func_274C90(void *self, void *target) {
        (void)self; (void)target;
        g_func_274C90_called++;
        return g_mock_rate;
    }
}

static void reset_test_state() {
    g_func_274C90_called = 0;
    g_mock_rate = 100.0f;
}

// Case 0: zero workers and non-80 target preserves rate unchanged
static void test_neutral_rate() {
    reset_test_state();
    DummyTargetMaster tmaster = { 10 };
    DummyTarget target = { {}, &tmaster, {}, 0 };
    DummyRebindAction action = {};
    action.m_worker_count = 0;

    float ret = func_002709B0((ActionRebind*)&action, &target);

    assert(g_func_274C90_called == 1);
    assert(std::fabs(ret - 100.0f) < 0.0001f);
}

// Case 1: self worker count > 0 multiplies rate by 1.1f
static void test_self_worker_boost() {
    reset_test_state();
    DummyTargetMaster tmaster = { 10 };
    DummyTarget target = { {}, &tmaster, {}, 0 };
    DummyRebindAction action = {};
    action.m_worker_count = 2; // > 0!

    float ret = func_002709B0((ActionRebind*)&action, &target);

    assert(g_func_274C90_called == 1);
    assert(std::fabs(ret - 110.0f) < 0.0001f); // 100 * 1.1
}

// Case 2: target class == 80 and target workers > 0 divides rate by 1.1f
static void test_target_worker_resistance() {
    reset_test_state();
    DummyTargetMaster tmaster = { 80 }; // class 80!
    DummyTarget target = { {}, &tmaster, {}, 3 }; // > 0!
    DummyRebindAction action = {};
    action.m_worker_count = 0;

    float ret = func_002709B0((ActionRebind*)&action, &target);

    assert(g_func_274C90_called == 1);
    assert(std::fabs(ret - (100.0f / 1.1f)) < 0.0001f);
}

// Case 3: both conditions active applies boost and resistance
static void test_both_active() {
    reset_test_state();
    DummyTargetMaster tmaster = { 80 };
    DummyTarget target = { {}, &tmaster, {}, 1 };
    DummyRebindAction action = {};
    action.m_worker_count = 1;

    float ret = func_002709B0((ActionRebind*)&action, &target);

    assert(g_func_274C90_called == 1);
    assert(std::fabs(ret - 100.0f) < 0.0001f); // (100 * 1.1) / 1.1
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_neutral_rate();
        test_self_worker_boost();
        test_target_worker_resistance();
        test_both_active();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_neutral_rate(); break;
        case 1: test_self_worker_boost(); break;
        case 2: test_target_worker_resistance(); break;
        case 3: test_both_active(); break;
        default: return 1;
    }
    return 0;
}

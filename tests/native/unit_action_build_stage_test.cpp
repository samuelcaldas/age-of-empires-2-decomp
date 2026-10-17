#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_stage_fixture.h"

static int g_func_df340_called = 0;
static ActionRebind *g_last_df340_self = nullptr;
static void *g_last_df340_arg1 = nullptr;

static int g_method12_called = 0;
static void *g_last_method12_fC = nullptr;
static void *g_last_method12_f10 = nullptr;
static int g_mock_method12_result = 0;

static int g_method36_called = 0;
static void *g_last_method36_fC = nullptr;
static void *g_last_method36_f10 = nullptr;
static int g_last_method36_step = -1;

extern "C" {
    void func_001DF340(ActionRebind *self, void *arg1) {
        g_func_df340_called++;
        g_last_df340_self = self;
        g_last_df340_arg1 = arg1;
    }
}

static int mock_method12(void *fC, void *f10) {
    g_method12_called++;
    g_last_method12_fC = fC;
    g_last_method12_f10 = f10;
    return g_mock_method12_result;
}

static void mock_method36(void *fC, void *f10, int step) {
    g_method36_called++;
    g_last_method36_fC = fC;
    g_last_method36_f10 = f10;
    g_last_method36_step = step;
}

static void reset_test_state() {
    g_func_df340_called = 0;
    g_last_df340_self = nullptr;
    g_last_df340_arg1 = nullptr;
    g_method12_called = 0;
    g_last_method12_fC = nullptr;
    g_last_method12_f10 = nullptr;
    g_mock_method12_result = 0;
    g_method36_called = 0;
    g_last_method36_fC = nullptr;
    g_last_method36_f10 = nullptr;
    g_last_method36_step = -1;
}

// Case 0: Non-70 unit class forwards directly to func_001DF340
static void test_non_70_class() {
    reset_test_state();
    DummyMaster master = {};
    master.m_unit_class = 42;
    DummyAction action = {};
    action.m_field4 = &master;
    int dummy_arg = 0x1234;
    func_0026EEA0((ActionRebind*)&action, &dummy_arg);

    assert(g_method12_called == 0);
    assert(g_method36_called == 0);
    assert(g_func_df340_called == 1);
    assert(g_last_df340_self == (ActionRebind*)&action);
    assert(g_last_df340_arg1 == &dummy_arg);
}

// Case 1: Unit class 70 with null field10 forwards to func_001DF340
static void test_null_field10() {
    reset_test_state();
    DummyMaster master = {};
    master.m_unit_class = 70;
    DummyAction action = {};
    action.m_field4 = &master;
    void *dummy_arg = (void*)0x5678;
    func_0026EEA0((ActionRebind*)&action, dummy_arg);

    assert(g_method12_called == 0);
    assert(g_method36_called == 0);
    assert(g_func_df340_called == 1);
    assert(g_last_df340_self == (ActionRebind*)&action);
    assert(g_last_df340_arg1 == dummy_arg);
}

// Case 2: Unit class 70 with res + 1 < max_val increments step and forwards
static void test_step_increment() {
    reset_test_state();
    DummyMaster master = {};
    master.m_unit_class = 70;
    DummySubVTable vtable = {};
    vtable.m_method12 = (void*)mock_method12;
    vtable.m_method36 = (void*)mock_method36;
    DummyZone zone = {};
    zone.m_vtable = &vtable;
    DummyTarget target = {};
    target.m_max_step = 5;

    DummyAction action = {};
    action.m_field4 = &master;
    action.m_fieldC = &zone;
    action.m_field10 = &target;
    g_mock_method12_result = 2; // res 2 -> next 3 (< 5)

    int dummy_arg = 999;
    func_0026EEA0((ActionRebind*)&action, &dummy_arg);

    assert(g_method12_called == 1 && g_last_method12_fC == &zone);
    assert(g_method36_called == 1 && g_last_method36_step == 3);
    assert(g_func_df340_called == 1 && g_last_df340_arg1 == &dummy_arg);
}

// Case 3: Unit class 70 with res + 1 >= max_val wraps step around to 0
static void test_step_wraparound() {
    reset_test_state();
    DummyMaster master = {};
    master.m_unit_class = 70;
    DummySubVTable vtable = {};
    vtable.m_method12 = (void*)mock_method12;
    vtable.m_method36 = (void*)mock_method36;
    DummyZone zone = {};
    zone.m_vtable = &vtable;
    DummyTarget target = {};
    target.m_max_step = 4;

    DummyAction action = {};
    action.m_field4 = &master;
    action.m_fieldC = &zone;
    action.m_field10 = &target;
    g_mock_method12_result = 3; // res 3 -> next 4 (>= 4 -> wrap 0)

    func_0026EEA0((ActionRebind*)&action, (void*)0xABCD);

    assert(g_method12_called == 1 && g_method36_called == 1);
    assert(g_last_method36_step == 0);
    assert(g_func_df340_called == 1 && g_last_df340_arg1 == (void*)0xABCD);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_non_70_class();
        test_null_field10();
        test_step_increment();
        test_step_wraparound();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_non_70_class(); break;
        case 1: test_null_field10(); break;
        case 2: test_step_increment(); break;
        case 3: test_step_wraparound(); break;
        default: return 1;
    }
    return 0;
}

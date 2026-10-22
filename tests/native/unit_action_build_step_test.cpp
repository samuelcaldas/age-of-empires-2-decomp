#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_step_fixture.h"

static int g_func_123350_called = 0;
static float g_last_123350_val = 0.0f;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        g_last_123350_val = val;
        return (int)val;
    }
}

static void reset_state() {
    g_func_123350_called = 0;
    g_last_123350_val = 0.0f;
}

static void test_limit_less_than_val() {
    reset_state();
    DummyStepMaster master = { {}, 5, {}, 4.0f };
    DummyStepAction action = { nullptr, &master, {}, 10.0f };
    int res = func_00270E70((ActionRebind*)&action);
    assert(g_func_123350_called == 1 && g_last_123350_val == 10.0f);
    assert(res == 4);
}

static void test_limit_greater_or_equal_val() {
    reset_state();
    DummyStepMaster master = { {}, 8, {}, 12.0f };
    DummyStepAction action = { nullptr, &master, {}, 6.0f };
    int res = func_00270E70((ActionRebind*)&action);
    assert(g_func_123350_called == 1 && g_last_123350_val == 12.0f);
    assert(res == 7);
}

static void test_step_clamping_to_max_step() {
    reset_state();
    DummyStepMaster master = { {}, 3, {}, 2.0f };
    DummyStepAction action = { nullptr, &master, {}, 20.0f };
    int res = func_00270E70((ActionRebind*)&action);
    assert(res == 2);
}

static void test_zero_or_negative_step() {
    reset_state();
    DummyStepMaster master = { {}, 0, {}, 0.0f };
    DummyStepAction action = { nullptr, &master, {}, 0.0f };
    int res = func_00270E70((ActionRebind*)&action);
    assert(res == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_limit_less_than_val();
        test_limit_greater_or_equal_val();
        test_step_clamping_to_max_step();
        test_zero_or_negative_step();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_limit_less_than_val(); break;
        case 1: test_limit_greater_or_equal_val(); break;
        case 2: test_step_clamping_to_max_step(); break;
        case 3: test_zero_or_negative_step(); break;
        default: return 1;
    }
    return 0;
}

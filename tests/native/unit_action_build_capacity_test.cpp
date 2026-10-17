#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_capacity_fixture.h"

static void reset_test_state() {
    g_func_268500_ret = 1;
    g_func_268530_ret = 10;
}

static void test_func_268500_zero_returns_zero() {
    reset_test_state();
    g_func_268500_ret = 0;
    DummyCapacityAction action = { nullptr, {}, 5 };
    int ret = func_00271460((ActionRebind*)&action);
    assert(ret == 0);
}

static void test_calculates_difference_correctly() {
    reset_test_state();
    g_func_268500_ret = 1;
    g_func_268530_ret = 15;
    DummyCapacityAction action = { nullptr, {}, 6 };
    int ret = func_00271460((ActionRebind*)&action);
    assert(ret == 9);
}

static void test_handles_zero_difference() {
    reset_test_state();
    g_func_268500_ret = 1;
    g_func_268530_ret = 8;
    DummyCapacityAction action = { nullptr, {}, 8 };
    int ret = func_00271460((ActionRebind*)&action);
    assert(ret == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_268500_zero_returns_zero();
        test_calculates_difference_correctly();
        test_handles_zero_difference();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_func_268500_zero_returns_zero();
    if (t == 1) test_calculates_difference_correctly();
    if (t == 2) test_handles_zero_difference();
    return 0;
}

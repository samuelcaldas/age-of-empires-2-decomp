#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_offset_query_fixture.h"

static int g_func_268500_called = 0;
static int g_mock_268500_return = 0;
static int g_func_268530_called = 0;
static int g_mock_268530_return = 0;

extern "C" {
    int func_00268500(ActionRebind *self) {
        (void)self;
        g_func_268500_called++;
        return g_mock_268500_return;
    }
    int func_00268530(ActionRebind *self) {
        (void)self;
        g_func_268530_called++;
        return g_mock_268530_return;
    }
}

static void reset_state() {
    g_func_268500_called = g_func_268530_called = 0;
    g_mock_268500_return = g_mock_268530_return = 0;
}

static void test_invalid_target_returns_zero() {
    reset_state();
    g_mock_268500_return = 0;
    DummyOffsetAction action = { nullptr, {}, 25 };
    int res = func_00271460((ActionRebind*)&action);
    assert(g_func_268500_called == 1 && g_func_268530_called == 0);
    assert(res == 0);
}

static void test_valid_target_subtracts_offset() {
    reset_state();
    g_mock_268500_return = 1;
    g_mock_268530_return = 50;
    DummyOffsetAction action = { nullptr, {}, 20 };
    int res = func_00271460((ActionRebind*)&action);
    assert(g_func_268500_called == 1 && g_func_268530_called == 1);
    assert(res == 30);
}

static void test_negative_result_preserved() {
    reset_state();
    g_mock_268500_return = 1;
    g_mock_268530_return = 10;
    DummyOffsetAction action = { nullptr, {}, 15 };
    int res = func_00271460((ActionRebind*)&action);
    assert(g_func_268500_called == 1 && g_func_268530_called == 1);
    assert(res == -5);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_invalid_target_returns_zero();
        test_valid_target_subtracts_offset();
        test_negative_result_preserved();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_invalid_target_returns_zero(); break;
        case 1: test_valid_target_subtracts_offset(); break;
        case 2: test_negative_result_preserved(); break;
        default: return 1;
    }
    return 0;
}

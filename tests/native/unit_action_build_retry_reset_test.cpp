#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_retry_reset_fixture.h"

static int g_func_270BA0_called = 0;
static void *g_last_call_self = nullptr;
static int g_last_call_status = 0;

extern "C" {
    void func_270BA0(ActionRebind *self, int status) {
        g_func_270BA0_called++;
        g_last_call_self = self;
        g_last_call_status = status;
    }
}

static void reset_test_state() {
    g_func_270BA0_called = 0;
    g_last_call_self = nullptr;
    g_last_call_status = 0;
}

static void test_status_0xff_does_nothing() {
    reset_test_state();
    DummyResetAction action = { nullptr, {}, 0xFF };
    func_00270E30((ActionRebind*)&action);
    assert(g_func_270BA0_called == 0);
    assert(action.m_field15A == 0xFF);
}

static void test_valid_status_8_dispatches_and_resets() {
    reset_test_state();
    DummyResetAction action = { nullptr, {}, 8 };
    func_00270E30((ActionRebind*)&action);
    assert(g_func_270BA0_called == 1);
    assert(g_last_call_self == &action);
    assert(g_last_call_status == 8);
    assert(action.m_field15A == 0xFF);
}

static void test_valid_status_27_dispatches_and_resets() {
    reset_test_state();
    DummyResetAction action = { nullptr, {}, 27 };
    func_00270E30((ActionRebind*)&action);
    assert(g_func_270BA0_called == 1);
    assert(g_last_call_self == &action);
    assert(g_last_call_status == 27);
    assert(action.m_field15A == 0xFF);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_status_0xff_does_nothing();
        test_valid_status_8_dispatches_and_resets();
        test_valid_status_27_dispatches_and_resets();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_status_0xff_does_nothing();
    if (t == 1) test_valid_status_8_dispatches_and_resets();
    if (t == 2) test_valid_status_27_dispatches_and_resets();
    return 0;
}

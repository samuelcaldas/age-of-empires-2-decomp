#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_flag_2000_get_fixture.h"

static int g_func_26AD20_called = 0;
static void *g_last_action = nullptr;
static int g_last_flag = 0;
static int g_mock_flag_return = 0;

extern "C" {
    char func_26AD20(void *action, int flag) {
        g_func_26AD20_called++;
        g_last_action = action;
        g_last_flag = flag;
        return (char)g_mock_flag_return;
    }
}

static void reset_state() {
    g_func_26AD20_called = 0;
    g_last_action = nullptr;
    g_last_flag = 0;
    g_mock_flag_return = 0;
}

static void test_flag_unset_returns_zero() {
    reset_state();
    g_mock_flag_return = 0;
    DummyFlagAction action = { nullptr };
    char res = func_002715E0((ActionRebind*)&action);
    assert(g_func_26AD20_called == 1 && g_last_action == &action && g_last_flag == 0x2000);
    assert(res == 0);
}

static void test_flag_set_returns_one() {
    reset_state();
    g_mock_flag_return = 1;
    DummyFlagAction action = { nullptr };
    char res = func_002715E0((ActionRebind*)&action);
    assert(g_func_26AD20_called == 1 && g_last_action == &action && g_last_flag == 0x2000);
    assert(res == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_flag_unset_returns_zero();
        test_flag_set_returns_one();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_flag_unset_returns_zero(); break;
        case 1: test_flag_set_returns_one(); break;
        default: return 1;
    }
    return 0;
}

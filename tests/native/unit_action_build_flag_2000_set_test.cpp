#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_flag_2000_set_fixture.h"

static int g_func_26AD30_called = 0;
static void *g_last_set_action = nullptr;
static int g_last_set_flag = 0;
static int g_last_set_enable = 0;

static int g_func_26AD20_called = 0;
static int g_mock_flag_2000_result = 0;

static DummyF404 g_f404 = { {}, 123456 };
static DummySetGame g_game = { {}, &g_f404 };
void *D_004E3180 = &g_game;

extern "C" {
    void func_26AD30(void *action, int flag, int enable) {
        g_func_26AD30_called++;
        g_last_set_action = action;
        g_last_set_flag = flag;
        g_last_set_enable = enable;
    }
    char func_26AD20(void *action, int flag) {
        (void)action;
        g_func_26AD20_called++;
        if (flag == 0x2000) {
            return (char)g_mock_flag_2000_result;
        }
        return 0;
    }
}

static void reset_state() {
    g_func_26AD30_called = g_func_26AD20_called = 0;
    g_last_set_action = nullptr;
    g_last_set_flag = g_last_set_enable = 0;
    g_mock_flag_2000_result = 0;
}

static void test_flag_active_updates_field_c0() {
    reset_state();
    g_mock_flag_2000_result = 1;
    DummySetAction action = { nullptr, {}, 0 };
    func_002715F0((ActionRebind*)&action, 1);
    assert(g_func_26AD30_called == 1 && g_last_set_flag == 0x2000 && g_last_set_enable == 1);
    assert(g_func_26AD20_called == 1);
    assert(action.m_fieldC0 == 123456);
}

static void test_flag_inactive_leaves_field_c0_untouched() {
    reset_state();
    g_mock_flag_2000_result = 0;
    DummySetAction action = { nullptr, {}, 999 };
    func_002715F0((ActionRebind*)&action, 0);
    assert(g_func_26AD30_called == 1 && g_last_set_flag == 0x2000 && g_last_set_enable == 0);
    assert(g_func_26AD20_called == 1);
    assert(action.m_fieldC0 == 999);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_flag_active_updates_field_c0();
        test_flag_inactive_leaves_field_c0_untouched();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_flag_active_updates_field_c0(); break;
        case 1: test_flag_inactive_leaves_field_c0_untouched(); break;
        default: return 1;
    }
    return 0;
}

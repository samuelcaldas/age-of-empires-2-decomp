#include <cassert>
#include <cstdlib>
#include "zone_cursor_controller_timer_tick.h"

// Mocks for native test
static int g_mock_time = 0;
static void *g_mock_1947b0_arg = 0;
static int g_mock_1947b0_calls = 0;
static int g_mock_1db6b0_ret = 1;
static int g_mock_1db6b0_calls = 0;
void *D_004E3108 = (void *)0x12345678;

extern "C" {
int func_2261c0() {
    return g_mock_time;
}

void func_1947B0(void *ptr) {
    g_mock_1947b0_arg = ptr;
    g_mock_1947b0_calls++;
}

int func_001DB6B0(void *self) {
    g_mock_1db6b0_calls++;
    return g_mock_1db6b0_ret;
}
}

static void test_timer1_trigger() {
    CursorController ctrl;
    for (int i = 0; i < sizeof(ctrl); i++) ((char *)&ctrl)[i] = 0;

    ctrl.f148 = 1;
    ctrl.f144 = 100;
    g_mock_time = 151; // 151 - 100 = 51 > 50 (0x32)
    g_mock_1947b0_calls = 0;
    g_mock_1947b0_arg = 0;

    func_001DB7F0(&ctrl);

    assert(ctrl.f144 == 151);
    assert(g_mock_1947b0_calls == 1);
    assert(g_mock_1947b0_arg == (void *)0x12345678);
}

static void test_timer1_not_trigger() {
    CursorController ctrl;
    for (int i = 0; i < sizeof(ctrl); i++) ((char *)&ctrl)[i] = 0;

    // Case A: f148 == 0
    ctrl.f148 = 0;
    ctrl.f144 = 100;
    g_mock_time = 200;
    g_mock_1947b0_calls = 0;
    func_001DB7F0(&ctrl);
    assert(ctrl.f144 == 100);
    assert(g_mock_1947b0_calls == 0);

    // Case B: dt <= 50 (0x32)
    ctrl.f148 = 1;
    ctrl.f144 = 100;
    g_mock_time = 150; // 150 - 100 = 50 <= 50
    func_001DB7F0(&ctrl);
    assert(ctrl.f144 == 100);
    assert(g_mock_1947b0_calls == 0);
}

static void test_timer2_trigger() {
    CursorController ctrl;
    for (int i = 0; i < sizeof(ctrl); i++) ((char *)&ctrl)[i] = 0;

    ctrl.f38 = 100;
    ctrl.f34 = 1;
    ctrl.f14 = 77;
    ctrl.f18 = 0;
    g_mock_time = 134; // 134 - 100 = 34 (0x22) >= 0x22
    g_mock_1db6b0_ret = 1;
    g_mock_1db6b0_calls = 0;

    func_001DB7F0(&ctrl);

    assert(ctrl.f38 == 134);
    assert(g_mock_1db6b0_calls == 1);
    assert(ctrl.f18 == 77);
}

static void test_timer2_not_trigger() {
    CursorController ctrl;
    for (int i = 0; i < sizeof(ctrl); i++) ((char *)&ctrl)[i] = 0;

    // Case A: dt < 34 (0x22)
    ctrl.f38 = 100;
    g_mock_time = 133;
    g_mock_1db6b0_calls = 0;
    func_001DB7F0(&ctrl);
    assert(ctrl.f38 == 100);
    assert(g_mock_1db6b0_calls == 0);

    // Case B: func_001DB6B0 returns 0
    ctrl.f38 = 100;
    g_mock_time = 140;
    g_mock_1db6b0_ret = 0;
    g_mock_1db6b0_calls = 0;
    func_001DB7F0(&ctrl);
    assert(ctrl.f38 == 100);
    assert(g_mock_1db6b0_calls == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_timer1_trigger();
        test_timer1_not_trigger();
        test_timer2_trigger();
        test_timer2_not_trigger();
        return 0;
    }

    int case_num = std::atoi(argv[1]);
    switch (case_num) {
        case 0:
            test_timer1_trigger();
            break;
        case 1:
            test_timer1_not_trigger();
            break;
        case 2:
            test_timer2_trigger();
            break;
        case 3:
            test_timer2_not_trigger();
            break;
        default:
            return 1;
    }
    return 0;
}

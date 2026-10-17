#include "render_manager_close_window.h"
#include <cassert>
#include <cstdlib>

static int g_226180_calls = 0, g_226180_cmd = 0;
static void *g_226180_hwnd = 0;
static int g_225750_calls = 0, g_225750_arg = -1;

extern "C" {
void func_226180(void *hwnd, int cmd) {
    g_226180_calls++;
    g_226180_hwnd = hwnd;
    g_226180_cmd = cmd;
}

void func_225750(int arg) {
    g_225750_calls++;
    g_225750_arg = arg;
}
}

static void test_close_window_field68_zero() {
    RenderManagerCloseWindow mgr = {};
    mgr.field_2C = (void *)0x1234;
    mgr.field_30 = 1;
    mgr.field_68 = 0;
    g_226180_calls = g_225750_calls = 0;

    assert(func_00187660(&mgr) == 1);
    assert(mgr.field_30 == 0);
    assert(mgr.field_2C == 0);
    assert(g_226180_calls == 0);
    assert(g_225750_calls == 1 && g_225750_arg == 0);
}

static void test_close_window_field68_nonzero() {
    RenderManagerCloseWindow mgr = {};
    mgr.field_2C = (void *)0x5678;
    mgr.field_30 = 1;
    mgr.field_68 = 1;
    g_226180_calls = g_225750_calls = 0;

    assert(func_00187660(&mgr) == 1);
    assert(mgr.field_30 == 0);
    assert(mgr.field_2C == 0);
    assert(g_226180_calls == 1 && g_226180_hwnd == (void *)0x5678 && g_226180_cmd == 1);
    assert(g_225750_calls == 1 && g_225750_arg == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_close_window_field68_zero(); return 0;
    case 1: test_close_window_field68_nonzero(); return 0;
    default: return 1;
    }
}

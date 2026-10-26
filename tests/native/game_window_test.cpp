// tests/native/game_window_test.cpp
#include <cassert>
#include <cstdio>
#include "game_window.h"

static int s_wndproc_called = 0;
static int s_last_hwnd = 0;
static unsigned int s_last_msg = 0;
static unsigned int s_last_wparam = 0;
static long s_last_lparam = 0;

static int mock_wndproc(int hwnd, unsigned int msg, unsigned int wp, long lp) {
    s_wndproc_called++;
    s_last_hwnd = hwnd;
    s_last_msg = msg;
    s_last_wparam = wp;
    s_last_lparam = lp;
    return 42;
}

void test_wndproc_dispatch() {
    SetWindowProc((void *)mock_wndproc);
    MSG msg = {0};
    msg.message = 0x100; // WM_KEYDOWN
    msg.wParam = 0x20;
    msg.lParam = 0x12345678;

    int res = func_00226630(&msg);
    assert(res == 42);
    assert(s_wndproc_called == 1);
    assert(s_last_hwnd == 1);
    assert(s_last_msg == 0x100);
    assert(s_last_wparam == 0x20);
    assert(s_last_lparam == 0x12345678);

    // Test null wndproc safe return (prevents pc=0)
    SetWindowProc(NULL);
    res = func_00226630(&msg);
    assert(res == 0);
    printf("PASS: test_wndproc_dispatch\n");
}

int main() {
    test_wndproc_dispatch();
    return 0;
}

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

void test_win32_window_long_management() {
    g_wndproc = NULL;

    // 1. func_002264A0 stores proc and returns 1
    int res = func_002264A0((void *)0x12345678);
    assert(res == 1);
    assert(g_wndproc == (void *)0x12345678);

    // 2. func_002264B0 queries GWL_WNDPROC (-4)
    void *proc = func_002264B0(1, GWL_WNDPROC);
    assert(proc == (void *)0x12345678);

    // 2b. func_002264B0 with other index returns 1
    void *non_wndproc = func_002264B0(1, 0);
    assert(non_wndproc == (void *)1);

    // 3. func_002264E0 replaces GWL_WNDPROC (-4) and returns old proc
    void *old = func_002264E0(1, GWL_WNDPROC, (void *)0x87654321);
    assert(old == (void *)0x12345678);
    assert(g_wndproc == (void *)0x87654321);

    // 3b. func_002264E0 with other index does not mutate g_wndproc
    func_002264E0(1, 0, (void *)0x99999999);
    assert(g_wndproc == (void *)0x87654321);

    printf("PASS: test_win32_window_long_management\n");
}

int main() {
    test_wndproc_dispatch();
    test_win32_window_long_management();
    return 0;
}

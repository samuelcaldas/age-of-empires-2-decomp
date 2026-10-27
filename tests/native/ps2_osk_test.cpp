// tests/native/ps2_osk_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "ps2_osk.h"
#include "kt_libpad.h"

static int s_injected_msg = 0;
static int s_injected_char = 0;
static int s_inject_count = 0;

extern "C" int func_2263F0(int msg, int wParam, int lParam) {
    (void)lParam;
    s_injected_msg = msg;
    s_injected_char = wParam;
    s_inject_count++;
    return 1;
}

static int s_mock_keybd_connected = 0;

extern "C" int func_136230(int port) {
    (void)port;
    return s_mock_keybd_connected;
}

void test_osk_grid_navigation_and_input() {
    OSKState osk;
    OSK_Init(&osk, 32);

    assert(osk.cursor_row == 0);
    assert(osk.cursor_col == 0);
    assert(osk.active == 1);
    assert(osk.shift_mode == 1); // Default Uppercase

    s_inject_count = 0;

    // Initially at Row 0, Col 0: character '1'
    // Press Cross (KT_PAD_CROSS) -> Injects '1'
    int ret = OSK_ProcessInput(&osk, KT_PAD_CROSS, KT_PAD_CROSS);
    assert(ret == 0); // Not submitted yet
    assert(s_inject_count == 1);
    assert(s_injected_msg == 0x102); // WM_CHAR
    assert(s_injected_char == '1');
    assert(strcmp(osk.buffer, "1") == 0);

    // Navigate Right -> Col 1 ('2')
    OSK_ProcessInput(&osk, KT_PAD_RIGHT, KT_PAD_RIGHT);
    assert(osk.cursor_col == 1);

    // Navigate Down -> Row 1, Col 1 ('W')
    OSK_ProcessInput(&osk, KT_PAD_DOWN, KT_PAD_DOWN);
    assert(osk.cursor_row == 1);
    assert(osk.cursor_col == 1);

    // Press Cross -> Injects 'W'
    OSK_ProcessInput(&osk, KT_PAD_CROSS, KT_PAD_CROSS);
    assert(s_inject_count == 2);
    assert(s_injected_char == 'W');
    assert(strcmp(osk.buffer, "1W") == 0);

    // Press Square (KT_PAD_SQUARE) -> Backspace
    OSK_ProcessInput(&osk, KT_PAD_SQUARE, KT_PAD_SQUARE);
    assert(s_inject_count == 3);
    assert(s_injected_char == 0x08); // VK_BACK
    assert(strcmp(osk.buffer, "1") == 0);

    // Toggle Triangle (KT_PAD_TRIANGLE) -> Lowercase
    OSK_ProcessInput(&osk, KT_PAD_TRIANGLE, KT_PAD_TRIANGLE);
    assert(osk.shift_mode == 0);

    // At Row 1, Col 1 with shift=0: 'w'
    OSK_ProcessInput(&osk, KT_PAD_CROSS, KT_PAD_CROSS);
    assert(s_inject_count == 4);
    assert(s_injected_char == 'w');
    assert(strcmp(osk.buffer, "1w") == 0);

    // Submit with Start (KT_PAD_START)
    ret = OSK_ProcessInput(&osk, KT_PAD_START, KT_PAD_START);
    assert(ret == 1); // Submitted
    assert(osk.active == 0);

    printf("PASS: test_osk_grid_navigation_and_input\n");
}

void test_osk_usb_keyboard_interplay() {
    OSKState osk;
    OSK_Init(&osk, 32);

    // 1. Without USB keyboard: OSK_IsKeyboardActive returns 0
    s_mock_keybd_connected = 0;
    assert(OSK_IsKeyboardActive() == 0);

    // 2. With USB keyboard connected: OSK_IsKeyboardActive returns 1
    s_mock_keybd_connected = 1;
    assert(OSK_IsKeyboardActive() == 1);

    // Direct injection into target control
    s_inject_count = 0;
    OSK_DirectTypingInput(&osk, 'A');
    assert(s_inject_count == 1);
    assert(s_injected_msg == 0x102); // WM_CHAR
    assert(s_injected_char == 'A');
    assert(strcmp(osk.buffer, "A") == 0);

    printf("PASS: test_osk_usb_keyboard_interplay\n");
}

int main() {
    test_osk_grid_navigation_and_input();
    test_osk_usb_keyboard_interplay();
    return 0;
}

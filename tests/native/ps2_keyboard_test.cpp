// tests/native/ps2_keyboard_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "ps2_keyboard.h"

void test_scancode_table_parity() {
    // US HID usages 0x04..0x1D must map to 'A'..'Z'
    for (int i = 0x04; i <= 0x1D; ++i) {
        assert(g_usb_scancode_table[i] == (unsigned short)('A' + (i - 0x04)));
    }

    // US HID usages 0x1E..0x26 map to '1'..'9', 0x27 maps to '0'
    for (int i = 0x1E; i <= 0x26; ++i) {
        assert(g_usb_scancode_table[i] == (unsigned short)('1' + (i - 0x1E)));
    }
    assert(g_usb_scancode_table[0x27] == '0');

    // Special keys
    assert(g_usb_scancode_table[0x28] == 0x0D); // Return / Enter
    assert(g_usb_scancode_table[0x29] == 0x1B); // Escape
    assert(g_usb_scancode_table[0x2A] == 0x08); // Backspace
    assert(g_usb_scancode_table[0x2B] == 0x09); // Tab
    assert(g_usb_scancode_table[0x2C] == 0x20); // Space

    // Modifiers (0xE0..0xE7)
    assert(g_usb_scancode_table[0xE0] == 0x11); // LCtrl
    assert(g_usb_scancode_table[0xE1] == 0x10); // LShift
    assert(g_usb_scancode_table[0xE2] == 0x12); // LAlt
    assert(g_usb_scancode_table[0xE3] == 0x5B); // LWin
    assert(g_usb_scancode_table[0xE4] == 0x11); // RCtrl
    assert(g_usb_scancode_table[0xE5] == 0x10); // RShift
    assert(g_usb_scancode_table[0xE6] == 0x12); // RAlt
    assert(g_usb_scancode_table[0xE7] == 0x5C); // RWin

    printf("PASS: test_scancode_table_parity\n");
}

void test_modifier_queries() {
    // Initially all released
    g_keybd_shift_state = 0;
    g_keybd_ctrl_state = 0;
    g_keybd_alt_state = 0;

    assert(func_0036DF30(VK_SHIFT) == 0);
    assert(func_0036DF30(VK_CONTROL) == 0);
    assert(func_0036DF30(VK_MENU) == 0);
    assert(func_0036DF30(0x41) == 0);

    // Press Shift
    g_keybd_shift_state = 1;
    assert(func_0036DF30(VK_SHIFT) == -1);
    assert(func_0036DF30(VK_CONTROL) == 0);
    assert(func_0036DF30(VK_MENU) == 0);

    // Press Ctrl
    g_keybd_ctrl_state = 1;
    assert(func_0036DF30(VK_SHIFT) == -1);
    assert(func_0036DF30(VK_CONTROL) == -1);
    assert(func_0036DF30(VK_MENU) == 0);

    // Press Alt
    g_keybd_alt_state = 1;
    assert(func_0036DF30(VK_SHIFT) == -1);
    assert(func_0036DF30(VK_CONTROL) == -1);
    assert(func_0036DF30(VK_MENU) == -1);

    // Release Shift
    g_keybd_shift_state = 0;
    assert(func_0036DF30(VK_SHIFT) == 0);
    assert(func_0036DF30(VK_CONTROL) == -1);
    assert(func_0036DF30(VK_MENU) == -1);

    // Test func_0036DFB0
    g_keybd_modifier_byte = 0;
    assert(func_0036DFB0(0) == 0);
    assert(func_0036DFB0(1) == 0);

    g_keybd_modifier_byte = 0x01; // Left Ctrl
    assert(func_0036DFB0(0) == 1);
    assert(func_0036DFB0(1) == 0);

    g_keybd_modifier_byte = 0x02; // Left Shift
    assert(func_0036DFB0(0) == 0);
    assert(func_0036DFB0(1) == 1);

    g_keybd_modifier_byte = 0x03; // Left Ctrl + Shift
    assert(func_0036DFB0(0) == 1);
    assert(func_0036DFB0(1) == 1);

    printf("PASS: test_modifier_queries\n");
}

static int s_posted_msg = 0;
static int s_posted_wparam = 0;
static int s_posted_lparam = 0;
static int s_post_count = 0;
static unsigned int s_mock_tick = 1000;

extern "C" int func_2263F0(int msg, int wParam, int lParam) {
    s_posted_msg = msg;
    s_posted_wparam = wParam;
    s_posted_lparam = lParam;
    s_post_count++;
    return 1;
}

extern "C" unsigned int func_2261C0(void) {
    return s_mock_tick;
}

void test_win32_key_event_bridge() {
    s_post_count = 0;
    memset(g_key_pressed_state, 0, sizeof(g_key_pressed_state));
    s_repeat_key = 0;
    s_repeat_time = 0;
    g_keybd_alt_state = 0;

    // 1. func_0036E0A8: Key-Down on 'A' (HID usage 0x04)
    func_0036E0A8(0x04);
    assert(s_post_count == 1);
    assert(s_posted_msg == 0x100); // WM_KEYDOWN
    assert(s_posted_wparam == 'A');
    assert(g_key_pressed_state['A'] == 0x80);
    assert(s_repeat_key == 'A');
    assert(s_repeat_time == s_mock_tick + 0x1F4); // Initial typematic delay: 500ms

    // Pressing already pressed key does not repost WM_KEYDOWN
    func_0036E0A8(0x04);
    assert(s_post_count == 1);

    // 2. func_0036E160: Typematic repeat before interval does nothing
    s_mock_tick += 200; // 1200 < 1500
    func_0036E160();
    assert(s_post_count == 1);

    // Tick reaches 1501 (> 1500) -> emits repeated WM_KEYDOWN
    s_mock_tick = 1501;
    func_0036E160();
    assert(s_post_count == 2);
    assert(s_posted_msg == 0x100);
    assert(s_posted_wparam == 'A');
    assert(s_repeat_time == s_mock_tick + 0x32); // Repeat interval: 50ms

    // 3. func_0036E1F0: Key release detection
    // Packet with no keys active
    unsigned char empty_packet[8] = {0};
    func_0036E1F0(empty_packet);
    assert(s_post_count == 3);
    assert(s_posted_msg == 0x101); // WM_KEYUP
    assert(s_posted_wparam == 'A');
    assert(g_key_pressed_state['A'] == 0);
    assert(s_repeat_key == 0);

    // 4. Alt down produces WM_SYSKEYDOWN (0x104) and WM_SYSKEYUP (0x105)
    g_keybd_alt_state = 1;
    func_0036E0A8(0x05); // 'B'
    assert(s_post_count == 4);
    assert(s_posted_msg == 0x104); // WM_SYSKEYDOWN
    assert(s_posted_wparam == 'B');

    func_0036E1F0(empty_packet);
    assert(s_post_count == 5);
    assert(s_posted_msg == 0x105); // WM_SYSKEYUP
    assert(s_posted_wparam == 'B');

    printf("PASS: test_win32_key_event_bridge\n");
}

int main() {
    test_scancode_table_parity();
    test_modifier_queries();
    test_win32_key_event_bridge();
    return 0;
}

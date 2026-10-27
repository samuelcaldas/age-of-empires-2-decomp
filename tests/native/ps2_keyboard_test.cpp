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

int main() {
    test_scancode_table_parity();
    test_modifier_queries();
    return 0;
}

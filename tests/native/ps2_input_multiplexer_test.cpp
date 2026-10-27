// tests/native/ps2_input_multiplexer_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "ps2_input_multiplexer.h"
#include "ps2_keyboard.h"

static unsigned int s_mock_pad_buttons = 0;
static unsigned int s_mock_mouse_buttons = 0;

extern "C" unsigned int func_00126410(int pad_number) {
    (void)pad_number;
    return s_mock_pad_buttons;
}

unsigned int g_mock_mouse_buttons = 0;

void test_unified_input_multiplexer() {
    int flags = 0;

    // 1. All idle
    s_mock_pad_buttons = 0;
    g_mock_mouse_buttons = 0;
    g_keybd_shift_state = 0;
    g_keybd_ctrl_state = 0;
    g_keybd_alt_state = 0;

    func_0036D5F0(&flags);
    assert(flags == 0);

    // 2. Mouse buttons
    g_mock_mouse_buttons = 0x01; // LMB
    func_0036D5F0(&flags);
    assert(flags & 0x01);

    g_mock_mouse_buttons = 0x02; // RMB
    func_0036D5F0(&flags);
    assert(flags & 0x02);

    g_mock_mouse_buttons = 0;

    // 3. Gamepad shoulder button R1 (0x0008) emulates Shift (0x04)
    s_mock_pad_buttons = 0x0008; // R1
    func_0036D5F0(&flags);
    assert(flags & 0x04);

    // 4. Gamepad shoulder button L1 (0x0004) emulates Ctrl (0x08)
    s_mock_pad_buttons = 0x0004; // L1
    func_0036D5F0(&flags);
    assert(flags & 0x08);

    s_mock_pad_buttons = 0;

    // 5. USB Keyboard Shift sets flag 0x04
    g_keybd_shift_state = 1;
    func_0036D5F0(&flags);
    assert(flags & 0x04);

    // 6. USB Keyboard Ctrl sets flag 0x08
    g_keybd_ctrl_state = 1;
    func_0036D5F0(&flags);
    assert(flags & 0x08);

    // 7. USB Keyboard Alt sets flag 0x10
    g_keybd_alt_state = 1;
    func_0036D5F0(&flags);
    assert(flags & 0x10);

    // 8. Combined: Gamepad R1 + USB Ctrl + Mouse LMB
    s_mock_pad_buttons = 0x0008; // R1 -> Shift (0x04)
    g_keybd_shift_state = 0;
    g_keybd_ctrl_state = 1;      // Ctrl (0x08)
    g_keybd_alt_state = 0;
    g_mock_mouse_buttons = 0x01; // LMB (0x01)

    func_0036D5F0(&flags);
    assert(flags == (0x01 | 0x04 | 0x08));

    printf("PASS: test_unified_input_multiplexer\n");
}

int main() {
    test_unified_input_multiplexer();
    return 0;
}

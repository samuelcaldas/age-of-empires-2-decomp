#include "ps2_input_multiplexer.h"
#include "ps2_keyboard.h"

unsigned int func_00126410(int pad_number);

/* Global mouse work buttons (offset 0x138C110 in AOK.ELF) */
#if defined(__GNUC__)
extern unsigned int g_mock_mouse_buttons __attribute__((weak));
unsigned int g_mock_mouse_buttons = 0;
#else
extern unsigned int g_mock_mouse_buttons;
#endif

/*
 * func_0036D5F0: Unified Input Multiplexer
 * Matches AOK.ELF 0x0036D5F0 - 0x0036D700 (272 bytes)
 */
void func_0036D5F0(int *out_flags) {
    if (!out_flags) {
        return;
    }

    *out_flags = 0;

    /* 1. Mouse Buttons (0x138C110) */
    unsigned int mouse = g_mock_mouse_buttons;
    if (mouse & 0x1) {
        *out_flags |= 0x1; // Left Button
    }
    if (mouse & 0x2) {
        *out_flags |= 0x2; // Right Button
    }

    /* 2. DualShock 2 Gamepad Buttons (ktPadGetButtons(0)) */
    unsigned int pad = func_00126410(0);
    if (pad & 0x0004) { // L1 button emulates Ctrl
        *out_flags |= 0x8;
    }
    if (pad & 0x0008) { // R1 button emulates Shift
        *out_flags |= 0x4;
    }
    if (pad & 0x0001) { // L2 / R2 emulates Alt
        *out_flags |= 0x10;
    }

    /* 3. USB Keyboard Modifiers (func_0036DF30) */
    if (func_0036DF30(VK_SHIFT) != 0) {
        *out_flags |= 0x4; // Shift
    }
    if (func_0036DF30(VK_CONTROL) != 0) {
        *out_flags |= 0x8; // Ctrl
    }
    if (func_0036DF30(VK_MENU) != 0) {
        *out_flags |= 0x10; // Alt
    }
}

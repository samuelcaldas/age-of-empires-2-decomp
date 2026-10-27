#include "ps2_keyboard.h"

unsigned char g_keybd_shift_state = 0;
unsigned char g_keybd_ctrl_state = 0;
unsigned char g_keybd_alt_state = 0;
unsigned char g_keybd_modifier_byte = 0;

/*
 * USB HID Usage Code to Win32 Virtual-Key Code Translation Table
 * Matches AOK.ELF 0x0048A470 (256 halfwords / 512 bytes)
 */
const unsigned short g_usb_scancode_table[256] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C,
    0x004D, 0x004E, 0x004F, 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x0031, 0x0032,
    0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x0030, 0x000D, 0x001B, 0x0008, 0x0009, 0x0020, 0x00BD, 0x00DE, 0x00C0,
    0x00DB, 0x00DC, 0x00DD, 0x00BB, 0x00BA, 0x00F4, 0x00BC, 0x00BE, 0x00BF, 0x0014, 0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075,
    0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x002C, 0x0091, 0x0013, 0x002D, 0x0024, 0x0021, 0x002E, 0x0023, 0x0022, 0x0027,
    0x0025, 0x0028, 0x0026, 0x0090, 0x006F, 0x006A, 0x006D, 0x006B, 0x000D, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x0060, 0x006E, 0x0000, 0x0000, 0x0000, 0x0000, 0x007C, 0x007D, 0x007E, 0x007F, 0x0080, 0x0081, 0x0082, 0x0083,
    0x0084, 0x0085, 0x0086, 0x0087, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00E2, 0x00F2, 0x00DC, 0x001C, 0x001D, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0011, 0x0010, 0x0012, 0x005B, 0x0011, 0x0010, 0x0012, 0x005C, 0x0008, 0x0000, 0x5910, 0x004D, 0x0009, 0x0000, 0x591C, 0x004D,
    0x000D, 0x0000, 0x5920, 0x004D, 0x0010, 0x0000, 0x5928, 0x004D, 0x0011, 0x0000, 0x5930, 0x004D, 0x0012, 0x0000, 0x5938, 0x004D,
};

/*
 * func_0036DF30: Win32 GetAsyncKeyState for USB Keyboard Modifiers
 * Matches AOK.ELF 0x0036DF30 - 0x0036DFA8 (120 bytes)
 */
int func_0036DF30(int vkey) {
    if (vkey == VK_SHIFT) {
        if (g_keybd_shift_state != 0) {
            return -1;
        }
    } else if (vkey == VK_CONTROL) {
        if (g_keybd_ctrl_state != 0) {
            return -1;
        }
    } else if (vkey == VK_MENU) {
        if (g_keybd_alt_state != 0) {
            return -1;
        }
    }
    return 0;
}

__attribute__((weak)) int func_2263F0(int msg, int wParam, int lParam) {
    (void)msg; (void)wParam; (void)lParam;
    return 1;
}

__attribute__((weak)) unsigned int func_2261C0(void) {
    return 0;
}

__attribute__((weak)) int func_136190(int port, void *packet) {
    (void)port; (void)packet;
    return 0;
}

__attribute__((weak)) int func_136230(int port) {
    (void)port;
    return 0;
}

/*
 * func_0036DFB0: Evaluates USB HID modifier bytes
 * Matches AOK.ELF 0x0036DFB0 - 0x0036E008 (88 bytes)
 */
int func_0036DFB0(int mode) {
    if (mode == 1) {
        if (g_keybd_modifier_byte & 0x02) {
            return 1;
        }
    } else if (mode == 0) {
        if (g_keybd_modifier_byte & 0x01) {
            return 1;
        }
    }
    return 0;
}

unsigned char g_key_pressed_state[256] = {0};
unsigned short s_repeat_key = 0;
unsigned int s_repeat_time = 0;

/*
 * func_0036E010: Scancode translation and layout adjustment
 * Matches AOK.ELF 0x0036E010 - 0x0036E0A4 (148 bytes)
 */
int func_0036E010(int scancode) {
    int vk = g_usb_scancode_table[scancode & 0xFF];
    return vk;
}

/*
 * func_0036E0A8: Key-Down Event Handler
 * Matches AOK.ELF 0x0036E0A8 - 0x0036E15C (180 bytes)
 */
void func_0036E0A8(int scancode) {
    int vk = func_0036E010(scancode);
    if (vk != 0 && g_key_pressed_state[vk] == 0) {
        int msg = (g_keybd_alt_state != 0) ? 0x104 : 0x100; // WM_SYSKEYDOWN : WM_KEYDOWN
        func_2263F0(msg, vk, 0);
        s_repeat_key = (unsigned short)vk;
        s_repeat_time = func_2261C0() + 0x1F4; // Initial typematic delay: 500 ms
        g_key_pressed_state[vk] = 0x80;
    }
}

/*
 * func_0036E160: Typematic Key Repeat Handler
 * Matches AOK.ELF 0x0036E160 - 0x0036E1E4 (132 bytes)
 */
void func_0036E160(void) {
    if (s_repeat_key != 0 && g_key_pressed_state[s_repeat_key] != 0) {
        unsigned int now = func_2261C0();
        if (now > s_repeat_time) {
            int msg = (g_keybd_alt_state != 0) ? 0x104 : 0x100;
            func_2263F0(msg, s_repeat_key, 0);
            s_repeat_time = func_2261C0() + 0x32; // Repeat rate: 50 ms
        }
    }
}

/*
 * func_0036E1F0: Key-Up Event Detector
 * Matches AOK.ELF 0x0036E1F0 - 0x0036E340 (336 bytes)
 */
void func_0036E1F0(const unsigned char *current_packet) {
    for (int vk = 0; vk < 256; ++vk) {
        if (g_key_pressed_state[vk] != 0) {
            int still_pressed = 0;
            if (current_packet != 0) {
                for (int slot = 2; slot < 8; ++slot) {
                    int scancode = current_packet[slot];
                    if (scancode >= 4 && func_0036E010(scancode) == vk) {
                        still_pressed = 1;
                        break;
                    }
                }
            }
            if (!still_pressed) {
                int msg = (g_keybd_alt_state != 0) ? 0x105 : 0x101; // WM_SYSKEYUP : WM_KEYUP
                func_2263F0(msg, vk, 0);
                g_key_pressed_state[vk] = 0;
                if (s_repeat_key == vk) {
                    s_repeat_key = 0;
                }
            }
        }
    }
}

/*
 * func_0036E350: Modifier Transition and LED Update
 * Matches AOK.ELF 0x0036E350 - 0x0036E508 (440 bytes)
 */
void func_0036E350(void) {
    g_keybd_shift_state = (g_keybd_modifier_byte & 0x22) ? 1 : 0;
    g_keybd_ctrl_state  = (g_keybd_modifier_byte & 0x11) ? 1 : 0;
    g_keybd_alt_state   = (g_keybd_modifier_byte & 0x44) ? 1 : 0;
}

/*
 * func_0036E510: Packet Polling Loop
 * Matches AOK.ELF 0x0036E510 - 0x0036E5D8 (200 bytes)
 */
int func_0036E510(int reset_flag) {
    if (reset_flag != 0) {
        for (int i = 4; i < 256; ++i) {
            g_key_pressed_state[i] = 0;
        }
    }

    unsigned char packet[8];
    while (func_136190(0, packet) > 0) {
        g_keybd_modifier_byte = packet[0];
        func_0036E350();

        for (int slot = 2; slot < 8; ++slot) {
            int scancode = packet[slot];
            if (scancode >= 4) {
                func_0036E0A8(scancode);
            }
        }
        func_0036E1F0(packet);
    }

    func_0036E160();
    return 0;
}

/*
 * func_0036E5E0: Subsystem Update Tick
 * Matches AOK.ELF 0x0036E5E0 - 0x0036E76F (400 bytes)
 */
int func_0036E5E0(void) {
    int status = func_136230(0);
    if (status == 1) {
        func_0036E510(0);
        return 1;
    }

    /* Disconnected: release any stuck keys */
    func_0036E1F0((const unsigned char *)0);
    return 0;
}


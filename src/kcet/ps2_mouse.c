#include "ps2_mouse.h"

int g_cursor_x = 0;
int g_cursor_y = 0;

static unsigned int s_last_lbutton_down_tick = 0;
static unsigned int s_prev_mouse_buttons = 0;
static int s_mouse_mode = MOUSE_MODE_RELATIVE;

__attribute__((weak)) int g_mock_mouse_buttons = 0;

__attribute__((weak)) int func_2263F0(int msg, int wParam, int lParam) {
    (void)msg; (void)wParam; (void)lParam;
    return 1;
}

__attribute__((weak)) unsigned int func_2261C0(void) {
    return 0;
}

__attribute__((weak)) int func_00135118(int port, int *out) {
    (void)port; (void)out;
    return 0;
}

__attribute__((weak)) int func_00135258(int port) {
    (void)port;
    return 0;
}

int func_00225580(POINT *pt) {
    if (!pt) return 0;
    pt->x = g_cursor_x;
    pt->y = g_cursor_y;
    return 1;
}

int func_002255A0(int x, int y) {
    if (x < 0) x = 0;
    if (x > 639) x = 639;
    if (y < 0) y = 0;
    if (y > 479) y = 479;
    g_cursor_x = x;
    g_cursor_y = y;
    return 1;
}

void func_0036D700_dispatch_buttons(unsigned int new_buttons, unsigned int prev_buttons, unsigned int now_tick) {
    int lparam = (g_cursor_y << 16) | (g_cursor_x & 0xFFFF);
    unsigned int diff = new_buttons ^ prev_buttons;

    if (!diff) {
        return;
    }

    /* Left Button (bit 0 / 0x01) */
    if (diff & 0x01) {
        if (new_buttons & 0x01) {
            if (s_last_lbutton_down_tick != 0 && (now_tick - s_last_lbutton_down_tick) <= 250) {
                func_2263F0(WM_LBUTTONDBLCLK, new_buttons, lparam);
                s_last_lbutton_down_tick = 0;
            } else {
                func_2263F0(WM_LBUTTONDOWN, new_buttons, lparam);
                s_last_lbutton_down_tick = now_tick;
            }
        } else {
            func_2263F0(WM_LBUTTONUP, new_buttons, lparam);
        }
    }

    /* Right Button (bit 1 / 0x02) */
    if (diff & 0x02) {
        if (new_buttons & 0x02) {
            func_2263F0(WM_RBUTTONDOWN, new_buttons, lparam);
        } else {
            func_2263F0(WM_RBUTTONUP, new_buttons, lparam);
        }
    }

    /* Middle Button (bit 2 / 0x04) */
    if (diff & 0x04) {
        if (new_buttons & 0x04) {
            func_2263F0(WM_MBUTTONDOWN, new_buttons, lparam);
        } else {
            func_2263F0(WM_MBUTTONUP, new_buttons, lparam);
        }
    }
}

int func_0036D700(void) {
    int packet[8];
    int total_dx = 0;
    int total_dy = 0;
    int total_wheel = 0;
    int got_packet = 0;
    unsigned int buttons = s_prev_mouse_buttons;

    while (func_00135118(0, packet)) {
        got_packet = 1;
        buttons = (unsigned int)packet[0];
        total_dx += packet[1];
        total_dy += packet[2];
        total_wheel += packet[3];
    }

    if (!got_packet) {
        return 0;
    }

    if (s_mouse_mode != MOUSE_MODE_ABSOLUTE) {
        func_002255A0(g_cursor_x + total_dx, g_cursor_y + total_dy);
    }

    int lparam = (g_cursor_y << 16) | (g_cursor_x & 0xFFFF);

    if (s_mouse_mode != MOUSE_MODE_ABSOLUTE && (total_dx != 0 || total_dy != 0)) {
        func_2263F0(WM_MOUSEMOVE, buttons, lparam);
    }

    if (total_wheel != 0) {
        func_2263F0(WM_MOUSEWHEEL, (total_wheel << 16) | (buttons & 0xFFFF), lparam);
    }

    unsigned int now_tick = func_2261C0();
    func_0036D700_dispatch_buttons(buttons, s_prev_mouse_buttons, now_tick);

    s_prev_mouse_buttons = buttons;
    g_mock_mouse_buttons = buttons;

    return 1;
}

void Mouse_SetMode(int mode) {
    s_mouse_mode = mode;
}

int Mouse_GetMode(void) {
    return s_mouse_mode;
}

void Mouse_SetAbsolutePosition(int x, int y, unsigned int buttons) {
    int prev_x = g_cursor_x;
    int prev_y = g_cursor_y;

    func_002255A0(x, y);

    int lparam = (g_cursor_y << 16) | (g_cursor_x & 0xFFFF);

    if (g_cursor_x != prev_x || g_cursor_y != prev_y) {
        func_2263F0(WM_MOUSEMOVE, buttons, lparam);
    }

    unsigned int now_tick = func_2261C0();
    func_0036D700_dispatch_buttons(buttons, s_prev_mouse_buttons, now_tick);

    s_prev_mouse_buttons = buttons;
    g_mock_mouse_buttons = buttons;
}

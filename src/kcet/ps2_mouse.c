#include "ps2_mouse.h"

int g_cursor_x = 0;
int g_cursor_y = 0;

static unsigned int s_last_lbutton_down_tick = 0;

__attribute__((weak)) int func_2263F0(int msg, int wParam, int lParam) {
    (void)msg; (void)wParam; (void)lParam;
    return 1;
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

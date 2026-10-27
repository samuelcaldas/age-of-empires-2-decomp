#include "ps2_mouse.h"

int g_cursor_x = 0;
int g_cursor_y = 0;

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

#ifndef PS2_MOUSE_H
#define PS2_MOUSE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int x;
    int y;
} POINT;

extern int g_cursor_x;
extern int g_cursor_y;

int func_00225580(POINT *pt);
int func_002255A0(int x, int y);

#define GetCursorPos func_00225580
#define SetCursorPos func_002255A0

#ifdef __cplusplus
}
#endif

#endif /* PS2_MOUSE_H */

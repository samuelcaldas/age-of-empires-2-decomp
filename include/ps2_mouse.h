#ifndef PS2_MOUSE_H
#define PS2_MOUSE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int x;
    int y;
} POINT;

/* Win32 Mouse Messages */
#define WM_MOUSEMOVE     0x0200
#define WM_LBUTTONDOWN   0x0201
#define WM_LBUTTONUP     0x0202
#define WM_LBUTTONDBLCLK 0x0203
#define WM_RBUTTONDOWN   0x0204
#define WM_RBUTTONUP     0x0205
#define WM_RBUTTONDBLCLK 0x0206
#define WM_MBUTTONDOWN   0x0207
#define WM_MBUTTONUP     0x0208
#define WM_MBUTTONDBLCLK 0x0209
#define WM_MOUSEWHEEL    0x020A

/* Mouse Key Flags */
#define MK_LBUTTON       0x0001
#define MK_RBUTTON       0x0002
#define MK_SHIFT         0x0004
#define MK_CONTROL       0x0008
#define MK_MBUTTON       0x0010

/* Mouse Operating Modes */
#define MOUSE_MODE_RELATIVE 0
#define MOUSE_MODE_ABSOLUTE 1

extern int g_cursor_x;
extern int g_cursor_y;

int func_00225580(POINT *pt);
int func_002255A0(int x, int y);
void func_0036D700_dispatch_buttons(unsigned int new_buttons, unsigned int prev_buttons, unsigned int now_tick);
int func_0036D700(void);

void Mouse_SetMode(int mode);
int Mouse_GetMode(void);
void Mouse_SetAbsolutePosition(int x, int y, unsigned int buttons);

#define GetCursorPos func_00225580
#define SetCursorPos func_002255A0
#define Mouse_Update func_0036D700
#define PollMouse    func_0036D700

#ifdef __cplusplus
}
#endif

#endif /* PS2_MOUSE_H */

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MSG {
    int hwnd;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned int time;
    int pt_x;
    int pt_y;
} MSG;

#define GWL_WNDPROC (-4)

extern void *g_wndproc;

int func_002264A0(void *proc);
void *func_002264B0(int hwnd, int nIndex);
void *func_002264E0(int hwnd, int nIndex, void *newVal);
int func_00226630(const MSG *msg);

#define RegisterWndProc func_002264A0
#define GetWindowLongA func_002264B0
#define SetWindowLongA func_002264E0
void *SetWindowProc(void *proc);
void *GetWindowProc(void);

#ifdef __cplusplus
}
#endif

#endif /* GAME_WINDOW_H */

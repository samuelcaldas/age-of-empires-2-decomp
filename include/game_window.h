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

extern void *g_wndproc;

int func_00226630(const MSG *msg);
void *SetWindowProc(void *proc);
void *GetWindowProc(void);

#ifdef __cplusplus
}
#endif

#endif /* GAME_WINDOW_H */

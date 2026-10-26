#include <stddef.h>
#include "game_window.h"

/* Window procedure pointer stored at gp - 0x746C */
void *g_wndproc = NULL;

void *SetWindowProc(void *proc) {
    void *old = g_wndproc;
    g_wndproc = proc;
    return old;
}

void *GetWindowProc(void) {
    return g_wndproc;
}

int func_00226630(const MSG *msg) {
    typedef int (*WndProcFn)(int hwnd, unsigned int uMsg, unsigned int wParam, long lParam);
    WndProcFn proc = (WndProcFn)g_wndproc;
    if (proc != NULL) {
        return proc(1, msg->message, msg->wParam, msg->lParam);
    }
    return 0;
}

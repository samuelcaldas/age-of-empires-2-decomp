#include <stddef.h>
#include "game_window.h"

/* Window procedure pointer stored at gp - 0x746C */
void *g_wndproc = NULL;

int func_002264A0(void *proc) {
    g_wndproc = proc;
    return 1;
}

void *func_002264B0(int hwnd, int nIndex) {
    (void)hwnd;
    if (nIndex == GWL_WNDPROC) {
        return g_wndproc;
    }
    return (void *)1;
}

void *func_002264E0(int hwnd, int nIndex, void *newVal) {
    (void)hwnd;
    if (nIndex == GWL_WNDPROC) {
        void *old = g_wndproc;
        g_wndproc = newVal;
        return old;
    }
    return NULL;
}

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

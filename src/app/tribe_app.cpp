#include <string.h>
#include <stddef.h>
#include "tribe_app.h"
#include "game_window.h"

#ifdef __cplusplus
extern "C" {
#endif

void *g_pApp = NULL;

__attribute__((weak)) int func_185160(MSG *msg, int *handled) {
    (void)msg;
    if (handled) {
        *handled = 0;
    }
    return 1;
}

__attribute__((weak)) int func_002265D0(MSG *msg, void *hwnd, int min, int max, int remove) {
    (void)msg;
    (void)hwnd;
    (void)min;
    (void)max;
    (void)remove;
    return 0; // No more messages in queue
}

__attribute__((weak)) int func_00226620(const MSG *msg) {
    (void)msg;
    return 0;
}

__attribute__((weak)) int func_00226630(const MSG *msg) {
    (void)msg;
    return 0;
}

__attribute__((weak)) void func_388010(void *app) {
    (void)app;
}

/* Static initial message template at 0x00391CD0 */
static const MSG s_default_msg = {0, 0, 0, 0, 0, 0, 0};

/*
 * func_00185230: Main Win32 Event Pump of RGE_App / TRIBE_App
 * Matches AOK.ELF 0x00185230 - 0x001853D8
 */
int func_00185230(void *self) {
    if (!self) {
        return 0;
    }

    /* field_1C is the quit request flag */
    *(int *)((char *)self + 0x1C) = 0;

    MSG msg = s_default_msg;
    typedef int (*VirtualMethodFn)(void *app, MSG *m);

    void ***vtable_ptr = (void ***)self;
    void **vtable = *vtable_ptr;

    /* Loop until field_1C becomes non-zero or WM_QUIT (0x12) is received */
    while (*(int *)((char *)self + 0x1C) == 0) {
        if (msg.message == 0x12) { // WM_QUIT
            break;
        }

        /* Virtual call at vtable[0xA8 / 4] (Method 0xA8) */
        if (vtable && vtable[0x2A]) {
            VirtualMethodFn methodA8 = (VirtualMethodFn)vtable[0x2A];
            if (!methodA8(self, &msg)) {
                break;
            }
        }

        int handled = 0;
        int res = func_185160(&msg, &handled);
        if (res > 0) {
            func_00226620(&msg);
            func_00226630(&msg);
        }

        /* Poll remaining messages in queue */
        if (!func_002265D0(&msg, NULL, 0, 0, 1)) {
            /* Queue empty: call idle handler at vtable[0xAC / 4] (Method 0xAC) */
            if (vtable && vtable[0x2B]) {
                VirtualMethodFn methodAC = (VirtualMethodFn)vtable[0x2B];
                methodAC(self, &msg);
            }
            break;
        }
    }

    func_388010(self);
    return 0;
}

void *g_tribe_app_vtable[64] = {
    NULL,                   // slot 0
    NULL,                   // slot 1
    NULL,                   // slot 2
    (void *)func_00185230,  // slot 3: message pump loop (prevents pc=0)
    NULL
};

void *func_2F61F0(void *obj, void *cfg, int arg) {
    if (!obj) {
        return NULL;
    }

    // 1. Invoke base constructor (failure must still preserve 'obj' in return)
    func_184340(obj, cfg, arg);

    char *self = (char *)obj;

    // 2. Assign vtable (0x004DE5E0 in AOK.ELF)
    *(void ***)self = g_tribe_app_vtable;

    // 3. Initialize fields according to AOK.ELF 0x002F61F0 assembly
    for (int off = 0x142C; off <= 0x1468; off += 4) {
        *(int *)(self + off) = 0;
    }
    *(int *)(self + 0x1430) = -1; // 0x2406FFFF: li $a2, -1

    *(int *)(self + 0x190C) = 0;
    *(int *)(self + 0x1940) = 0;
    *(int *)(self + 0x1944) = 0;

    *(void **)(self + 0x1F0) = obj;
    *(int *)(self + 0x1F4) = 0;

    *(int *)(self + 0x1070) = 0;
    *(char *)(self + 0x1470) = 0;
    *(char *)(self + 0x1570) = 0;
    *(int *)(self + 0x146C) = 0;
    *(char *)(self + 0x1670) = 0;
    *(char *)(self + 0x1324) = 0;
    *(int *)(self + 0x1910) = 0;
    *(int *)(self + 0x118C) = 0;
    *(int *)(self + 0x1190) = 0;
    *(int *)(self + 0x1194) = 0;
    *(int *)(self + 0x1198) = 0;
    *(int *)(self + 0x11A0) = 0xD; // 0x2403000D: li $v1, 0xD

    // 4. Register global pointer g_pApp = this (gp - 0x7A04)
    g_pApp = obj;

    return obj;
}

#ifdef __cplusplus
}
#endif

#include <string.h>
#include <stddef.h>
#include "tribe_app.h"
#include "game_window.h"

#ifdef __cplusplus
extern "C" {
#endif

void *g_pApp = NULL;

__attribute__((weak)) int func_00226630(const MSG *msg);
__attribute__((weak)) int func_00300C90(void);

int func_00185230(void *self) {
    if (self) {
        *(int *)((char *)self + 0x1C) = 0;
    }
    MSG msg;
    memset(&msg, 0, sizeof(msg));
    if (func_00226630) {
        func_00226630(&msg);
    }
    if (func_00300C90) {
        func_00300C90();
    }
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

#include <string.h>
#include <stddef.h>
#include "screen_manager.h"
#include "overlay_loader.h"

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((weak)) int func_188140(void *app) {
    (void)app;
    return 1;
}

__attribute__((weak)) void *func_100850(int size) {
    (void)size;
    return NULL;
}

__attribute__((weak)) void *func_23FF80(void *panel) {
    return panel;
}

__attribute__((weak)) void func_188680(void *app) {
    (void)app;
}

__attribute__((weak)) void func_1886B0(void *app) {
    (void)app;
}

__attribute__((weak)) void func_2F8DB0(void *app) {
    (void)app;
}

__attribute__((weak)) void func_185F00(void *app, int a1, int a2) {
    (void)app;
    (void)a1;
    (void)a2;
}

__attribute__((weak)) int func_3000B0(void *app, int mode) {
    (void)app;
    (void)mode;
    return 1;
}

/*
 * func_002FD5A0: Screen transition helper
 * Matches AOK.ELF 0x002FD5A0 - 0x002FD5BC
 */
int func_002FD5A0(void *app) {
    func_188140(app);
    return 1;
}

/*
 * func_002FD5C0: Main screen change driver to SMENU
 * Matches AOK.ELF 0x002FD5C0 - 0x002FD994
 */
int func_002FD5C0(void *app) {
    if (!app) {
        return 0;
    }

    char *self = (char *)app;

    /* 1. Clear screen state arrays 0x191C (7 bytes) and 0x1924 (7 words) */
    for (int i = 0; i < 7; ++i) {
        self[0x191C + i] = 0;
        *(int *)(self + 0x1924 + i * 4) = 0;
    }

    /* 2. Release previous panel at 0x1468 if present */
    void *old_panel = *(void **)(self + 0x1468);
    if (old_panel) {
        typedef void (*ReleaseFn)(void *p, int flag);
        void ***vtable_ptr = (void ***)old_panel;
        if (vtable_ptr && *vtable_ptr && (*vtable_ptr)[2]) {
            ReleaseFn release = (ReleaseFn)(*vtable_ptr)[2];
            release(old_panel, 1);
        }
        *(void **)(self + 0x1468) = NULL;
    }

    /* 3. Stream smenu_cd.bin into 0x01D98000 */
    func_00300C90();

    /* 4. Register screen mode (mode 4) */
    func_3000B0(app, 4);

    return 1;
}

/*
 * func_002FC350: Menu screen transition caller
 * Matches AOK.ELF 0x002FC350
 */
int func_002FC350(void *app) {
    return func_002FD5C0(app);
}

/*
 * func_002FC510: Scenario/game screen transition caller
 * Matches AOK.ELF 0x002FC510
 */
int func_002FC510(void *app) {
    func_002FD5A0(app);
    return func_002FD5C0(app);
}

/*
 * func_002F8EA0: Multi-menu transition caller
 * Matches AOK.ELF 0x002F8EA0
 */
int func_002F8EA0(void *app) {
    (void)app;
    func_00300C60();
    return 1;
}

#ifdef __cplusplus
}
#endif

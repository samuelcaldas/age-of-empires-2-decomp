#include <stddef.h>
#include "game_thread.h"
#include "overlay_loader.h"

void *g_mo_ov_handle = NULL;
void *g_dcomp_ptr = NULL;
unsigned char g_dcomp_loaded = 0;
void *g_game_context = NULL;

MoOvEntryFn g_mo_ov_entry = (MoOvEntryFn)MO_OV_ENTRY_POINT;
RmmMemEntryFn g_rmmmem_entry = (RmmMemEntryFn)RMMMEM_ENTRY_POINT;
HistEntryFn g_hist_entry = (HistEntryFn)HIST_ENTRY_POINT;
DcompInitFn g_dcomp_init = (DcompInitFn)DCOMP_ENTRY_INIT;
DcompDispatchFn g_dcomp_dispatch = (DcompDispatchFn)DCOMP_ENTRY_DISPATCH;

__attribute__((weak)) void func_0036CC40(void *handle) {
    (void)handle;
}

__attribute__((weak)) void func_257E40(void *ctx) {
    (void)ctx;
}

/*
 * 0x00300C90
 * Streams smenu_cd.bin into 0x01D98000
 */
int func_00300C90(void) {
    while (!func_002240B0("smenu_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}

/*
 * 0x00300C60
 * Streams multimcd.bin into 0x01D98000
 */
int func_00300C60(void) {
    while (!func_002240B0("multimcd.bin", (void *)OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}

/*
 * 0x003800F0
 * Streams thelp_cd.bin into 0x01F68000
 */
int func_003800F0(void) {
    while (!func_002240B0("thelp_cd.bin", (void *)THELP_OVERLAY_LOAD_ADDR)) {
    }
    return 1;
}

/*
 * 0x0036C350
 * Streams mo_ov_cd.bin into 0x01ED7000, executes 0x01ED7080,
 * stores returned handle in gp - 0x71a4, and passes it to func_0036CC40
 */
void func_0036C350(void) {
    while (!func_002240B0("mo_ov_cd.bin", (void *)MO_OV_OVERLAY_LOAD_ADDR)) {
    }
    if (g_mo_ov_entry != NULL) {
        g_mo_ov_handle = g_mo_ov_entry();
    }
    func_0036CC40(g_mo_ov_handle);
}

/*
 * 0x0022F550
 * Checks field_13C. If 0, streams rmmmemcd.bin into 0x01D98000
 * and executes entry point 0x01D98080.
 */
int func_0022F550(void *screen_obj) {
    if (screen_obj != NULL && *(int *)((char *)screen_obj + 0x13C) == 0) {
        while (!func_002240B0("rmmmemcd.bin", (void *)OVERLAY_LOAD_ADDR)) {
        }
        if (g_rmmmem_entry != NULL) {
            g_rmmmem_entry();
        }
        return 1;
    }
    return 0;
}

/*
 * 0x00258E40
 * Prepares context via func_257E40, streams hist_cd.bin into 0x01D98000,
 * and executes entry point 0x01D98820.
 */
int func_00258E40(void *context) {
    (void)context;
    func_257E40(g_game_context);
    while (!func_002240B0("hist_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
    }
    if (g_hist_entry != NULL) {
        g_hist_entry();
    }
    return 1;
}

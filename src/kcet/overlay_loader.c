#include <stddef.h>
#include "game_thread.h"
#include "overlay_loader.h"

void *g_mo_ov_handle = NULL;
void *g_dcomp_ptr = NULL;
unsigned char g_dcomp_loaded = 0;

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

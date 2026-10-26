#include "game_thread.h"
#include "overlay_loader.h"

__attribute__((weak)) int func_00300C90(void) {
    while (!func_002240B0("smenu_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
        /* wait for disc read completion */
    }
    return 1;
}

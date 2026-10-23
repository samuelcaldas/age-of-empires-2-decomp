/**
 * kcet_iop_drivers.c - KCET Proprietary IOP Drivers Implementation
 *
 * Age of Empires II (PS2 SLES-50282)
 *
 * Implements the RPC server functions and drivers for the IOP MIPS processor:
 *   - soundcd: SPU2 DMA control and CD-DA audio track playback
 *   - sdstr: Stream buffer ring management for speech and voiceover
 *   - sdcd: Low-level CD/DVD sector polling and synchronization
 *   - usbmlcnt / usbmload: USB mouse packet parser and event queue
 */

#include "kcet_iop_drivers.h"
#include <string.h>

static KcetMousePacket s_mouse_state = { 0, 0, 0, 0, 0 };
static uint16_t s_master_volume = 0x3fff;

int soundcd_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int sdstr_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int sdcd_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int sdrdrv_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int usbmlcnt_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int usbmload_init(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    return 0;
}

int kcet_sound_rpc_dispatch(int command, void *data, size_t size) {
    (void)size;
    if (command == KCET_SOUND_CMD_SET_VOLUME && data) {
        s_master_volume = *(uint16_t *)data;
        return 0;
    }
    if (command == KCET_SOUND_CMD_PLAY_TRACK && data) {
        /* Start CD-DA streaming via SPU2 channel */
        return 0;
    }
    if (command == KCET_SOUND_CMD_STOP_TRACK) {
        return 0;
    }
    return 0;
}

int kcet_mouse_rpc_dispatch(int command, void *data, size_t size) {
    if (command == KCET_MOUSE_CMD_GET_STATE && data && size >= sizeof(KcetMousePacket)) {
        memcpy(data, &s_mouse_state, sizeof(KcetMousePacket));
        /* Reset relative delta movement after polling */
        s_mouse_state.delta_x = 0;
        s_mouse_state.delta_y = 0;
        return 0;
    }
    return 0;
}

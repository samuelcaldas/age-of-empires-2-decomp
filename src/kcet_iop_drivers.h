/**
 * kcet_iop_drivers.h - KCET Proprietary IOP Drivers Interface
 *
 * Age of Empires II (PS2 SLES-50282)
 * Target: IOP MIPS R3000A (32-bit Little Endian)
 *
 * Covers:
 *   1. SOUNDCD.IRX ("kcet sd drv.") - Master Audio Synthesizer & CD-DA Mixer
 *   2. SDSTR.IRX   ("sdstr_driver") - Streaming Voice & Music Subsystem
 *   3. SD_CD.IRX   ("sdcd_Lib")     - CD-DA Sector Reader Library
 *   4. SDRDRV.IRX  ("sdr_driver")   - Sony SPU2 Sound Runtime
 *   5. USBMLCNT.IRX ("usbmlcnt")    - Mouse Event Packet Controller
 *   6. USBMLOAD.IRX ("USB_module_loader") - Dynamic Peripheral Loader
 */

#ifndef KCET_IOP_DRIVERS_H
#define KCET_IOP_DRIVERS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IOP Audio RPC Commands */
#define KCET_SOUND_CMD_INIT         0x01
#define KCET_SOUND_CMD_PLAY_TRACK   0x02
#define KCET_SOUND_CMD_STOP_TRACK   0x03
#define KCET_SOUND_CMD_SET_VOLUME   0x04
#define KCET_SOUND_CMD_PLAY_VOICE   0x05
#define KCET_SOUND_CMD_STREAM_CHUNK 0x06

/* IOP Mouse RPC Commands */
#define KCET_MOUSE_CMD_GET_STATE    0x10
#define KCET_MOUSE_CMD_SET_SPEED    0x11
#define KCET_MOUSE_CMD_POLL_PACKET  0x12

typedef struct {
    int16_t delta_x;
    int16_t delta_y;
    uint8_t buttons;
    uint8_t wheel;
    uint16_t reserved;
} KcetMousePacket;

typedef struct {
    uint32_t track_id;
    uint16_t volume_l;
    uint16_t volume_r;
    uint32_t loop_flag;
} KcetSoundTrackCmd;

/* Driver entry point prototypes (IOP MIPS) */
int soundcd_init(int argc, char *argv[]);
int sdstr_init(int argc, char *argv[]);
int sdcd_init(int argc, char *argv[]);
int sdrdrv_init(int argc, char *argv[]);
int usbmlcnt_init(int argc, char *argv[]);
int usbmload_init(int argc, char *argv[]);

/* RPC Dispatchers */
int kcet_sound_rpc_dispatch(int command, void *data, size_t size);
int kcet_mouse_rpc_dispatch(int command, void *data, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* KCET_IOP_DRIVERS_H */

/**
 * kt_sound.c - KCET PlayStation 2 EE Sound Client & Streaming Driver
 *
 * Age of Empires II (PS2 SLES-50282)
 *
 * Implements SIF RPC client bindings and queries for SDCD (0x20) and SDD (0x30).
 */

#include "kt_sound.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

/* Forward declarations for PS2 SIF RPC functions */
extern int sceSifInitRpc(int mode);
extern int sceSifBindRpc(SifRpcClientData *client, int dev, int mode);
extern int sceSifCallRpc(SifRpcClientData *client, int fno, int mode,
                         void *send, int send_size,
                         void *recv, int recv_size,
                         void *end_func, void *end_para);

/* Global client structs in BSS / rodata buffers */
static SifRpcClientData D_004F1640; /* SDCD SifRpcClientData */
static SifRpcClientData D_004F1680; /* SDD SifRpcClientData */

static char D_004F1540[256];        /* Stream filename buffer */
static u8 D_0038C880[64];           /* SIF response buffer */

static int D_0012D648_initialized = 0;

/* Function 0x0012D648: Initialize Sound SIF RPC services */
int func_0012D648(void) {
    if (D_0012D648_initialized != 0) {
        return 0;
    }

    sceSifInitRpc(0);

    /* Bind SDCD (0x20) */
    sceSifBindRpc(&D_004F1640, KT_SOUND_SIF_SDCD_DEV, 0);
    if (D_004F1640.serve == NULL) {
        printf("SDCD_CDREAD_CALL DaMe!!\n");
    }

    sceSifInitRpc(0);

    /* Bind SDD (0x30) */
    sceSifBindRpc(&D_004F1680, KT_SOUND_SIF_SDD_DEV, 0);
    if (D_004F1680.serve == NULL) {
        printf("SDD_GETVOL DaMe!!\n");
        printf("sd_getvol.serve : 0x%x\n", (unsigned int)(uintptr_t)D_004F1680.serve);
    }

    D_0012D648_initialized = 1;
    return 0;
}

/* Function 0x0012D7E0: Open audio stream on CD */
int func_0012D7E0(const char *name) {
    strcpy(D_004F1540, name);
    return sceSifCallRpc(&D_004F1640, 0x10, 0, D_004F1540, 256, NULL, 0, NULL, NULL);
}

/* Function 0x0012D840: Query sound driver extended status/volume */
int func_0012D840(int cmd) {
    return sceSifCallRpc(&D_004F1680, cmd & 0xFF, 0, NULL, 0, D_0038C880, 48, NULL, NULL);
}

/* Function 0x0012D888: Query sound driver readiness status */
int func_0012D888(void) {
    sceSifCallRpc(&D_004F1680, 3, 0, NULL, 0, D_0038C880, 1, NULL, NULL);
    return (int)D_0038C880[0];
}

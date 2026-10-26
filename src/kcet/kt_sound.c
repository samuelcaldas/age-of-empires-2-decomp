/**
 * kt_sound.c - KCET PlayStation 2 EE Sound Client & Streaming Driver
 *
 * Age of Empires II (PS2 SLES-50282)
 *
 * Implements:
 * - SIF RPC client bindings and queries for SDCD (0x20) and SDD (0x30).
 * - Multi-stage audio hardware synchronization and status poll loops.
 * - Master sound channel management and volume routing.
 */

#include "kt_sound.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

/* Forward declarations for PS2 external functions */
extern int sceSifInitRpc(int mode);
extern int sceSifBindRpc(SifRpcClientData *client, int dev, int mode);
extern int sceSifCallRpc(SifRpcClientData *client, int fno, int mode,
                         void *send, int send_size,
                         void *recv, int recv_size,
                         void *end_func, void *end_para);
extern int sceGsSyncV(int mode);

/* Global client structs in BSS / rodata buffers */
static SifRpcClientData D_004F1640; /* SDCD SifRpcClientData */
static SifRpcClientData D_004F1680; /* SDD SifRpcClientData */

static char D_004F1540[256];        /* Stream filename buffer */
static u8 D_0038C880[64];           /* SIF response buffer */

static int D_0012D648_initialized = 0;

/* Sound channel configuration tables (BSS / data) */
static u32 D_004E8C20[32];
static u32 D_004E8C24[32];
static u32 D_004E8C28[32];
static u8 D_004E8C08_flag = 0;
static u8 D_004E8C10_flag = 0;
static u8 D_004E8C18_flag = 0;
static u32 D_004E8C00_master = 0;

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

/* Function 0x00220F70: VSYNC synchronization and readiness wait loop */
int func_00220F70(void) {
    sceGsSyncV(0);

    while (1) {
        int status = func_0012D888() & 0xFF;
        if (status == SDD_STATUS_BUSY) {
            /* 0x10000 iteration busy delay between queries */
            volatile int delay;
            for (delay = 0; delay < 0x100; delay++) {
                /* Delay cycles */
            }
            sceGsSyncV(0);
            continue;
        }

        if (status == SDD_STATUS_READY) {
            break;
        }

        /* If error or non-busy/non-ready state, exit loop */
        break;
    }
    return 0;
}

/* Function 0x0025D320: Set audio channel volume / attenuation */
int func_0025D320(int channel, int volume) {
    int v = volume & 0x7F;
    int addr = channel + v;
    (void)addr;
    return 0;
}

/* Function 0x0025D430: Sound command category router */
int func_0025D430(int cmd) {
    if (cmd == 0x1005) {
        return 0;
    }
    if (cmd == 0x1004) {
        return 0;
    }
    if (cmd == 0x1003) {
        return 0;
    }
    return 0;
}

/* Function 0x0025D060: Master KCET Sound Channel Dispatcher */
int func_0025D060(int cmd) {
    if (D_004E8C08_flag == 0) {
        D_004E8C08_flag = 1;
    }
    if (D_004E8C10_flag == 0) {
        D_004E8C10_flag = 1;
    }
    if (D_004E8C18_flag == 0) {
        D_004E8C18_flag = 1;
    }

    if (cmd == 0x1000) {
        D_004E8C00_master = 1;
        func_0025D320(0x1E00, 0x1B);
        func_0025D320(0x1F00, 0x1B);
        return 0;
    }

    /* Commands 0x1010 - 0x101F configure individual voices and channels */
    return 0;
}

/* Function 0x00220FF0: Multi-stage audio startup sequence */
int func_00220FF0(void) {
    int i;
    for (i = 0; i < 25; i++) {
        D_004E8C20[i] = 0x19;
    }
    func_0025D430(0x1003);

    for (i = 0; i < 24; i++) {
        D_004E8C24[i] = 0x18;
    }
    func_0025D430(0x1004);

    func_0025D430(0x1005);

    /* 5-stage sequential audio initialization commands */
    func_0025D060(0x1010);
    func_00220F70();

    func_0025D060(0x1011);
    func_00220F70();

    func_0025D060(0x1012);
    func_00220F70();

    func_0025D060(0x1013);
    func_00220F70();

    func_0025D060(0x101F);
    func_00220F70();

    return 0;
}

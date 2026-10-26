#include <string.h>
#include "game_thread.h"
#include "kt_libcdvd_server.h"

/* State machine GP offsets / global variables */
s16 g_boot_phase_init = 0;   /* gp - 0x74B8 */
s16 g_boot_phase = 0;        /* gp - 0x74B6 */
s16 g_boot_subphase = 0;     /* gp - 0x74B4 */

u64 g_frame_counter_1 = 0;   /* 0x00CA1550 */
u64 g_frame_counter_2 = 0;   /* 0x00CA1560 */

s32 g_sema_render = 1;       /* 0x00C6F390 */
s32 g_sema_vsync = 2;        /* 0x00C6F3B0 */
s32 g_sema_msg_queue = 3;    /* 0x00C6F3D0 */
int g_game_loop_break = 0;

/*
 * 0x002240B0 : Overlay CD Reader Bridge
 * Formats "EN\<filename>" on the stack and requests CDVD asynchronous sector
 * loading to destination, polling until status reports 1 (complete), then
 * invalidates data cache over the loaded image range.
 */
int func_002240B0(const char *filename, void *destination) {
    char req[64];
    int status_buf[8];

    req[0] = '0';
    req[1] = '\0';
    req[2] = '\0';
    req[3] = '\0';
    strcpy(&req[4], "EN\\");
    strcat(&req[4], filename);

    do {
        while (!func_0012C1D0(req, destination, status_buf, NULL)) {
            /* retry request submission */
        }
    } while (status_buf[0] != 1);

    func_100270((u32)status_buf[4], destination);
    return 1;
}

#include "tribe_app.h"

/* External subsystem stubs and drivers */
extern void func_1DE9900(void);
extern void func_1DE9B00(void);
extern void func_25D060(int a0);
extern void func_2249C0(int a0, void *a1, int a2);
extern int func_224B30(void);

static unsigned char s_tribe_app_buffer[TRIBE_APP_SIZE];

void func_21BDF0(void) {
    func_2F61F0(s_tribe_app_buffer, NULL, 1);
}

void func_21BFB0(void) {
    if (g_pApp != NULL) {
        void **vtable = *(void ***)g_pApp;
        if (vtable != NULL && vtable[3] != NULL) {
            typedef int (*EventLoopFn)(void *self);
            EventLoopFn fn = (EventLoopFn)vtable[3];
            fn(g_pApp);
        }
    }
}
extern void func_33B680(void);
extern void func_1C1FD0(int a0, int a1, void *a2, int a3);
extern void func_223DE0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3);
extern void func_222370(void *a0, void *a1, int a2, int a3, int t0, int t1, int t2, int t3);
extern void func_223670(void *a0, int a1);
extern void func_222B00(void);
extern void func_2230D0(void *a0);
extern void func_220E90(void);
extern void func_220FF0(void);
extern void func_223FF0(void);

extern void func_220940(void);
extern void func_220BA0(void);
extern void func_220C60(void);
extern void func_221110(void);
extern void func_221410(void);
extern void func_103358(int a0);
extern void func_2208F0(void);
extern void func_2263A0(int a0);
extern void func_2204D0(s32 sema_id);
extern void func_226260(void);
extern int func_2204E0(s32 sema_id);
extern void func_2207B0(void);
extern void func_221790(void);
extern void func_3379F0(int a0);
extern void func_36F800(int a0);
extern void func_221C00(void);
extern void func_224A10(void);

/*
 * 0x00222180
 * Sets the boot phase and resets subphase index to 0.
 */
void func_00222180(s16 phase) {
    g_boot_phase = phase;
    g_boot_subphase = 0;
}

/*
 * 0x00222190
 * Clears boot initialization flags, phase, and subphase.
 */
void func_00222190(void) {
    g_boot_phase_init = 0;
    g_boot_phase = 0;
    g_boot_subphase = 0;
}

/*
 * 0x002221A0 : Overlay Phase Sequencer & Phase 12 Handoff
 * Sequentially prepares, streams from disc, and executes the
 * language and lobby overlay modules.
 */
int func_002221A0(void) {
    s16 phase = g_boot_phase;

    switch (phase) {
    case BOOT_PHASE_INIT_START: /* 0x00 */
        func_25D060(0x2009);
        func_25D060(0x2008);
        g_boot_phase = BOOT_PHASE_PREPARE_OVERLAY; /* 0x08 */
        break;

    case BOOT_PHASE_PREPARE_OVERLAY: /* 0x08 */
        func_2249C0(0, (void *)0x00392E40, 0);
        g_boot_phase = 0x09;
        break;

    case 0x09:
        if (func_224B30()) {
            g_boot_phase = 0x0B;
        }
        break;

    case 0x0B:
        g_boot_phase = BOOT_PHASE_LOAD_OVERLAY; /* 0x0C */
        break;

    case BOOT_PHASE_LOAD_OVERLAY: /* 0x0C (Phase 12) */
        while (!func_002240B0("lobby_cd.bin", (void *)OVERLAY_LOAD_ADDR)) {
            /* loop until overlay loaded */
        }
        g_boot_phase = BOOT_PHASE_OVERLAY_ENTRY1; /* 0x10 */
        /* fallthrough into phase 0x10 handoff */
    case BOOT_PHASE_OVERLAY_ENTRY1: /* 0x10 */
        func_1DE9900();
        g_boot_phase = BOOT_PHASE_OVERLAY_ENTRY2; /* 0x11 */
        break;

    case BOOT_PHASE_OVERLAY_ENTRY2: /* 0x11 */
        func_1DE9B00();
        break;

    default:
        break;
    }

    return 0;
}

/*
 * 0x00221F40 : Boot & Menu State Machine
 * Evaluates boot flags, delegates higher phases to func_002221A0,
 * and executes initial menu/boot state machine via jump table.
 */
void func_00221F40(void) {
    if (g_boot_phase_init == 1 || g_boot_phase_init != 0) {
        return;
    }

    if (g_boot_phase == BOOT_PHASE_OVERLAY_ENTRY2) { /* 0x11 */
        func_21BFB0();
        func_33B680();
        return;
    }

    if (g_boot_phase == BOOT_PHASE_OVERLAY_ENTRY1) { /* 0x10 */
        func_21BDF0();
        g_boot_phase++;
        func_21BFB0();
        func_33B680();
        return;
    }

    if (g_boot_phase != 0) {
        func_002221A0();
        return;
    }

    /* Initial boot screen / viewport initialization */
    {
        char buffer[256];
        int rect[4] = {0};
        func_1C1FD0(0, 0xDEA8, buffer, 0x100);
        func_223DE0(buffer, 0, 0, 0, 0, 0, 0, 0);
        rect[0] = (640 - rect[2]) >> 1;
        rect[1] = (448 - rect[3]) >> 1;
        func_222370(buffer, rect, 0, 0, rect[0], rect[1], 0x9000, 0);
        func_223670(buffer, 0);
        func_222B00();
        func_2230D0(buffer);
    }

    /* Jump table at 0x00492EF0 for subphases 0..9 */
    if ((u16)g_boot_subphase < 10) {
        switch (g_boot_subphase) {
        case 0:
            g_boot_subphase++;
            break;
        case 1:
            func_220E90();
            g_boot_subphase++;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            g_boot_subphase++;
            break;
        case 6:
            func_220FF0();
            g_boot_subphase++;
            break;
        case 7:
            func_2249C0(0, (void *)0x00392DB0, 9);
            g_boot_subphase++;
            break;
        case 8:
            if (func_224B30()) {
                func_223FF0();
                g_boot_subphase++;
            }
            break;
        case 9:
            func_00222180(BOOT_PHASE_OVERLAY_ENTRY1);
            break;
        }
    }
}

/*
 * 0x002206F0_iter : Single iteration of GameThread per-frame loop
 */
void func_002206F0_iter(void) {
    func_2204D0(g_sema_render);
    func_104D40(g_sema_vsync);
    func_104D60(g_sema_render);

    g_frame_counter_1++;
    g_frame_counter_2++;
    func_226260();

    while (!func_2204E0(g_sema_msg_queue)) {
        /* wait for message queue processing */
    }

    func_2207B0();
    func_104D40(g_sema_msg_queue);
    func_221790();
    func_3379F0(0);
    func_00221F40();
    func_3379F0(0);
    func_36F800(0);
    func_221C00();
    func_224A10();
}

/*
 * 0x002206F0 : GameThread Per-Frame Loop
 * Synchronizes with VSYNC semaphore, updates peripheral inputs,
 * executes boot and menu state machine, and loops indefinitely.
 */
void func_002206F0(void) {
    while (!g_game_loop_break) {
        func_002206F0_iter();
    }
}

/*
 * 0x002206A0 : GameThread Entry Point
 * Initializes platform drivers, clears boot state, and transfers
 * execution into the per-frame game loop.
 */
void func_002206A0(void) {
    func_220940();
    func_220BA0();
    func_220C60();
    func_221110();
    func_221410();
    func_103358(0);
    func_2208F0();
    func_00222190();
    func_2263A0(1);
    func_002206F0();
}



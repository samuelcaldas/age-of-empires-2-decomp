/* KCET Gamepad Subsystem (kt_libpad.h) */
#ifndef KT_LIBPAD_H
#define KT_LIBPAD_H

#include "common.h"

/* DualShock 2 Button Masks */
#define KT_PAD_L2        0x0001
#define KT_PAD_R2        0x0002
#define KT_PAD_L1        0x0004
#define KT_PAD_R1        0x0008
#define KT_PAD_TRIANGLE  0x0010
#define KT_PAD_CIRCLE    0x0020
#define KT_PAD_CROSS     0x0040
#define KT_PAD_SQUARE    0x0080
#define KT_PAD_SELECT    0x0100
#define KT_PAD_L3        0x0200
#define KT_PAD_R3        0x0400
#define KT_PAD_START     0x0800
#define KT_PAD_UP        0x1000
#define KT_PAD_RIGHT     0x2000
#define KT_PAD_DOWN      0x4000
#define KT_PAD_LEFT      0x8000

/* Pad limits */
#define KT_PAD_MAX_ACTUATOR 6
#define KT_PAD_N_PRESS      12
#define KT_PAD_RAPID_GRP    6

/* Pad Slot Context Structure (512 bytes / 0x200 bytes per slot) */
typedef struct PadSlot {
    u16 buttons;          /* 0x00 */
    u16 buttons_pressed;  /* 0x02 */
    u16 buttons_released; /* 0x04 */
    u16 pad_06;           /* 0x06 alignment */
    u32 unk_08;           /* 0x08 */
    u32 unk_0C;           /* 0x0C */
    u8 data_10[12];       /* 0x10 */
    u8 unk_1C[24];        /* 0x1C */
    u32 unk_34;           /* 0x34 */
    u8 rapid_table[12];   /* 0x38 */
    u8 act_data[17];      /* 0x44 */
    u8 act_config[18];    /* 0x55 */
    u8 pad_67;            /* 0x67 alignment */
    u32 unk_68;           /* 0x68 */
    s32 port;             /* 0x6C */
    s32 slot;             /* 0x70 */
    s32 req_port;         /* 0x74 */
    s32 req_slot;         /* 0x78 */
    s32 act_mode;         /* 0x7C */
    s32 act_param;        /* 0x80 */
    s32 retry_count;      /* 0x84 */
    s32 unk_88;           /* 0x88 */
    s32 state;            /* 0x8C */
    s32 step;             /* 0x90 */
    s32 unk_94;           /* 0x94 */
    s32 err_count;        /* 0x98 */
    s32 press_mode;       /* 0x9C */
    s32 unk_A0;           /* 0xA0 */
    u8 act_align[12];     /* 0xA4 */
    u32 flags;            /* 0xB0 */
    u32 act_exec[2];      /* 0xB4 */
    s32 model;            /* 0xBC */
    u8 dma_buffer[0x140]; /* 0xC0 .. 0x200 */
} PadSlot;
_Static_assert(sizeof(PadSlot) == 512, "PadSlot size");
_Static_assert(offsetof(PadSlot, buttons) == 0x00, "PadSlot buttons offset");
_Static_assert(offsetof(PadSlot, port) == 0x6C, "PadSlot port offset");
_Static_assert(offsetof(PadSlot, state) == 0x8C, "PadSlot state offset");
_Static_assert(offsetof(PadSlot, dma_buffer) == 0xC0, "PadSlot dma_buffer offset");

/* Pad Global State Structure */
typedef struct PadWork {
#if defined(__LP64__)
    u32 slots;      /* 0x00: pointer/GuestAddr to PadSlot array */
#else
    PadSlot *slots; /* 0x00: pointer to PadSlot array */
#endif
    s32 n_pad;      /* 0x04: number of pads */
    s32 sema;       /* 0x08: semaphore id */
    s32 flags;      /* 0x0C */
} PadWork;
_Static_assert(sizeof(PadWork) == 16, "PadWork size");
_Static_assert(offsetof(PadWork, slots) == 0x00, "PadWork slots offset");
_Static_assert(offsetof(PadWork, n_pad) == 0x04, "PadWork n_pad offset");
_Static_assert(offsetof(PadWork, sema) == 0x08, "PadWork sema offset");
_Static_assert(offsetof(PadWork, flags) == 0x0C, "PadWork flags offset");

/* Functions 0x125A70 .. 0x125AF8 */
PadSlot *func_00125A70(int idx);
void func_00125AA8(void);
void func_00125AC8(void);
int func_00125AE8(int a0, int a1);
int func_00125AF8(void);

void func_00125C38(int rpc_id, int n_pad, PadSlot *buf);
void func_00125C58(int rpc_id, int n_pad, PadSlot *buf, int flag);
void func_00125E30(PadSlot *p);
void func_00125E68(PadSlot *p);
int func_001262E8(int *p_ports, int start, u16 *out_ports, int max_items, int n_ports);
void func_00126350(int pad_number, int cmd);
u32 func_00126410(int pad_number);
u32 func_00126488(int pad_number);
u32 func_00126500(int pad_number);
int func_001275A0(PadSlot *p);
int func_001276B8(PadSlot *p);
void func_00127BD8(PadSlot *p);
int func_00127BE8(PadSlot *p);

/* Aliases / Macros for known function names */
#define ktPadInit                   func_00125C38
#define ktPadInit2                  func_00125C58
#define ktPadResetButtons           func_00125E30
#define ktPadResetAll               func_00125E68
#define ktPadEnumPorts              func_001262E8
#define ktPadDispatchCmd            func_00126350
#define ktPadGetButtons             func_00126410
#define ktPadGetButtonsPressed      func_00126488
#define ktPadGetButtonsReleased     func_00126500
#define ktPadProcessState           func_001275A0
#define ktPadCheckDisconnected      func_001276B8
#define ktPadCountError             func_00127BD8
#define ktPadReadDmaBuffer          func_00127BE8

#endif /* KT_LIBPAD_H */

#ifndef KT_MOUSE_H
#define KT_MOUSE_H

#include <stddef.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

/*
 * KCET Mouse Port and Event structures.
 * Per AOK.ELF binary analysis (VRAM 0x00134DE8 - 0x00135EA0):
 *
 * Each port is 176 (0xB0) bytes in D_509F00[2]:
 *   +0x00: s16 port_id
 *   +0x02: s16 state (-1: unallocated/free, 0+: allocated / active state)
 *   +0x04: s32 type (device type assigned at alloc)
 *   +0x08: s32 payload_len (bytes in payload buffer)
 *   +0x0C: u8  payload[8] (payload buffer)
 *   +0x14: s32 queue_cap (capacity of event ring buffer, initialized to 4)
 *   +0x18: s32 read_idx (current dequeue ring index)
 *   +0x1C: s32 write_idx (current enqueue ring index)
 *   +0x20: KT_MOUSE_EVENT events[4] (ring buffer, 4 entries * 0x24 bytes = 0x90 bytes)
 * Total port size: 0x20 + 0x90 = 0xB0 (176) bytes.
 */

typedef struct KT_MOUSE_EVENT {
    s32 valid;          /* +0x00: 1 if entry contains event, 0 if free */
    s32 data[8];        /* +0x04 .. +0x24: 8 data words (packet / payload / delta) */
} KT_MOUSE_EVENT;
_Static_assert(sizeof(KT_MOUSE_EVENT) == 36, "KT_MOUSE_EVENT size must be 0x24");

typedef struct KT_MOUSE_PORT {
    s16 port_id;                /* +0x00 */
    s16 state;                  /* +0x02: -1 if free */
    s32 type;                   /* +0x04 */
    s32 payload_len;            /* +0x08 */
    u8  payload[8];             /* +0x0C */
    s32 queue_cap;              /* +0x14: initialized to 4 */
    s32 read_idx;               /* +0x18 */
    s32 write_idx;              /* +0x1C */
    KT_MOUSE_EVENT events[4];   /* +0x20: ring buffer of 4 entries */
} KT_MOUSE_PORT;
_Static_assert(sizeof(KT_MOUSE_PORT) == 176, "KT_MOUSE_PORT size must be 0xB0 (176) bytes");
_Static_assert(offsetof(KT_MOUSE_PORT, port_id) == 0x00, "KT_MOUSE_PORT port_id offset");
_Static_assert(offsetof(KT_MOUSE_PORT, state) == 0x02, "KT_MOUSE_PORT state offset");
_Static_assert(offsetof(KT_MOUSE_PORT, type) == 0x04, "KT_MOUSE_PORT type offset");
_Static_assert(offsetof(KT_MOUSE_PORT, payload_len) == 0x08, "KT_MOUSE_PORT payload_len offset");
_Static_assert(offsetof(KT_MOUSE_PORT, payload) == 0x0C, "KT_MOUSE_PORT payload offset");
_Static_assert(offsetof(KT_MOUSE_PORT, queue_cap) == 0x14, "KT_MOUSE_PORT queue_cap offset");
_Static_assert(offsetof(KT_MOUSE_PORT, read_idx) == 0x18, "KT_MOUSE_PORT read_idx offset");
_Static_assert(offsetof(KT_MOUSE_PORT, write_idx) == 0x1C, "KT_MOUSE_PORT write_idx offset");
_Static_assert(offsetof(KT_MOUSE_PORT, events) == 0x20, "KT_MOUSE_PORT events offset");

typedef struct KT_MOUSE_WORK {
    s32 handle;                 /* +0x00: semaphore handle */
    s32 count;                  /* +0x04: n_mouse (<= 2) */
    char *buffer;               /* +0x08: pointer to port buffer (D_509F00) */
    s32 flag;                   /* +0x0C */
} KT_MOUSE_WORK;
_Static_assert(sizeof(KT_MOUSE_WORK) == 16, "KT_MOUSE_WORK size must be 0x10 bytes");
_Static_assert(offsetof(KT_MOUSE_WORK, handle) == 0x00, "KT_MOUSE_WORK handle offset");
_Static_assert(offsetof(KT_MOUSE_WORK, count) == 0x04, "KT_MOUSE_WORK count offset");
_Static_assert(offsetof(KT_MOUSE_WORK, buffer) == 0x08, "KT_MOUSE_WORK buffer offset");
_Static_assert(offsetof(KT_MOUSE_WORK, flag) == 0x0C, "KT_MOUSE_WORK flag offset");

typedef struct {
    s32 f0;                     /* +0x00 */
    s32 f4;                     /* +0x04 */
    s32 f8;                     /* +0x08: mouse_id / port index */
} MouseBlock_9B8;
_Static_assert(sizeof(MouseBlock_9B8) == 12, "MouseBlock_9B8 size must be 0x0C bytes");
_Static_assert(offsetof(MouseBlock_9B8, f0) == 0x00, "MouseBlock_9B8 f0 offset");
_Static_assert(offsetof(MouseBlock_9B8, f4) == 0x04, "MouseBlock_9B8 f4 offset");
_Static_assert(offsetof(MouseBlock_9B8, f8) == 0x08, "MouseBlock_9B8 f8 offset");

/* Function declarations */
int func_00134DE8(int a0, int a1);
void func_00134E50(int n_mouse);
void func_00134F18(void);
void func_00134F20(void);
void func_00134F50(void);
void func_00134F90(void);
void func_00134FB8(void);
int func_00134FE0(int a0, int a1);
void func_00135008(int a0);
int *func_00135058(int a0);
void func_00135090(int a0);
int *func_001350E0(int a0);
int func_00135118(int a0, int *out);
short func_001351B0(short *ptr);
short func_001351B8(int a0);
int func_00135238(short *ptr);
int func_00135258(int a0);
int func_001352D8(int a0, int *out);
int func_001353C0(int a0);
void func_00135478(void);
void func_001354A0(void);
void func_001354C8(int a0);
void func_00135508(void);
void *func_00135530(void);
void func_00135598(int *ptr);
int func_001355D0(int a0);
void func_00135638(int a0, int a1);
int func_001356D8(short *ptr);
int func_001356E8(int a0, int a1);
int func_00135798(int a0, void *a1, int a2);
int func_00135870(int a0, int a1, int a2, int a3, int a4);
int func_00135980(void);
void func_001359B8(MouseBlock_9B8 *ptr, int val);
void func_001359D0(char *ptr, int count, int stride);
void func_00135A38(char *ptr, int count, int stride, int a3);
void func_00135AB8(char *ptr, int count, int stride, int a3, char *buf);
void func_00135B88(int a0);
void func_00135BE8(void);
void func_00135BF0(void);
void func_00135D60(int a0);
void func_00135D98(void);

/* Aliases / Macros for known function names */
#define ktMouseDispatchNotify       func_00134DE8
#define ktMouseInit                 func_00134E50
#define ktMouseLock                 func_00134F90
#define ktMouseUnlock               func_00134FB8
#define ktMouseAdvanceWriteIndex    func_00135008
#define ktMouseGetWriteBufferEntry  func_00135058
#define ktMouseAdvanceReadIndex     func_00135090
#define ktMouseGetReadBufferEntry   func_001350E0
#define ktMouseReadPacket           func_00135118
#define ktMouseGetStatus            func_00135258
#define ktMouseReadPayload          func_001352D8
#define ktMouseResetPorts           func_001353C0
#define ktMouseStartup              func_001354C8
#define ktMouseShutdown             func_00135508
#define ktMouseFindFreePort         func_00135530
#define ktMouseSetPortState         func_001356E8
#define ktMouseSetPayload           func_00135798
#define ktMousePostEvent            func_00135870
#define ktMouseProcessEvents        func_00135BF0

#endif /* KT_MOUSE_H */

#ifndef KT_MOUSE_H
#define KT_MOUSE_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

/* KCET Mouse device structure (176 bytes / 0xB0 bytes per mouse) */
typedef struct KT_MOUSE {
    s32 state;
    s32 buttons;
    s32 x;
    s32 y;
    s32 wheel;
    u8 raw_data[156];
} KT_MOUSE;

/* Global mouse context structure */
typedef struct KT_MOUSE_WORK {
    s32 pad0;
    s32 n_mouse;
    KT_MOUSE *mice;
    s32 flags;
} KT_MOUSE_WORK;

/* Function declarations */
void func_00134E50(int n_mouse);
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
void func_001354C8(int a0);
void func_00135508(void);
void *func_00135530(void);
int func_001356E8(int a0, int a1);
int func_00135798(int a0, void *a1, int a2);
int func_00135870(int a0, int a1, int a2, int a3, int a4);
void func_00135BF0(void);

/* Aliases / Macros for known function names */
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

void ktMouseDummy(void);
void ktMousePoll(void);
int ktMouseCheck(void);
void ktMouseFuncA(void);
void ktMouseFuncB(void);

#endif /* KT_MOUSE_H */

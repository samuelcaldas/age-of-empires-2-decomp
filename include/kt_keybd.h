#ifndef KT_KEYBD_H
#define KT_KEYBD_H

#include "common.h"

typedef struct {
    s32 handle;
    s32 count;
    u32 buffer;
} KeybdWork;
_Static_assert(sizeof(KeybdWork) == 12, "KeybdWork size");
_Static_assert(offsetof(KeybdWork, handle) == 0, "KeybdWork handle offset");
_Static_assert(offsetof(KeybdWork, count) == 4, "KeybdWork count offset");
_Static_assert(offsetof(KeybdWork, buffer) == 8, "KeybdWork buffer offset");

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} KeybdBlock;
_Static_assert(sizeof(KeybdBlock) == 12, "KeybdBlock size");
_Static_assert(offsetof(KeybdBlock, f0) == 0, "KeybdBlock f0 offset");
_Static_assert(offsetof(KeybdBlock, f4) == 4, "KeybdBlock f4 offset");
_Static_assert(offsetof(KeybdBlock, f8) == 8, "KeybdBlock f8 offset");

typedef struct {
    char data[16];
} KeybdData16;
_Static_assert(sizeof(KeybdData16) == 16, "KeybdData16 size");

void func_00135EC0(int n_keybd);
void func_00135F90(void);
void func_00135F98(void);
void func_00135FC8(void);
void func_00136008(void);
void func_00136030(void);
int func_00136058(int a0, int a1);
void func_00136080(int a0);
int *func_001360D0(int a0);
void func_00136108(int a0);
int *func_00136158(int a0);
int func_00136190(int a0, KeybdData16 *out);
short func_00136228(short *ptr);
short func_00136230(int a0);
int func_001362B8(short *ptr);
int func_001362D8(int a0);
int func_00136360(int a0, int *out);
int func_00136450(int a0);
void func_00136508(int a0, int a1);
void func_00136598(int a0, int a1);
void func_00136628(int a0);
void func_00136668(void);
void *func_00136690(void);
void func_001366F8(int *ptr);
int func_00136730(int a0);
void func_00136798(int a0, int a1);
int func_00136840(short *ptr);
int func_00136850(int a0, int a1);
int func_00136908(int a0, const void *a1, int a2);
int func_001369E8(int a0, unsigned char a1, unsigned char a2, const void *a3, int a4);
int func_00136B50(int a0);
void func_00136BE0(int a0, int a1);
int func_00136C90(int a0);
void func_00136D20(int a0, int a1);
void func_00136DD0(KeybdBlock *ptr, int val);
void func_00136DE8(char *ptr, int count, int stride);
void func_00136E50(char *ptr, int count, int stride, int a3);
void func_00136ED0(char *ptr, int count, int stride, int a3, char *buf);
void func_00136FA0(int a0);
void func_00137000(void);
void func_001371C8(int a0);
void func_00137200(void);

/* Aliases / Macros for known function names */
#define ktKeybdInit                 func_00135EC0
#define ktKeybdLock                 func_00136008
#define ktKeybdUnlock               func_00136030
#define ktKeybdAdvanceWriteIndex    func_00136080
#define ktKeybdGetWriteBufferEntry  func_001360D0
#define ktKeybdAdvanceReadIndex     func_00136108
#define ktKeybdGetReadBufferEntry   func_00136158
#define ktKeybdReadPacket           func_00136190
#define ktKeybdGetStatus            func_001362D8
#define ktKeybdResetPorts           func_00136450
#define ktKeybdSetBus               func_00136508
#define ktKeybdSetLocation          func_00136598
#define ktKeybdStartup              func_00136628
#define ktKeybdShutdown             func_00136668
#define ktKeybdFindFreePort         func_00136690
#define ktKeybdSetPortState         func_00136850
#define ktKeybdPostEvent            func_001369E8
#define ktKeybdGetLed               func_00136B50
#define ktKeybdSetLed               func_00136BE0
#define ktKeybdGetCapsType          func_00136C90
#define ktKeybdSetCapsType          func_00136D20
#define ktKeybdProcessEvents        func_00137000

#endif /* KT_KEYBD_H */

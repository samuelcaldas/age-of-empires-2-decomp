#include "common.h"
#include "kt_gpu.h"
#include "kt_libpad.h"

#if defined(__mips__)
typedef unsigned int u128 __attribute__((mode(TI)));
#else
typedef struct { u64 lo, hi; } u128;
#endif
typedef void (*FuncPtr)(void *, void *);

extern const u128 D_38C730;
extern FuncPtr D_38C740[];
extern const char D_48F1B8[];
extern const char D_48F1C8[];

void func_1045E8(void *p, u128 q);
int func_123A70(void *p);
void func_1046A8(void *p, int reg, u64 val);
void func_114320(const char *file, int line, const char *expr);
void func_104448(void *p, int, int, int);
void func_104600(void *p);

/* 0x00125808 : ktGpuSetFrame1 (handler 23) */
void func_00125808(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 6, data[1]);
}

/* 0x00125858 : ktGpuSetFrame2 (handler 24) */
void func_00125858(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 20, data[1]);
}

/* 0x001258A8 : ktGpuSetZbuf1 (handler 25) */
void func_001258A8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 22, data[1]);
}

/* 0x001258F8 : ktGpuSetZbuf2 (handler 26) */
void func_001258F8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3B, data[1]);
}

/* 0x00125940 : ktGpuSetDrawRegisters (handler 27) */
void func_00125940(void *p, u32 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x1C, data[1]);
}

/* 0x00125988 : ktGpuResetTestRegister (handler 28) */
void func_00125988(void *p) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3F, 0);
}

/* 0x001259C8 : ktGpuDispatchCommand (dispatcher) */
void func_001259C8(void *p, u8 *cmd, int flag) {
    u8 kind = *cmd;
    if (kind >= 29) {
        func_114320(D_48F1B8, 630, D_48F1C8);
    }
    if (!flag) {
        func_104448(p, 0, 0, 0);
    }
    D_38C740[kind](p, cmd);
    func_104600(p);
}

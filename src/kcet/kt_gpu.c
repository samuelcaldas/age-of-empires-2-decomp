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

/* 0x00125808 (handler 23) */
void func_00125808(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 6, data[1]);
}

/* 0x00125858 (handler 24) */
void func_00125858(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 20, data[1]);
}

/* 0x001258A8 (handler 25) */
void func_001258A8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 22, data[1]);
}

/* 0x001258F8 (handler 26) */
void func_001258F8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3B, data[1]);
}

/* 0x00125940 (handler 27) */
void func_00125940(void *p, u32 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x1C, data[1]);
}

/* 0x00125988 (handler 28) */
void func_00125988(void *p) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3F, 0);
}

/* 0x001259C8 (dispatcher) */
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

/* GpuWorkState defined in kt_gpu.h */

extern GpuWorkState D_4EA148;
void func_134500(int);
void func_134440(int);
void func_10D8B0(int, int, void *);
int func_10D0F8(int, int);
int func_10CE90(void);
void func_116F68(int);
void func_1344C0(int);

/* 0x00125A70 */
void *func_00125A70(int idx) {
    if ((unsigned int)idx < (unsigned int)D_4EA148.count) {
        return D_4EA148.buffer + (idx << 9);
    }
    return 0;
}

/* 0x00125AA8 */
void func_00125AA8(void) {
    if (D_4EA148.sema >= 0) {
        func_134500(D_4EA148.sema);
    }
}

/* 0x00125AC8 */
void func_00125AC8(void) {
    if (D_4EA148.sema >= 0) {
        func_134440(D_4EA148.sema);
    }
}

/* 0x00125AE8 */
void func_00125AE8(int a0, int a1) {
#if defined(__mips__)
    register void *gp asm("8");
    func_10D8B0(a0, a1, (char *)gp - 0x7c00);
#else
    func_10D8B0(a0, a1, NULL);
#endif
}

/* 0x00125AF8 */
int func_00125AF8(void) {
    int i;
    int res = 1;

    if (D_4EA148.count > 0) {
        for (i = 0; i < D_4EA148.count; i++) {
            PadSlot *item = (PadSlot *)func_00125A70(i);
            int v1 = item->port;
            int v2 = item->slot;
            if (v1 != -1 && v2 != -1) {
                if (item->flags & 0x20000) {
                    func_00125AE8(v1, v2);
                }
                if (func_10D0F8(v1, v2) == 1) {
                    res = 0;
                    item->slot = -1;
                    item->port = -1;
                }
            }
        }
    }
    if (res != 0) {
        if (func_10CE90() == 1) {
            if (D_4EA148.flags & 1) {
                func_116F68(*(int *)((char *)&D_4EA148 - 24248));
                D_4EA148.flags &= ~1;
            }
            func_1344C0(D_4EA148.sema);
        } else {
            res = 0;
        }
    }
    return res;
}

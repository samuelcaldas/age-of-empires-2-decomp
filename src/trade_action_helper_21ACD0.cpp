#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00221B60(int type);
void func_0021DF50(void *ctx, int a1, int f1c, int a3, int s1, int a5, int a6, int aligned_3c, long long f38);
void func_00223F50(void);
void func_0021E370(int a0, int v0, int f1c, int a3, int t0, int t1, int t2, int t3);

int func_0021ACD0(void *arg0, void *arg1) {
    char *s0 = (char *)arg0;
    unsigned int flags0 = *(unsigned int *)(s0 + 0x98);

    if ((flags0 & 0x800) == 0) {
        return 0;
    }

    char *s1 = (char *)arg1;
    unsigned int flags1 = *(unsigned int *)(s1 + 0x98);
    if ((flags1 & 0x200) != 0) {
        return 0;
    }

    int s1_54 = *(int *)(s0 + 0x54);
    void *ctx = func_00221B60(0xC);
    short f38 = *(short *)(s0 + 0x38);
    short f1c = *(short *)(s0 + 0x1C);
    int f3c = *(int *)(s0 + 0x3C);
    int aligned_3c = (f3c + 3) & ~3;

    func_0021DF50(ctx, 0x28C0, f1c, 0xA, s1_54, 0, 0, aligned_3c, f38);
    return 0;
}

int func_0021AD70(void *self) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);
    int v0 = *(int *)(self_bytes + 0x54);
    int t2 = 0;
    int t3 = 0;

    if ((flags & 0x200) != 0) {
        func_00223F50();
        t2 = 2;
        t3 = 2;
    }

    flags = *(unsigned int *)(self_bytes + 0x98);
    if ((flags & 0x800) != 0) {
        v0 = 0xA3000;
        t2 = 0;
        t3 = 0;
    }

    if ((flags & 0x200) == 0) {
        return 0;
    }

    int a3 = *(int *)(self_bytes + 0x3C);
    int t0 = *(int *)(self_bytes + 0x38);
    int f1c = *(int *)(self_bytes + 0x1C);
    func_0021E370(0, v0, f1c, a3, t0, 0x50000, t2, t3);
    return 0;
}

int func_0021AE10(void *self) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        return 0;
    }

    func_00223F50();

    flags = *(unsigned int *)(self_bytes + 0x98);
    if ((flags & 0x200) == 0) {
        return 0;
    }

    int f1c = *(int *)(self_bytes + 0x1C);
    func_0021E370(0, 0, f1c, 640, 512, 0x50000, 2, 2);
    return 0;
}
}

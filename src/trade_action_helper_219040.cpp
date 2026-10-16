#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *memset(void *dest, int val, unsigned int size);
void *func_00219C90(void *self, int arg1);
int func_00225200(void *arg0);
int func_0011ACD0(void *arg0);
int func_002252E0(void *buf, void *s2, short arg2);
int func_00225DB0(void *arg0, void *arg1, short arg2, void *loc198);

typedef void *(*VirtualFn128)(void *, int);

void func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, void *arg5, int arg6) {
    char *s6 = (char *)self;
    int s1 = (arg6 != 0) ? *(int *)(s6 + 0x14C) : *(int *)(s6 + 0x148);

    void *s2;
    if (arg6 != 0) {
        s2 = func_00219C90(self, (int)arg3);
    } else {
        void **vtable = *(void ***)self;
        VirtualFn128 fn128 = (VirtualFn128)*(void **)((char *)vtable + 0x128);
        s2 = fn128(self, (int)arg3);
    }

    int loc198[2] = {0, 0};
    int s0 = 0;

    if (s2 != 0) {
        short field12A = *(short *)(s6 + 0x12A);
        if (field12A == 0) {
            func_00225200(s2);
            int v0 = func_0011ACD0(s2);
            func_00225DB0(arg1, s2, (short)v0, loc198);
        } else {
            int count = func_00225200(s2);
            if ((short)count < field12A) {
                int v0 = func_0011ACD0(s2);
                func_00225DB0(arg1, s2, (short)v0, loc198);
                s0 = loc198[0];
            } else {
                char buf90[256];
                memset(buf90, 0, 256);
                func_002252E0(buf90, s2, field12A);
                int v0 = func_0011ACD0(buf90);
                func_00225DB0(arg1, s2, (short)v0, loc198);
                s0 = loc198[0];
            }
        }
    }

    if (s1 != 0 && s1 != 6) {
        s0 += 5;
    }

    int v1;
    if (s1 == 1) {
        v1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x1BC);
    } else if (s1 == 2) {
        int a1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x14) - 7 - loc198[0];
        v1 = a1 - *(int *)(s6 + 0x1BC);
    } else if (s1 == 5) {
        v1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x1BC);
        int f14 = *(int *)(s6 + 0x14);
        if (s0 + 1 >= f14) {
            v1 -= (s0 - f14 + 2);
        }
    } else {
        int f14_half = *(int *)(s6 + 0x14) >> 1;
        int loc198_half = loc198[0] >> 1;
        v1 = (*(int *)(s6 + 0xC) + f14_half) - loc198_half;
    }

    int a0_step = *(int *)(s6 + 0x17C);
    int f1c0 = *(int *)(s6 + 0x1C0);
    if (f1c0 != 0) {
        a0_step += 2 * f1c0 - 1;
    }

    int f144 = *(int *)(s6 + 0x144);
    int a1_pos;
    if (f144 == 4) {
        short f120 = *(short *)(s6 + 0x120);
        int diff = (int)f120 - (int)arg2;
        int mult = a0_step * diff;
        int sum = *(int *)(s6 + 0x10) + *(int *)(s6 + 0x18) - 1;
        a1_pos = sum - *(int *)(s6 + 0x1BC) - mult;
    } else if (f144 == 3) {
        int base = *(int *)(s6 + 0x10) + *(int *)(s6 + 0x1BC);
        a1_pos = base + a0_step * (int)arg2;
    } else {
        short f120 = *(short *)(s6 + 0x120);
        int term1 = *(int *)(s6 + 0x10) + (*(int *)(s6 + 0x18) >> 1);
        int term2 = (a0_step * (int)f120) >> 1;
        a1_pos = term1 - term2 + a0_step * (int)arg2;
    }

    int *out_rect = (int *)loc100;
    out_rect[0] = v1;
    out_rect[1] = a1_pos;
    out_rect[2] = v1 + loc198[0] - 1;
    out_rect[3] = a1_pos + *(int *)(s6 + 0x17C);

    if (arg5 != 0) {
        *(int *)arg5 = s0;
    }
}
}

#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001ABA00(void *arg0);
int func_002257A0(void *arg0, int arg1);
int func_001ABA70(void *arg0);
void func_002184D0(void *self);
void func_00218820(void *self);

typedef void (*VFnArg)(void *, void *);
typedef void (*VFn)(void *);
typedef void (*VFn5)(void *, void *, void *, void *, void *);

void func_00218350(void *self) {
    char *s4 = (char *)self;
    *(int *)(s4 + 0x38) = 0;

    void *field20 = *(void **)(s4 + 0x20);
    if (field20 == 0) {
        return;
    }

    void *field88 = *(void **)(s4 + 0x88);
    if (field88 == 0) {
        return;
    }

    void *field84 = *(void **)(s4 + 0x84);
    if (field84 == 0) {
        return;
    }

    void **vtable = *(void ***)self;
    VFnArg fn30 = (VFnArg)*(void **)((char *)vtable + 0x30);
    fn30(self, 0);

    func_002184D0(self);

    void *fresh_field20 = *(void **)(s4 + 0x20);
    void *s0_res = (void *)(unsigned long)func_001ABA00(fresh_field20);

    if (s0_res != 0) {
        int field12C = *(int *)(s4 + 0x12C);
        int s1_res = func_002257A0(s0_res, field12C);

        short s2 = *(short *)(s4 + 0x124);
        short s3 = 0;
        short limit126 = *(short *)(s4 + 0x126);

        while (limit126 >= s2) {
            int flag8C = *(int *)(s4 + 0x8C);
            int flag90 = *(int *)(s4 + 0x90);
            int flag80 = *(int *)(s4 + 0x80);

            vtable = *(void ***)self;
            VFn5 fn120 = (VFn5)*(void **)((char *)vtable + 0x120);
            if (flag8C != 0 && flag90 != 0) {
                fn120(self, s0_res, (void *)(unsigned long)s3, (void *)(unsigned long)s2, (void *)1);
            } else if (flag80 != 0) {
                fn120(self, s0_res, (void *)(unsigned long)s3, (void *)(unsigned long)s2, (void *)0);
            }

            s2 = (short)(s2 + 1);
            s3 = (short)(s3 + 1);
            limit126 = *(short *)(s4 + 0x126);
        }

        func_002257A0(s0_res, s1_res);

        fresh_field20 = *(void **)(s4 + 0x20);
        func_001ABA70(fresh_field20);
    }

    func_00218820(self);

    vtable = *(void ***)self;
    VFn fn34 = (VFn)*(void **)((char *)vtable + 0x34);
    fn34(self);
}
}

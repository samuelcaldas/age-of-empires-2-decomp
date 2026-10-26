#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00219C00(void *self, int arg1, void **loc120, void **loc124, void **loc128, void **loc12C);
void *func_00219C90(void *self, int arg1);
int func_0011ACD0(void *arg0);
int func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, int zero1, int zero2);
int func_002257A0(void *arg0, int arg1);
int func_00225200(void *arg0);
int func_00225820(void *arg0, void *arg1);
int func_00225980(void *arg0);
int func_002258D0(void *arg0, void *arg1, int arg2);

void func_00218A60(void *self, void *arg1, short arg2, short arg3, int selector) {
    char *s6 = (char *)self;
    int val128 = 0;
    int val12C = 0;

    if (selector != 0) {
        val128 = *(int *)(s6 + 0x164);
        val12C = *(int *)(s6 + 0x168);
    } else {
        val128 = *(int *)(s6 + 0x15C);
        val12C = *(int *)(s6 + 0x160);
    }

    void *local120 = 0;
    void *local124 = 0;
    void *local128 = (void *)(long)val128;
    void *local12C_ptr = (void *)(long)val12C;
    int local100_pair[2] = {0, 0};

    int s0 = (int)arg3;
    func_00219C00(self, s0, &local120, &local124, &local128, &local12C_ptr);
    void *s3 = func_00219C90(self, s0);

    if (local120 == 0 && s3 == 0) {
        return;
    }

    if (local120 != 0) {
        func_0011ACD0(local120);
    }
    if (s3 != 0) {
        func_0011ACD0(s3);
    }

    func_00219040(self, arg1, arg2, arg3, local100_pair, 0, 0);
    s6 = (char *)self; // Reload self from stack (sp+148)

    int pair_val_0 = local100_pair[0];
    int pair_val_1 = local100_pair[1];
    if (pair_val_0 == -999 && pair_val_1 == -999) {
        return;
    }

    if (local124 != 0) {
        int idx = *(int *)((char *)local124 + 4);
        int field_val = *(int *)(s6 + 0x12C + 4 * idx);
        int s1_res = func_002257A0(arg1, field_val);

        void *field14C = *(void **)(s6 + 0x14C);
        if (field14C != 0) {
            func_00225200(arg1);
            func_0011ACD0(field14C);
        }

        func_00225820(arg1, (void *)(long)s1_res);
        func_00225980(arg1);
        func_002258D0(arg1, (void *)0, 2);
        func_00225980(arg1);
    }
}
}

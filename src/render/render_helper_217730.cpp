#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00185e20(void *arg, int val);
void func_002177C0(void *self, int *arr, int arg2, int arg3);
void func_00217B50(void *self, int flag);

extern void *D_004E3058;

void func_00217730(void *self, int arg1) {
    void *v0;
    if (arg1 >= 0) {
        v0 = func_00185e20(D_004E3058, arg1);
    } else {
        v0 = func_00185e20(D_004E3058, 2);
    }

    int val = 0;
    int a2 = 0;
    int a3 = 0;
    if (v0 != 0) {
        val = *(int *)v0;
        a2 = *(int *)((char *)v0 + 4);
        a3 = *(int *)((char *)v0 + 8);
    }

    int arr[4];
    for (int a0_loop = 0; a0_loop < 4; a0_loop++) {
        arr[a0_loop] = val;
    }

    func_002177C0(self, arr, a2, a3);
}

struct BaseRenderHelper217730 {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void method28(int arg1);
};

void func_002177C0(void *self, int *arr, int arg2, int arg3) {
    char *s0 = (char *)self;
    for (int i = 0; i < 4; i++) {
        *(int *)(s0 + 0x12C + i * 4) = arr[i];
    }

    *(int *)(s0 + 0x13C) = arg2;
    *(int *)(s0 + 0x140) = arg3;

    func_00217B50(self, 1);

    ((BaseRenderHelper217730 *)self)->method28(1);
}
}

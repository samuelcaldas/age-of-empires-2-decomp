#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00185E20(void *arg, int val);
void func_002177C0(void *self, int *arr, int arg2, int arg3);
void func_00217B50(void *self, int flag);

extern void *D_004E3058;

void func_00217730(void *self, int arg1) {
    void *s0 = self;
    int selected_index = (arg1 < 0) ? 2 : arg1;
    void *v0 = func_00185E20(D_004E3058, selected_index);

    int arr[4];
    int val = 0;
    int a2 = 0;
    int a3 = 0;
    if (v0 != 0) {
        val = *(int *)v0;
        a2 = *(int *)((char *)v0 + 4);
        a3 = *(int *)((char *)v0 + 8);
    }

    int a0_loop = 0;
    do {
        arr[a0_loop] = val;
        a0_loop++;
    } while (a0_loop < 4);

    func_002177C0(s0, arr, a2, a3);
}

void func_002177C0(void *self, int *arr, int arg2, int arg3) {
    char *s0 = (char *)self;
    int i = 0;
    do {
        *(int *)(s0 + 0x12C + i * 4) = arr[i];
        i++;
    } while (i < 4);

    *(int *)(s0 + 0x13C) = arg2;
    *(int *)(s0 + 0x140) = arg3;

    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    typedef void (*Fn)(void *, int);
    Fn fn = (Fn)*(void **)((char *)vtable + 0x28);
    fn(self, 1);
}
}

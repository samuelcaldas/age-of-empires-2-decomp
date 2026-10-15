#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_185E20(void *arg, int val);
void func_2177C0(void *self, int *arr);

extern void *D_004E3058;

void func_00217730(void *self, int arg1) {
    void *s0 = self;
    void *v0;
    if (arg1 < 0) {
        v0 = func_185E20(D_004E3058, 0);
    } else {
        v0 = func_185E20(D_004E3058, 2);
    }

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

    func_2177C0(s0, arr);
}
}

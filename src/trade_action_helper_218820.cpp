#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001AB8F0(void *arg0, int arg1);
int func_001ACDF0(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5);
int func_001AD940(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6);
int func_001ADA70(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
int func_001ADC00(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10);
int func_001AB9D0(void *arg0);

void func_00218820(void *self) {
    char *s0 = (char *)self;
    int state1AC = *(int *)(s0 + 0x1AC);
    if (state1AC == 0) {
        return;
    }

    void *arg20 = *(void **)(s0 + 0x20);
    int res = func_001AB8F0(arg20, 1);
    if (res == 0) {
        arg20 = *(void **)(s0 + 0x20);
        func_001AB9D0(arg20);
        return;
    }

    state1AC = *(int *)(s0 + 0x1AC);
    if ((unsigned int)state1AC >= 8) {
        arg20 = *(void **)(s0 + 0x20);
        func_001AB9D0(arg20);
        return;
    }

    arg20 = *(void **)(s0 + 0x20);

    void *f0c = *(void **)(s0 + 0xC);
    void *f10 = *(void **)(s0 + 0x10);
    void *f14 = *(void **)(s0 + 0x14);
    void *f18 = *(void **)(s0 + 0x18);

    int computed_arg3 = (int)((unsigned long)f0c + (unsigned long)f14 - 1);
    int computed_arg4 = (int)((unsigned long)f10 + (unsigned long)f18 - 1);

    unsigned char b1B0 = *(unsigned char *)(s0 + 0x1B0);
    unsigned char b1B1 = *(unsigned char *)(s0 + 0x1B1);
    unsigned char b1B2 = *(unsigned char *)(s0 + 0x1B2);
    unsigned char b1B3 = *(unsigned char *)(s0 + 0x1B3);
    unsigned char b1B4 = *(unsigned char *)(s0 + 0x1B4);
    unsigned char b1B5 = *(unsigned char *)(s0 + 0x1B5);
    unsigned char b194 = *(unsigned char *)(s0 + 0x194);

    switch (state1AC) {
        case 1:
            func_001ACDF0(arg20, f0c, f10, computed_arg3, computed_arg4, b194);
            break;
        case 2:
            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B0);
            break;
        case 3:
            func_001ADA70(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B4, b1B1, b1B0);
            break;
        case 4:
            func_001ADC00(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B4, b1B3, b1B2, b1B1, b1B0);
            break;
        case 5:
            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B5);
            break;
        case 6:
            func_001ADA70(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B1, b1B4, b1B5);
            break;
        case 7:
            func_001ADC00(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B1, b1B2, b1B3, b1B4, b1B5);
            break;
        default:
            break;
    }

    arg20 = *(void **)(s0 + 0x20);
    func_001AB9D0(arg20);
}
}

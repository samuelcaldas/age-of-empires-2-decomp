#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_0021AE90(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5);
void func_0021ACD0(void *arg0, void *self);
void func_0021AD70(void *self);
int func_0021A960(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5);
void func_0021AE10(void *self);

int func_0021A780(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5) {
    unsigned long flags = *(unsigned int *)((char *)self + 0x98);
    int res;

    if ((flags & 0x800UL) != 0) {
        res = func_0021AE90(self, arg1, arg2, arg3, arg4, arg5);
    } else {
        if (arg2 != 0) {
            func_0021ACD0(arg2, self);
        }
        func_0021AD70(self);
        res = func_0021A960(self, arg1, arg2, arg3, arg4, arg5);
        func_0021AE10(self);
    }

    return res;
}
}

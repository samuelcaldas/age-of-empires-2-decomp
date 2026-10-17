#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00219990(void *self, int arg1);

typedef int (*VirtualMethod124)(void *self, int arg1, int arg2, int arg3, int arg4, int arg5);

int func_00219910(void *self, int arg1, int arg2, int arg3, int arg4) {
    char *s2 = (char *)self;
    int old_198 = *(int *)(s2 + 0x198);
    *(int *)(s2 + 0x198) = 0;

    void **vtable = *(void ***)self;
    VirtualMethod124 method124 = (VirtualMethod124)*(void **)((char *)vtable + 0x124);
    int res = method124(self, arg1, arg2, arg3, arg4, 0);

    if (res != 0) {
        func_00219990(self, arg1 + 1);
        *(int *)(s2 + 0x198) = old_198;
        return 1;
    }

    *(int *)(s2 + 0x198) = old_198;
    return 0;
}
}

#pragma exceptions off
#include "sub_list.h"

extern "C" {
typedef int (*VirtualMethod124)(void *self, short arg1, int arg2, int arg3, int arg4, int arg5);

int func_002198A0(void *self, short arg1, int arg2, int arg3, int arg4);
int func_002195A0(void *self, short arg1, int arg2, int arg3, int arg4);

int func_00219530(void *self, int arg1, int arg2, int arg3) {
    short f120 = *(short *)((char *)self + 0x120);
    return func_002195A0(self, f120, arg1, arg2, arg3);
}

int func_00219550(void *self, int arg1, int arg2, int arg3) {
    short f120 = *(short *)((char *)self + 0x120);
    void **vtable = *(void ***)self;
    VirtualMethod124 method124 = (VirtualMethod124)*(void **)((char *)vtable + 0x124);
    return method124(self, f120, arg1, arg2, arg3, 0);
}

int func_00219580(void *self, int arg1, int arg2) {
    short f120 = *(short *)((char *)self + 0x120);
    return func_002198A0(self, f120, arg1, arg2, 0);
}

int func_002195A0(void *self, short arg1, int arg2, int arg3, int arg4) {
    void **vtable = *(void ***)self;
    VirtualMethod124 method124 = (VirtualMethod124)*(void **)((char *)vtable + 0x124);
    return method124(self, arg1, arg2, 0, arg3, arg4);
}
}

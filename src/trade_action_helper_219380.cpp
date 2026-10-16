#pragma exceptions off
#include "sub_list.h"

extern "C" {
typedef int (*VirtualMethodD0)(void *target, void *self, int arg2, int arg3, int arg4);

int func_00219380(void *self) {
    char *s = (char *)self;
    void *target = *(void **)(s + 0x40);
    if (target == 0) {
        return 0;
    }
    void **vtable = *(void ***)target;
    VirtualMethodD0 methodD0 = (VirtualMethodD0)*(void **)((char *)vtable + 0xD0);
    return methodD0(target, self, 1, 0, 0);
}
}

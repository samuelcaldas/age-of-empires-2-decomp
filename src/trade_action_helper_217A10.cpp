#pragma exceptions off
#include "sub_list.h"

extern "C" {
typedef void (*Fn)(void *, int);

static inline void call_vtable_28(void *self) {
    void **vtable = *(void ***)self;
    Fn fn = (Fn)*(void **)((char *)vtable + 0x28);
    fn(self, 1);
}

void func_00217A10(void *self, int arg1, int arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x190) = arg1;
    int v0 = *(int *)(s0 + 0x190);
    int flag = (v0 != 0) ? 1 : 0;
    *(int *)(s0 + 0x1AC) = flag;
    *(char *)(s0 + 0x194) = (char)arg2;
    call_vtable_28(self);
}
}

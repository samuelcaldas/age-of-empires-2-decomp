#pragma exceptions off
#include "unit_action_build_42c0.h"

extern "C" {
    void func_0026AD30(void *self, int flag);
}

typedef void (*Vtable80Method)(void *self);

void func_002742C0(void *self) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif
    short type = *(short *)((char *)proto + 0xE);
    if (type != 0x3A && type != 0x1 && type != 0x2A) {
        func_0026AD30(self, 0x200);
        void **vtbl = *(void ***)self;
        Vtable80Method fn = (Vtable80Method)vtbl[32];
        fn(self);
    }
}

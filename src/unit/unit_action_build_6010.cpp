#pragma exceptions off
#include "unit_action_build_6010.h"

extern "C" {
    void func_196570(void *self, void *target);
}

typedef void (*VtableCallbackMethod)(void *target, void *owner, int arg2, int arg3, int arg4);

void func_276010(void *self, void *target) {
    func_196570(self, target);

#if defined(__LP64__) || defined(_LP64)
    void *current_target = *(void **)((char *)self + 0x38);
#else
    void *current_target = *(void **)((char *)self + 0x1C);
#endif
    if (current_target != target) {
        return;
    }

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)target + 0x8);
#else
    void *proto = *(void **)((char *)target + 0x4);
#endif
    if (*(unsigned char *)((char *)proto + 0x0) != 0x50) {
        return;
    }

#if defined(__LP64__) || defined(_LP64)
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *owner = *(void **)((char *)self + 0x8);
#endif

    void **vtbl = *(void ***)target;
    VtableCallbackMethod fn = (VtableCallbackMethod)vtbl[61];
    fn(target, owner, 0, 5, 0);
}

#pragma exceptions off
#include "unit_action_build_6080.h"

typedef void (*VtableUnbindMethod)(void *target, void *self);
typedef void (*VtableCallbackMethod)(void *target, void *owner, int arg2, int arg3, int arg4);

void func_276080(void *self) {
#if defined(__LP64__) || defined(_LP64)
    void *target = *(void **)((char *)self + 0x38);
#else
    void *target = *(void **)((char *)self + 0x1C);
#endif
    if (target == 0) {
        return;
    }

    void **vtbl = *(void ***)target;
    VtableUnbindMethod unbind_fn = (VtableUnbindMethod)vtbl[60];
    unbind_fn(target, self);

#if defined(__LP64__) || defined(_LP64)
    void *cur_target1 = *(void **)((char *)self + 0x38);
#else
    void *cur_target1 = *(void **)((char *)self + 0x1C);
#endif
    if (cur_target1 != target) {
#if defined(__LP64__) || defined(_LP64)
        void *proto = *(void **)((char *)target + 0x8);
#else
        void *proto = *(void **)((char *)target + 0x4);
#endif
        if (*(unsigned char *)((char *)proto + 0x0) == 0x50) {
#if defined(__LP64__) || defined(_LP64)
            void *owner = *(void **)((char *)self + 0x10);
#else
            void *owner = *(void **)((char *)self + 0x8);
#endif
            VtableCallbackMethod callback_fn = (VtableCallbackMethod)vtbl[62];
            callback_fn(target, owner, 0, 5, 0);
        }
    }

#if defined(__LP64__) || defined(_LP64)
    void *cur_target2 = *(void **)((char *)self + 0x38);
#else
    void *cur_target2 = *(void **)((char *)self + 0x1C);
#endif
    if (cur_target2 != target) {
        *(unsigned char *)((char *)self + 0x118) = 0;
    }
}

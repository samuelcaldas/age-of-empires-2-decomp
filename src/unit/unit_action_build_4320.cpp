#pragma exceptions off
#include "unit_action_build_4320.h"

extern "C" {
    void func_80195F40(void *self, void *target, void *arg2, int flag);
}

typedef int (*Vtable154Method)(void *self, int type);
typedef void (*Vtable94Method)(void *self, int a1, int a2, float f12);

static void check_visibility_override(void *self, void *arg4) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)arg4 + 0x8);
#else
    void *proto = *(void **)((char *)arg4 + 0x4);
#endif
    void **vtbl = *(void ***)self;
    Vtable154Method v154 = (Vtable154Method)vtbl[85];
    short type = *(short *)((char *)proto + 0xE);

    if (!v154(self, type)) {
        Vtable94Method v94 = (Vtable94Method)vtbl[37];
        v94(self, 0, 1, 0.0f);
    }
}

int func_274320(void *self, void *target, void *arg2, void *arg3, void *arg4) {
    float field_30 = *(float *)((char *)self + 0x30);
    if (field_30 < 1.0f) {
        return 0;
    }

    func_80195F40(self, target, arg2, 1);

    if (*(float *)((char *)self + 0x30) < 1.0f) {
        check_visibility_override(self, arg4);
    }

    return 1;
}

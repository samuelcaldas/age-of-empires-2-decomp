#pragma exceptions off
#include "unit_action_build_3970.h"

extern "C" {
    void func_00275A40(void *self);
    int func_00268530(void *self);
    void func_001827B0(void *arg0, void *arg1);
    int func_123350(float val);
    void func_001CF350(void *arg0, void *arg1, int a2);
    int func_00268200(void *self, int state);
}

typedef void (*Vtable68Method)(void *self, void *arg1);
typedef void (*OwnerCostMethod)(void *owner, int res_id);

static void check_early_attachment(void *self, int state) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif
    if (*(short *)((char *)proto + 0x8) != 0x80) {
        return;
    }
    if (*(float *)((char *)self + 0x40) <= 0.0f) {
        return;
    }
    if ((state & 0xFF) >= 3) {
        return;
    }
    if (*(unsigned char *)((char *)self + 0x39) < 3) {
#if defined(__LP64__) || defined(_LP64)
        void *owner = *(void **)((char *)self + 0x10);
#else
        void *owner = *(void **)((char *)self + 0x8);
#endif
        void *field_70 = *(void **)((char *)owner + 0x70);
        void **vtbl = *(void ***)self;
        Vtable68Method fn = (Vtable68Method)vtbl[26];
        fn(self, *(void **)((char *)field_70 + 0x330));
    }
}

static void refund_resource_costs(void *self) {
#if defined(__LP64__) || defined(_LP64)
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *owner = *(void **)((char *)self + 0x8);
#endif
    void *stats = *(void **)((char *)owner + 0xBAC);

    if (*(float *)((char *)stats + 0x24C) < 0.0f) {
        void **vtbl = *(void ***)((char *)owner + 0x1B30);
        OwnerCostMethod fn = (OwnerCostMethod)vtbl[30];
        fn(owner, 0x62);
    }

    if (*(float *)((char *)stats + 0x290) < 0.0f) {
        void **vtbl = *(void ***)((char *)owner + 0x1B30);
        OwnerCostMethod fn = (OwnerCostMethod)vtbl[30];
        fn(owner, 0xA4);
    }
}

int func_00273970(void *self, int state) {
    check_early_attachment(self, state);
    refund_resource_costs(self);
    return func_00268200(self, state);
}

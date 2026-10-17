#pragma exceptions off
#include "unit_action_build_4fd0.h"

extern "C" {
    int func_123350(float val);
    int func_801AAB30();
    void func_803675D0(void *self);
    void func_802753E0(void *self, void *target, int zero,
                       float x, float y, float z,
                       float scatter_x, float scatter_y);
    int func_80195660(void *self, void *target, void *arg2);
}

typedef int (*VtableQueryMethod)(void *self);

static void trigger_construction_audio_and_dust(void *self, void *target, void *proto) {
    func_803675D0(self);

    float width = *(float *)((char *)proto + 0x14C);
    float rand_w = (float)func_801AAB30();
    float scatter_x = (width * rand_w) / 32767.0f - width / 2.0f;

    float height = *(float *)((char *)proto + 0x150);
    float rand_h = (float)func_801AAB30();
    float scatter_y = (height * rand_h) / 32767.0f - height / 2.0f;

    float x = *(float *)((char *)self + 0x44);
    float y = *(float *)((char *)self + 0x48);
    float z = *(float *)((char *)self + 0x4C);

    func_802753E0(self, target, 0, x, y, z, scatter_x, scatter_y);
}

int func_274FD0(void *self, void *target, void *arg2) {
    void **vtbl = *(void ***)self;
    VtableQueryMethod query = (VtableQueryMethod)vtbl[218];
    if (query(self) == 0) {
        return func_80195660(self, target, arg2);
    }

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif

    trigger_construction_audio_and_dust(self, target, proto);
    return func_80195660(self, target, arg2);
}

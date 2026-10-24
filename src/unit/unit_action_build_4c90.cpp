#pragma exceptions off
#include "unit_action_build_4c90.h"

typedef int (*Vtable368Method)(void *self);

float func_274C90(void *self, void *target) {
    float modifier = 1.0f;

    void **vtbl = *(void ***)self;
    Vtable368Method method_368 = (Vtable368Method)vtbl[218];

    if (method_368(self) != 0) {
        modifier *= 1.25f;
    } else {
        float self_z = *(float *)((char *)self + 0x4C);
        float target_z = *(float *)((char *)target + 0x4C);
        if (self_z < target_z) {
            modifier *= 0.75f;
        }
    }

    return modifier;
}

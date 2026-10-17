#pragma exceptions off
#include "unit_action_build_53e0.h"

extern "C" {
    int func_123350(float val);
    void func_8033D560(void *obj, int tile_x);
    void func_8033D530(void *obj, int tile_y);
    float func_801234E0(float val);
    float func_80122058(float v1, float v2);
    float func_801228E8(float val);
    void func_801D8710(void *node, void *spatial);
}

typedef void (*VtableUpdateMethod)(void *obj);

void func_802753E0(void *self, void *target, int zero,
                   float x, float y, float z,
                   float scatter_x, float scatter_y) {
    float pos_x = x + scatter_x;
    float pos_y = y + scatter_y;

    int tile_x = func_123350(pos_x);
    func_8033D560(target, tile_x);

    int tile_y = func_123350(pos_y);
    func_8033D530(target, tile_y);

    if (target != nullptr) {
        void **vtbl = *(void ***)target;
        VtableUpdateMethod update_fn = (VtableUpdateMethod)vtbl[4];
        update_fn(target);
    }
}

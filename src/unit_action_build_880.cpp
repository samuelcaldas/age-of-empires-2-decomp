#pragma exceptions off
#include "unit_action_build_880.h"

typedef int (*CornerQueryMethod)(void *target, void *owner, int zero_arg,
                                 int one_arg1, int one_arg2, int zero_arg2,
                                 int zero_arg3, void *self);

static void update_corner_coords(int step, float &x, float &y, float dx, float dy) {
    if (step == 1) {
        y -= dy;
        return;
    }
    if (step == 2) {
        x += dx;
        return;
    }
    if (step == 3) {
        y += dy;
        return;
    }
}

int func_00272880(void *self, void *target, float *out_x, float *out_y,
                  float in_x, float in_y, float dx, float dy) {
    void **vtbl = *(void ***)((char *)target + 0xA0);
    CornerQueryMethod query = (CornerQueryMethod)vtbl[15];
    void *owner = *(void **)((char *)self + 0x8);

    float cur_x = in_x;
    float cur_y = in_y;

    for (int step = 0; step < 4; ++step) {
        update_corner_coords(step, cur_x, cur_y, dx, dy);

        int result = query(target, owner, 0, 1, 1, 0, 0, self);
        if ((result & 0xFF) != 0) {
            *out_x = cur_x;
            *out_y = cur_y;
            return 1;
        }
    }
    return 0;
}

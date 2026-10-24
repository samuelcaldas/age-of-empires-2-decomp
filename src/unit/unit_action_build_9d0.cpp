#pragma exceptions off
#include "unit_action_build_9d0.h"

typedef int (*TargetQueryMethod)(void *target, void *owner, int zero_arg,
                                int one_arg1, int one_arg2, int zero_arg2,
                                int zero_arg3, void *self);

int func_002729D0(void *self, void *target, float *out_x, float *out_y,
                  float in_x, float in_y) {
    void **vtbl = *(void ***)((char *)target + 0xA0);
    TargetQueryMethod query = (TargetQueryMethod)vtbl[15];

    void *owner = *(void **)((char *)self + 0x8);
    int result = query(target, owner, 0, 1, 1, 0, 0, self);

    if ((result & 0xFF) == 0) {
        return 0;
    }

    *out_x = in_x;
    *out_y = in_y;
    return 1;
}

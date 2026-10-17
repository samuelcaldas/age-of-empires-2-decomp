#pragma exceptions off
#include "unit_action_build_784d0.h"

int func_002784D0(void *self, int action_type) {
    (void)self;
    if (action_type == 0) return 4;
    if (action_type == 3) return 3;
    if (action_type == 0x38) return 2;
    if (action_type == 1 || action_type == 2) return 0;
    return -1;
}

int func_00278530(void *self, int stance_mode) {
    (void)self;
    if (stance_mode == 4) return 0;
    if (stance_mode == 3) return 3;
    if (stance_mode == 2) return 0x38;
    if (stance_mode == 1) return 1;
    if (stance_mode == 0) return 0;
    return -1;
}

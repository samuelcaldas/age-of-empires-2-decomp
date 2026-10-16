#ifndef UNIT_ACTION_COORDS_H
#define UNIT_ACTION_COORDS_H

#include "unit_action_distance.h"

extern "C" {
    int func_00263020(int target, int frame, int dir, int *out_x, int *out_y);
    int func_002621E0(int target, int frame, int dir);
    int func_00268410(ActionRebind *self);

    int func_00269290(ActionRebind *self, int *out_dir, int *out_frame, int *out_x, int *out_y, int *out_extra);
    int func_00269450(ActionRebind *self, void *renderer, int arg2, int arg3, int arg4, int arg5, int arg6);
    void func_002697B0(ActionRebind *self, float x, float y, float z);
}

#endif // UNIT_ACTION_COORDS_H

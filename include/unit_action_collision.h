#ifndef UNIT_ACTION_COLLISION_H
#define UNIT_ACTION_COLLISION_H

#include "unit_action_state.h"

extern "C" {
    void func_002697B0(ActionRebind *self, float x, float y, float z);
    int func_002699A0(ActionRebind *self, int arg1, float *out_x, float *out_y, void *child_field4, ActionRebind *child, float coord_x, float coord_y, float ext_x, float ext_y);

    int func_002697C0(ActionRebind *self, int arg1);
}

#endif // UNIT_ACTION_COLLISION_H

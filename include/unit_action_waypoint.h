#ifndef UNIT_ACTION_WAYPOINT_H
#define UNIT_ACTION_WAYPOINT_H

#include "unit_action_state_mgr.h"

extern "C" {
    int func_186010(void *world, int tx, int ty);
    int func_001378C0(void *zone, int tx, int ty);
    float func_001141E8(float val);
    float func_003151E0(float val);
    float func_00113FB8(float y, float x);
    void func_0026A680(void *action, unsigned char frame);

    int func_0026A700(ActionRebind *self, int *out_x, int *out_y);
    void* func_0026A9E0(void *out, ActionRebind *other);
    int func_0026AA00(ActionRebind *self, float *target_pos, float speed);
    float func_0026AC30(ActionRebind *self);
}

#endif // UNIT_ACTION_WAYPOINT_H

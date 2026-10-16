#ifndef UNIT_ACTION_TILE_NODE_H
#define UNIT_ACTION_TILE_NODE_H

#include "unit_action_coords.h"

extern "C" {
    void func_003357B0(void *arg0, short val);
    void func_00335920(void *arg0, short val);
    void func_00334FC0(void *arg0, short val);

    void func_00269D80(void *node, int a1, int a2);
    unsigned char func_00269E50(ActionRebind *self, int tile_x, int tile_y);
    int func_00269F30(ActionRebind *self, int curr_type, int target_type);
}

#endif // UNIT_ACTION_TILE_NODE_H

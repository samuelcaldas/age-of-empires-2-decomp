#ifndef UNIT_ACTION_RESOLVE_H
#define UNIT_ACTION_RESOLVE_H

#include "unit_action_collision.h"

extern "C" {
    int func_001AAB30();
    int func_123350(float val);
    unsigned char func_00269E50(ActionRebind *self, int tile_x, int tile_y);
    int func_00269F30(ActionRebind *self, int curr_type, int target_type);
}

#endif // UNIT_ACTION_RESOLVE_H

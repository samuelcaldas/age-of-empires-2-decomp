#pragma exceptions off
#pragma conditional_move off

#include "zone_spatial_view_check_bitmask.h"

extern "C" {
extern const unsigned int D_00492570[];
}

extern "C" int func_001DAA60(const unsigned int *self, int idx) {
    if (idx >= 0 && idx < 32 && (*self & D_00492570[idx])) {
        return 1;
    }
    return 0;
}

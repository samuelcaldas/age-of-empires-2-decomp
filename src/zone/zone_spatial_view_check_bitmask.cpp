#pragma exceptions off

#include "zone_spatial_view_check_bitmask.h"

extern "C" {
extern const unsigned int D_492570[];
}

extern "C" int func_001DAA60(const unsigned int *self, int idx) {
    if (idx < 0) {
        return 0;
    }
    if (idx >= 32) {
        goto L_zero;
    }
    if (*self & D_492570[idx]) {
        return 1;
    }
L_zero:
    return 0;
}

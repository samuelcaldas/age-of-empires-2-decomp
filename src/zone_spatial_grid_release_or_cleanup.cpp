#pragma exceptions off
#include "zone_spatial_grid_release_or_cleanup.h"

extern "C" void *func_001ED1B0(void *self, short flag) {
    if (self != 0) {
        if (flag > 0) {
            func_100670(self);
        }
    }
    return self;
}

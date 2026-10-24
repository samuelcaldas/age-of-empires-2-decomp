#pragma exceptions off
#include "zone_spatial_grid_lookup.h"

extern "C" void *func_001F2700(ZoneSpatialGrid *self, void *item) {
    void **node = (void **)func_001F2E00(self, item);
    if (node != 0) {
        return node[0];
    }
    return 0;
}

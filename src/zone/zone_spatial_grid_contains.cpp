#pragma exceptions off
#include "zone_spatial_grid_contains.h"

extern "C" int func_001F2D50(ZoneSpatialGrid *self, SpatialItem *item) {
    if (item == 0 || func_001F2E00(self, func_001F6CD0(item)) == 0) {
        return 0;
    }
    return 1;
}

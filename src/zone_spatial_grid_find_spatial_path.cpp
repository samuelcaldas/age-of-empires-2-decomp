#pragma exceptions off
#include "zone_spatial_grid_find_spatial_path.h"

struct Point2D {
    float x;
    float y;
};

struct SpatialGrid {
    char pad[0x10];
};

extern "C" int func_001EA7F0(SpatialGrid *self, void *start, void *end, int flag, void *out_path, int *out_len, int *out_status) {
    if (self == 0 || start == 0 || end == 0) {
        return 0;
    }
    return 0;
}

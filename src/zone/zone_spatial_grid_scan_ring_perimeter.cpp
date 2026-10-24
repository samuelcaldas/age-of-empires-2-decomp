#pragma exceptions off
#include "zone_spatial_grid_scan_ring_perimeter.h"

extern "C" {
void func_1E7BC0(void *self, int x, int y, float radius);
}

struct SpatialGrid {
    char pad_A4[0xA4];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

extern "C" void func_001E7460(SpatialGrid *self, float margin) {
    int x1 = self->min_x - 2;
    int x2 = self->max_x + 2;
    int y1 = self->min_y - 2;
    int y2 = self->max_y + 2;
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
}

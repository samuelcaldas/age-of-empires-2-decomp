#pragma exceptions off
#include "zone_spatial_grid_partition_area_query.h"

struct SpatialGrid {
    char pad_A4[0xA4];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

extern "C" void func_001E7630(SpatialGrid *self, void *p1, void *p2, void *p3, void *p4, void *p5, float radius) {
    int x1 = self->min_x - 2;
    int y1 = self->min_y - 2;
    int x2 = self->max_x + 2;
    int y2 = self->max_y + 2;
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    int area = (x2 - x1) * (y2 - y1);
    if (area < 101) {
    }
}

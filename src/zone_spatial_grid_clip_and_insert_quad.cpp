#pragma exceptions off
#include "zone_spatial_grid_clip_and_insert_quad.h"

extern "C" {
int func_1E4200(void *p1, void *p2, void *p3, void *p4);
void func_1E4820(void *p1, void *p2, int p3);
}

struct Point2D {
    float x;
    float y;
};

struct SpatialGrid {
    char pad_0C[0xC];
    void **cells;
};

extern "C" void func_001E7ED0(SpatialGrid *self, void *box_min, void *box_max) {
    Point2D *min_pt = (Point2D *)box_min;
    Point2D *max_pt = (Point2D *)box_max;
    if (self == 0 || min_pt == 0 || max_pt == 0) {
        return;
    }
}

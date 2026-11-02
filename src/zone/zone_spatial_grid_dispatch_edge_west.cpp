#pragma exceptions off
#pragma bool off
#include "zone_spatial_grid_dispatch_edge_west.h"

extern "C" unsigned char func_001E5850(SpatialGrid *self, float *pt, int a2, float *out_pt, int *out_t0, int *out_t1) {
    out_pt[1] = pt[1];
    float limit = 3.402823466e+38F;
    unsigned char matched = 0;
    SpatialGridItem *item = self->f28;

    for (int i = 0; i < self->f20; i++, item++) {
        if (pt[1] < item->minY) continue;
        if (!(pt[1] <= item->maxY)) continue;
        int code = (i == a2) ? (pt[0] < item->minX) : (pt[0] <= item->minX);
        float candidate;
        if (code != 0) {
            code = 3;
            candidate = item->minX;
            goto calc;
        }
        if (!(pt[0] < item->maxX)) continue;
        code = 1;
        candidate = item->maxX;
    calc:
        float diff = candidate - pt[0];
        if (diff < limit) {
            *out_t0 = i;
            *out_t1 = code;
            out_pt[0] = candidate;
            limit = diff;
            matched = 1;
        }
    }
    return matched;
}

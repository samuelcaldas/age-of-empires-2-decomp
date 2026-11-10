#pragma exceptions off
#pragma bool off
#include "zone_spatial_grid_dispatch_edge_east.h"

extern "C" unsigned char func_001E5630(SpatialGrid *self, float *pt, int a2, float *out_pt, int *out_t0, int *out_t1) {
    out_pt[0] = pt[0];
    float limit = 3.402823466e+38F;
    unsigned char matched = 0;
    SpatialGridItem *item = self->f28;

    for (int i = 0; i < self->f20; i++, item++) {
        if (pt[0] < item->minX) continue;
        if (!(pt[0] <= item->maxX)) continue;
        int code = (i == a2) ? (pt[1] < item->minY) : (pt[1] <= item->minY);
        float candidate;
        if (code != 0) {
            code = 2;
            candidate = item->minY;
            goto calc;
        }
        if (!(pt[1] < item->maxY)) continue;
        code = 0;
        candidate = item->maxY;
    calc:
        float diff = candidate - pt[1];
        if (diff < limit) {
            *out_t0 = i;
            *out_t1 = code;
            out_pt[1] = candidate;
            limit = diff;
            matched = 1;
        }
    }
    return matched;
}

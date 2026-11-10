#pragma exceptions off
#pragma bool off
#include "zone_spatial_grid_evaluate_edge_cross.h"

extern "C" unsigned char func_001E5960(SpatialGrid *self, void *p1, int edge, void *p3, void *p4) {
    unsigned char ret = 0;
    switch (edge) {
    case 0:
        ret = func_1E59F0(self, p1, p3, p4);
        break;
    case 1:
        ret = func_1E5BC0(self, p1, p3, p4);
        break;
    case 2:
        ret = func_1E5D90(self, p1, p3, p4);
        break;
    case 3:
        ret = func_1E5F60(self, p1, p3, p4);
        break;
    default:
        break;
    }
    return ret;
}

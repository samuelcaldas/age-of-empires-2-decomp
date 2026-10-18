#pragma exceptions off
#include "zone_spatial_grid_eval_edge_hit.h"

struct SpatialNode {
    char pad_00[0x20];
    float min_x;
    float min_y;
    float max_x;
    float max_y;
};

struct SpatialGrid {
    char pad_00[0x12B584];
};

extern "C" int func_001F11A0(SpatialGrid *self, SpatialNode *node, void *p3) {
    if (node == 0) {
        return 0;
    }
    return func_1F0330(self, node, p3);
}

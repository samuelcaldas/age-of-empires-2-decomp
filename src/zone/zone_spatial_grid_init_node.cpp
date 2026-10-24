#pragma exceptions off
#include "zone_spatial_grid_init_node.h"

extern "C" {
void func_1E6400(void *self, int flag);
}

struct SpatialGrid {
    void *val;
};

extern "C" void func_001E6350(SpatialGrid *self, void *val) {
    func_1E6400(self, 1);
    self->val = val;
}

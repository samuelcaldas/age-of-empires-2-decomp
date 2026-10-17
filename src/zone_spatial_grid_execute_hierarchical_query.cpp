#pragma exceptions off
#include "zone_spatial_grid_execute_hierarchical_query.h"

extern "C" {
void func_1E7020(void *self, float margin);
}

struct SpatialGrid {
    char pad_A4[0xA4];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

extern "C" int func_001E9160(SpatialGrid *self, int a1, int a2, int a3, char t0, void *t1, void *t2, void *t3, float f12, float f13, float f14, float f15, float f16, float f17, void *stack_arg) {
    if (t0 == 0) {
        self->min_x = -1;
        self->min_y = -1;
        self->max_x = -1;
        self->max_y = -1;
    }
    if (a3 != 0) {
        func_1E7020(self, f14);
    }
    return 0;
}

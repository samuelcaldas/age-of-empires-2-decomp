#pragma exceptions off
#include "zone_spatial_grid_query_bounded_area.h"

extern "C" {
void *func_332E60(void *world, void *item);
float func_1234E0(float f, double d);
float func_1140C8(float f);
float func_1228E8(float f);
int func_113FB8(float f);
float func_123350(float f);
}

struct SpatialGrid {
    char pad_4[0x4];
    int count;
    char pad_A4[0x9C];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

extern "C" void func_001E7110(SpatialGrid *self, int p1, void *p2, void *p3, void *p4, float radius) {
    self->count = 0;
    if (self->min_x < 0) {
        self->min_x = 0;
    }
    if (self->min_y < 0) {
        self->min_y = 0;
    }
}

#pragma exceptions off
#include "zone_spatial_grid_trace_grid_ray.h"

extern "C" {
void func_1EE350(void *p1, int p2);
void func_1EF900(void *p1, int p2, void *p3, void *p4, void *p5, int p6, int p7);
}

struct SpatialGrid {
    void *world;
    char pad_98[0x94];
    int status_98;
    int cap_9C;
    void *buf_A0;
};

extern "C" int func_001E8CE0(SpatialGrid *self, void *start, void *end, int p3, void *p4, void *p5, int p6, int p7, float margin, int p9) {
    if (self == 0 || start == 0 || end == 0) {
        return 0;
    }
    return 0;
}

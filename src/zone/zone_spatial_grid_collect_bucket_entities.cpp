#pragma exceptions off
#include "zone_spatial_grid_collect_bucket_entities.h"

extern "C" {
void func_1E7EC0(void *p1, void *p2, void *p3);
void func_1E46E0(void *p1, void *p2, int p3);
float func_3675D0(void *entity);
}

struct Bucket {
    char pad_0D[0xD];
    unsigned char count;
    char pad_14[0x6];
    void **entities;
};

struct SpatialGrid {
    char pad_0C[0xC];
    void **cells;
    char pad_8C[0x7C];
    int count_8C;
    char pad_94[0x4];
    int *array_94;
};

extern "C" void func_001E7C70(SpatialGrid *self, void *b_ptr, void *p2, int p3, float margin, void *p5, int p6) {
    Bucket *b = (Bucket *)b_ptr;
    if (b->count == 0) {
        return;
    }
}

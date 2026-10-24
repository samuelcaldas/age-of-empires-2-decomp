#pragma exceptions off
#include "zone_spatial_grid_allocate_node.h"

extern "C" {
void func_1E6F50(void *self, int count);
void *func_117CAC(void *dst, int val, unsigned int size);
void func_1E3F90(void *node);
}

struct SpatialGrid {
    char pad_04[0x4];
    int count;
    char pad_0C[0x4];
    void **nodes;
};

extern "C" void *func_001E8210(SpatialGrid *self, int *out_index) {
    int idx = self->count;
    func_1E6F50(self, idx + 1);
    *out_index = self->count;
    return self->nodes[*out_index];
}

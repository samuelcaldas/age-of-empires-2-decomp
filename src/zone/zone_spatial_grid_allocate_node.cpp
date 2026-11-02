#pragma exceptions off
#include "zone_spatial_grid_allocate_node.h"

extern "C" {
void func_001E6F50(void *self, int count);
void *func_117CAC(void *dst, int val, unsigned int size);
void func_001E3F90(void *node);
extern char D_009397F0[44];
}

struct SpatialGrid {
    char pad_04[0x4];
    int count;
    char pad_0C[0x4];
    void **nodes;
};

extern "C" void *func_001E8210(SpatialGrid *self, int *out_index) {
    func_001E6F50(self, self->count + 1);
    *out_index = self->count;
    if (!self->nodes[*out_index]) {
        self->nodes[*out_index] = func_117CAC((void *)&D_009397F0[*out_index * 44], 0, 44);
        func_001E3F90(self->nodes[*out_index]);
    }
    self->count++;
    return self->nodes[*out_index];
}

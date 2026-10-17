#pragma exceptions off
#include "zone_spatial_grid_expand_buffer3.h"

extern "C" {
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct SpatialGrid {
    char pad_9C[0x9C];
    int cap9C;
    void **bufA0;
    char pad_5CC[0x528];
    char embedded_buffer3[0x400];
};

extern "C" void func_001E6FD0(SpatialGrid *self, int needed) {
    if (self->cap9C < needed) {
        void *buf;
        if (needed == 0x100) {
            buf = func_117CAC(&self->embedded_buffer3[0], 0, 0x400);
        }
        self->bufA0 = (void **)buf;
        self->cap9C = needed;
    }
}

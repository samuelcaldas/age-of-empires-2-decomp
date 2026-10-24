#pragma exceptions off
#include "zone_spatial_grid_expand_buffer2.h"

extern "C" {
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct SpatialGrid {
    char pad_8[0x8];
    int cap8;
    void **bufC;
    char pad_1CC[0x1BC];
    char embedded_buffer2[0x400];
};

extern "C" void func_001E6F60(SpatialGrid *self, int needed) {
    if (needed < self->cap8) {
        return;
    }
    int extra = self->cap8 + 0x100;
    if (extra >= needed) {
        needed = extra;
    }
    int final_needed = needed;
    void *buf;
    if (final_needed == 0x100) {
        buf = func_117CAC(&self->embedded_buffer2[0], 0, 0x400);
        self->bufC = (void **)buf;
    }
    self->cap8 = final_needed;
}

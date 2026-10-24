#pragma exceptions off
#include "zone_spatial_grid_push_buffer1.h"

extern "C" {
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct SpatialGrid {
    char pad_8C[0x8C];
    int count;
    int capacity;
    void **buffer;
    char pad_CC[0x34];
    char embedded_buffer[0x100];
};

extern "C" void func_001E6ED0(SpatialGrid *self, void *val) {
    if (self->count == self->capacity) {
        self->capacity += 0x40;
        if (self->capacity == 0x40) {
            self->buffer = (void **)func_117CAC(&self->embedded_buffer[0], 0, 0x100);
        }
    }
    self->buffer[self->count] = val;
    self->count++;
}

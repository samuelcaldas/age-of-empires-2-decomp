#pragma exceptions off
#include "zone_spatial_grid_vector_find_by_id.h"

struct Element {
    char pad_24[0x24];
    short id;
};

struct FastVector {
    Element **buffer;
    short count;
};

extern "C" void *func_001EC560(void *self_ptr, int id) {
    FastVector *self = (FastVector *)self_ptr;
    for (int i = 0; i < self->count; i++) {
        if (self->buffer[i]->id == id) {
            return self->buffer[i];
        }
    }
    return 0;
}

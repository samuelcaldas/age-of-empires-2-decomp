#pragma exceptions off
#include "zone_spatial_grid_vector_swap_remove.h"

struct Element {
    char pad_26[0x26];
    short index;
};

struct FastVector {
    void **buffer;
    short count;
    short cap;
    char flag;
};

extern "C" void func_001EBB20(void *self_ptr, void *elem, int index) {
    FastVector *self = (FastVector *)self_ptr;
    if (self->flag != 0) {
        return;
    }
    if (index >= 0 && index < self->count) {
        self->count--;
        void *last = self->buffer[self->count];
        self->buffer[index] = last;
        Element *el = (Element *)self->buffer[index];
        el->index = (short)index;
        self->buffer[self->count] = 0;
        return;
    }
}

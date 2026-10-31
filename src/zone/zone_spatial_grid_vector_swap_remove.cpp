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
    unsigned char flag;
};

extern "C" void func_001EBB20(void *self_ptr, void *elem, short index) {
    FastVector *self = (FastVector *)self_ptr;
    if (self->flag != 0) {
        return;
    }
    if (index >= 0 && index < self->count) {
        self->count--;
        void *last = self->buffer[self->count];
        self->buffer[index] = last;
        Element *el = (Element *)self->buffer[index];
        el->index = index;
        self->buffer[self->count] = 0;
        return;
    }
    for (int i = 0; i < self->count; ++i) {
        if (self->buffer[i] == elem) {
            self->count--;
            if (i < self->count) {
                void *last = self->buffer[self->count];
                self->buffer[i] = last;
                Element *el = (Element *)self->buffer[i];
                el->index = (short)i;
            }
            self->buffer[self->count] = 0;
            return;
        }
    }
}

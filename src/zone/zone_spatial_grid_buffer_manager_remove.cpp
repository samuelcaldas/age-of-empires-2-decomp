#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_remove.h"

struct ElementTeam;
struct Element;

struct SpatialGridBufferManager {
    ElementTeam *owner;       // 0x000
    Element *elems[200];      // 0x004
    void *ptrs[200];          // 0x324
    int vals[200];            // 0x644
    short shorts[200];        // 0x964
    short cap;                // 0xAF4
    short count;              // 0xAF6
};

extern "C" int func_001ECD10(void *self_ptr, void *elem) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    if (self->count <= 0) {
        return 0;
    }
    for (int i = 0; i < self->count; i++) {
        if (self->elems[i] == (Element *)elem) {
            self->count--;
            if (i < self->count) {
                self->elems[i] = self->elems[self->count];
                self->ptrs[i] = self->ptrs[self->count];
                self->vals[i] = self->vals[self->count];
                self->shorts[i] = self->shorts[self->count];
            }
            self->elems[self->count] = 0;
            self->ptrs[self->count] = 0;
            self->vals[self->count] = 0;
            self->shorts[self->count] = 0;
            return 1;
        }
    }
    return 0;
}


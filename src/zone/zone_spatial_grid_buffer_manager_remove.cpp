#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_remove.h"

struct SpatialGridBufferManager {
    void *buffer;
    void *items[200];
    int table_324[200];
    int table_644[200];
    short cap;
    short count;
};

extern "C" int func_001ECD10(void *self_ptr, void *elem) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    if (self->count <= 0) {
        return 0;
    }
    for (int i = 0; i < self->count; i++) {
        if (self->items[i] == elem) {
            self->count--;
            if (i < self->count) {
                self->items[i] = self->items[self->count];
                self->table_324[i] = self->table_324[self->count];
                self->table_644[i] = self->table_644[self->count];
            }
            return 1;
        }
    }
    return 0;
}

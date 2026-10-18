#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_sync_tables.h"

extern "C" {
int func_332E60(void *p0, short p1);
int func_1EBA00(void *p0);
int func_202B10(void *p0);
void func_1ECD00(void *p0, void *p1);
}

struct SpatialGridBufferManager {
    void *owner;
    void *items[200];
    int *table_324[200];
    int table_644[200];
    char pad_AF0[0xAF0 - 200 * 4 - 200 * 4 - 200 * 4 - 4];
    short cap;
    short count;
};

extern "C" void func_001ECE20(void *self_ptr) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    if (self->count <= 0) {
        return;
    }
    void *to_remove = 0;
    for (int i = 0; i < self->count; i++) {
        int val_324 = *self->table_324[i];
        int val_644 = self->table_644[i];
        if (val_324 != val_644) {
            self->table_644[i] = val_324;
            to_remove = self->items[i];
        }
    }
    if (to_remove != 0) {
        func_1ECD00(self, to_remove);
    }
}

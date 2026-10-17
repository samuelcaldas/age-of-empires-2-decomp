#pragma exceptions off
#include "zone_spatial_grid_realloc_vector.h"

extern "C" {
void func_1E67A0(void *self, int flag);
void *func_100730(unsigned int size);
void func_100630(void *ptr);
}

struct SpatialGrid {
    char pad_7C[0x7C];
    void **items;
    int count;
    int capacity;
};

extern "C" void func_001E6680(SpatialGrid *self) {
    func_1E67A0(self, 0);
    func_1E67A0(self, 1);
    for (int i = 0; i < self->count; i++) {
        self->items[i] = 0;
    }
    if (self->capacity < 0) {
        int cap = self->capacity;
        if (cap <= 0) {
            cap = 1;
        } else {
            cap <<= 1;
        }
        self->capacity = cap;
        void **new_items = (void **)func_100730(cap * sizeof(void *));
        if (new_items != 0) {
            int old_count = self->count;
            if (old_count < 0) {
                old_count = 0;
            }
            if (self->items != 0) {
                for (int j = 0; j < old_count; j++) {
                    new_items[j] = self->items[j];
                }
            }
            func_100630(self->items);
            self->items = new_items;
            self->count = 0;
        }
    }
}

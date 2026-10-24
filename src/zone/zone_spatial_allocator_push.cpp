#pragma exceptions off

#include "zone_spatial_allocator_push.h"

struct SpatialItemVector {
    char pad[0xC];
    int count;
    char pad2[4];
    void **items;
};

extern "C" void func_001D8340(SpatialItemVector *self, void *item) {
    self->items[self->count] = item;
    self->count++;
}

#pragma exceptions off

#include "zone_spatial_find_item.h"

extern "C" {
bool func_1D20D0(void *self, void *item, int flag);
}

struct SpatialNodeArray {
    void **items;
    int count;
};

extern "C" void *func_001D7BF0(SpatialNodeArray *self, void *item, int flag) {
    if (item && flag > 0) {
        for (int i = 0; i < self->count; i++) {
            if (func_1D20D0(self->items[i], item, flag) == true) {
                return self->items[i];
            }
        }
    }
    return 0;
}

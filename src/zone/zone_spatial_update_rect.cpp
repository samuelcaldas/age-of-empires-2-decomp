#pragma exceptions off

#include "zone_spatial_update_rect.h"

extern "C" {
void func_1D2320(void *self, int x0, int y0, int x1, int y1);
}

struct SpatialNodeArray {
    void **items;
    int count;
};

extern "C" void func_001D7DD0(SpatialNodeArray *self, int x0, int y0, int x1, int y1) {
    for (int i = 0; i < self->count; i++) {
        func_1D2320(self->items[i], x0, y0, x1, y1);
    }
}

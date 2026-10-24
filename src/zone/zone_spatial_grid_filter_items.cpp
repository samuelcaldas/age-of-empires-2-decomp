#pragma exceptions off
#include "zone_spatial_grid_filter_items.h"

extern "C" void func_001ED0E0(SpatialItemList *self) {
    for (int i = 0; i < self->count; ++i) {
        SpatialItem *item = self->items[i];
        if (item->type == 0x3C) {
            func_367470(item);
            --i;
        }
    }
}

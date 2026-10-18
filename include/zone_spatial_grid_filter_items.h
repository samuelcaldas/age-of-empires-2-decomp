#ifndef ZONE_SPATIAL_GRID_FILTER_ITEMS_H
#define ZONE_SPATIAL_GRID_FILTER_ITEMS_H

struct SpatialItem {
    char pad_00[0x38];
    unsigned char type;
};

struct SpatialItemList {
    SpatialItem **items;
    short count;
};

extern "C" {
void func_001ED0E0(SpatialItemList *self);
void func_367470(SpatialItem *item);
}

#endif

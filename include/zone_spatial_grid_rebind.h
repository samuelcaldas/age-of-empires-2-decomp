#ifndef ZONE_SPATIAL_GRID_REBIND_H
#define ZONE_SPATIAL_GRID_REBIND_H

struct ZoneSpatialGrid;
struct SpatialItem;
struct GlobalManager;

extern "C" {
extern GlobalManager *D_004D89C0;
extern void *D_004D8940;
extern int D_004D8E18;

void func_001F6CA0(SpatialItem *newItem, SpatialItem *oldItem);
void func_001F2BD0(ZoneSpatialGrid *self);

void func_001F2EB0(ZoneSpatialGrid *self, SpatialItem *item1, int item2);
}

#endif // ZONE_SPATIAL_GRID_REBIND_H

#ifndef ZONE_SPATIAL_GRID_RELINK_H
#define ZONE_SPATIAL_GRID_RELINK_H

struct ZoneSpatialGrid;
struct SpatialItem;
struct GlobalManager;

extern "C" {
extern GlobalManager *D_004D89C0;
extern void *D_004D8940;

SpatialItem *func_001F6C90(SpatialItem *elem);
void func_001F6CA0(SpatialItem *newItem, SpatialItem *oldItem);
void *func_001F6CD0(SpatialItem *item);
void func_001F2CB0(ZoneSpatialGrid *self, void *handle);

int func_001F2980(ZoneSpatialGrid *self, int flag);
}

#endif // ZONE_SPATIAL_GRID_RELINK_H

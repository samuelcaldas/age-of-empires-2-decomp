#ifndef ZONE_SPATIAL_GRID_BOUNDS_H
#define ZONE_SPATIAL_GRID_BOUNDS_H

struct ZoneSpatialGrid;
struct SpatialItem;
struct SpatialNode;

extern "C" {
void func_001F6CC0(SpatialItem *elem, ...);
void func_001F6750(void *handle, ...);

void func_001F2AD0(ZoneSpatialGrid *self, SpatialItem *elem);
}

#endif // ZONE_SPATIAL_GRID_BOUNDS_H

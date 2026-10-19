#ifndef ZONE_SPATIAL_GRID_ADVANCE_H
#define ZONE_SPATIAL_GRID_ADVANCE_H

struct ZoneSpatialGrid;
struct SpatialItem;

extern "C" {
SpatialItem *func_001F6CB0(SpatialItem *item);
void func_001F2AB0(ZoneSpatialGrid *self, SpatialItem *item);
void func_001F2AC0(ZoneSpatialGrid *self, SpatialItem *item);

int func_001F2C20(ZoneSpatialGrid *self);
}

#endif // ZONE_SPATIAL_GRID_ADVANCE_H

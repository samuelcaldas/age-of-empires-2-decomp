#ifndef ZONE_SPATIAL_GRID_CONTAINS_H
#define ZONE_SPATIAL_GRID_CONTAINS_H

struct ZoneSpatialGrid;
struct SpatialItem;
struct ListNode;

extern "C" {
void *func_001F6CD0(SpatialItem *item);
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *handle);

int func_001F2D50(ZoneSpatialGrid *self, SpatialItem *item);
}

#endif // ZONE_SPATIAL_GRID_CONTAINS_H

#ifndef ZONE_SPATIAL_GRID_LOOKUP_NODE_H
#define ZONE_SPATIAL_GRID_LOOKUP_NODE_H

struct ZoneSpatialGrid;
struct SpatialItem;
struct ListNode;

extern "C" {
void *func_001F6CD0(SpatialItem *item);
int func_0011AA78(const void *s1, const void *s2);

ListNode *func_001F2E00(ZoneSpatialGrid *self, void *handle);
}

#endif // ZONE_SPATIAL_GRID_LOOKUP_NODE_H

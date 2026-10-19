#ifndef ZONE_SPATIAL_GRID_UNBIND_H
#define ZONE_SPATIAL_GRID_UNBIND_H

struct ZoneSpatialGrid;
struct ListNode;
struct SpatialItem;

extern "C" {
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *elem);
void func_00116F68(void *ptr);

int func_001F2CB0(ZoneSpatialGrid *self, void *elem);
}

#endif // ZONE_SPATIAL_GRID_UNBIND_H

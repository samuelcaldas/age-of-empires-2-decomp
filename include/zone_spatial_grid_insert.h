#ifndef ZONE_SPATIAL_GRID_INSERT_H
#define ZONE_SPATIAL_GRID_INSERT_H

struct ListNode;
struct ZoneSpatialGrid;

extern "C" {
void *func_001F6CD0(void *elem);
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *item);
void *func_001143F8(int count, int size);
void func_001F6CA0(void *elem, int zero);
void func_001F2EB0(ZoneSpatialGrid *self, void *elem, int param3);

int func_001F2730(ZoneSpatialGrid *self, void *elem, int update_spatial, int param3);
}

#endif // ZONE_SPATIAL_GRID_INSERT_H

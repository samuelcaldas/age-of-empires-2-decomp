#ifndef ZONE_SPATIAL_GRID_UPDATE_H
#define ZONE_SPATIAL_GRID_UPDATE_H

struct ListNode;
struct ZoneSpatialGrid;

extern "C" {
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *item);
void func_001F65A0(int field_04);
void func_001F2EB0(ZoneSpatialGrid *self, void *elem, int param2);

int func_001F2900(ZoneSpatialGrid *self, void *item, int param2);
}

#endif // ZONE_SPATIAL_GRID_UPDATE_H

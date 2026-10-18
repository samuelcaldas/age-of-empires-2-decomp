#ifndef MAP_ZONE_LOS_H
#define MAP_ZONE_LOS_H

#include "map_zone.h"

struct SightEntry {
    int dy;
    int min_dx;
    int max_dx;
};

struct ZoneFieldC {
    char pad[0x8E8C];
    char **m_grid;
};

extern "C" {
    void func_00137E90(void *self);
    void func_00137EA0(MapZone *self, int x, int y, int radius, int mode, int flag);
}

#endif // MAP_ZONE_LOS_H

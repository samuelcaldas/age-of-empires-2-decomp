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

struct ZoneMapLos {
    unsigned char **m_row_ptrs; // 0x00
    int pad_04;                 // 0x04
    ZoneWorld *m_world;         // 0x08
    ZoneFieldC *m_fieldC;       // 0x0C
    void *m_tile_data;          // 0x10
    int m_width;                // 0x14
    int m_height;               // 0x18
    int m_field1C;              // 0x1C
    int pad_20;                 // 0x20
    int pad_24;                 // 0x24
    int m_field28;              // 0x28
    int m_field2C;              // 0x2C
};

extern "C" {
    void func_00137E90(void *self);
    void func_00137EA0(ZoneMapLos *self, int x, int y, int radius, int mode, int flag);
}

#endif // MAP_ZONE_LOS_H

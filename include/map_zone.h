#ifndef MAP_ZONE_H
#define MAP_ZONE_H

struct ZoneWorld {
    char pad_00[2976];
    short m_fieldBA0;      // 2976 (0xBA0)
    char pad_BA2[14];
    char m_fieldBB0[12];   // 2992 (0xBB0)
    int m_fieldBBC;        // 3004 (0xBBC)
    char pad_BC0[100];
    int m_fieldC24;        // 3108 (0xC24)
    int m_fieldC28;        // 3112 (0xC28)
};

struct MapZone {
    unsigned char **m_row_ptrs; // 0x00
    int pad_04;                 // 0x04
    ZoneWorld *m_world;         // 0x08
    int pad_0C;                 // 0x0C
    void *m_tile_data;          // 0x10
    int m_width;                // 0x14
    int m_height;               // 0x18
    int m_field1C;              // 0x1C
    int pad_20;                 // 0x20
    int pad_24;                 // 0x24
    int pad_28;                 // 0x28
    int m_field2C;              // 0x2C
};

extern "C" {
    void func_00137810(MapZone *self, void *stream);
    int func_001378C0(MapZone *self, int x, int y);
    void func_00137920(MapZone *self);
}

#endif // MAP_ZONE_H

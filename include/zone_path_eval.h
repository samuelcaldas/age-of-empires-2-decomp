#ifndef ZONE_PATH_EVAL_H
#define ZONE_PATH_EVAL_H

#ifdef __cplusplus
extern "C" {
#endif

struct MapTile {
    unsigned char m_pad00[4];      // 0x00..0x03
    unsigned char m_terrain;       // 0x04
    unsigned char m_zone_id;       // 0x05
    unsigned char m_slope_flag;    // 0x06
    unsigned char m_pad07[6];      // 0x07..0x0C
    unsigned char m_unit_count;    // 0x0D
    unsigned char m_pad0E[6];      // 0x0E..0x13
    void **m_unit_array;           // 0x14
    unsigned char m_pad18[4];      // 0x18..0x1B
};

struct MapContext {
    char m_pad00[8];               // 0x00..0x07
    int m_width;                   // 0x08
    int m_height;                  // 0x0C
    char m_pad10[0x8E7C];          // 0x10..0x8E8B
    struct MapTile **m_tile_rows;  // 0x8E8C
};

struct UnitMaster {
    unsigned char m_class;         // 0x00
    char m_pad01[7];
    short m_id;                    // 0x08
    char m_pad0A[4];
    short m_type;                  // 0x0E
    char m_pad10[16];
    float m_radius_x;              // 0x20
    float m_radius_y;              // 0x24
    char m_pad28[24];
    unsigned char m_flag40;        // 0x40
};

struct Unit {
    char m_pad00[4];
    struct UnitMaster *m_master;   // 0x04
    char m_pad08[28];
    short m_id;                    // 0x24
    char m_pad26[19];
    unsigned char m_unit_type;     // 0x39
    char m_pad3A[10];
    float m_x;                     // 0x44
    float m_y;                     // 0x48
};

struct BuildingMaster {
    char m_pad00[8];
    short m_id;                    // 0x08
    char m_pad0A[4];
    short m_construction_type;     // 0x0E
    char m_pad10[16];
    float m_alt_radius_x;          // 0x20
    float m_alt_radius_y;          // 0x24
    float m_field28;               // 0x28
    char m_pad2C[24];
    short m_field44;               // 0x44
    short m_required_zone;         // 0x46
    short m_field48;               // 0x48
    short m_field4A;               // 0x4A
    float m_radius_x;              // 0x4C
    float m_radius_y;              // 0x50
    char m_pad54[2];
    unsigned char m_placement_type;// 0x56
    char m_pad57;                  // 0x57
    short m_type_id;               // 0x58
};

#ifdef __cplusplus
int func_001C7850(
    struct BuildingMaster *bld,
    void *world,
    int *out_id,
    unsigned char flag1,
    unsigned char flag2 = 0,
    int arg5 = 0,
    int use_alt_radius = 0,
    unsigned char flag3 = 0,
    unsigned char arg9 = 0,
    int arg10 = 0,
    struct Unit *ignore_unit = 0,
    float x = 0.0f,
    float y = 0.0f
);
#else
int func_001C7850(
    struct BuildingMaster *bld,
    void *world,
    int *out_id,
    unsigned char flag1,
    unsigned char flag2,
    int arg5,
    int use_alt_radius,
    unsigned char flag3,
    unsigned char arg9,
    int arg10,
    struct Unit *ignore_unit,
    float x,
    float y
);
#endif

#ifdef __cplusplus
}
#endif

#endif // ZONE_PATH_EVAL_H

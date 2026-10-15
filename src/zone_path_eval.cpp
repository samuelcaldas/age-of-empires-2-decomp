#pragma exceptions off
#include "sub_list.h"

extern "C" {

struct MapTile {
    unsigned char m_terrain;       // 0x00
    unsigned char m_elevation;     // 0x01
    unsigned char m_pad02[3];      // 0x02..0x04
    unsigned char m_zone_id;       // 0x05
    unsigned char m_slope_flag;    // 0x06
    unsigned char m_pad07[6];      // 0x07..0x0C
    unsigned char m_unit_count;    // 0x0D
    unsigned char m_pad0E[6];      // 0x0E..0x13
    void **m_unit_array;           // 0x14
    unsigned char m_pad18[4];      // 0x18..0x1B
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
    UnitMaster *m_master;          // 0x04
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

int func_123350(float val);
int func_1378c0(void *map_zone, int x, int y);
float func_3675D0(void *unit);

int func_001C7850(BuildingMaster *bld, void *world, int *out_id, char flag1, char flag2, int arg5, int use_alt_radius, char flag3, char arg9, int arg10, Unit *ignore_unit, float x, float y) {
    void *map = *(void **)((char *)world + 0xB98);
    float **slope_table = *(float ***)((char *)map + 0x68);
    float *slope_limits = slope_table[bld->m_type_id];

    void *s0 = *(void **)((char *)map + 0x3C);
    int map_w = *(int *)((char *)s0 + 0x8);
    int map_h = *(int *)((char *)s0 + 0xC);

    float rx, ry;
    if (use_alt_radius) {
        rx = bld->m_radius_x;
        ry = bld->m_radius_y;
    } else {
        rx = bld->m_alt_radius_x;
        ry = bld->m_alt_radius_y;
    }

    float min_x = x - rx;
    float max_x = x + rx - 0.0001f;
    float min_y = y - ry;
    float max_y = y + ry - 0.0001f;

    if (min_x < 0.0f || max_x >= (float)map_w || min_y < 0.0f || max_y >= (float)map_h) {
        return 7;
    }

    short t_min_x = (short)func_123350(min_x);
    short t_max_x = (short)func_123350(max_x);
    short t_min_y = (short)func_123350(min_y);
    short t_max_y = (short)func_123350(max_y);

    MapTile **tile_rows = *(MapTile ***)((char *)s0 + 0x8E8C);

    if (bld->m_field48 >= 0) {
        int cx = func_123350(x);
        int cy = func_123350(y);
        MapTile *center_tile = &tile_rows[cy][cx];
        if (center_tile->m_zone_id != bld->m_field48 && center_tile->m_zone_id != bld->m_field4A) {
            return 1;
        }
    }

    int fp_flag = 0;

    if (bld->m_required_zone >= 0) {
        int touches_zone = 0;
        int touches_wild = 0;

        for (int cur_x = t_min_x - 1; cur_x <= t_max_x + 1; cur_x++) {
            if (t_min_y - 1 >= 0) {
                MapTile *t = &tile_rows[t_min_y - 1][cur_x];
                if (t->m_zone_id == bld->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == 255) touches_wild = 1;
            }
        }
        for (int cur_y = t_min_y; cur_y <= t_max_y; cur_y++) {
            if (t_max_x + 1 < map_w) {
                MapTile *t = &tile_rows[cur_y][t_max_x + 1];
                if (t->m_zone_id == bld->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == 255) touches_wild = 1;
            }
        }
        for (int cur_x = t_max_x + 1; cur_x >= t_min_x - 1; cur_x--) {
            if (t_max_y + 1 < map_h) {
                MapTile *t = &tile_rows[t_max_y + 1][cur_x];
                if (t->m_zone_id == bld->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == 255) touches_wild = 1;
            }
        }
        for (int cur_y = t_max_y; cur_y >= t_min_y; cur_y--) {
            if (t_min_x - 1 >= 0) {
                MapTile *t = &tile_rows[cur_y][t_min_x - 1];
                if (t->m_zone_id == bld->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == 255) touches_wild = 1;
            }
        }

        if (!touches_zone && !touches_wild) {
            return 1;
        }
    }

    MapTile *base_tile = &tile_rows[t_min_y][t_min_x];
    int base_slope = base_tile->m_slope_flag;
    int min_slope = base_slope - 1;
    int max_slope = base_slope + 1;

    for (int cur_y = t_min_y; cur_y <= t_max_y; cur_y++) {
        for (int cur_x = t_min_x; cur_x <= t_max_x; cur_x++) {
            MapTile *t = &tile_rows[cur_y][cur_x];

            if (slope_limits[t->m_zone_id] <= 0.0f) {
                return 2;
            }

            if (flag1) {
                void *zone_mgr = *(void **)((char *)world + 0xB94);
                if (func_1378c0(zone_mgr, cur_x, cur_y) != 0) {
                    fp_flag = 1;
                }
            }

            if (flag2) {
                int terrain = t->m_terrain;
                int slope = t->m_slope_flag;

                if (bld->m_placement_type == 3) {
                    if (cur_y == t_min_y || cur_x == t_max_x) {
                        if (slope < min_slope || slope > max_slope) return 3;
                    }
                } else if (bld->m_placement_type == 2) {
                    if (terrain != 0) return 2;
                } else if (bld->m_placement_type == 1) {
                    if (terrain != 0 && terrain != 5 && terrain != 7 && terrain != 6 && terrain != 8) {
                        return 2;
                    }
                }
            }
        }
    }

    if (flag1 == 1 && fp_flag == 0) {
        return 5;
    }

    if (rx <= 0.0f && ry <= 0.0f) {
        return 0;
    }

    int check_min_x = func_123350(x - 8.0f);
    int check_min_y = func_123350(y - 8.0f);
    int check_max_x = func_123350(x + 8.0f);
    int check_max_y = func_123350(y + 8.0f);

    if (check_min_x < 0) check_min_x = 0;
    if (check_max_x >= map_w) check_max_x = map_w - 1;
    if (check_min_y < 0) check_min_y = 0;
    if (check_max_y >= map_h) check_max_y = map_h - 1;

    if (bld->m_id == 59) {
        bld->m_field28 = 1.0f;
    }

    for (int cur_y = check_min_y; cur_y <= check_max_y; cur_y++) {
        for (int cur_x = check_min_x; cur_x <= check_max_x; cur_x++) {
            MapTile *t = &tile_rows[cur_y][cur_x];
            for (int i = 0; i < t->m_unit_count; i++) {
                Unit *u = (Unit *)t->m_unit_array[i];
                if (u == ignore_unit) continue;
                if (u->m_unit_type < 7) {
                    UnitMaster *m = u->m_master;
                    if (m->m_flag40 != 1) {
                        float dist_x = u->m_x - x;
                        if (dist_x < 0.0f) dist_x = -dist_x;
                        float dist_y = u->m_y - y;
                        if (dist_y < 0.0f) dist_y = -dist_y;

                        if (dist_x < rx + m->m_radius_x && dist_y < ry + m->m_radius_y) {
                            if (out_id) {
                                *out_id = u->m_id;
                            }
                            return 6;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

}

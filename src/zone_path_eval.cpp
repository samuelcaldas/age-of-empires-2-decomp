#pragma exceptions off
#include "zone_path_eval.h"

extern void *D_004E3180;

extern "C" {
int func_123350(float val);
unsigned char func_1378c0(void *map_zone, int x, int y);
float func_3675D0(void *unit);

int func_001C7860(
    BuildingMaster *bld,
    void *world,
    int *out_id,
    unsigned char flag1,
    unsigned char flag2,
    int arg5,
    int use_alt_radius,
    unsigned char flag3,
    unsigned char arg9,
    int arg10,
    Unit *ignore_unit,
    float x,
    float y
) {
    (void)arg5;

    MapContext *s0;
    short cur_x;
    BuildingMaster *bld_var;

    void *map = *(void **)((char *)world + 0xB98);
    s0 = *(MapContext **)((char *)map + 0x3C);
    short type_id = bld->m_type_id;
    float **slope_table = *(float ***)((char *)map + 0x68);
    bld_var = bld;
    float *slope_limits = slope_table[type_id];

    float rx, ry;
    if (use_alt_radius) {
        rx = bld_var->m_radius_x;
        ry = bld_var->m_radius_y;
    } else {
        rx = bld_var->m_alt_radius_x;
        ry = bld_var->m_alt_radius_y;
    }

    float min_x = x - rx;
    float min_y = y - ry;
    float max_x = (x + rx) - 0.001f;
    float max_y = (y + ry) - 0.001f;

    int map_w = s0->m_width;
    int map_h = s0->m_height;

    if (min_x < 0.0f || max_x >= (float)map_w || min_y < 0.0f || max_y >= (float)map_h) {
        return 7;
    }

    short t_min_x = (short)func_123350(min_x);
    short t_max_x = (short)func_123350(max_x);
    short t_min_y = (short)func_123350(min_y);
    short t_max_y = (short)func_123350(max_y);

    short p_min_x, p_max_x, p_min_y, p_max_y;
    short field48 = bld_var->m_field48;
    if (field48 >= 0 || bld_var->m_field4A >= 0) {
        short cy = (short)func_123350(y);
        MapTile *center_row = s0->m_tile_rows[cy];
        short cx = (short)func_123350(x);
        MapTile *center_tile = &center_row[cx];
        if (center_tile->m_zone_id != field48 && center_tile->m_zone_id != bld_var->m_field4A) {
            return 1;
        }
        p_min_x = (short)func_123350(x);
        p_max_x = p_min_x;
        p_min_y = (short)func_123350(y);
        p_max_y = p_min_y;
    } else {
        p_max_y = t_max_y;
        p_min_x = t_min_x;
        p_max_x = t_max_x;
        p_min_y = t_min_y;
    }

    if (bld_var->m_required_zone >= 0) {
        int touches_zone = 0;
        int touches_wild = 0;

        short edge_min_x = (short)(p_min_x - 1);
        short edge_max_x = (short)(p_max_x + 1);
        short edge_max_y = (short)(p_max_y + 1);
        short edge_min_y = (short)(p_min_y - 1);

        if (edge_min_y >= 0) {
            for (cur_x = p_min_x; cur_x <= p_max_x; cur_x++) {
                MapTile *t = &s0->m_tile_rows[edge_min_y][cur_x];
                if (t->m_zone_id == bld_var->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == -1) touches_wild = 1;
            }
        }
        if (edge_max_x < map_w) {
            for (short cur_y = p_min_y; cur_y <= p_max_y; cur_y++) {
                MapTile *t = &s0->m_tile_rows[cur_y][edge_max_x];
                if (t->m_zone_id == bld_var->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == -1) touches_wild = 1;
            }
        }
        if (edge_max_y < map_h) {
            for (cur_x = p_max_x; cur_x >= p_min_x; cur_x--) {
                MapTile *t = &s0->m_tile_rows[edge_max_y][cur_x];
                if (t->m_zone_id == bld_var->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == -1) touches_wild = 1;
            }
        }
        if (edge_min_x >= 0) {
            for (short cur_y = p_max_y; cur_y >= p_min_y; cur_y--) {
                MapTile *t = &s0->m_tile_rows[cur_y][edge_min_x];
                if (t->m_zone_id == bld_var->m_required_zone) touches_zone = 1;
                if (t->m_zone_id == -1) touches_wild = 1;
            }
        }

        if (!touches_zone && !touches_wild) {
            return 1;
        }
    }

    int fp_flag = 0;

    MapTile *base_tile = &s0->m_tile_rows[t_max_y][t_min_x];
    short base_slope = base_tile->m_slope_flag;
    short min_slope = (short)(base_slope - 1);
    short max_slope = (short)(base_slope + 1);

    for (cur_x = t_min_x; cur_x <= t_max_x; cur_x++) {
        for (short cur_y = t_min_y; cur_y <= t_max_y; cur_y++) {
            if (bld_var->m_id == 0x299 || bld_var->m_id == 0x29A) {
                if (cur_x - t_min_x != cur_y - t_min_y) continue;
            } else if ((unsigned int)(bld_var->m_id - 0x2A1) < 2) {
                if (t_max_x - cur_x != cur_y - t_min_y) continue;
            }

            if (slope_limits[s0->m_tile_rows[cur_y][cur_x].m_zone_id] <= 0.05f) {
                return 2;
            }

            if (flag1) {
                if (*(int *)((char *)D_004E3180 + 0x1C8) == 7) {
                    fp_flag = 1;
                } else {
                    void *world_val = *(void * volatile *)&world;
                    void *zone_mgr = *(void **)((char *)world_val + 0xB94);
                    if (func_1378c0(zone_mgr, cur_x, cur_y) != 0) {
                        fp_flag = 1;
                    }
                }
            }

            if (flag2) {
                short terrain = s0->m_tile_rows[cur_y][cur_x].m_terrain;
                short slope = s0->m_tile_rows[cur_y][cur_x].m_slope_flag;

                switch (bld_var->m_placement_type) {
                case 1:
                    if (terrain == 0 || terrain == 5 || terrain == 7 || terrain == 6 || terrain == 8) {
                    } else {
                        return 2;
                    }
                    break;
                case 2:
                    if (terrain != 0) return 2;
                    break;
                case 3:
                    if (cur_x == t_min_x || cur_y == t_max_y) {
                        if (slope < min_slope || slope > max_slope) return 3;
                    }
                    break;
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

    short check_min_x = (short)func_123350(x - 8.0f);
    short check_min_y = (short)func_123350(y - 8.0f);
    short check_max_x = (short)func_123350(x + 8.0f);
    short check_max_y = (short)func_123350(y + 8.0f);

    if (check_min_x < 0) check_min_x = 0;
    if (check_max_x >= s0->m_width) check_max_x = (short)(s0->m_width - 1);
    if (check_min_y < 0) check_min_y = 0;
    if (check_max_y >= s0->m_height) check_max_y = (short)(s0->m_height - 1);

    if (bld_var->m_id == 0x3B) {
        bld_var->m_field28 = 1.0f;
    }

    float check_radius;
    if (arg10 != 0) {
        check_radius = func_3675D0((void *)arg10);
    } else {
        check_radius = bld_var->m_field28;
    }

    if (arg9 && (flag3 || check_radius > 0.0f)) {
        for (short cur_y = check_min_y; cur_y <= check_max_y; cur_y++) {
        MapTile *t = &s0->m_tile_rows[cur_y][check_min_x];
        for (cur_x = check_min_x; cur_x <= check_max_x; cur_x++, t++) {
            if (t->m_unit_count == 0) continue;
            for (int i = 0; i < t->m_unit_count; i++) {
                Unit *u = (Unit *)t->m_unit_array[i];
                if (u == ignore_unit) continue;
                if (u->m_unit_type < 7) {
                    UnitMaster *m = u->m_master;
                    if (m->m_flag40 != 1) {
                        float u_rx = m->m_radius_x;
                        float u_ry = m->m_radius_y;
                        float u_rad = func_3675D0(u);
                        m = u->m_master; // reload m after function call
                        if (m->m_id == 59) {
                            u_rad = 1.0f;
                        } else if (bld_var->m_construction_type == 15 && m->m_type == 49) {
                            u_rad = 1.0f;
                        } else if (u_rad == 0.0f && m->m_class == 80 && m->m_id != 50) {
                            u_rad = 1.0f;
                        }

                        if (u_rx <= 0.0f) continue;
                        if (u_ry <= 0.0f) continue;
                        if (u_rad <= 0.0f) continue;
                        if (check_radius <= 0.0f) continue;

                        float dist_y = u->m_y - y;
                        float dist_x = u->m_x - x;
                        if (dist_y < 0.0f) dist_y = -dist_y;
                        if (dist_x < 0.0f) dist_x = -dist_x;

                        if (dist_x < rx + u_rx) {
                            if (dist_y < ry + u_ry) {
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
    }
    }

    return 0;
}
}

#include <cassert>
#include <cstring>
#include "zone_path_eval.h"

extern "C" {
void *D_004E3180 = 0;
int func_123350(float val) {
    return static_cast<int>(val);
}
int g_zone_query_result = 0;
int g_zone_query_calls = 0;
int func_1378c0(void *map_zone, int x, int y) {
    (void)map_zone; (void)x; (void)y;
    ++g_zone_query_calls;
    return g_zone_query_result;
}
float func_3675D0(void *unit) {
    (void)unit;
    return 1.0f;
}
}

int main() {
    // Setup mock building master
    BuildingMaster bld;
    std::memset(&bld, 0, sizeof(bld));
    bld.m_type_id = 0;
    bld.m_radius_x = 1.0f;
    bld.m_radius_y = 1.0f;
    bld.m_alt_radius_x = 1.0f;
    bld.m_alt_radius_y = 1.0f;
    bld.m_required_zone = -1;
    bld.m_field48 = -1;
    bld.m_field4A = -1;

    // Setup mock map structure
    char world_buf[0xC00];
    std::memset(world_buf, 0, sizeof(world_buf));

    char map_buf[0x100];
    std::memset(map_buf, 0, sizeof(map_buf));

    float slope_limits[256];
    for (int i = 0; i < 256; ++i) slope_limits[i] = 1.0f;
    float *slope_table[1] = { slope_limits };

    char s0_buf[0x9000];
    std::memset(s0_buf, 0, sizeof(s0_buf));
    *reinterpret_cast<int *>(s0_buf + 0x8) = 100; // map_w
    *reinterpret_cast<int *>(s0_buf + 0xC) = 100; // map_h

    // Setup grid tiles
    static MapTile grid_tiles[100][100];
    std::memset(grid_tiles, 0, sizeof(grid_tiles));
    static MapTile *tile_rows[100];
    for (int r = 0; r < 100; ++r) {
        tile_rows[r] = grid_tiles[r];
    }
    *reinterpret_cast<MapTile ***>(s0_buf + 0x8E8C) = tile_rows;

    *reinterpret_cast<void **>(world_buf + 0xB98) = map_buf;
    *reinterpret_cast<void **>(map_buf + 0x68) = slope_table;
    *reinterpret_cast<void **>(map_buf + 0x3C) = s0_buf;

    // Behavioral test 1: negative x coordinate out of bounds must return 7
    int res_neg_x = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5.0f, 10.0f);
    assert(res_neg_x == 7);

    // Behavioral test 2: coordinate exceeding map dimensions must return 7
    int res_oob_x = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150.0f, 10.0f);
    assert(res_oob_x == 7);

    // Behavioral test 3: negative y coordinate out of bounds must return 7
    int res_neg_y = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, -5.0f);
    assert(res_neg_y == 7);

    // Behavioral test 4: slope threshold exceeded on boundary tile must return 3
    bld.m_placement_type = 3;
    grid_tiles[9][9].m_slope_flag = 0;  // base tile slope
    grid_tiles[9][10].m_slope_flag = 5; // steep slope on boundary exceeding base + 1
    int res_slope_fail = func_001C7850(&bld, world_buf, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_slope_fail == 3);

    // Behavioral test 5: slope within threshold must succeed (not return 3)
    grid_tiles[9][10].m_slope_flag = 1; // within [base - 1, base + 1]
    int res_slope_pass = func_001C7850(&bld, world_buf, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_slope_pass == 0);

    // ELF 0x1C7E7C..0x1C7EB8: flag1 consults the singleton at +0x1C8. Mode 7 sets the
    // flag without calling func_1378c0. Otherwise only the low byte of the result counts (andi 0xFF).
    bld.m_placement_type = 0;
    char singleton_buf[0x200];
    std::memset(singleton_buf, 0, sizeof(singleton_buf));
    D_004E3180 = singleton_buf;

    g_zone_query_result = 0x100;
    int res_query_high_bits_only = func_001C7850(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_query_high_bits_only == 5);

    g_zone_query_result = 1;
    g_zone_query_calls = 0;
    int res_query_hit = func_001C7850(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_query_hit == 0);
    assert(g_zone_query_calls == 4);

    *reinterpret_cast<int *>(singleton_buf + 0x1C8) = 7;
    g_zone_query_result = 0;
    g_zone_query_calls = 0;
    int res_mode_seven = func_001C7850(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_mode_seven == 0);
    assert(g_zone_query_calls == 0);
    D_004E3180 = 0;

    return 0;
}

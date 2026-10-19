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

    int res_x_margin = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99.0005f, 10.0f);
    assert(res_x_margin == 0);
    int res_x_limit = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99.001f, 10.0f);
    assert(res_x_limit == 7);
    int res_y_margin = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 99.0005f);
    assert(res_y_margin == 0);
    int res_y_limit = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 99.001f);
    assert(res_y_limit == 7);

    // Behavioral test 1: negative x coordinate out of bounds must return 7
    int res_neg_x = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5.0f, 10.0f);
    assert(res_neg_x == 7);

    // Behavioral test 2: coordinate exceeding map dimensions must return 7
    int res_oob_x = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150.0f, 10.0f);
    assert(res_oob_x == 7);

    // Behavioral test 3: negative y coordinate out of bounds must return 7
    int res_neg_y = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, -5.0f);
    assert(res_neg_y == 7);

    // Behavioral test 4: slope threshold exceeded on boundary tile (cur_x == t_min_x || cur_y == t_max_y)
    // ELF 0x73C..0x778: base_tile is [t_max_y][t_min_x] ([10][9]).
    bld.m_placement_type = 3;
    grid_tiles[10][9].m_slope_flag = 0;  // base tile slope
    grid_tiles[9][9].m_slope_flag = 5;   // steep slope on boundary tile (cur_x == t_min_x) exceeding base + 1
    int res_slope_fail = func_001C7860(&bld, world_buf, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_slope_fail == 3);

    // Behavioral test 5: slope within threshold must succeed (not return 3)
    grid_tiles[9][9].m_slope_flag = 1; // within [base - 1, base + 1]
    int res_slope_pass = func_001C7860(&bld, world_buf, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_slope_pass == 0);

    // ELF 0x500..0x508: base slope is indexed at tile_rows[t_max_y][t_min_x] (grid_tiles[10][9]).
    // Set base slope at [10][9] to 4 (valid range [3..5]).
    // Boundary tiles [9][9] and [10][10] slope 4 must pass.
    grid_tiles[10][9].m_slope_flag = 4;
    grid_tiles[9][9].m_slope_flag = 4;
    grid_tiles[10][10].m_slope_flag = 4;
    int res_base_max_y = func_001C7860(&bld, world_buf, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_base_max_y == 0);
    grid_tiles[10][9].m_slope_flag = 0;
    grid_tiles[9][9].m_slope_flag = 0;
    grid_tiles[10][10].m_slope_flag = 0;

    // ELF 0x1C7E8C..0x1C7EC8: flag1 consults the singleton at +0x1C8. Mode 7 sets the
    // flag without calling func_1378c0. Otherwise only the low byte of the result counts (andi 0xFF).
    bld.m_placement_type = 0;
    char singleton_buf[0x200];
    std::memset(singleton_buf, 0, sizeof(singleton_buf));
    D_004E3180 = singleton_buf;

    g_zone_query_result = 0x100;
    int res_query_high_bits_only = func_001C7860(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_query_high_bits_only == 5);

    g_zone_query_result = 1;
    g_zone_query_calls = 0;
    int res_query_hit = func_001C7860(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_query_hit == 0);
    assert(g_zone_query_calls == 4);

    *reinterpret_cast<int *>(singleton_buf + 0x1C8) = 7;
    g_zone_query_result = 0;
    g_zone_query_calls = 0;
    int res_mode_seven = func_001C7860(&bld, world_buf, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_mode_seven == 0);
    assert(g_zone_query_calls == 0);
    D_004E3180 = 0;

    // Behavioral test 6: Diagonal gate (0x299) at non-equal x/y map coordinates (x=20, y=50).
    // ELF 0x1C7DE8..0x1C7E0C checks cur_x - t_min_x == cur_y - t_min_y.
    // Tile (cur_x=19, cur_y=49) is on the diagonal; with impassable slope limit (0.0f),
    // func_001C7860 must detect the obstruction and return 2.
    bld.m_id = 0x299;
    grid_tiles[49][19].m_zone_id = 10;
    slope_limits[10] = 0.0f;
    int res_diag_gate = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20.0f, 50.0f);
    assert(res_diag_gate == 2);
    slope_limits[10] = 1.0f;
    bld.m_id = 0;

    // Behavioral test 7: Perimeter zone adjacency requires orthogonal edge contact (p_min..p_max),
    // not diagonal corner contact. ELF 0x274..0x2E8 iterates cur_x from p_min_x to p_max_x,
    // excluding corner (edge_min_x, edge_min_y).
    bld.m_required_zone = 5;
    grid_tiles[8][8].m_zone_id = 5; // corner tile (8, 8)
    int res_corner_only = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_corner_only == 1);

    grid_tiles[8][9].m_zone_id = 5; // edge tile (8, 9)
    int res_edge_touch = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_edge_touch == 0);
    grid_tiles[8][8].m_zone_id = 0;
    grid_tiles[8][9].m_zone_id = 0;
    bld.m_required_zone = -1;

    // Behavioral test 8: Unit collision detection and out_id assignment.
    // ELF 0x9D4..0xB78: loops units on tiles in check_radius; when distance matches,
    // writes u->m_id to out_id and returns 6. With ignore_unit, collision is bypassed.
    UnitMaster master;
    std::memset(&master, 0, sizeof(master));
    master.m_id = 100;
    master.m_flag40 = 0;
    master.m_radius_x = 0.5f;
    master.m_radius_y = 0.5f;

    Unit obstructing_unit;
    std::memset(&obstructing_unit, 0, sizeof(obstructing_unit));
    obstructing_unit.m_id = 42;
    obstructing_unit.m_unit_type = 2; // < 7
    obstructing_unit.m_master = &master;
    obstructing_unit.m_x = 10.2f;
    obstructing_unit.m_y = 10.2f;

    void *unit_list[1] = { &obstructing_unit };
    grid_tiles[10][10].m_unit_count = 1;
    grid_tiles[10][10].m_unit_array = unit_list;

    int out_id = 0;
    bld.m_field28 = 1.0f;
    // Call with arg9=1 to enable collision check
    int res_collision = func_001C7860(&bld, world_buf, &out_id, 0, 0, 0, 0, 0, 1, 0, 0, 10.0f, 10.0f);
    assert(res_collision == 6);
    assert(out_id == 42);

    // With ignore_unit, collision is skipped
    out_id = 0;
    int res_ignored = func_001C7860(&bld, world_buf, &out_id, 0, 0, 0, 0, 0, 1, 0, &obstructing_unit, 10.0f, 10.0f);
    assert(res_ignored == 0);
    assert(out_id == 0);

    // With zero check_radius and flag3=0, collision check is bypassed
    bld.m_field28 = 0.0f;
    out_id = 0;
    int res_zero_radius = func_001C7860(&bld, world_buf, &out_id, 0, 0, 0, 0, 0, 1, 0, 0, 10.0f, 10.0f);
    assert(res_zero_radius == 0);
    assert(out_id == 0);

    // With zero check_radius and flag3=1, inner loop check (check_radius <= 0.0f) also bypasses collision
    out_id = 0;
    int res_flag3_zero_radius = func_001C7860(&bld, world_buf, &out_id, 0, 0, 0, 0, 1, 1, 0, 0, 10.0f, 10.0f);
    assert(res_flag3_zero_radius == 0);
    assert(out_id == 0);
    bld.m_field28 = 1.0f;

    grid_tiles[10][10].m_unit_count = 0;
    grid_tiles[10][10].m_unit_array = 0;

    grid_tiles[10][10].m_zone_id = 20;
    slope_limits[20] = 0.05f;
    int res_at_threshold = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_at_threshold == 2);

    slope_limits[20] = 0.051f;
    int res_above_threshold = func_001C7860(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, 10.0f);
    assert(res_above_threshold == 0);
    grid_tiles[10][10].m_zone_id = 0;
    slope_limits[20] = 1.0f;

    return 0;
}

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "map_zone_add_rect.h"

static int g_func_002082B0_called = 0;

extern "C" {
    int D_004E3058 = 0;
    int *D_50A5A0[100];
    void func_002082B0(void *obj, int x, int y) {
        (void)obj; (void)x; (void)y;
        g_func_002082B0_called++;
    }
}

static void test_out_of_bounds() {
    ZoneMapReveal zone;
    memset(&zone, 0, sizeof(zone));
    ZonePlayerMgr mgr;
    memset(&mgr, 0, sizeof(mgr));
    mgr.m_player_id = -1;
    zone.m_player_mgr = &mgr;
    zone.m_width = 10;
    zone.m_height = 10;

    // Completely out of bounds min_x >= m_width
    assert(func_00138040(&zone, 10, 0, 15, 5, 0) == 0);
    // max_x < 0
    assert(func_00138040(&zone, -5, 0, -1, 5, 0) == 0);
    // min_y >= m_height
    assert(func_00138040(&zone, 0, 10, 5, 15, 0) == 0);
    // max_y < 0
    assert(func_00138040(&zone, 0, -5, 5, -1, 0) == 0);
}

static void test_reveal_logic() {
    ZoneMapReveal zone;
    memset(&zone, 0, sizeof(zone));
    ZonePlayerMgr mgr;
    memset(&mgr, 0, sizeof(mgr));
    mgr.m_player_id = -1;
    zone.m_player_mgr = &mgr;
    ZoneWorld world;
    memset(&world, 0, sizeof(world));
    zone.m_world = &world;
    zone.m_width = 4;
    zone.m_height = 4;
    zone.m_field24 = 0x10;
    zone.m_field2C = 0x20;

    unsigned char row0[4] = {255, 0, 1, 249};
    unsigned char row1[4] = {255, 0, 1, 249};
    unsigned char *rows[4] = {row0, row1, nullptr, nullptr};
    zone.m_row_ptrs = rows;

    int flag_row0[4] = {0, 0, 0, 0};
    int flag_row1[4] = {0, 0, 0, 0};
    D_50A5A0[0] = flag_row0;
    D_50A5A0[1] = flag_row1;

    ZoneFieldC fieldC;
    memset(&fieldC, 0, sizeof(fieldC));
    char grid0[4 * 28];
    char grid1[4 * 28];
    memset(grid0, 0, sizeof(grid0));
    memset(grid1, 0, sizeof(grid1));
    char *grid_rows[2] = {grid0, grid1};
    fieldC.m_grid = grid_rows;
    zone.m_fieldC = &fieldC;

    g_func_002082B0_called = 0;

    // Reveal (0, 0) to (3, 0), flag=1
    int revealed = func_00138040(&zone, 0, 0, 3, 0, 1);

    // row0[0] was 255. 255 + 1 = 0 (byte overflow).
    // Should be counted as newly revealed!
    // val becomes 1, *flag_ptr |= m_field2C (0x20).
    // val == 1 then *flag_ptr |= m_field24 (0x10) and grid0[9] = 15.
    assert(revealed == 1);
    assert(row0[0] == 1);
    assert((flag_row0[0] & 0x20) == 0x20);
    assert((flag_row0[0] & 0x10) == 0x10);
    assert(grid0[9] == 15);

    // row0[1] was 0 -> becomes 1 -> *flag_ptr |= 0x10, grid0[28 + 9] = 15
    assert(row0[1] == 1);
    assert((flag_row0[1] & 0x10) == 0x10);
    assert(grid0[28 + 9] == 15);

    // row0[3] was 249 -> becomes 250 -> clamped to 249
    assert(row0[3] == 249);
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "0") == 0) {
        test_out_of_bounds();
    } else {
        test_reveal_logic();
    }
    return 0;
}

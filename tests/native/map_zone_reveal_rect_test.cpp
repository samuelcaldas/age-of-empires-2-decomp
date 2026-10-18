#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "map_zone_reveal_rect.h"

static int g_func_002082B0_called = 0;

extern "C" {
    int D_004E3058 = 0;
    int *D_50A5A0[100];
    void func_002082B0(void *obj, int x, int y) {
        (void)obj; (void)x; (void)y;
        g_func_002082B0_called++;
    }
}

static void test_bounds() {
    ZoneMapReveal zone;
    memset(&zone, 0, sizeof(zone));
    ZonePlayerMgr mgr;
    memset(&mgr, 0, sizeof(mgr));
    mgr.m_player_id = -1;
    zone.m_player_mgr = &mgr;
    zone.m_width = 10;
    zone.m_height = 10;

    assert(func_001384C0(&zone, 10, 0, 15, 5, 0) == 0);
    assert(func_001384C0(&zone, -5, 0, -1, 5, 0) == 0);
    assert(func_001384C0(&zone, 0, 10, 5, 15, 0) == 0);
    assert(func_001384C0(&zone, 0, -5, 5, -1, 0) == 0);
}

static void test_reveal() {
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
    zone.m_field2C = 0x40;

    unsigned char row0[4] = {255, 0, 255, 1};
    unsigned char *rows[4] = {row0, nullptr, nullptr, nullptr};
    zone.m_row_ptrs = rows;

    int flag_row0[4] = {0, 0, 0, 0};
    D_50A5A0[0] = flag_row0;

    ZoneFieldC fieldC;
    memset(&fieldC, 0, sizeof(fieldC));
    char grid0[4 * 28];
    memset(grid0, 0, sizeof(grid0));
    char *grid_rows[1] = {grid0};
    fieldC.m_grid = grid_rows;
    zone.m_fieldC = &fieldC;

    g_func_002082B0_called = 0;

    int revealed = func_001384C0(&zone, 0, 0, 3, 0, 1);

    // Two tiles equal to 255 (index 0 and index 2) should be revealed.
    assert(revealed == 2);
    assert(row0[0] == 0);
    assert(row0[2] == 0);
    assert((flag_row0[0] & 0x40) == 0x40);
    assert((flag_row0[2] & 0x40) == 0x40);
    assert(grid0[9] == (char)128);
    assert(grid0[2*28 + 9] == (char)128);
    assert(g_func_002082B0_called == 2);
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "0") == 0) {
        test_bounds();
    } else {
        test_reveal();
    }
    return 0;
}

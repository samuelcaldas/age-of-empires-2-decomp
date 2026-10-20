#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "map_zone_rect.h"

extern "C" {
    int D_004E3058 = 0;
    int *D_50A5A0[100];
}

static void test_bounds() {
    ZoneMapLos zone;
    memset(&zone, 0, sizeof(zone));
    zone.m_width = 10;
    zone.m_height = 10;

    // Out of bounds
    func_00138320(&zone, 10, 0, 15, 5, 0);
    func_00138320(&zone, -5, 0, -1, 5, 0);
    func_00138320(&zone, 0, 10, 5, 15, 0);
    func_00138320(&zone, 0, -5, 5, -1, 0);
}

static void test_hide_los() {
    ZoneMapLos zone;
    memset(&zone, 0, sizeof(zone));
    zone.m_width = 4;
    zone.m_height = 4;
    zone.m_field28 = ~0x0F;

    unsigned char row0[4] = {1, 2, 0, 255};
    unsigned char *rows[4] = {row0, nullptr, nullptr, nullptr};
    zone.m_row_ptrs = rows;

    int flag_row0[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    D_50A5A0[0] = flag_row0;

    ZoneFieldC fieldC;
    memset(&fieldC, 0, sizeof(fieldC));
    char grid0[4 * 28];
    memset(grid0, 0, sizeof(grid0));
    char *grid_rows[1] = {grid0};
    fieldC.m_grid = grid_rows;
    zone.m_fieldC = &fieldC;

    // Call func_00138320 covering (0,0) to (3,0), flag=1
    func_00138320(&zone, 0, 0, 3, 0, 1);

    // row0[0] was 1 -> 1 - 1 = 0. !val is true -> grid0[9] = 128, flag_row0[0] &= ~0x0F
    assert(row0[0] == 0);
    assert((flag_row0[0] & 0x0F) == 0);
    assert(grid0[9] == (char)128);

    // row0[1] was 2 -> 2 - 1 = 1
    assert(row0[1] == 1);

    // row0[2] was 0 -> 0 - 1 = -1 (255) -> wrapped to 0. !val true.
    assert(row0[2] == 0);
    assert((flag_row0[2] & 0x0F) == 0);

    // row0[3] was 255 -> 255 - 1 = 254 -> converted to 255
    assert(row0[3] == 255);
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "0") == 0) {
        test_bounds();
    } else {
        test_hide_los();
    }
    return 0;
}

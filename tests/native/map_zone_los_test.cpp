#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "map_zone_los.h"

extern "C" {
    int D_004E3058 = 0;
    SightEntry dummy_table0[3] = {
        {0, -1, 1},
        {1, 0, 0},
        {999, 0, 0}
    };
    SightEntry dummy_table1[3] = {
        {0, 0, 0},
        {999, 0, 0},
        {999, 0, 0}
    };
    SightEntry *D_0038FA40[25] = { dummy_table0 };
    SightEntry *D_0038FAA0[25] = { dummy_table1 };
    int *D_50A5A0[100];
}

static void test_stub() {
    func_00137E90(nullptr);
}

static void test_los_update() {
    MapZone zone;
    memset(&zone, 0, sizeof(zone));
    zone.m_width = 4;
    zone.m_height = 4;
    zone.pad_28 = ~0x0F;

    unsigned char row0[4] = {1, 2, 3, 4};
    unsigned char row1[4] = {1, 2, 3, 4};
    unsigned char row2[4] = {1, 2, 3, 4};
    unsigned char row3[4] = {1, 2, 3, 4};
    unsigned char *rows[4] = {row0, row1, row2, row3};
    zone.m_row_ptrs = rows;

    int flag_row0[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    int flag_row1[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    int flag_row2[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    int flag_row3[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    D_50A5A0[0] = flag_row0;
    D_50A5A0[1] = flag_row1;
    D_50A5A0[2] = flag_row2;
    D_50A5A0[3] = flag_row3;

    func_00137EA0(&zone, 1, 0, 0, 0, 0);

    assert(row0[0] == 0);
    assert((flag_row0[0] & 0x0F) == 0);
    assert(row0[1] == 1);
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "0") == 0) {
        test_stub();
    } else {
        test_los_update();
    }
    return 0;
}

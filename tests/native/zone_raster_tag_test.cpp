#include <cassert>
#include <cstdio>
#include <cstring>

#define func_001CA7F0 mock_func_001CA7F0
#define D_392060 mock_D_392060

static int g_ca7f0_called = 0;

extern "C" {
unsigned char mock_D_392060[32] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15,
    0, 0, 0, 0, 0, 0, 0, 0
};

int mock_func_001CA7F0(void *self, int px, int py, int x0, int y0, int x1, int y1) {
    g_ca7f0_called++;
    return 0x55;
}
}

#include "../../src/zone/zone_raster_tag.cpp"

int main() {
    // Test trivial point
    int res = func_001CA180(NULL, 5, 5, 5, 5, 5, 5);
    assert(res == 1);

    // Setup layout
    ZoneLayout zm;
    memset(&zm, 0, sizeof(zm));
    zm.width = 10;
    zm.height = 10;

    ZoneCell row0[10];
    ZoneCell row1[10];
    ZoneCell row2[10];
    memset(row0, 0, sizeof(row0));
    memset(row1, 0, sizeof(row1));
    memset(row2, 0, sizeof(row2));

    ZoneCell *cells[3] = { row0, row1, row2 };
    zm.cells_ptr = cells;

    // Point outside box
    res = func_001CA180(&zm, 5, 5, 0, 0, 2, 2);
    assert(res == 0);

    // Point inside box
    res = func_001CA180(&zm, 1, 1, 0, 0, 2, 2);
    assert(res == 1);
    assert(g_ca7f0_called == 1);

    // Check tagged cell at (1,1)
    assert((row1[1].f_B & 0x40) != 0);
    assert(row1[1].f_C == 0x55);

    // Check other cell at (0,0)
    assert((row0[0].f_B & 0x20) != 0);

    printf("zone_raster_tag_test passed\n");
    return 0;
}

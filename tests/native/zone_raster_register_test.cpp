#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_raster_register.h"

static int g_100730_called = 0;
static int g_1cac00_called = 0;
static short g_allocated_buf[256];

extern "C" {
void* func_00100730(unsigned int size) {
    g_100730_called++;
    return g_allocated_buf;
}

void func_001CAC00(void *self, short *buffer, int p1, int p2) {
    g_1cac00_called++;
}
}

#include "../../src/zone/zone_raster_register.cpp"

int main() {
    ZoneLayout layout;
    memset(&layout, 0, sizeof(layout));
    layout.width = 100;
    layout.height = 100;

    int packed_table[10];
    short *buf_table[10];
    memset(packed_table, 0, sizeof(packed_table));
    memset(buf_table, 0, sizeof(buf_table));

    layout.f_8ED0 = 0;
    layout.f_8ED4 = 10;
    layout.f_8ED8 = packed_table;
    layout.f_8EDC = buf_table;

    // Out of bounds checks
    assert(func_001CA7F0(&layout, 5, 5, 200, 5, 210, 10) == 0); // x0 >= width
    assert(func_001CA7F0(&layout, 5, 5, 5, 200, 10, 210) == 0); // y0 >= height
    assert(func_001CA7F0(&layout, 5, 5, -20, 5, -10, 10) == 0); // x1 < 0
    assert(func_001CA7F0(&layout, 5, 5, 5, -20, 10, -10) == 0); // y1 < 0
    assert(func_001CA7F0(&layout, 5, 5, 5, 5, 5, 5) == 0);       // x0==x1 && y0==y1

    // Valid registration
    int res1 = func_001CA7F0(&layout, 10, 10, 5, 5, 15, 15);
    assert(res1 == 1);
    assert(layout.f_8ED0 == 1);
    assert(g_100730_called == 1);
    assert(g_1cac00_called >= 4);

    // Existing entry lookup
    int res2 = func_001CA7F0(&layout, 10, 10, 5, 5, 15, 15);
    assert(res2 == 1); // returns cached index i + 1
    assert(layout.f_8ED0 == 1); // no new entry added

    printf("zone_raster_register_test passed\n");
    return 0;
}

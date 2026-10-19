#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include "zone_spatial_grid_constructor.h"

static int g_func_001F2DA0_called = 0;
static void *g_func_001F2DA0_arg_self = 0;

struct StrictSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    void *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[10];
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
};

extern "C" {
void func_001F2DA0(ZoneSpatialGrid *self) {
    g_func_001F2DA0_called++;
    g_func_001F2DA0_arg_self = self;
}
}

int main() {
    // ABI layout verification
    assert(sizeof(StrictSpatialGrid) >= 0xAB4);
    assert(offsetof(StrictSpatialGrid, vtable_00) == 0x00);
    assert(offsetof(StrictSpatialGrid, field_04) == 0x04);
    assert(offsetof(StrictSpatialGrid, field_1C) == 0x1C);
    assert(offsetof(StrictSpatialGrid, table_20) == 0x20);
    assert(offsetof(StrictSpatialGrid, buckets_48) == 0x48);
    assert(offsetof(StrictSpatialGrid, table_A48) == 0xA48);
    assert(offsetof(StrictSpatialGrid, table_A70) == 0xA70);
    assert(offsetof(StrictSpatialGrid, field_A98) == 0xA98);
    assert(offsetof(StrictSpatialGrid, field_A9C) == 0xA9C);
    assert(offsetof(StrictSpatialGrid, field_AA0) == 0xAA0);
    assert(offsetof(StrictSpatialGrid, field_AA4) == 0xAA4);
    assert(offsetof(StrictSpatialGrid, field_AA8) == 0xAA8);
    assert(offsetof(StrictSpatialGrid, field_AAC) == 0xAAC);
    assert(offsetof(StrictSpatialGrid, field_AB0) == 0xAB0);

    StrictSpatialGrid *grid = new StrictSpatialGrid();
    // Fill with nonzero canary to ensure constructor actually zeroes fields
    memset(grid, 0xAA, sizeof(StrictSpatialGrid));

    g_func_001F2DA0_called = 0;
    g_func_001F2DA0_arg_self = 0;

    ZoneSpatialGrid *ret = func_001F24E0((ZoneSpatialGrid *)grid);

    // Constructor contract assertions
    assert(ret == (ZoneSpatialGrid *)grid);
    assert(grid->vtable_00 == (void *)0x4D9AD0);
    assert(grid->field_04 == 0);
    assert(grid->field_08 == 0);
    assert(grid->field_0C == 0);
    assert(grid->field_10 == 0);
    assert(grid->field_14 == 0);
    assert(grid->field_18 == 0);
    assert(grid->field_1C == 0);

    for (int i = 0; i < 10; ++i) {
        assert(grid->table_20[i] == 0);
        assert(grid->buckets_48[i][0] == 0);
        assert(grid->table_A48[i] == 0);
        assert(grid->table_A70[i] == 0);
    }

    assert(grid->field_A98 == 0);
    assert(grid->field_A9C == 1);
    assert(grid->field_AA0 == 0);
    assert(grid->field_AA4 == 0);
    assert(grid->field_AA8 == 0);
    assert(grid->field_AAC == 1);
    assert(grid->field_AB0 == 0);

    assert(g_func_001F2DA0_called == 1);
    assert(g_func_001F2DA0_arg_self == (void *)grid);

    delete grid;
    return 0;
}

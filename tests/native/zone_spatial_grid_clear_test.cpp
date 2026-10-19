#include <cassert>
#include <cstddef>
#include <cstring>
#include "zone_spatial_grid_clear.h"

struct GridClearLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    void *field_14;
    int field_18;
    int field_1C;
    int guard_20;
};

int main() {
    assert(offsetof(GridClearLayout, field_04) == 0x04);
    assert(offsetof(GridClearLayout, field_08) == 0x08);
    assert(offsetof(GridClearLayout, field_0C) == 0x0C);
    assert(offsetof(GridClearLayout, field_10) == 0x10);
    assert(offsetof(GridClearLayout, field_14) == 0x14);
    assert(offsetof(GridClearLayout, field_18) == 0x18);
    assert(offsetof(GridClearLayout, field_1C) == 0x1C);

    GridClearLayout grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: All 5 matching fields are cleared to 0
    // Unrelated fields (vtable_00, field_14, field_18, guard_20) must be preserved
    grid.vtable_00 = reinterpret_cast<void *>(0x12345678);
    grid.field_04 = 0x42;
    grid.field_08 = 0x42;
    grid.field_0C = 0x42;
    grid.field_10 = 0x42;
    grid.field_14 = reinterpret_cast<void *>(0x87654321);
    grid.field_18 = 0x99;
    grid.field_1C = 0x42;
    grid.guard_20 = 0xdeadbeef;

    func_001F28A0(grid_ptr, 0x42);

    assert(grid.field_10 == 0); // offset 0x10 cleared
    assert(grid.field_04 == 0); // offset 0x04 cleared
    assert(grid.field_08 == 0); // offset 0x08 cleared
    assert(grid.field_0C == 0); // offset 0x0C cleared
    assert(grid.field_1C == 0); // offset 0x1C cleared

    assert(grid.vtable_00 == reinterpret_cast<void *>(0x12345678));
    assert(grid.field_14 == reinterpret_cast<void *>(0x87654321));
    assert(grid.field_18 == 0x99);
    assert(grid.guard_20 == static_cast<int>(0xdeadbeef));

    // Test Case 2: Selective clearing (only fields matching val are cleared)
    grid.field_10 = 0x55;
    grid.field_04 = 0x11;
    grid.field_08 = 0x55;
    grid.field_0C = 0x22;
    grid.field_1C = 0x33;

    func_001F28A0(grid_ptr, 0x55);

    assert(grid.field_10 == 0);
    assert(grid.field_04 == 0x11);
    assert(grid.field_08 == 0);
    assert(grid.field_0C == 0x22);
    assert(grid.field_1C == 0x33);

    // Test Case 3: None matching -> no modifications
    func_001F28A0(grid_ptr, 0x999);

    assert(grid.field_10 == 0);
    assert(grid.field_04 == 0x11);
    assert(grid.field_08 == 0);
    assert(grid.field_0C == 0x22);
    assert(grid.field_1C == 0x33);

    return 0;
}

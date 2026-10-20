#include <cassert>
#include <cstddef>
#include <cstring>
#include "zone_spatial_grid_setters.h"

struct GridSettersLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int guard_14;
};

int main() {
    assert(offsetof(GridSettersLayout, field_04) == 0x04);
    assert(offsetof(GridSettersLayout, field_08) == 0x08);
    assert(offsetof(GridSettersLayout, field_0C) == 0x0C);
    assert(offsetof(GridSettersLayout, field_10) == 0x10);

    GridSettersLayout grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    grid.vtable_00 = reinterpret_cast<void *>(0x12345678);
    grid.field_04 = 0;
    grid.field_08 = 0;
    grid.field_0C = static_cast<int>(0xdeadbeef);
    grid.field_10 = static_cast<int>(0xfeedface);
    grid.guard_14 = static_cast<int>(0x99999999);

    // Test Case 1: func_001F2AB0 sets field_04 exactly
    func_001F2AB0(grid_ptr, 0x42);
    assert(grid.field_04 == 0x42);
    assert(grid.field_08 == 0);
    assert(grid.field_0C == static_cast<int>(0xdeadbeef));
    assert(grid.field_10 == static_cast<int>(0xfeedface));
    assert(grid.vtable_00 == reinterpret_cast<void *>(0x12345678));
    assert(grid.guard_14 == static_cast<int>(0x99999999));

    // Test Case 2: func_001F2AC0 sets field_08 exactly
    func_001F2AC0(grid_ptr, 0x84);
    assert(grid.field_04 == 0x42);
    assert(grid.field_08 == 0x84);
    assert(grid.field_0C == static_cast<int>(0xdeadbeef));
    assert(grid.field_10 == static_cast<int>(0xfeedface));
    assert(grid.vtable_00 == reinterpret_cast<void *>(0x12345678));
    assert(grid.guard_14 == static_cast<int>(0x99999999));

    // Test Case 3: Boundary values and negative values
    func_001F2AB0(grid_ptr, -12345);
    func_001F2AC0(grid_ptr, -67890);
    assert(grid.field_04 == -12345);
    assert(grid.field_08 == -67890);

    func_001F2AB0(grid_ptr, 0x7FFFFFFF);
    func_001F2AC0(grid_ptr, static_cast<int>(0x80000000));
    assert(grid.field_04 == 0x7FFFFFFF);
    assert(grid.field_08 == static_cast<int>(0x80000000));

    return 0;
}

#include <cassert>
#include <cstddef>
#include <cstring>
#include "zone_spatial_grid_getters.h"

struct MockSpatialGrid {
    void *vtable;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int trailing_guard;
};

int main() {
    assert(sizeof(MockSpatialGrid) >= 0x18);
    assert(offsetof(MockSpatialGrid, field_04) == 0x04);
    assert(offsetof(MockSpatialGrid, field_08) == 0x08);
    assert(offsetof(MockSpatialGrid, field_0C) == 0x0C);
    assert(offsetof(MockSpatialGrid, field_10) == 0x10);

    MockSpatialGrid grid;
    std::memset(&grid, 0x55, sizeof(grid));

    grid.field_04 = 0x12345678;
    grid.field_08 = 0x23456789;
    grid.field_0C = 0x3456789A;
    grid.field_10 = 0x456789AB;

    ZoneSpatialGrid *ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Verify each getter returns the exact field at the expected offset
    assert(func_001F26C0(ptr) == 0x456789AB); // offset 0x10
    assert(func_001F26D0(ptr) == 0x12345678); // offset 0x04
    assert(func_001F26E0(ptr) == 0x23456789); // offset 0x08
    assert(func_001F26F0(ptr) == 0x3456789A); // offset 0x0C

    // Mutate and verify dynamic read
    grid.field_04 = -100;
    grid.field_08 = -200;
    grid.field_0C = -300;
    grid.field_10 = -400;

    assert(func_001F26C0(ptr) == -400);
    assert(func_001F26D0(ptr) == -100);
    assert(func_001F26E0(ptr) == -200);
    assert(func_001F26F0(ptr) == -300);

    return 0;
}

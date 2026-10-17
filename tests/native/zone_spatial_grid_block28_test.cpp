#include <cassert>
#include "zone_spatial_grid_push_buffer1.h"
#include "zone_spatial_grid_expand_buffer2.h"
#include "zone_spatial_grid_expand_buffer3.h"
#include "zone_spatial_grid_set_margin_bounds.h"
#include "zone_spatial_grid_test_point_in_bounds.h"
#include "zone_spatial_grid_set_field10.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct WorldMap {
    char pad[0x12B424];
    int map_width;
    int map_height;
};

struct MockGrid {
    WorldMap *map;
    char pad_10[0xC];
    void *val_10;
    char pad_BC[0xBC - 0x14];
    float margin;
    float min_x;
    float max_x;
    float max_y;
};

static void test_bounds_checking() {
    MockGrid grid;
    for (int i = 0; i < sizeof(grid); i++) ((char *)&grid)[i] = 0;

    grid.margin = 2.0f;
    grid.min_x = 2.0f;
    grid.max_x = 98.0f;
    grid.max_y = 98.0f;

    // Inside bounds
    assert(func_001E7080((const SpatialGrid *)&grid, 50.0f, 50.0f) == 1);
    assert(func_001E7080((const SpatialGrid *)&grid, 2.0f, 2.0f) == 1);
    assert(func_001E7080((const SpatialGrid *)&grid, 98.0f, 98.0f) == 1);

    // Outside bounds
    assert(func_001E7080((const SpatialGrid *)&grid, 1.0f, 50.0f) == 0);
    assert(func_001E7080((const SpatialGrid *)&grid, 99.0f, 50.0f) == 0);
    assert(func_001E7080((const SpatialGrid *)&grid, 50.0f, 1.0f) == 0);
    assert(func_001E7080((const SpatialGrid *)&grid, 50.0f, 99.0f) == 0);

    // Test setter
    void *dummy = (void *)0x1234;
    func_001E7100((SpatialGrid *)&grid, dummy);
    assert(grid.val_10 == dummy);
}

int main(int argc, char **argv) {
    test_bounds_checking();
    return 0;
}

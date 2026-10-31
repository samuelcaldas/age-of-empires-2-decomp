#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_set_margin_bounds.h"

struct WorldMap {
    char pad[0x12B424];
    int map_width;
    int map_height;
};

struct SpatialGrid {
    WorldMap *map;
    char pad_BC[0xBC - 4];
    float margin;
    float min_x;
    float max_x;
    float max_y;
};

static void test_layout() {
    assert(offsetof(WorldMap, map_width) == 0x12B424);
    assert(offsetof(WorldMap, map_height) == 0x12B428);
    assert(offsetof(SpatialGrid, map) == 0x00);
    assert(offsetof(SpatialGrid, margin) == 0xBC);
    assert(offsetof(SpatialGrid, min_x) == 0xC0);
    assert(offsetof(SpatialGrid, max_x) == 0xC4);
    assert(offsetof(SpatialGrid, max_y) == 0xC8);
}

static void test_set_margin_bounds_positive() {
    SpatialGrid grid;
    std::memset(&grid, 0, sizeof(grid));

    WorldMap *map = (WorldMap *)std::malloc(sizeof(WorldMap));
    assert(map != nullptr);
    std::memset(map, 0, sizeof(WorldMap));
    map->map_width = 200;
    map->map_height = 300;

    grid.map = map;
    func_001E7030(&grid, 15.0f);

    assert(grid.margin == 15.0f);
    assert(grid.min_x == 15.0f);
    assert(grid.max_x == 185.0f);
    assert(grid.max_y == 285.0f);

    std::free(map);
}

static void test_set_margin_bounds_zero() {
    SpatialGrid grid;
    std::memset(&grid, 0, sizeof(grid));

    WorldMap *map = (WorldMap *)std::malloc(sizeof(WorldMap));
    assert(map != nullptr);
    std::memset(map, 0, sizeof(WorldMap));
    map->map_width = 120;
    map->map_height = 140;

    grid.map = map;
    func_001E7030(&grid, 0.0f);

    assert(grid.margin == 0.0f);
    assert(grid.min_x == 0.0f);
    assert(grid.max_x == 120.0f);
    assert(grid.max_y == 140.0f);

    std::free(map);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
    case 0:
        test_layout();
        break;
    case 1:
        test_set_margin_bounds_positive();
        break;
    case 2:
        test_set_margin_bounds_zero();
        break;
    default:
        return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}

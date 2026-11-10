#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_set_obstacle_array.h"

struct SpatialGrid {
    char pad_00[0x12B584];
    unsigned char flag;
    char pad_85[3];
    int count;
    int array_ptr;
};

static void test_layout() {
    assert(offsetof(SpatialGrid, flag) == 0x12B584);
    assert(offsetof(SpatialGrid, count) == 0x12B588);
    assert(offsetof(SpatialGrid, array_ptr) == 0x12B58C);
    assert(sizeof(SpatialGrid) == 0x12B590);
}

static void test_valid_obstacle_array() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0, sizeof(SpatialGrid));

    func_001EE860(grid, 1, 0x12345678, 42);
    assert(grid->flag == 1);
    assert(grid->array_ptr == 0x12345678);
    assert(grid->count == 42);

    std::free(grid);
}

static void test_null_array_ptr_clears() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0xAA, sizeof(SpatialGrid));

    func_001EE860(grid, 1, 0, 10);
    assert(grid->flag == 0);
    assert(grid->array_ptr == 0);
    assert(grid->count == 0);

    std::free(grid);
}

static void test_non_positive_count_clears() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0xAA, sizeof(SpatialGrid));

    // count = 0
    func_001EE860(grid, 1, 0x5000, 0);
    assert(grid->flag == 0);
    assert(grid->array_ptr == 0);
    assert(grid->count == 0);

    // count = -1
    func_001EE860(grid, 1, 0x5000, -1);
    assert(grid->flag == 0);
    assert(grid->array_ptr == 0);
    assert(grid->count == 0);

    std::free(grid);
}

static void test_flag_zero_clears() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    assert(grid != nullptr);
    std::memset(grid, 0xAA, sizeof(SpatialGrid));

    func_001EE860(grid, 0, 0x5000, 20);
    assert(grid->flag == 0);
    assert(grid->array_ptr == 0);
    assert(grid->count == 0);

    std::free(grid);
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
        test_valid_obstacle_array();
        break;
    case 2:
        test_null_array_ptr_clears();
        break;
    case 3:
        test_non_positive_count_clears();
        break;
    case 4:
        test_flag_zero_clears();
        break;
    default:
        return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}

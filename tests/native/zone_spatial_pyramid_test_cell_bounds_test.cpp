#include <cassert>
#include <cstddef>
#include <cstring>
#include "zone_spatial_pyramid_test_cell_bounds.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static void test_test_cell_bounds_out_of_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 8;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 16;  // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 32;  // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 48; // max_y

    // At level 2 (>> 2): bounds are [2, 4, 8, 12]
    assert(func_001D40E0(zm, 2, 1, 5, 0.0f, 0.0f, 0.0f, 0.0f) == 0); // x < 2
    assert(func_001D40E0(zm, 2, 9, 5, 0.0f, 0.0f, 0.0f, 0.0f) == 0); // x > 8
    assert(func_001D40E0(zm, 2, 3, 3, 0.0f, 0.0f, 0.0f, 0.0f) == 0); // y < 4
    assert(func_001D40E0(zm, 2, 3, 13, 0.0f, 0.0f, 0.0f, 0.0f) == 0); // y > 12
}

static void test_test_cell_bounds_occupied_and_distance() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 0;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 0;   // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 100; // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 100; // max_y

    // Level 0: cell at (0, 0)
    // x = 0, y = 0
    char cell_occupied[4] = { 0x01, 0x00, 0x00, 0x00 };
    void *level0[1] = { cell_occupied };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    // Test with center at (0, 0), radius = 5.0f, radius_sq = 25.0f: should find hit (return 1)
    int res_hit = func_001D40E0(zm, 0, 0, 0, 0.0f, 0.0f, 5.0f, 25.0f);
    assert(res_hit == 1);

    // Test with center far away (100.0f, 100.0f), radius = 1.0f, radius_sq = 1.0f: should not hit (return 0)
    int res_miss = func_001D40E0(zm, 0, 0, 0, 100.0f, 100.0f, 1.0f, 1.0f);
    assert(res_miss == 0);
}

int main(int argc, char **argv) {
    test_test_cell_bounds_out_of_bounds();
    test_test_cell_bounds_occupied_and_distance();
    return 0;
}

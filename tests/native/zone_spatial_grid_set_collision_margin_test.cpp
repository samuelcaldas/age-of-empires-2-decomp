#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_set_collision_margin.h"

struct SpatialGridTest {
    char pad_00[0x12B59E];
    unsigned char has_margin;
    char pad_align;
    float margin;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    int case_id = std::atoi(argv[1]);
    SpatialGridTest *grid = (SpatialGridTest *)std::calloc(1, sizeof(SpatialGridTest));
    if (!grid) {
        return 2;
    }

    switch (case_id) {
        case 0: {
            // Test setting flag = 1 and positive float margin
            func_001EE900((SpatialGrid *)grid, 1, 3.5f);
            assert(grid->has_margin == 1);
            assert(std::fabs(grid->margin - 3.5f) < 1e-6f);
            break;
        }
        case 1: {
            // Test setting flag = 0 and zero float margin
            grid->has_margin = 1;
            grid->margin = 100.0f;
            func_001EE900((SpatialGrid *)grid, 0, 0.0f);
            assert(grid->has_margin == 0);
            assert(std::fabs(grid->margin - 0.0f) < 1e-6f);
            break;
        }
        case 2: {
            // Test byte truncation of flag and negative float margin
            func_001EE900((SpatialGrid *)grid, 0x105, -42.25f);
            assert(grid->has_margin == 0x05);
            assert(std::fabs(grid->margin - (-42.25f)) < 1e-6f);
            break;
        }
        default:
            std::free(grid);
            return 3;
    }

    std::free(grid);
    return 0;
}

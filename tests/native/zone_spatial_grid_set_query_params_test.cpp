#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_set_query_params.h"

struct SpatialGridTest {
    char pad_00[0x12B590];
    int param1;
    int param2;
    int param3;
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
            func_001EE8D0((SpatialGrid *)grid, 10, 20, 30);
            assert(grid->param1 == 10);
            assert(grid->param2 == 20);
            assert(grid->param3 == 30);
            break;
        }
        case 1: {
            grid->param1 = 100;
            grid->param2 = 200;
            grid->param3 = 300;
            func_001EE8D0((SpatialGrid *)grid, 0, 0, 0);
            assert(grid->param1 == 0);
            assert(grid->param2 == 0);
            assert(grid->param3 == 0);
            break;
        }
        case 2: {
            func_001EE8D0((SpatialGrid *)grid, -1, -100, 0x7FFFFFFF);
            assert(grid->param1 == -1);
            assert(grid->param2 == -100);
            assert(grid->param3 == 0x7FFFFFFF);
            break;
        }
        default:
            std::free(grid);
            return 3;
    }

    std::free(grid);
    return 0;
}

#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_set_obstacle_callback.h"

struct SpatialGridTest {
    char pad_00[0x12B5A4];
    void *callback_fn;
    void *callback_ctx;
};

static void dummy_cb() {}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    int case_id = std::atoi(argv[1]);
    SpatialGridTest *grid = (SpatialGridTest *)std::calloc(1, sizeof(SpatialGridTest));
    if (!grid) {
        return 2;
    }

    int dummy_ctx_val = 42;

    switch (case_id) {
        case 0: {
            func_001EE710((SpatialGrid *)grid, (void *)dummy_cb, (void *)&dummy_ctx_val);
            assert(grid->callback_fn == (void *)dummy_cb);
            assert(grid->callback_ctx == (void *)&dummy_ctx_val);
            break;
        }
        case 1: {
            grid->callback_fn = (void *)dummy_cb;
            grid->callback_ctx = (void *)&dummy_ctx_val;
            func_001EE710((SpatialGrid *)grid, NULL, NULL);
            assert(grid->callback_fn == NULL);
            assert(grid->callback_ctx == NULL);
            break;
        }
        case 2: {
            int new_ctx = 999;
            func_001EE710((SpatialGrid *)grid, (void *)dummy_cb, (void *)&new_ctx);
            assert(grid->callback_fn == (void *)dummy_cb);
            assert(grid->callback_ctx == (void *)&new_ctx);
            break;
        }
        default:
            std::free(grid);
            return 3;
    }

    std::free(grid);
    return 0;
}

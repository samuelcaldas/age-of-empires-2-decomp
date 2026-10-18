#include <cassert>
#include <cstring>
#include "zone_spatial_grid_eval_ray_hit.h"
#include "zone_spatial_grid_eval_cell_hit.h"

static int g_func_1F0330_called = 0;

extern "C" {
int func_1F0330(SpatialGrid *self, SpatialNode *node, void *p3) {
    g_func_1F0330_called++;
    return 1;
}
}

int main() {
    // Test 1: func_001F0630 - evaluation of ray hits
    g_func_1F0330_called = 0;
    int res_ray = func_001F0630(0, 0, 0);
    assert(res_ray >= 0);

    // Test 2: func_001F0A20 - evaluation of cell hits
    g_func_1F0330_called = 0;
    int res_cell = func_001F0A20(0, 0, 0);
    assert(res_cell >= 0);

    return 0;
}

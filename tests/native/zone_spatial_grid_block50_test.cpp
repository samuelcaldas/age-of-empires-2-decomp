#include <cassert>
#include <cstring>
#include <cmath>
#include "zone_spatial_grid_test_cell_items.h"
#include "zone_spatial_grid_test_cell_raycast.h"
#include "zone_spatial_grid_intersect_segments_2d.h"

static int g_func_1F0A10_called = 0;
static int g_func_1F1190_called = 0;

extern "C" {
int func_1F0A10(SpatialGrid *self, void *item, void *p3) {
    g_func_1F0A10_called++;
    return 1;
}

int func_1F1190(SpatialGrid *self, void *item, void *p3) {
    g_func_1F1190_called++;
    return 1;
}
}

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001EF410 - 2D line segment intersection
    // -------------------------------------------------------------
    // Line 1: (0, 0) to (10, 10)
    // Line 2: (0, 10) to (10, 0)
    // Expected intersection: (5, 5)
    float out_x = 0.0f;
    float out_y = 0.0f;
    func_001EF410(&out_x, &out_y, 0.0f, 0.0f, 10.0f, 10.0f, 0.0f, 10.0f, 10.0f, 0.0f);
    assert(std::fabs(out_x - 5.0f) < 0.001f);
    assert(std::fabs(out_y - 5.0f) < 0.001f);

    return 0;
}

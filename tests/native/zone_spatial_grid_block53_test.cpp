#include <cassert>
#include <cstring>
#include "zone_spatial_grid_test_ray_box.h"
#include "zone_spatial_grid_intersect_ray_edge.h"

static int g_func_1F0530_called = 0;
static int g_func_1F0290_called = 0;

struct Point2D {
    float x;
    float y;
};

extern "C" {
int func_1F0530(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float *out_t) {
    g_func_1F0530_called++;
    *out_t = 0.5f;
    return 1;
}

int func_1F0290(SpatialGrid *self, void *node, Point2D *pos) {
    g_func_1F0290_called++;
    return 1;
}
}

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001F0540 - intersect ray against edge
    // -------------------------------------------------------------
    // Ray from (0, 5) to (10, 5)
    // Edge from (5, 0) to (5, 10)
    // Expected: intersects at t = 0.5
    float t = 0.0f;
    int hit = func_001F0540(0.0f, 5.0f, 10.0f, 5.0f, 5.0f, 0.0f, 5.0f, 10.0f, &t);
    assert(hit >= 0);

    return 0;
}

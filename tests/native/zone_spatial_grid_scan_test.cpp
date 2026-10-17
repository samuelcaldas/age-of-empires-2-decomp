#include <cassert>
#include "zone_spatial_grid_scan_occupants.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static void test_point_in_polygon() {
    Point2D pts[4];
    pts[0].x = 0.0f; pts[0].y = 0.0f;
    pts[1].x = 10.0f; pts[1].y = 0.0f;
    pts[2].x = 10.0f; pts[2].y = 10.0f;
    pts[3].x = 0.0f; pts[3].y = 10.0f;

    Polygon poly;
    poly.num_points = 4;
    poly.points = pts;

    assert(func_001E4F50(&poly, 5.0f, 5.0f) == 1);
    assert(func_001E4F50(&poly, 15.0f, 5.0f) == 0);
    assert(func_001E4F50(&poly, -5.0f, 5.0f) == 0);
    assert(func_001E4F50(&poly, 5.0f, 15.0f) == 0);
}

int main(int argc, char **argv) {
    test_point_in_polygon();
    return 0;
}

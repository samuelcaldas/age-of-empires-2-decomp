#include <cassert>
#include <cstdio>
#include <cstring>

#include "zone_spatial_grid_scan_occupants.h"
#include "../../src/zone/zone_spatial_grid_scan_occupants.cpp"

int main() {
    Point2D pts[4] = {
        { 0.0f, 0.0f },
        { 10.0f, 0.0f },
        { 10.0f, 10.0f },
        { 0.0f, 10.0f }
    };

    Polygon poly;
    poly.num_points = 4;
    poly.points = pts;

    // Inside point
    assert(func_001E4F50(&poly, 5.0f, 5.0f) == 1);

    // Outside points
    assert(func_001E4F50(&poly, -1.0f, 5.0f) == 0);
    assert(func_001E4F50(&poly, 15.0f, 5.0f) == 0);
    assert(func_001E4F50(&poly, 5.0f, -1.0f) == 0);
    assert(func_001E4F50(&poly, 5.0f, 15.0f) == 0);

    printf("zone_spatial_grid_scan_occupants_test passed\n");
    return 0;
}

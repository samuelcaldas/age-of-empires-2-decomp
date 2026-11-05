#include <cassert>
#include <cstdio>
#include "zone_spatial_grid_scan_cross_occupants.h"

struct Vec2f {
    float x;
    float y;
};

struct SpatialGrid {
    int count;
    Vec2f *points;
};

static void test_empty() {
    SpatialGrid sg;
    sg.count = 0;
    sg.points = 0;
    float p1[2] = {1.0f, 2.0f};
    float p2[2] = {0.0f, 0.0f};
    int p3 = 0;

    int res = func_001E5A00(&sg, p1, p2, &p3);
    assert(res == 1);
}

static void test_polygon_scan() {
    SpatialGrid sg;
    Vec2f pts[4];
    pts[0].x = 0.0f; pts[0].y = 0.0f;
    pts[1].x = 10.0f; pts[1].y = 0.0f;
    pts[2].x = 10.0f; pts[2].y = 10.0f;
    pts[3].x = 0.0f; pts[3].y = 10.0f;

    sg.count = 4;
    sg.points = pts;

    float pt[2] = {5.0f, 5.0f};
    float out_pt[2] = {0.0f, 0.0f};
    int out_edge = -1;

    int res = func_001E5A00(&sg, pt, out_pt, &out_edge);
    assert(res == 1);
    assert(out_edge == 1); // edge (10,0)-(0,0) or (0,0)-(10,0)
    assert(out_pt[0] == 5.0f);
    assert(out_pt[1] == 0.0f);
}

int main() {
    test_empty();
    test_polygon_scan();
    std::printf("zone_spatial_grid_scan_cross_occupants_test passed\n");
    return 0;
}

#include <cassert>
#include "zone_spatial_grid_dispatch_edge.h"
#include "zone_spatial_grid_dispatch_edge_north.h"
#include "zone_spatial_grid_dispatch_edge_east.h"
#include "zone_spatial_grid_dispatch_edge_south.h"
#include "zone_spatial_grid_dispatch_edge_west.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

// Test doubles for the target functions
extern "C" {
static int s_called_target = -1;

unsigned char func_1E5510(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5) {
    s_called_target = 0;
    return 10;
}

unsigned char func_1E5620(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5) {
    s_called_target = 1;
    return 11;
}

unsigned char func_1E5730(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5) {
    s_called_target = 2;
    return 12;
}

unsigned char func_1E5840(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5) {
    s_called_target = 3;
    return 13;
}
}

static void test_dispatch_edge() {
    SpatialGrid sg;
    float p1[2] = {1.0f, 2.0f};
    float p3[2] = {0.0f, 0.0f};
    int p4 = 0, p5 = 0, p6 = 0;

    s_called_target = -1;
    unsigned char res = func_001E5460(&sg, p1, 0, p3, &p4, &p5, &p6);
    assert(s_called_target == 0);
    assert(res == 10);

    s_called_target = -1;
    res = func_001E5460(&sg, p1, 1, p3, &p4, &p5, &p6);
    assert(s_called_target == 1);
    assert(res == 11);

    s_called_target = -1;
    res = func_001E5460(&sg, p1, 2, p3, &p4, &p5, &p6);
    assert(s_called_target == 2);
    assert(res == 12);

    s_called_target = -1;
    res = func_001E5460(&sg, p1, 3, p3, &p4, &p5, &p6);
    assert(s_called_target == 3);
    assert(res == 13);

    s_called_target = -1;
    res = func_001E5460(&sg, p1, 4, p3, &p4, &p5, &p6);
    assert(s_called_target == -1);
    assert(res == 0);
}

static void test_edges() {
    SpatialGrid sg;
    SpatialGridItem items[2];
    sg.f20 = 2;
    sg.f28 = items;

    // Item 0: [0, 0] to [10, 10]
    items[0].minX = 0.0f;
    items[0].minY = 0.0f;
    items[0].maxX = 10.0f;
    items[0].maxY = 10.0f;
    items[0].f10 = 0;

    // Item 1: [20, 20] to [30, 30]
    items[1].minX = 20.0f;
    items[1].minY = 20.0f;
    items[1].maxX = 30.0f;
    items[1].maxY = 30.0f;
    items[1].f10 = 0;

    float pt[2];
    float out_pt[2];
    int out_t0 = -1;
    int out_t1 = -1;

    // Test north
    pt[0] = 5.0f;
    pt[1] = 15.0f;
    unsigned char m = func_001E5520(&sg, pt, -1, out_pt, &out_t0, &out_t1);
    assert(m == 1);
    assert(out_t0 == 0);
    assert(out_t1 == 0);
    assert(out_pt[0] == 5.0f);
    assert(out_pt[1] == 10.0f);

    // Test east
    pt[0] = 5.0f;
    pt[1] = -5.0f;
    m = func_001E5630(&sg, pt, -1, out_pt, &out_t0, &out_t1);
    assert(m == 1);
    assert(out_t0 == 0);
    assert(out_t1 == 2);
    assert(out_pt[0] == 5.0f);
    assert(out_pt[1] == 0.0f);

    // Test south
    pt[0] = 15.0f;
    pt[1] = 5.0f;
    m = func_001E5740(&sg, pt, -1, out_pt, &out_t0, &out_t1);
    assert(m == 1);
    assert(out_t0 == 0);
    assert(out_t1 == 1);
    assert(out_pt[0] == 10.0f);
    assert(out_pt[1] == 5.0f);

    // Test west
    pt[0] = -5.0f;
    pt[1] = 5.0f;
    m = func_001E5850(&sg, pt, -1, out_pt, &out_t0, &out_t1);
    assert(m == 1);
    assert(out_t0 == 0);
    assert(out_t1 == 3);
    assert(out_pt[0] == 0.0f);
    assert(out_pt[1] == 5.0f);
}

int main(int argc, char **argv) {
    test_dispatch_edge();
    test_edges();
    return 0;
}

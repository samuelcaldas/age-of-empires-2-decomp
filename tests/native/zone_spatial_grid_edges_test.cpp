#include <cassert>
#include "zone_spatial_grid_dispatch_edge_north.h"
#include "zone_spatial_grid_dispatch_edge_east.h"
#include "zone_spatial_grid_dispatch_edge_south.h"
#include "zone_spatial_grid_dispatch_edge_west.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

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
    test_edges();
    return 0;
}

#include <cassert>
#include "zone_spatial_grid_dispatch_edge_north.h"
#include "zone_spatial_grid_dispatch_edge_east.h"
#include "zone_spatial_grid_dispatch_edge_south.h"
#include "zone_spatial_grid_dispatch_edge_west.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialGrid {
    char pad[0x10];
};

static void test_stubs() {
    SpatialGrid sg;
    assert(func_001E5520(&sg, nullptr, nullptr, nullptr) == 0);
    assert(func_001E5630(&sg, nullptr, nullptr, nullptr) == 0);
    assert(func_001E5740(&sg, nullptr, nullptr, nullptr) == 0);
    assert(func_001E5850(&sg, nullptr, nullptr, nullptr) == 0);
}

int main(int argc, char **argv) {
    test_stubs();
    return 0;
}

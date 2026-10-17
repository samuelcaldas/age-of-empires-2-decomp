#include <cassert>
#include "zone_spatial_grid_query_bounded_area.h"
#include "zone_spatial_grid_scan_ring_perimeter.h"
#include "zone_spatial_grid_partition_area_query.h"
#include "zone_spatial_grid_filter_terrain_obstacle.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct MockSpatialGrid {
    char pad[0x1000];
};

static void test_bounded_area() {
    MockSpatialGrid grid;
    for (int i = 0; i < sizeof(grid); i++) ((char *)&grid)[i] = 0;
    func_001E7110((SpatialGrid *)&grid, 0, 0, 0, 0, 5.0f);
    func_001E7460((SpatialGrid *)&grid, 2.0f);
    func_001E7630((SpatialGrid *)&grid, 0, 0, 0, 0, 0, 5.0f);
}

int main(int argc, char **argv) {
    test_bounded_area();
    return 0;
}

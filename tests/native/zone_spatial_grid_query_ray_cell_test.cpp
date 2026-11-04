#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_query_ray_cell.h"

int main() {
    assert(func_001EC5B0(NULL, NULL, NULL, NULL, NULL, -2.0f, 0.0f) == 0);
    assert(func_001EC5B0(NULL, NULL, NULL, NULL, NULL, 0.0f, -2.0f) == 0);
    assert(func_001EC5B0(NULL, NULL, NULL, NULL, NULL, 10.0f, 10.0f) == 0);
    return 0;
}

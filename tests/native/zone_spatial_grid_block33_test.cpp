#include <cassert>
#include <cstring>
#include "zone_spatial_grid_execute_hierarchical_query.h"

extern "C" {
void func_1E7020(void *self, float margin) {}
}

int main() {
    struct DummyGrid {
        char pad_A4[0xA4];
        int min_x;
        int min_y;
        int max_x;
        int max_y;
    } dummy;
    dummy.min_x = 10;
    dummy.min_y = 20;
    dummy.max_x = 30;
    dummy.max_y = 40;

    int res = func_001E9160((SpatialGrid *)&dummy, 0, 0, 1, 0, nullptr, nullptr, nullptr, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, nullptr);
    assert(res == 0);
    assert(dummy.min_x == -1);
    assert(dummy.min_y == -1);
    assert(dummy.max_x == -1);
    assert(dummy.max_y == -1);
    return 0;
}

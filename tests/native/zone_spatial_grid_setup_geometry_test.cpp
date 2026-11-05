#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_grid_setup_geometry.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vec2f {
    float x;
    float y;
};

struct SpatialGrid {
    int f0;
    float *f4;
    char pad_08[0x8];
    Vec2f f10;
    Vec2f f18;
    int f20;
};

static int s_calls_1e5380 = 0;
static void *s_last_self = 0;
static int s_last_index = 0;

extern "C" {
int func_1E5380(void *self, int index) {
    s_calls_1e5380++;
    s_last_self = self;
    s_last_index = index;
    return 1;
}
}

static void test_setup_geometry_initializes_and_calls() {
    SpatialGrid grid;
    std::memset(&grid, 0xAA, sizeof(grid));

    float f4_buf[8];
    std::memset(f4_buf, 0, sizeof(f4_buf));
    grid.f4 = f4_buf;

    Vec2f p1 = { 10.0f, 20.0f };
    Vec2f p2 = { 30.0f, 40.0f };

    s_calls_1e5380 = 0;
    int ret = func_001E4150(&grid, &p1, &p2);

    assert(ret == 1);
    assert(grid.f0 == 0);
    assert(grid.f20 == 0);
    assert(grid.f10.x == 10.0f);
    assert(grid.f10.y == 20.0f);
    assert(grid.f18.x == 30.0f);
    assert(grid.f18.y == 40.0f);

    assert(s_calls_1e5380 == 1);
    assert(s_last_self == &grid);
    assert(s_last_index == 4);

    assert(f4_buf[0] == 30.0f);
    assert(f4_buf[1] == 40.0f);
    assert(f4_buf[2] == 30.0f);
    assert(f4_buf[3] == 20.0f);
    assert(f4_buf[4] == 10.0f);
    assert(f4_buf[5] == 20.0f);
    assert(f4_buf[6] == 10.0f);
    assert(f4_buf[7] == 40.0f);
}

int main() {
    test_setup_geometry_initializes_and_calls();
    std::printf("zone_spatial_grid_setup_geometry_test passed\n");
    return 0;
}

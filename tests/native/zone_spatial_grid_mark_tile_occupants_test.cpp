#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_mark_tile_occupants.h"

static int s_func_1E6EC0_calls = 0;
static void *s_last_self = NULL;
static int s_last_coord = 0;

extern "C" {
void func_1E6EC0(void *self, int packed_coord) {
    s_func_1E6EC0_calls++;
    s_last_self = self;
    s_last_coord = packed_coord;
}

void *func_332E60(void *world, void *item) { (void)world; (void)item; return NULL; }
float func_1234E0(float f, double d) { (void)d; return f; }
float func_1140C8(float f) { return f; }
float func_1228E8(float f) { return f; }
int func_113FB8(float f) { return (int)f; }
float func_123350(float f) { return f; }
}

struct SpatialGridMock {
    void *world;
};

int main() {
    SpatialGridMock grid;
    grid.world = NULL;

    SpatialGrid *self = reinterpret_cast<SpatialGrid *>(&grid);

    void *items[3] = {(void *)10, (void *)20, (void *)30};

    // Case 1: mode_flag == 0 -> nothing called
    func_001E6CC0(self, 0, items, 3, 0);
    assert(s_func_1E6EC0_calls == 0);

    // Case 2: mode_flag != 0 -> func_1E6EC0 called for each item
    func_001E6CC0(self, 1, items, 3, 0);
    assert(s_func_1E6EC0_calls == 3);
    assert(s_last_self == self);
    assert(s_last_coord == 30);

    return 0;
}

#include <cassert>
#include "zone_spatial_grid_reset_destructor.h"
#include "zone_spatial_grid_init_node.h"
#include "zone_spatial_grid_free_buffers.h"
#include "zone_spatial_grid_init_pyramid.h"
#include "zone_spatial_grid_leaf_helper.h"
#include "zone_spatial_grid_reset_pyramid.h"
#include "zone_spatial_grid_realloc_vector.h"
#include "zone_spatial_grid_transfer_bucket.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static void *g_last_p = 0;
static int g_last_flag = 0;

extern "C" void func_1FD400(void *p, int flag) {
    g_last_p = p;
    g_last_flag = flag;
}

struct MockSpatialGrid {
    char pad[0x1000];
};

static void test_grid_initialization() {
    MockSpatialGrid grid;
    for (int i = 0; i < sizeof(grid); i++) {
        ((char *)&grid)[i] = 0;
    }
    func_001E6540(&grid);
    assert(g_last_p == &grid);
    assert(g_last_flag == -1);
}

int main(int argc, char **argv) {
    test_grid_initialization();
    return 0;
}

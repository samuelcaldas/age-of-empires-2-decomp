#include <cassert>
#include <cstring>
#include "zone_spatial_grid_eval_node_hit.h"
#include "zone_spatial_grid_eval_edge_hit.h"

static int g_func_1F0330_called = 0;

extern "C" {
int func_1F0330(SpatialGrid *self, SpatialNode *node, void *p3) {
    g_func_1F0330_called++;
    return 1;
}
}

int main() {
    // Test 1: func_001F0E10 - eval node hit
    g_func_1F0330_called = 0;
    int res_node = func_001F0E10(0, 0, 0);
    assert(res_node >= 0);

    // Test 2: func_001F11A0 - eval edge hit
    g_func_1F0330_called = 0;
    int res_edge = func_001F11A0(0, 0, 0);
    assert(res_edge >= 0);

    return 0;
}

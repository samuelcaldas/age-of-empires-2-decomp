#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

struct NodePool;

static int g_func_118de0_calls = 0;
static int g_func_001F20E0_calls = 0;
static int g_func_001F20E0_val = 0;
static int g_func_001F21E0_calls = 0;
static void *g_func_001F21E0_p1 = NULL;

extern "C" {
void *func_118de0(const char *fmt, const char *file, int line) {
    g_func_118de0_calls++;
    return NULL;
}

void func_001F20E0(NodePool *self, int val) {
    g_func_001F20E0_calls++;
    g_func_001F20E0_val = val;
}

void func_001F21E0(NodePool *self, void *p1) {
    g_func_001F21E0_calls++;
    g_func_001F21E0_p1 = p1;
}
}

#include "../../src/zone/zone_spatial_grid_node_pool_setup.cpp"

int main() {
    NodePool pool;
    std::memset(&pool, 0xFF, sizeof(pool));

    int dummy = 42;
    func_001F1EE0(&pool, &dummy, 100);

    assert(pool.table_138810 == 0);
    assert(pool.table_138814 == 0);
    assert(pool.field_13881C == 1);
    assert(pool.count_138818 == 0);
    assert(pool.field_138820 == 0);
    assert(pool.field_138824 == -1);
    assert(pool.field_138828 == -1);
    assert(pool.field_13882C == 0);
    assert(pool.field_138830 == 0);
    assert(pool.capacity_138834 == 100);

    assert(g_func_118de0_calls == 1);
    assert(g_func_001F20E0_calls == 1);
    assert(g_func_001F20E0_val == 1);
    assert(g_func_001F21E0_calls == 1);
    assert(g_func_001F21E0_p1 == &dummy);

    std::printf("zone_spatial_grid_node_pool_setup_test passed\n");
    return 0;
}

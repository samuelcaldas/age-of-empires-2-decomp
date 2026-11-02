#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

static int g_func_117cac_calls = 0;
static void *g_last_dst = NULL;
static int g_last_val = -1;
static int g_last_size = 0;
static int g_func_118de0_calls = 0;

static void *g_mock_table0[32];
static void *g_mock_table1[32];

const char D_492750[] = "test_fmt";
const char D_492740[] = "test_file";

extern "C" {
void *func_117CAC(void *dst, int val, int size) {
    g_func_117cac_calls++;
    g_last_dst = dst;
    g_last_val = val;
    g_last_size = size;
    if (g_func_117cac_calls % 2 == 1) {
        return g_mock_table0;
    }
    return g_mock_table1;
}

void *func_118de0(const char *fmt, const char *file, int line, int val) {
    g_func_118de0_calls++;
    return NULL;
}
}

#include "../../src/zone/zone_spatial_grid_node_pool_expand.cpp"

int main() {
    NodePool pool;
    std::memset(&pool, 0, sizeof(pool));
    pool.field_13881C = 10;

    // Case 1: new_cap < field_13881C -> no op
    g_func_117cac_calls = 0;
    func_001F20E0(&pool, 5);
    assert(g_func_117cac_calls == 0);
    assert(pool.field_13881C == 10);

    // Case 2: new_cap >= field_13881C and table_138810 is NULL
    g_func_117cac_calls = 0;
    g_func_118de0_calls = 0;
    func_001F20E0(&pool, 12);
    assert(g_func_117cac_calls == 2);
    assert(g_func_118de0_calls == 0);
    assert(pool.field_13881C == 12);
    assert(pool.table_138810 == g_mock_table0);
    assert(pool.table_138814 == g_mock_table1);

    // Case 3: new_cap >= field_13881C and table_138810 is NOT NULL -> triggers func_118de0
    g_func_117cac_calls = 0;
    g_func_118de0_calls = 0;
    func_001F20E0(&pool, 15);
    assert(g_func_117cac_calls == 2);
    assert(g_func_118de0_calls == 1);
    assert(pool.field_13881C == 15);

    std::printf("zone_spatial_grid_node_pool_expand_test passed\n");
    return 0;
}

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

static int g_func_117cac_calls = 0;
static void *g_last_dst = NULL;
static int g_last_val = -1;
static int g_last_size = 0;

extern "C" void func_117CAC(void *dst, int val, int size) {
    g_func_117cac_calls++;
    g_last_dst = dst;
    g_last_val = val;
    g_last_size = size;
    std::memset(dst, val, size);
}

#include "../../src/zone/zone_spatial_grid_node_pool_clear.cpp"

int main() {
    NodePool pool;
    std::memset(&pool, 0, sizeof(pool));

    // Case 1: table_138810 is NULL and table_138814 is NULL
    g_func_117cac_calls = 0;
    func_001F2020(&pool);
    assert(g_func_117cac_calls == 0);

    // Case 2: table_138814 is non-null
    pool.table_138814 = (void *)0x1234;
    func_001F2020(&pool);
    assert(g_func_117cac_calls == 1);
    assert(g_last_size == 8);
    assert(g_last_dst == (char *)&pool + 8);

    // Case 3: table_138810 has entries
    void *tables[3];
    tables[0] = (void *)0x1;
    tables[1] = NULL;
    tables[2] = (void *)0x2;
    pool.table_138810 = tables;
    pool.count_138818 = 3;
    g_func_117cac_calls = 0;

    func_001F2020(&pool);
    // 2 non-null tables -> 2 calls with 0x138800 bytes
    // plus 1 call for self (8 bytes)
    // plus 1 call for table_138814 (8 bytes)
    // total 4 calls
    assert(g_func_117cac_calls == 4);

    // Case 4: func_001F2010 calls func_001F2020
    g_func_117cac_calls = 0;
    func_001F2010(&pool);
    assert(g_func_117cac_calls == 4);

    std::printf("zone_spatial_grid_node_pool_clear_test passed\n");
    return 0;
}

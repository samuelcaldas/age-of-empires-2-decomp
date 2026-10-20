#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_alloc_node.h"

static int g_func_1F21E0_called = 0;
static void *g_func_1F21E0_arg_self = 0;
static int g_func_1F21E0_arg_num_items = 0;

struct StrictNodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void **table_138814;
    int count_138818;
    int field_13881C;
    void *field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" {
void func_1F21E0(NodePool *self, int num_items) {
    g_func_1F21E0_called++;
    g_func_1F21E0_arg_self = self;
    g_func_1F21E0_arg_num_items = num_items;
    StrictNodePool *p = (StrictNodePool *)self;
    p->field_138830 += num_items;
}
}

int main() {
    // ABI layout verification
    assert(sizeof(StrictNodePool) >= 0x138838);
    assert(offsetof(StrictNodePool, buffer_10) == 0x10);
    assert(offsetof(StrictNodePool, table_138810) == 0x138810);
    assert(offsetof(StrictNodePool, table_138814) == 0x138814);
    assert(offsetof(StrictNodePool, count_138818) == 0x138818);
    assert(offsetof(StrictNodePool, field_13881C) == 0x13881C);
    assert(offsetof(StrictNodePool, field_138820) == 0x138820);
    assert(offsetof(StrictNodePool, field_138824) == 0x138824);
    assert(offsetof(StrictNodePool, field_138828) == 0x138828);
    assert(offsetof(StrictNodePool, field_13882C) == 0x13882C);
    assert(offsetof(StrictNodePool, field_138830) == 0x138830);
    assert(offsetof(StrictNodePool, capacity_138834) == 0x138834);

    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    // Case 1: Empty pool triggers expansion helper call
    pool->field_138830 = 0;
    pool->capacity_138834 = 500;
    pool->field_138824 = 0;
    pool->field_138828 = 0;
    pool->count_138818 = 1;

    char empty_mock_zone[64 * 4];
    memset(empty_mock_zone, 0xEE, sizeof(empty_mock_zone));
    void *empty_table0[1];
    void *empty_table1[1];
    empty_table0[0] = empty_mock_zone;
    empty_table1[0] = (void *)4;
    pool->table_138810 = empty_table0;
    pool->table_138814 = empty_table1;

    g_func_1F21E0_called = 0;
    g_func_1F21E0_arg_self = 0;
    g_func_1F21E0_arg_num_items = 0;

    void *expanded_node = func_001F2320((NodePool *)pool);
    assert(g_func_1F21E0_called == 1);
    assert(g_func_1F21E0_arg_self == (void *)pool);
    assert(g_func_1F21E0_arg_num_items == 500);
    assert(expanded_node == (void *)empty_mock_zone);
    assert(pool->field_138830 == 499); // 500 added by mock, 1 consumed
    assert(pool->field_138828 == 1);

    // Case 2: Pop from free-list when field_138820 is non-null
    void *recycled_node1[8];
    void *recycled_node2[8];
    memset(recycled_node1, 0, sizeof(recycled_node1));
    memset(recycled_node2, 0, sizeof(recycled_node2));
    *(void **)((char *)recycled_node1 + 12) = (void *)recycled_node2;
    pool->field_138820 = recycled_node1;
    pool->field_138830 = 2;

    void *got1 = func_001F2320((NodePool *)pool);
    assert(got1 == (void *)recycled_node1);
    assert(pool->field_138820 == (void *)recycled_node2);
    assert(pool->field_138830 == 1);

    void *got2 = func_001F2320((NodePool *)pool);
    assert(got2 == (void *)recycled_node2);
    assert(pool->field_138820 == 0);
    assert(pool->field_138830 == 0);

    // Case 3: Multi-zone transition across zones
    char mock_zone0[64 * 2];
    char mock_zone1[64 * 2];
    memset(mock_zone0, 0x11, sizeof(mock_zone0));
    memset(mock_zone1, 0x22, sizeof(mock_zone1));

    void *multi_table0[2];
    void *multi_table1[2];
    multi_table0[0] = mock_zone0;
    multi_table0[1] = mock_zone1;
    multi_table1[0] = (void *)2; // 2 nodes in zone 0
    multi_table1[1] = (void *)2; // 2 nodes in zone 1

    pool->table_138810 = multi_table0;
    pool->table_138814 = multi_table1;
    pool->count_138818 = 2; // 2 zones total
    pool->field_138820 = 0;
    pool->field_138824 = 0; // start in zone 0
    pool->field_138828 = 0;
    pool->field_138830 = 4;

    // Allocate first node from zone 0
    void *z0_n0 = func_001F2320((NodePool *)pool);
    assert(z0_n0 == (void *)mock_zone0);
    assert(pool->field_138824 == 0);
    assert(pool->field_138828 == 1);
    assert(pool->field_138830 == 3);

    // Allocate second node from zone 0 -> exhausts zone 0, transitions to zone 1
    void *z0_n1 = func_001F2320((NodePool *)pool);
    assert(z0_n1 == (void *)(mock_zone0 + 64));
    assert(pool->field_138824 == 1); // advanced to zone 1
    assert(pool->field_138828 == 0); // reset node index to 0
    assert(pool->field_138830 == 2);

    // Allocate first node from zone 1
    void *z1_n0 = func_001F2320((NodePool *)pool);
    assert(z1_n0 == (void *)mock_zone1);
    assert(pool->field_138824 == 1);
    assert(pool->field_138828 == 1);
    assert(pool->field_138830 == 1);

    // Allocate second node from zone 1 -> exhausts zone 1, field_138824 becomes -1
    void *z1_n1 = func_001F2320((NodePool *)pool);
    assert(z1_n1 == (void *)(mock_zone1 + 64));
    assert(pool->field_138824 == -1); // reached count_138818 (2 == 2), reset to -1
    assert(pool->field_138828 == 0);
    assert(pool->field_138830 == 0);

    delete pool;
    return 0;
}

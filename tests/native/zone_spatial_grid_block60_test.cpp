#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_alloc_node.h"

static int g_func_1F21E0_called = 0;
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
    g_func_1F21E0_arg_num_items = num_items;
    StrictNodePool *p = (StrictNodePool *)self;
    p->field_138830 += num_items;
}
}

int main() {
    // ABI verification
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

    // Case 1: Empty pool triggers func_1F21E0 expansion call
    pool->field_138830 = 0;
    pool->capacity_138834 = 500;
    g_func_1F21E0_called = 0;

    void *recycled_node1[8];
    void *recycled_node2[8];
    memset(recycled_node1, 0, sizeof(recycled_node1));
    memset(recycled_node2, 0, sizeof(recycled_node2));
    // Link recycled_node1 -> recycled_node2 at offset +12
    *(void **)((char *)recycled_node1 + 12) = (void *)recycled_node2;
    pool->field_138820 = recycled_node1;
    pool->field_138830 = 2;

    // Pop from free list
    void *got1 = func_001F2320((NodePool *)pool);
    assert(got1 == (void *)recycled_node1);
    assert(pool->field_138820 == (void *)recycled_node2);
    assert(pool->field_138830 == 1);

    void *got2 = func_001F2320((NodePool *)pool);
    assert(got2 == (void *)recycled_node2);
    assert(pool->field_138820 == 0);
    assert(pool->field_138830 == 0);

    // Case 2: Carving from active zone when free list is empty
    char mock_zone[64 * 4];
    memset(mock_zone, 0xAA, sizeof(mock_zone));
    void *mock_table0[2];
    void *mock_table1[2];
    mock_table0[0] = mock_zone;
    mock_table1[0] = (void *)2; // 2 nodes in zone 0
    pool->table_138810 = mock_table0;
    pool->table_138814 = mock_table1;
    pool->count_138818 = 1;
    pool->field_138820 = 0;
    pool->field_138824 = 0;
    pool->field_138828 = 0;
    pool->field_138830 = 2;

    void *carved0 = func_001F2320((NodePool *)pool);
    assert(carved0 == (void *)mock_zone);
    assert(pool->field_138828 == 1);
    assert(pool->field_138824 == 0);
    assert(pool->field_138830 == 1);

    void *carved1 = func_001F2320((NodePool *)pool);
    assert(carved1 == (void *)(mock_zone + 64));
    assert(pool->field_138828 == 0);
    assert(pool->field_138824 == -1); // exhausted zone 0 (0 == count_138818 - 1)
    assert(pool->field_138830 == 0);

    delete pool;
    return 0;
}

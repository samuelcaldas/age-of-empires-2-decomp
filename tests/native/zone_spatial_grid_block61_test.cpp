#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include "zone_spatial_grid_node_pool_free_node.h"

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

    // Case 1: Freeing first node to empty free-list
    char node1[64];
    memset(node1, 0xAA, sizeof(node1));
    *(void **)(node1 + 12) = (void *)0xDEADBEEF;

    pool->field_138820 = 0;
    pool->field_138830 = 0;

    func_001F24A0((NodePool *)pool, node1);

    assert(pool->field_138820 == (void *)node1);
    assert(*(void **)(node1 + 12) == 0);
    assert(pool->field_138830 == 1);

    // Verify node1 payload bytes [0..11] and [16..63] remain 0xAA
    for (int i = 0; i < 12; ++i) {
        assert((unsigned char)node1[i] == 0xAA);
    }
    for (int i = 16; i < 64; ++i) {
        assert((unsigned char)node1[i] == 0xAA);
    }

    // Case 2: Freeing second node onto existing free-list
    char node2[64];
    memset(node2, 0xBB, sizeof(node2));
    *(void **)(node2 + 12) = (void *)0xCAFEBABE;

    func_001F24A0((NodePool *)pool, node2);

    assert(pool->field_138820 == (void *)node2);
    assert(*(void **)(node2 + 12) == (void *)node1);
    assert(pool->field_138830 == 2);

    // Verify node2 payload bytes remain 0xBB
    for (int i = 0; i < 12; ++i) {
        assert((unsigned char)node2[i] == 0xBB);
    }
    for (int i = 16; i < 64; ++i) {
        assert((unsigned char)node2[i] == 0xBB);
    }

    delete pool;
    return 0;
}

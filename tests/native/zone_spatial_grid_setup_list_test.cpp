#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_setup_list.h"

struct MockListNode {
    void *elem;
    MockListNode *next;
    MockListNode *prev;
};

struct MockGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    MockListNode *field_14;
    int field_18;
    char pad_1C[0xAB0 - 0x1C];
    int field_AB0;
};

static std::vector<int> call_log;
static int observed_count = 0;
static int observed_size = 0;
static MockListNode *mock_alloc_return = 0;

extern "C" {
void *func_001143F8(int count, int size) {
    observed_count = count;
    observed_size = size;
    call_log.push_back(100);
    return reinterpret_cast<void *>(mock_alloc_return);
}
}

int main() {
    assert(offsetof(MockGrid, field_14) == 0x14);
    assert(offsetof(MockGrid, field_AB0) == 0xAB0);
    assert(offsetof(MockListNode, elem) == 0x00);
    assert(offsetof(MockListNode, next) == 0x04);
    assert(offsetof(MockListNode, prev) == 0x08);

    MockGrid grid;
    std::memset(&grid, 0, sizeof(grid));
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    MockListNode allocated_node;

    // Test Case 1: Allocation failure
    // func_001143F8 returns NULL -> func_001F2DA0 must return 0
    // field_14 is set to NULL, field_AB0 remains 0
    call_log.clear();
    mock_alloc_return = NULL;
    observed_count = 0;
    observed_size = 0;
    grid.field_14 = reinterpret_cast<MockListNode *>(0x12345678);
    grid.field_AB0 = 0;

    int res1 = func_001F2DA0(grid_ptr);
    assert(res1 == 0);
    assert(call_log.size() == 1);
    assert(call_log[0] == 100);
    assert(observed_count == 1);
    assert(observed_size == 12);
    assert(grid.field_14 == NULL);
    assert(grid.field_AB0 == 0);

    // Test Case 2: Allocation success
    // func_001143F8 returns valid node -> func_001F2DA0 must return 1
    // field_14 points to node, field_AB0 is set to 1
    // sentinel->elem == NULL, sentinel->next == sentinel, sentinel->prev == sentinel
    call_log.clear();
    std::memset(&allocated_node, 0xCC, sizeof(allocated_node));
    mock_alloc_return = &allocated_node;
    observed_count = 0;
    observed_size = 0;
    grid.field_14 = NULL;
    grid.field_AB0 = 0;

    int res2 = func_001F2DA0(grid_ptr);
    assert(res2 == 1);
    assert(call_log.size() == 1);
    assert(call_log[0] == 100);
    assert(observed_count == 1);
    assert(observed_size == 12);
    assert(grid.field_14 == &allocated_node);
    assert(grid.field_AB0 == 1);
    assert(allocated_node.elem == NULL);
    assert(allocated_node.next == &allocated_node);
    assert(allocated_node.prev == &allocated_node);

    return 0;
}

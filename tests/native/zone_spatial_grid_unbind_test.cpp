#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_unbind.h"

typedef void (*ItemMethod)(void *, int);

struct MockItem {
    ItemMethod *vtable;
    int id;
};

struct MockListNode {
    MockItem *elem;
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
};

static std::vector<int> call_log;
static MockListNode *mock_lookup_return = 0;
static void *observed_self = 0;
static void *observed_elem = 0;
static void *observed_free_ptr = 0;
static void *observed_method_self = 0;
static int observed_method_arg = 0;
static MockGrid *current_grid = 0;

static void item_slot_0(void *self, int val) {
    observed_method_self = self;
    observed_method_arg = val;
    call_log.push_back(8);
}

static ItemMethod mock_vtable[8];

extern "C" {
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *elem) {
    observed_self = self;
    observed_elem = elem;
    call_log.push_back(100);
    return reinterpret_cast<ListNode *>(mock_lookup_return);
}

void func_00116F68(void *ptr) {
    observed_free_ptr = ptr;
    call_log.push_back(200);
}
}

int main() {
    assert(offsetof(MockGrid, field_18) == 0x18);
    assert(offsetof(MockListNode, prev) == 0x08);
    assert(offsetof(MockListNode, next) == 0x04);
    assert(offsetof(MockListNode, elem) == 0x00);

    std::memset(mock_vtable, 0, sizeof(mock_vtable));
    mock_vtable[0] = item_slot_0; // direct slot 0
    mock_vtable[2] = item_slot_0; // raw offset 8 / slot 0 in Itanium/Metrowerks

    MockItem item;
    item.vtable = mock_vtable;
    item.id = 42;

    MockGrid grid;
    std::memset(&grid, 0, sizeof(grid));
    grid.field_18 = 5;
    current_grid = &grid;
    MockGrid expected_grid = grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: Early null exit on elem == NULL
    // Must return 0 with 0 calls, grid untouched
    call_log.clear();
    int res1 = func_001F2CB0(grid_ptr, NULL);
    assert(res1 == 0);
    assert(call_log.empty());
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Test Case 2: Early null exit on lookup failure
    // Must return 0, call func_001F2E00, but no method or free, grid untouched
    call_log.clear();
    mock_lookup_return = NULL;
    int dummy_elem = 123;
    int res2 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res2 == 0);
    assert(call_log.size() == 1);
    assert(call_log[0] == 100);
    assert(observed_self == grid_ptr);
    assert(observed_elem == &dummy_elem);
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Setup circular doubly-linked list: prev_node <-> target_node <-> next_node
    MockListNode prev_node;
    MockListNode target_node;
    MockListNode next_node;

    prev_node.next = &target_node;
    prev_node.prev = &next_node;
    prev_node.elem = NULL;

    target_node.next = &next_node;
    target_node.prev = &prev_node;
    target_node.elem = NULL;

    next_node.next = &prev_node;
    next_node.prev = &target_node;
    next_node.elem = NULL;

    // Test Case 3: Success path with node->elem == NULL (interior unlinking)
    // Must decrement field_18, unlink target_node, free target_node, return 1, NO method_08
    call_log.clear();
    mock_lookup_return = &target_node;
    observed_free_ptr = NULL;
    grid.field_18 = 5;

    int res3 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res3 == 1);
    assert(grid.field_18 == 4);
    assert(prev_node.next == &next_node);
    assert(next_node.prev == &prev_node);
    assert(observed_free_ptr == &target_node);
    assert(call_log.size() == 2);
    assert(call_log[0] == 100); // lookup
    assert(call_log[1] == 200); // free

    // Test Case 4: Success path with node->elem != NULL (interior unlinking)
    // Reset list and set target_node.elem = &item
    prev_node.next = &target_node;
    prev_node.prev = &next_node;
    target_node.next = &next_node;
    target_node.prev = &prev_node;
    target_node.elem = &item;
    next_node.next = &prev_node;
    next_node.prev = &target_node;

    call_log.clear();
    mock_lookup_return = &target_node;
    observed_free_ptr = NULL;
    observed_method_self = NULL;
    observed_method_arg = 0;
    grid.field_18 = 10;

    int res4 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res4 == 1);
    assert(grid.field_18 == 9);
    assert(prev_node.next == &next_node);
    assert(next_node.prev == &prev_node);
    assert(observed_method_self == &item);
    assert(observed_method_arg == 1);
    assert(observed_free_ptr == &target_node);

    // Call order strictly lookup -> method_08 -> free
    assert(call_log.size() == 3);
    assert(call_log[0] == 100); // func_001F2E00
    assert(call_log[1] == 8);   // item->method_08(1)
    assert(call_log[2] == 200); // func_00116F68

    // Test Case 5: Head unlinking (prev is sentinel node)
    MockListNode sentinel;
    MockListNode head_node;
    MockListNode tail_node;

    sentinel.next = &head_node;
    sentinel.prev = &tail_node;
    sentinel.elem = NULL;

    head_node.next = &tail_node;
    head_node.prev = &sentinel;
    head_node.elem = &item;

    tail_node.next = &sentinel;
    tail_node.prev = &head_node;
    tail_node.elem = NULL;

    call_log.clear();
    mock_lookup_return = &head_node;
    grid.field_18 = 7;
    int res5 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res5 == 1);
    assert(grid.field_18 == 6);
    assert(sentinel.next == &tail_node);
    assert(tail_node.prev == &sentinel);
    assert(observed_free_ptr == &head_node);

    // Test Case 6: Tail unlinking (next is sentinel node)
    sentinel.next = &head_node;
    sentinel.prev = &tail_node;
    head_node.next = &tail_node;
    head_node.prev = &sentinel;
    tail_node.next = &sentinel;
    tail_node.prev = &head_node;
    tail_node.elem = &item;

    call_log.clear();
    mock_lookup_return = &tail_node;
    grid.field_18 = 6;
    int res6 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res6 == 1);
    assert(grid.field_18 == 5);
    assert(head_node.next == &sentinel);
    assert(sentinel.prev == &head_node);
    assert(observed_free_ptr == &tail_node);

    // Test Case 7: Self-loop unlinking (single isolated node)
    MockListNode solo_node;
    solo_node.next = &solo_node;
    solo_node.prev = &solo_node;
    solo_node.elem = &item;

    call_log.clear();
    mock_lookup_return = &solo_node;
    grid.field_18 = 1;
    int res7 = func_001F2CB0(grid_ptr, &dummy_elem);
    assert(res7 == 1);
    assert(grid.field_18 == 0);
    assert(solo_node.next == &solo_node);
    assert(solo_node.prev == &solo_node);
    assert(observed_free_ptr == &solo_node);

    return 0;
}

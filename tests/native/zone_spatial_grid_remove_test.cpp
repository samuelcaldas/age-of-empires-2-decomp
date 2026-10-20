#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_remove.h"

struct ListNodeLayout {
    void *elem;
    ListNodeLayout *next;
    ListNodeLayout *prev;
};

struct GridTestLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    ListNodeLayout *field_14;
    int field_18;
};

static std::vector<int> call_log;
static void *last_f2e00_self = 0;
static void *last_f2e00_item = 0;
static void *mock_found_node = 0;
static void *last_f116f68_node = 0;

extern "C" {
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *item) {
    call_log.push_back(1);
    last_f2e00_self = self;
    last_f2e00_item = item;
    return reinterpret_cast<ListNode *>(mock_found_node);
}

void func_00116F68(void *node) {
    call_log.push_back(2);
    last_f116f68_node = node;
}
}

int main() {
    assert(sizeof(ListNodeLayout) == 12);
    assert(offsetof(GridTestLayout, field_14) == 20);
    assert(offsetof(GridTestLayout, field_18) == 24);

    GridTestLayout grid;
    ListNodeLayout sentinel;
    sentinel.elem = 0;
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;

    grid.vtable_00 = 0;
    grid.field_14 = &sentinel;
    grid.field_18 = 0;

    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);
    int entity1 = 42;

    // Test Case 1: elem is NULL
    // Must return 0 immediately without calling func_001F2E00 or func_00116F68
    call_log.clear();
    int res = func_001F2820(grid_ptr, 0);
    assert(res == 0);
    assert(call_log.empty());

    // Test Case 2: elem != NULL but not found (func_001F2E00 returns NULL)
    // Must return 0 without modifying list or freeing
    mock_found_node = 0;
    call_log.clear();
    res = func_001F2820(grid_ptr, &entity1);
    assert(res == 0);
    assert(call_log.size() == 1);
    assert(call_log[0] == 1);
    assert(last_f2e00_self == grid_ptr);
    assert(last_f2e00_item == &entity1);
    assert(grid.field_18 == 0);

    // Test Case 3: elem != NULL and found
    // Must decrement count, unlink node from sentinel ring, call func_00116F68, return 1
    ListNodeLayout target_node;
    target_node.elem = &entity1;
    target_node.next = &sentinel;
    target_node.prev = &sentinel;
    sentinel.next = &target_node;
    sentinel.prev = &target_node;
    grid.field_18 = 1;

    mock_found_node = &target_node;
    call_log.clear();
    last_f116f68_node = 0;

    res = func_001F2820(grid_ptr, &entity1);
    assert(res == 1);
    assert(call_log.size() == 2);
    assert(call_log[0] == 1); // func_001F2E00
    assert(call_log[1] == 2); // func_00116F68
    assert(last_f116f68_node == &target_node);
    assert(grid.field_18 == 0); // Count decremented from 1 to 0

    // Verify unlinked sentinel list
    assert(sentinel.next == &sentinel);
    assert(sentinel.prev == &sentinel);

    return 0;
}

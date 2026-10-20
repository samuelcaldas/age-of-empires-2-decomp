#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_contains.h"

struct MockItem {
    int id;
};

struct MockHandle {
    int handle_id;
};

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
};

static std::vector<int> call_log;
static MockHandle *mock_handle_return = 0;
static MockListNode *mock_lookup_return = 0;
static void *observed_extract_item = 0;
static void *observed_lookup_self = 0;
static void *observed_lookup_handle = 0;

extern "C" {
void *func_001F6CD0(SpatialItem *item) {
    observed_extract_item = item;
    call_log.push_back(100);
    return reinterpret_cast<void *>(mock_handle_return);
}

ListNode *func_001F2E00(ZoneSpatialGrid *self, void *handle) {
    observed_lookup_self = self;
    observed_lookup_handle = handle;
    call_log.push_back(200);
    return reinterpret_cast<ListNode *>(mock_lookup_return);
}
}

int main() {
    MockGrid grid;
    std::memset(&grid, 0xAA, sizeof(grid));
    MockGrid expected_grid = grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    MockItem item;
    item.id = 999;
    SpatialItem *item_ptr = reinterpret_cast<SpatialItem *>(&item);

    MockHandle handle;
    handle.handle_id = 777;

    MockListNode node;
    node.elem = &item;
    node.next = &node;
    node.prev = &node;

    // Test Case 1: item == NULL
    // Must return 0 with 0 calls; grid untouched
    call_log.clear();
    int res1 = func_001F2D50(grid_ptr, NULL);
    assert(res1 == 0);
    assert(call_log.empty());
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Test Case 2: item != NULL, lookup returns NULL (item not found)
    // Must return 0, call func_001F6CD0 then func_001F2E00; grid untouched
    call_log.clear();
    mock_handle_return = &handle;
    mock_lookup_return = NULL;
    observed_extract_item = NULL;
    observed_lookup_self = NULL;
    observed_lookup_handle = NULL;

    int res2 = func_001F2D50(grid_ptr, item_ptr);
    assert(res2 == 0);
    assert(call_log.size() == 2);
    assert(call_log[0] == 100); // func_001F6CD0
    assert(call_log[1] == 200); // func_001F2E00
    assert(observed_extract_item == item_ptr);
    assert(observed_lookup_self == grid_ptr);
    assert(observed_lookup_handle == &handle);
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Test Case 3: item != NULL, lookup returns valid node (item present)
    // Must return 1, call func_001F6CD0 then func_001F2E00; grid untouched
    call_log.clear();
    mock_handle_return = &handle;
    mock_lookup_return = &node;
    observed_extract_item = NULL;
    observed_lookup_self = NULL;
    observed_lookup_handle = NULL;

    int res3 = func_001F2D50(grid_ptr, item_ptr);
    assert(res3 == 1);
    assert(call_log.size() == 2);
    assert(call_log[0] == 100); // func_001F6CD0
    assert(call_log[1] == 200); // func_001F2E00
    assert(observed_extract_item == item_ptr);
    assert(observed_lookup_self == grid_ptr);
    assert(observed_lookup_handle == &handle);
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    return 0;
}

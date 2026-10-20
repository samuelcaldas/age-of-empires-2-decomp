#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_insert.h"

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
static void *last_f6cd0_elem = 0;
static void *last_f2e00_item = 0;
static void *mock_found_node = 0;
static void *mock_alloc_ptr = 0;
static void *last_f6ca0_elem = 0;
static int last_f6ca0_zero = -1;
static void *last_f2eb0_elem = 0;
static int last_f2eb0_param3 = -1;

extern "C" {
void *func_001F6CD0(void *elem) {
    call_log.push_back(1);
    last_f6cd0_elem = elem;
    return reinterpret_cast<void *>(reinterpret_cast<char *>(elem) + 1);
}

ListNode *func_001F2E00(ZoneSpatialGrid * /*self*/, void *item) {
    call_log.push_back(2);
    last_f2e00_item = item;
    return reinterpret_cast<ListNode *>(mock_found_node);
}

void *func_001143F8(int count, int size) {
    call_log.push_back(3);
    assert(count == 1);
    assert(size == 12);
    return mock_alloc_ptr;
}

void func_001F6CA0(void *elem, int zero) {
    call_log.push_back(4);
    last_f6ca0_elem = elem;
    last_f6ca0_zero = zero;
}

void func_001F2EB0(ZoneSpatialGrid * /*self*/, void *elem, int param3) {
    call_log.push_back(5);
    last_f2eb0_elem = elem;
    last_f2eb0_param3 = param3;
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
    int entity1 = 100;

    // Test Case 1: Item already present in grid (found_node != NULL)
    // Must NOT call new or f6ca0; if update_spatial == 1, calls f2eb0
    ListNodeLayout existing_node;
    mock_found_node = &existing_node;
    call_log.clear();

    int res = func_001F2730(grid_ptr, &entity1, 1, 999);
    assert(res == 1);
    assert(call_log.size() == 3);
    assert(call_log[0] == 1); // func_001F6CD0
    assert(call_log[1] == 2); // func_001F2E00
    assert(call_log[2] == 5); // func_001F2EB0
    assert(last_f2eb0_elem == &entity1);
    assert(last_f2eb0_param3 == 999);
    assert(grid.field_18 == 0); // Count not incremented

    // Test Case 2: Item not present, allocation fails (returns NULL)
    // Must return 0 immediately without mutating list or calling f6ca0
    mock_found_node = 0;
    mock_alloc_ptr = 0;
    call_log.clear();

    res = func_001F2730(grid_ptr, &entity1, 0, 0);
    assert(res == 0);
    assert(call_log.size() == 3);
    assert(call_log[0] == 1); // func_001F6CD0
    assert(call_log[1] == 2); // func_001F2E00
    assert(call_log[2] == 3); // func_001143F8
    assert(grid.field_18 == 0);
    assert(sentinel.next == &sentinel);

    // Test Case 3: Successful insertion into circular doubly-linked sentinel list
    ListNodeLayout new_node_buffer;
    std::memset(&new_node_buffer, 0, sizeof(new_node_buffer));
    mock_found_node = 0;
    mock_alloc_ptr = &new_node_buffer;
    call_log.clear();

    res = func_001F2730(grid_ptr, &entity1, 1, 777);
    assert(res == 1);
    assert(call_log.size() == 5);
    assert(call_log[0] == 1); // func_001F6CD0
    assert(call_log[1] == 2); // func_001F2E00
    assert(call_log[2] == 3); // func_001143F8
    assert(call_log[3] == 4); // func_001F6CA0
    assert(call_log[4] == 5); // func_001F2EB0
    assert(last_f6ca0_elem == &entity1);
    assert(last_f6ca0_zero == 0);
    assert(grid.field_18 == 1); // Count incremented to 1

    // Verify circular doubly-linked list structure
    assert(new_node_buffer.elem == &entity1);
    assert(sentinel.next == &new_node_buffer);
    assert(new_node_buffer.prev == &sentinel);
    assert(new_node_buffer.next == &sentinel);
    assert(sentinel.prev == &new_node_buffer);

    return 0;
}

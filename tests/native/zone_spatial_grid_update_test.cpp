#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_update.h"

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
    int field_1C;
};

static std::vector<int> call_log;
static void *last_f2e00_self = 0;
static void *last_f2e00_item = 0;
static void *mock_found_node = 0;
static int last_f65a0_val = 0;
static void *last_f2eb0_self = 0;
static void *last_f2eb0_elem = 0;
static int last_f2eb0_param2 = 0;

extern "C" {
ListNode *func_001F2E00(ZoneSpatialGrid *self, void *item) {
    call_log.push_back(1);
    last_f2e00_self = self;
    last_f2e00_item = item;
    return reinterpret_cast<ListNode *>(mock_found_node);
}

void func_001F65A0(int field_04) {
    call_log.push_back(2);
    last_f65a0_val = field_04;
}

void func_001F2EB0(ZoneSpatialGrid *self, void *elem, int param2) {
    call_log.push_back(3);
    last_f2eb0_self = self;
    last_f2eb0_elem = elem;
    last_f2eb0_param2 = param2;
}
}

int main() {
    assert(sizeof(ListNodeLayout) == 12);
    assert(offsetof(GridTestLayout, field_04) == 4);
    assert(offsetof(GridTestLayout, field_08) == 8);
    assert(offsetof(GridTestLayout, field_0C) == 12);

    GridTestLayout grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);
    int item_key = 42;
    int elem_entity = 100;

    // Test Case 1: node not found (func_001F2E00 returns NULL)
    // Must return 0 without calling func_001F65A0 or func_001F2EB0; fields 0x08 and 0x0C unchanged
    grid.field_04 = 10;
    grid.field_08 = 20;
    grid.field_0C = 30;
    mock_found_node = 0;
    call_log.clear();

    int res = func_001F2900(grid_ptr, &item_key, 555);
    assert(res == 0);
    assert(call_log.size() == 1);
    assert(call_log[0] == 1); // func_001F2E00
    assert(last_f2e00_self == grid_ptr);
    assert(last_f2e00_item == &item_key);
    assert(grid.field_08 == 20);
    assert(grid.field_0C == 30);

    // Test Case 2: node found and field_04 == 0
    // Must zero field_08 and field_0C, skip func_001F65A0, call func_001F2EB0, return 1
    ListNodeLayout found_node;
    found_node.elem = &elem_entity;
    found_node.next = 0;
    found_node.prev = 0;

    grid.field_04 = 0;
    grid.field_08 = 20;
    grid.field_0C = 30;
    mock_found_node = &found_node;
    call_log.clear();

    res = func_001F2900(grid_ptr, &item_key, 777);
    assert(res == 1);
    assert(call_log.size() == 2);
    assert(call_log[0] == 1); // func_001F2E00
    assert(call_log[1] == 3); // func_001F2EB0 (func_001F65A0 skipped)
    assert(last_f2eb0_self == grid_ptr);
    assert(last_f2eb0_elem == &elem_entity);
    assert(last_f2eb0_param2 == 777);
    assert(grid.field_08 == 0);
    assert(grid.field_0C == 0);

    // Test Case 3: node found and field_04 != 0
    // Must call func_001F65A0(field_04), zero field_08 and field_0C, call func_001F2EB0, return 1
    grid.field_04 = 12345;
    grid.field_08 = 88;
    grid.field_0C = 99;
    call_log.clear();

    res = func_001F2900(grid_ptr, &item_key, 888);
    assert(res == 1);
    assert(call_log.size() == 3);
    assert(call_log[0] == 1); // func_001F2E00
    assert(call_log[1] == 2); // func_001F65A0
    assert(call_log[2] == 3); // func_001F2EB0
    assert(last_f65a0_val == 12345);
    assert(last_f2eb0_self == grid_ptr);
    assert(last_f2eb0_elem == &elem_entity);
    assert(last_f2eb0_param2 == 888);
    assert(grid.field_08 == 0);
    assert(grid.field_0C == 0);

    return 0;
}

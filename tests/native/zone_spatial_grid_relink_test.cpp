#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_relink.h"

typedef void (*ItemMethod)(void *, int);
typedef void (*ManagerMethod)(void *, void *, int, int, int);

struct MockItem {
    ItemMethod *vtable;
};

struct MockManager {
    ManagerMethod *vtable;
};

struct GridRelinkLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    MockItem *field_10;
};

static std::vector<int> call_log;
static void *last_f6c90_elem = 0;
static void *mock_f6c90_return = 0;
static void *last_f6ca0_new = 0;
static void *last_f6ca0_old = 0;
static void *last_f6cd0_item = 0;
static void *last_f2cb0_self = 0;
static void *last_f2cb0_handle = 0;
static int item_method_10_calls = 0;
static int item_method_55_calls = 0;
static int manager_method_50_calls = 0;

static void item_slot_10(void * /*self*/, int val) {
    assert(val == 2);
    ++item_method_10_calls;
    call_log.push_back(10);
}

static void item_slot_55(void * /*self*/, int val) {
    assert(val == 1);
    ++item_method_55_calls;
    call_log.push_back(55);
}

static void manager_slot_50(void * /*self*/, void *p1, int p2, int p3, int p4) {
    assert(p1 == D_004D8940);
    assert(p2 == 0);
    assert(p3 == 0);
    assert(p4 == 0);
    ++manager_method_50_calls;
    call_log.push_back(50);
}

static ItemMethod mock_item_vtable[60];
static ManagerMethod mock_manager_vtable[60];

static MockManager mock_manager_inst;
GlobalManager *D_004D89C0 = reinterpret_cast<GlobalManager *>(&mock_manager_inst);
static int dummy_data = 0x1234;
void *D_004D8940 = &dummy_data;

extern "C" {
SpatialItem *func_001F6C90(SpatialItem *elem) {
    call_log.push_back(1);
    last_f6c90_elem = elem;
    return reinterpret_cast<SpatialItem *>(mock_f6c90_return);
}

void func_001F6CA0(SpatialItem *newItem, SpatialItem *oldItem) {
    call_log.push_back(2);
    last_f6ca0_new = newItem;
    last_f6ca0_old = oldItem;
}

void *func_001F6CD0(SpatialItem *item) {
    call_log.push_back(3);
    last_f6cd0_item = item;
    return item;
}

void func_001F2CB0(ZoneSpatialGrid *self, void *handle) {
    call_log.push_back(4);
    last_f2cb0_self = self;
    last_f2cb0_handle = handle;
}
}

int main() {
    assert(offsetof(GridRelinkLayout, field_10) == 16);

    std::memset(mock_item_vtable, 0, sizeof(mock_item_vtable));
    mock_item_vtable[8] = item_slot_10;
    mock_item_vtable[10] = item_slot_10;
    mock_item_vtable[53] = item_slot_55;
    mock_item_vtable[55] = item_slot_55;

    std::memset(mock_manager_vtable, 0, sizeof(mock_manager_vtable));
    mock_manager_vtable[48] = manager_slot_50;
    mock_manager_vtable[50] = manager_slot_50;
    mock_manager_inst.vtable = mock_manager_vtable;

    MockItem item1;
    item1.vtable = mock_item_vtable;
    MockItem item2;
    item2.vtable = mock_item_vtable;

    GridRelinkLayout grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: self->field_10 is NULL -> returns 0 immediately
    grid.field_10 = 0;
    call_log.clear();
    int res = func_001F2980(grid_ptr, 0);
    assert(res == 0);
    assert(call_log.empty());

    // Test Case 2: func_001F6C90 returns NULL or same item -> returns 0
    grid.field_10 = &item1;
    mock_f6c90_return = 0;
    call_log.clear();
    res = func_001F2980(grid_ptr, 0);
    assert(res == 0);
    assert(call_log.size() == 1);
    assert(call_log[0] == 1); // func_001F6C90

    mock_f6c90_return = &item1; // same item
    call_log.clear();
    res = func_001F2980(grid_ptr, 0);
    assert(res == 0);
    assert(call_log.size() == 1);

    // Test Case 3: flag == 0 (direct binding via func_001F6CA0)
    mock_f6c90_return = &item2;
    call_log.clear();
    item_method_10_calls = 0;
    item_method_55_calls = 0;
    manager_method_50_calls = 0;

    res = func_001F2980(grid_ptr, 0);
    assert(res == 1);
    assert(grid.field_10 == &item2); // Updated to newItem
    assert(last_f6ca0_new == &item2);
    assert(last_f6ca0_old == &item1);
    assert(item_method_55_calls == 1);
    assert(item_method_10_calls == 1);
    assert(manager_method_50_calls == 1);

    // Test Case 4: flag != 0 (re-linking with func_001F2CB0 and func_001F6CD0)
    grid.field_10 = &item1;
    mock_f6c90_return = &item2;
    call_log.clear();
    item_method_10_calls = 0;
    item_method_55_calls = 0;
    manager_method_50_calls = 0;

    res = func_001F2980(grid_ptr, 1);
    assert(res == 1);
    assert(grid.field_10 == &item2);
    assert(last_f2cb0_self == grid_ptr);
    assert(last_f2cb0_handle == &item1);
    assert(item_method_55_calls == 1);
    assert(item_method_10_calls == 1);
    assert(manager_method_50_calls == 1);

    return 0;
}

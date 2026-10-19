#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_advance.h"

typedef void (*ItemMethod)(void *, int);

struct MockItem {
    ItemMethod *vtable;
    int id;
};

struct GridAdvanceLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    MockItem *field_0C;
    MockItem *field_10;
    void *field_14;
    int field_18;
    void *field_1C;
};

static std::vector<int> call_log;
static MockItem *mock_cb_return = 0;
static int method_55_arg = 0;
static void *method_55_self = 0;
static void *setter_ab0_item = 0;
static void *setter_ac0_item = 0;
static GridAdvanceLayout *observed_grid = 0;
static MockItem *expected_current_item = 0;
static MockItem *expected_next_item = 0;
static SpatialItem *lookup_item = 0;

static void item_slot_55(void *self, int val) {
    assert(observed_grid->field_0C == expected_current_item);
    method_55_self = self;
    method_55_arg = val;
    call_log.push_back(55);
}

static ItemMethod mock_vtable[60];

extern "C" {
SpatialItem *func_001F6CB0(SpatialItem *item) {
    assert(item == reinterpret_cast<SpatialItem *>(expected_current_item));
    assert(observed_grid->field_0C == expected_current_item);
    lookup_item = item;
    call_log.push_back(100);
    return reinterpret_cast<SpatialItem *>(mock_cb_return);
}

void func_001F2AB0(ZoneSpatialGrid *self, SpatialItem *item) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid));
    assert(item == reinterpret_cast<SpatialItem *>(expected_next_item));
    assert(observed_grid->field_0C == expected_current_item);
    call_log.push_back(201);
    setter_ab0_item = item;
}

void func_001F2AC0(ZoneSpatialGrid *self, SpatialItem *item) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(observed_grid));
    assert(item == reinterpret_cast<SpatialItem *>(expected_next_item));
    assert(observed_grid->field_0C == expected_current_item);
    call_log.push_back(202);
    setter_ac0_item = item;
}
}

int main() {
    assert(offsetof(GridAdvanceLayout, field_0C) == 0x0C);

    std::memset(mock_vtable, 0, sizeof(mock_vtable));
    mock_vtable[53] = item_slot_55; // GCC Itanium vtable[53]
    mock_vtable[55] = item_slot_55; // Raw offset 220 (0xDC)

    MockItem item1;
    item1.vtable = mock_vtable;
    item1.id = 1;

    MockItem item2;
    item2.vtable = mock_vtable;
    item2.id = 2;

    GridAdvanceLayout grid;
    std::memset(&grid, 0, sizeof(grid));
    observed_grid = &grid;
    grid.field_04 = 0x12345678;
    grid.field_08 = 0x23456789;
    grid.field_10 = &item2;
    grid.field_14 = &grid;
    grid.field_18 = 0x34567890;
    grid.field_1C = &item1;
    GridAdvanceLayout expected_grid = grid;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: First null guard - self->field_0C == 0
    // Must return 0 immediately with zero calls
    call_log.clear();
    grid.field_0C = 0;
    int res1 = func_001F2C20(grid_ptr);
    assert(res1 == 0);
    assert(call_log.empty());
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Test Case 2: Second null guard - func_001F6CB0 returns NULL
    // Must return 0 with no method_55, no setters, field_0C unchanged
    call_log.clear();
    grid.field_0C = &item1;
    expected_current_item = &item1;
    mock_cb_return = 0;
    int res2 = func_001F2C20(grid_ptr);
    assert(res2 == 0);
    assert(grid.field_0C == &item1);
    assert(lookup_item == reinterpret_cast<SpatialItem *>(&item1));
    assert(call_log.size() == 1);
    assert(call_log[0] == 100); // Only func_001F6CB0 called
    expected_grid.field_0C = &item1;
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Test Case 3: Success path - func_001F6CB0 returns &item2
    // Must call item2->method_DC(1), func_001F2AB0(self, item2), func_001F2AC0(self, item2),
    // update field_0C = item2, and return 1
    call_log.clear();
    grid.field_0C = &item1;
    expected_current_item = &item1;
    expected_next_item = &item2;
    mock_cb_return = &item2;
    method_55_self = 0;
    method_55_arg = 0;
    setter_ab0_item = 0;
    setter_ac0_item = 0;

    int res3 = func_001F2C20(grid_ptr);
    assert(res3 == 1);
    assert(grid.field_0C == &item2);
    assert(method_55_self == &item2);
    assert(method_55_arg == 1);
    assert(setter_ab0_item == &item2);
    assert(setter_ac0_item == &item2);
    expected_grid.field_0C = &item2;
    assert(std::memcmp(&grid, &expected_grid, sizeof(grid)) == 0);

    // Call order verification: 100 -> 55 -> 201 -> 202
    assert(call_log.size() == 4);
    assert(call_log[0] == 100);
    assert(call_log[1] == 55);
    assert(call_log[2] == 201);
    assert(call_log[3] == 202);

    call_log.clear();
    grid.field_0C = &item2;
    expected_current_item = &item2;
    int repeated_result = func_001F2C20(grid_ptr);
    assert(repeated_result == 1);
    assert(grid.field_0C == &item2);
    assert(lookup_item == reinterpret_cast<SpatialItem *>(&item2));
    assert(call_log.size() == 4);
    assert(call_log[0] == 100);
    assert(call_log[1] == 55);
    assert(call_log[2] == 201);
    assert(call_log[3] == 202);

    return 0;
}

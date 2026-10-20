#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_bounds.h"

typedef void (*ItemMethod)(void *, int);

struct MockHandle {
    char pad_00[0x3C];
    int field_3C;
};

struct MockItem {
    ItemMethod *vtable;
    char pad_04[0x3C]; // offset 0x04..0x40
    MockHandle *field_40; // offset 0x40 (64)
    char pad_44[0x48]; // offset 0x44..0x8C
    int field_8C; // offset 0x8C (140)
};

struct GridBoundsLayout {
    void *vtable_00;
    int field_04;
    int field_08;
    MockItem *field_0C;
    MockItem *field_10;
    void *field_14;
    int field_18;
    MockHandle *field_1C;
};

static std::vector<int> call_log;
static void *last_f6cc0_elem = 0;
static void *last_f6750_handle = 0;
static int item_method_55_calls = 0;

static void item_slot_55(void * /*self*/, int val) {
    assert(val == 1);
    ++item_method_55_calls;
    call_log.push_back(55);
}

static ItemMethod mock_vtable[60];

extern "C" {
void func_001F6CC0(SpatialItem *elem, ...) {
    call_log.push_back(1);
    last_f6cc0_elem = elem;
}

void func_001F6750(void *handle, ...) {
    call_log.push_back(2);
    last_f6750_handle = handle;
}
}

int main() {
    assert(offsetof(MockItem, field_40) == 0x40);
    assert(offsetof(MockItem, field_8C) == 0x8C);
    assert(offsetof(MockHandle, field_3C) == 0x3C);
    assert(offsetof(GridBoundsLayout, field_0C) == 0x0C);
    assert(offsetof(GridBoundsLayout, field_10) == 0x10);
    assert(offsetof(GridBoundsLayout, field_1C) == 0x1C);

    std::memset(mock_vtable, 0, sizeof(mock_vtable));
    mock_vtable[53] = item_slot_55; // GCC Itanium
    mock_vtable[55] = item_slot_55; // Raw offset 220 (0xDC)

    MockHandle handle1;
    handle1.field_3C = reinterpret_cast<int>(&handle1);

    MockItem item1;
    std::memset(&item1, 0, sizeof(item1));
    item1.vtable = mock_vtable;
    item1.field_40 = &handle1;
    item1.field_8C = 0;

    MockItem item2;
    std::memset(&item2, 0, sizeof(item2));
    item2.vtable = mock_vtable;
    item2.field_40 = 0; // null handle triggers method_55
    item2.field_8C = 0;

    GridBoundsLayout grid;
    std::memset(&grid, 0, sizeof(grid));
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: Initial set of field_0C with handle != NULL
    // field_0C is NULL initially -> no func_001F6CC0 called
    // elem has handle1 -> field_1C set to handle1.field_3C, func_001F6750 called
    call_log.clear();
    func_001F2AD0(grid_ptr, reinterpret_cast<SpatialItem *>(&item1));

    assert(grid.field_0C == &item1);
    assert(grid.field_1C == reinterpret_cast<MockHandle *>(handle1.field_3C));
    assert(call_log.size() == 1);
    assert(call_log[0] == 2); // func_001F6750 called

    // Test Case 2: Transition from item1 to item2 (null handle)
    // item1 was set -> func_001F6CC0 called with item2
    // item2 has null field_40 -> method_55 invoked, field_1C set to 0
    call_log.clear();
    item_method_55_calls = 0;
    func_001F2AD0(grid_ptr, reinterpret_cast<SpatialItem *>(&item2));

    assert(grid.field_0C == &item2);
    assert(grid.field_1C == 0);
    assert(item_method_55_calls == 1);
    assert(call_log.size() == 3);
    assert(call_log[0] == 1); // func_001F6CC0(&item2)
    assert(call_log[1] == 2); // func_001F6750(old handle)
    assert(call_log[2] == 55); // method_55 on item2

    // Test Case 3: Passing NULL elem
    // Resets field_0C to NULL, frees prior handle if present
    call_log.clear();
    func_001F2AD0(grid_ptr, 0);
    assert(grid.field_0C == 0);
    assert(grid.field_1C == 0);

    return 0;
}

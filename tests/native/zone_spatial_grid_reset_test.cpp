#include <cassert>
#include <cstdarg>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_reset.h"

struct MockItem {
    int id;
};

struct GridResetLayout {
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
static void *last_f6cc0_item1 = 0;
static void *last_f6cc0_item2 = 0;
static void *field_0c_at_call_time = 0;
static GridResetLayout *observed_grid = 0;

extern "C" {
void func_001F6CC0(SpatialItem *item, ...) {
    call_log.push_back(1);
    last_f6cc0_item1 = item;
    va_list args;
    va_start(args, item);
    last_f6cc0_item2 = va_arg(args, void *);
    va_end(args);
    if (observed_grid) {
        field_0c_at_call_time = observed_grid->field_0C;
    }
}
}

int main() {
    assert(offsetof(GridResetLayout, field_0C) == 0x0C);
    assert(offsetof(GridResetLayout, field_10) == 0x10);

    MockItem item1;
    item1.id = 1;

    MockItem item2;
    item2.id = 2;

    GridResetLayout grid;
    std::memset(&grid, 0, sizeof(grid));
    grid.field_0C = &item1;
    grid.field_10 = &item2;
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: field_0C != 0 and field_0C != field_10
    // Must call func_001F6CC0(field_10, field_0C) before field_0C is reset
    observed_grid = &grid;
    call_log.clear();
    last_f6cc0_item1 = 0;
    last_f6cc0_item2 = 0;
    field_0c_at_call_time = 0;
    func_001F2BD0(grid_ptr);

    assert(grid.field_0C == &item2);
    assert(call_log.size() == 1);
    assert(call_log[0] == 1);
    assert(last_f6cc0_item1 == &item2);
    assert(last_f6cc0_item2 == &item1);
    assert(field_0c_at_call_time == &item1); // call order: must be called before field_0C is updated

    // Test Case 2: field_0C == field_10 (already reset)
    // No call to func_001F6CC0, field_0C remains field_10
    call_log.clear();
    func_001F2BD0(grid_ptr);

    assert(grid.field_0C == &item2);
    assert(call_log.empty());

    // Test Case 3: field_0C == 0
    // No call to func_001F6CC0, field_0C reset to field_10
    grid.field_0C = 0;
    call_log.clear();
    func_001F2BD0(grid_ptr);

    assert(grid.field_0C == &item2);
    assert(call_log.empty());

    return 0;
}

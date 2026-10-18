#include <cassert>
#include <cstring>
#include "zone_spatial_grid_filter_items.h"
#include "zone_spatial_grid_get_instance.h"
#include "zone_spatial_grid_reset_query_state.h"
#include "zone_spatial_grid_release_or_cleanup.h"
#include "zone_spatial_grid_clear_tables.h"

static int g_func_367470_called = 0;
static SpatialItem *g_last_pruned_item = 0;
static SpatialItemList *g_current_list = 0;

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;

static int g_func_1ED1F0_called = 0;
static int g_func_117CAC_called = 0;
static int g_func_1EE850_called = 0;
static int g_func_1EE8C0_called = 0;
static int g_func_1EE8F0_called = 0;

extern "C" {
void func_367470(SpatialItem *item) {
    g_func_367470_called++;
    g_last_pruned_item = item;
    if (g_current_list) {
        for (int i = 0; i < g_current_list->count; ++i) {
            if (g_current_list->items[i] == item) {
                for (int j = i; j < g_current_list->count - 1; ++j) {
                    g_current_list->items[j] = g_current_list->items[j + 1];
                }
                g_current_list->count--;
                break;
            }
        }
    }
}

void func_100670(void *ptr) {
    g_func_100670_called++;
    g_last_deleted_ptr = ptr;
}

void func_1ED1F0(SpatialGridState *self) {
    g_func_1ED1F0_called++;
}

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}

void func_1EE850(void *self, int p1, int p2, int p3) {
    g_func_1EE850_called++;
}

void func_1EE8C0(void *self, int p1, int p2, int p3) {
    g_func_1EE8C0_called++;
}

void func_1EE8F0(void *self, int p1, float p2) {
    g_func_1EE8F0_called++;
}
}

struct DummyGridFull {
    char pad[0x12B41C];
    char field_12B41C;
    char pad_align[3];
    int field_12B420;
    int field_12B424;
    int field_12B428;
    int field_12B42C;
    int field_12B430;
    int field_12B434;
    int field_12B438;
    int field_12B43C;
    int field_12B440;
    int field_12B444;
    int field_12B448;
    int field_12B44C;
    char buffer_12B450[0x80];
    char buffer_12B4D0[0xA0];
    int field_12B570;
    int field_12B574;
    int field_12B578;
    int field_12B57C;
    int field_12B580;
    char pad_12B584[0x20];
    int field_12B5A4;
    int field_12B5A8;
    int field_12B5AC;
    int field_12B5B0;
};

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001ED0E0 - filter items by type 0x3C
    // -------------------------------------------------------------
    SpatialItem item1;
    SpatialItem item2;
    SpatialItem item3;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));
    memset(&item3, 0, sizeof(item3));
    item1.type = 0x3C;
    item2.type = 0x10;
    item3.type = 0x3C;

    SpatialItem *item_ptrs[3] = { &item1, &item2, &item3 };
    SpatialItemList list;
    list.items = item_ptrs;
    list.count = 3;

    g_current_list = &list;
    g_func_367470_called = 0;
    func_001ED0E0(&list);
    assert(g_func_367470_called == 2);
    assert(g_last_pruned_item == &item3);
    assert(list.count == 1);
    assert(list.items[0] == &item2);

    // Empty list: no calls
    list.count = 0;
    g_func_367470_called = 0;
    func_001ED0E0(&list);
    assert(g_func_367470_called == 0);

    // -------------------------------------------------------------
    // Test 2: func_001ED150 - identity / get instance
    // -------------------------------------------------------------
    void *dummy_ptr = (void *)0xDEADBEEF;
    assert(func_001ED150(dummy_ptr) == dummy_ptr);
    assert(func_001ED150(0) == 0);

    // -------------------------------------------------------------
    // Test 3: func_001ED160 - reset query state
    // -------------------------------------------------------------
    DummyGridFull grid;
    memset(&grid, 0x55, sizeof(grid));
    g_func_1ED1F0_called = 0;
    func_001ED160((SpatialGridState *)&grid);
    assert(g_func_1ED1F0_called == 1);
    assert(grid.field_12B5B0 == -2);
    assert(grid.field_12B574 == -1);

    // -------------------------------------------------------------
    // Test 4: func_001ED1B0 - deleting destructor / release
    // -------------------------------------------------------------
    g_func_100670_called = 0;
    // When self is null: does not call delete
    void *res_null = func_001ED1B0(0, 1);
    assert(res_null == 0);
    assert(g_func_100670_called == 0);

    // When flag <= 0: does not call delete
    void *obj = (void *)0xCAFEBABE;
    void *res_noflag = func_001ED1B0(obj, 0);
    assert(res_noflag == obj);
    assert(g_func_100670_called == 0);

    // When flag > 0: calls delete(self) and returns self
    void *res_delete = func_001ED1B0(obj, 1);
    assert(res_delete == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // -------------------------------------------------------------
    // Test 5: func_001ED200 - clear spatial grid tables
    // -------------------------------------------------------------
    memset(&grid, 0xFF, sizeof(grid));
    g_func_117CAC_called = 0;
    g_func_1EE850_called = 0;
    g_func_1EE8C0_called = 0;
    g_func_1EE8F0_called = 0;

    func_001ED200((SpatialGridTables *)&grid);
    assert(grid.field_12B41C == 0);
    assert(grid.field_12B420 == 0);
    assert(grid.field_12B424 == 0);
    assert(grid.field_12B428 == 0);
    assert(grid.field_12B42C == 0);
    assert(grid.field_12B430 == 0);
    assert(grid.field_12B434 == 0);
    assert(grid.field_12B438 == 0);
    assert(grid.field_12B43C == 0);
    assert(grid.field_12B440 == 0);
    assert(grid.field_12B444 == 0);
    assert(grid.field_12B448 == 0);
    assert(grid.field_12B44C == 0);
    assert(grid.field_12B570 == 0);
    assert(grid.field_12B574 == -1);
    assert(grid.field_12B578 == 0);
    assert(grid.field_12B57C == 0);
    assert(grid.field_12B580 == 0);
    assert(grid.field_12B5A4 == 0);
    assert(grid.field_12B5A8 == 0);
    assert(grid.field_12B5AC == 0);
    assert(g_func_117CAC_called >= 2);
    assert(g_func_1EE850_called == 1);
    assert(g_func_1EE8C0_called == 1);
    assert(g_func_1EE8F0_called == 1);

    return 0;
}

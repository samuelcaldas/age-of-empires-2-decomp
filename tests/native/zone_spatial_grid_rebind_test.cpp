#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_rebind.h"

typedef void (*ItemMethod)(void *, int);
typedef void (*MgrMethod)(void *, void *, int, int, int);

struct MockItem {
    ItemMethod *vtable;
    int id;
};

struct MockMgr {
    MgrMethod *vtable;
    int id;
};

struct MockGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    MockItem *field_10;
    void *field_14;
    int field_18;
};

static std::vector<int> call_log;
static void *observed_bind_new = 0;
static void *observed_bind_old = 0;
static void *observed_reset_self = 0;
static void *observed_mgr_self = 0;
static void *observed_mgr_ctx = 0;
static int observed_mgr_a = -1;
static int observed_mgr_b = -1;
static int observed_mgr_c = -1;

static std::vector<std::pair<void *, int> > observed_method_dc_calls;
static std::vector<std::pair<void *, int> > observed_method_28_calls;

static void item_slot_55(void *self, int val) {
    call_log.push_back(55);
    observed_method_dc_calls.push_back(std::make_pair(self, val));
}

static void item_slot_10(void *self, int val) {
    call_log.push_back(10);
    observed_method_28_calls.push_back(std::make_pair(self, val));
}

static void mgr_slot_50(void *self, void *ctx, int a, int b, int c) {
    call_log.push_back(50);
    observed_mgr_self = self;
    observed_mgr_ctx = ctx;
    observed_mgr_a = a;
    observed_mgr_b = b;
    observed_mgr_c = c;
}

static ItemMethod mock_item_vtable[60];
static MgrMethod mock_mgr_vtable[60];

GlobalManager *D_004D89C0 = 0;
void *D_004D8940 = 0;
int D_004D8E18 = 0;

extern "C" {
void func_001F6CA0(SpatialItem *newItem, SpatialItem *oldItem) {
    call_log.push_back(100);
    observed_bind_new = newItem;
    observed_bind_old = oldItem;
}

void func_001F2BD0(ZoneSpatialGrid *self) {
    call_log.push_back(200);
    observed_reset_self = self;
}
}

int main() {
    assert(offsetof(MockGrid, field_10) == 0x10);

    std::memset(mock_item_vtable, 0, sizeof(mock_item_vtable));
    mock_item_vtable[8] = item_slot_10;  // raw offset 0x28 (40 bytes / 4 = 10; slot 8 in GCC)
    mock_item_vtable[10] = item_slot_10;
    mock_item_vtable[53] = item_slot_55; // raw offset 0xDC (220 bytes / 4 = 55; slot 53 in GCC)
    mock_item_vtable[55] = item_slot_55;

    std::memset(mock_mgr_vtable, 0, sizeof(mock_mgr_vtable));
    mock_mgr_vtable[48] = mgr_slot_50;  // raw offset 0xC8 (200 bytes / 4 = 50; slot 48 in GCC)
    mock_mgr_vtable[50] = mgr_slot_50;

    MockItem item1;
    item1.vtable = mock_item_vtable;
    item1.id = 1;
    SpatialItem *item1_ptr = reinterpret_cast<SpatialItem *>(&item1);

    MockItem item2;
    item2.vtable = mock_item_vtable;
    item2.id = 2;
    SpatialItem *item2_ptr = reinterpret_cast<SpatialItem *>(&item2);

    MockMgr mgr;
    mgr.vtable = mock_mgr_vtable;
    mgr.id = 99;

    char dummy_ctx[] = "context";
    D_004D89C0 = reinterpret_cast<GlobalManager *>(&mgr);
    D_004D8940 = dummy_ctx;
    D_004D8E18 = 0;

    MockGrid grid;
    std::memset(&grid, 0, sizeof(grid));
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    // Test Case 1: Null old occupant (field_10 == NULL), item2 == 0 (no reset)
    // func_001F6CA0(item1, NULL) called; no old method_DC; field_10 = item1;
    // item1->method_DC(1); item1->method_28(2); D_004D8E18 = 1; mgr->method_C8; no reset.
    call_log.clear();
    observed_bind_new = NULL;
    observed_bind_old = NULL;
    observed_reset_self = NULL;
    observed_method_dc_calls.clear();
    observed_method_28_calls.clear();
    D_004D8E18 = 0;
    grid.field_10 = NULL;

    func_001F2EB0(grid_ptr, item1_ptr, 0);

    assert(observed_bind_new == item1_ptr);
    assert(observed_bind_old == NULL);
    assert(grid.field_10 == &item1);
    assert(D_004D8E18 == 1);

    assert(observed_reset_self == NULL);
    assert(observed_mgr_self == &mgr);
    assert(observed_mgr_ctx == dummy_ctx);
    assert(observed_mgr_a == 0 && observed_mgr_b == 0 && observed_mgr_c == 0);

    // Notifications: only new item notified (method_DC(1) and method_28(2))
    assert(observed_method_dc_calls.size() == 1);
    assert(observed_method_dc_calls[0].first == &item1 && observed_method_dc_calls[0].second == 1);
    assert(observed_method_28_calls.size() == 1);
    assert(observed_method_28_calls[0].first == &item1 && observed_method_28_calls[0].second == 2);

    // Call order: 100 (bind) -> 55 (DC) -> 10 (28) -> 50 (mgr)
    assert(call_log.size() == 4);
    assert(call_log[0] == 100);
    assert(call_log[1] == 55);
    assert(call_log[2] == 10);
    assert(call_log[3] == 50);

    // Test Case 2: Non-null old occupant (field_10 == &item1), item2 != 0 (reset invoked)
    // Old item gets method_DC(0); new item gets method_DC(1) and method_28(2); reset called
    call_log.clear();
    observed_bind_new = NULL;
    observed_bind_old = NULL;
    observed_reset_self = NULL;
    observed_method_dc_calls.clear();
    observed_method_28_calls.clear();
    D_004D8E18 = 0;
    grid.field_10 = &item1;

    func_001F2EB0(grid_ptr, item2_ptr, 1);

    assert(observed_bind_new == item2_ptr);
    assert(observed_bind_old == item1_ptr);
    assert(grid.field_10 == &item2);
    assert(observed_reset_self == grid_ptr);
    assert(D_004D8E18 == 1);

    // Notifications: old item got DC(0), new item got DC(1) and 28(2)
    assert(observed_method_dc_calls.size() == 2);
    assert(observed_method_dc_calls[0].first == &item1 && observed_method_dc_calls[0].second == 0);
    assert(observed_method_dc_calls[1].first == &item2 && observed_method_dc_calls[1].second == 1);
    assert(observed_method_28_calls.size() == 1);
    assert(observed_method_28_calls[0].first == &item2 && observed_method_28_calls[0].second == 2);

    // Call order: 100 (bind) -> 55 (old DC) -> 55 (new DC) -> 10 (new 28) -> 50 (mgr) -> 200 (reset)
    assert(call_log.size() == 6);
    assert(call_log[0] == 100);
    assert(call_log[1] == 55);
    assert(call_log[2] == 55);
    assert(call_log[3] == 10);
    assert(call_log[4] == 50);
    assert(call_log[5] == 200);

    // Test Case 3: Same occupant (item1 == oldItem)
    // Old occupant notification DC(0) on item1, then new occupant notifications DC(1) and 28(2) on same item1
    call_log.clear();
    observed_method_dc_calls.clear();
    observed_method_28_calls.clear();
    observed_reset_self = NULL;
    grid.field_10 = &item1;

    func_001F2EB0(grid_ptr, item1_ptr, 0);

    assert(observed_method_dc_calls.size() == 2);
    assert(observed_method_dc_calls[0].first == &item1 && observed_method_dc_calls[0].second == 0);
    assert(observed_method_dc_calls[1].first == &item1 && observed_method_dc_calls[1].second == 1);
    assert(observed_method_28_calls.size() == 1);
    assert(observed_method_28_calls[0].first == &item1 && observed_method_28_calls[0].second == 2);
    assert(observed_reset_self == NULL);

    // Test Case 4: D_004D89C0 == NULL (manager disabled)
    // Manager notification and D_004D8E18 write must be skipped
    call_log.clear();
    D_004D89C0 = NULL;
    D_004D8E18 = 0;
    grid.field_10 = NULL;

    func_001F2EB0(grid_ptr, item1_ptr, 0);

    assert(D_004D8E18 == 0);
    // Call log has only bind (100), new DC (55), new 28 (10) -- no 50!
    assert(call_log.size() == 3);
    assert(call_log[0] == 100);
    assert(call_log[1] == 55);
    assert(call_log[2] == 10);

    return 0;
}

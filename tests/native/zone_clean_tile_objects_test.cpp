#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CE3B0(
    void *self, void *a1, int y, int x,
    int filter_type, int flag_delete_mode, int range_min, int range_max
);

static int g_func_1cf350_calls = 0;
static int g_func_1d09c0_calls = 0;
static int g_vtable31_calls = 0;
static int g_method15_calls = 0;
static int g_mock_placement_err = 0;

int func_1CF350(void *self, int x, int y) {
    g_func_1cf350_calls++;
    return 1;
}

void func_1D09C0(void *self, void *cell, int index) {
    g_func_1d09c0_calls++;
}

static void mock_delete_vtable31(void *item) {
    g_vtable31_calls++;
}

static int mock_method15_placement_check(
    void *item_info, void *player, int a2, int a3, int t0, int t1, int t2, int t3,
    float pos_x, float pos_y, long long s0, long long s1, long long s2, long long s3
) {
    g_method15_calls++;
    return g_mock_placement_err;
}
}

static void *g_vtable_item[35] = {};
static void *g_comp_vtable[20] = {};

struct DummyItemInfo {
    char pad[8];
    short val;
    char pad2[0x96];
    void *comp;
};

struct DummyItem {
    void **vtable;
    DummyItemInfo *info;
    void *player;
    char pad[0x38];
    float pos_x;
    float pos_y;
};

static void reset_test_state() {
    g_func_1cf350_calls = 0; g_func_1d09c0_calls = 0;
    g_vtable31_calls = 0; g_method15_calls = 0;
    g_mock_placement_err = 0;
    g_vtable_item[31] = (void *)&mock_delete_vtable31;
    g_comp_vtable[15] = (void *)&mock_method15_placement_check;
}

static void setup_zone(
    char *zone_mem, char *cell_mem, char *comp_mem, void *item_ptrs[4]
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(cell_mem, 0, 28);
    std::memset(comp_mem, 0, 0x40);

    *reinterpret_cast<void **>(comp_mem) = g_comp_vtable;

    static char *row_ptrs[8];
    row_ptrs[2] = cell_mem - 4 * 28; // row 2, col 4 -> cell_mem
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    *reinterpret_cast<void ***>(cell_mem + 0x14) = item_ptrs;
    *reinterpret_cast<unsigned char *>(cell_mem + 0xD) = 1; // 1 item
}

static void test_filter_neg1_deletes_via_1d09c0() {
    reset_test_state();
    char zone_mem[0x10000], cell_mem[28], comp_mem[0x40];
    DummyItemInfo info = {}; info.val = 55; info.comp = comp_mem;
    DummyItem item = {g_vtable_item, &info, nullptr, {}, 10.0f, 20.0f};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone(zone_mem, cell_mem, comp_mem, items);

    int ret = func_001CE3B0(zone_mem, nullptr, 2, 4, -1, 0, 10, 100);

    assert(ret == 55);
    assert(g_func_1cf350_calls == 1);
    assert(g_func_1d09c0_calls == 1);
    assert(g_vtable31_calls == 0);
}

static void test_filter_match_placement_valid_preserves_item() {
    reset_test_state();
    char zone_mem[0x10000], cell_mem[28], comp_mem[0x40];
    DummyItemInfo info = {}; info.val = 33; info.comp = comp_mem;
    DummyItem item = {g_vtable_item, &info, nullptr, {}, 15.0f, 25.0f};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone(zone_mem, cell_mem, comp_mem, items);

    // Filter table 3 has table_id = 33
    char *filter_table = zone_mem + 3 * 416;
    *reinterpret_cast<short *>(filter_table + 0x228) = 1;
    *reinterpret_cast<short *>(filter_table + 0x192) = 33;

    g_mock_placement_err = 0; // placement valid
    int ret = func_001CE3B0(zone_mem, nullptr, 2, 4, 3, 1, 10, 100);

    assert(ret == 33);
    assert(g_method15_calls == 1);
    assert(g_func_1d09c0_calls == 0);
    assert(g_vtable31_calls == 0);
}

static void test_filter_match_placement_invalid_deletes_via_vtable31() {
    reset_test_state();
    char zone_mem[0x10000], cell_mem[28], comp_mem[0x40];
    DummyItemInfo info = {}; info.val = 33; info.comp = comp_mem;
    DummyItem item = {g_vtable_item, &info, nullptr, {}, 15.0f, 25.0f};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone(zone_mem, cell_mem, comp_mem, items);

    char *filter_table = zone_mem + 3 * 416;
    *reinterpret_cast<short *>(filter_table + 0x228) = 1;
    *reinterpret_cast<short *>(filter_table + 0x192) = 33;

    g_mock_placement_err = 1; // placement error -> delete!
    int ret = func_001CE3B0(zone_mem, nullptr, 2, 4, 3, 1, 10, 100);

    assert(ret == 33);
    assert(g_method15_calls == 1);
    assert(g_func_1d09c0_calls == 0);
    assert(g_vtable31_calls == 1); // deleted via vtable[31]
}

static void test_out_of_range_or_empty_cell_returns_neg1() {
    reset_test_state();
    char zone_mem[0x10000], cell_mem[28], comp_mem[0x40];
    DummyItemInfo info = {}; info.val = 5; // < range_min (10)
    DummyItem item = {g_vtable_item, &info, nullptr, {}, 0.0f, 0.0f};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone(zone_mem, cell_mem, comp_mem, items);

    int ret = func_001CE3B0(zone_mem, nullptr, 2, 4, -1, 0, 10, 100);
    assert(ret == -1);
    assert(g_func_1d09c0_calls == 0);

    // Empty cell
    *reinterpret_cast<unsigned char *>(cell_mem + 0xD) = 0;
    ret = func_001CE3B0(zone_mem, nullptr, 2, 4, -1, 0, 10, 100);
    assert(ret == -1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "placement_valid") {
        test_filter_match_placement_valid_preserves_item();
    } else if (argc > 1 && std::string(argv[1]) == "placement_invalid") {
        test_filter_match_placement_invalid_deletes_via_vtable31();
    } else if (argc > 1 && std::string(argv[1]) == "out_of_range") {
        test_out_of_range_or_empty_cell_returns_neg1();
    } else {
        test_filter_neg1_deletes_via_1d09c0();
        test_filter_match_placement_valid_preserves_item();
        test_filter_match_placement_invalid_deletes_via_vtable31();
        test_out_of_range_or_empty_cell_returns_neg1();
    }
    return 0;
}

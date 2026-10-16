#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CDF30(
    void *self, void *player, int a2, int y, int x,
    int filter_type, int flag_delete_mode, int range_min, int range_max
);

static int g_func_1cf350_calls = 0;
static int g_func_1d09c0_calls = 0;
static int g_func_1aab30_calls = 0;
static int g_vtable31_calls = 0;
static int g_method15_calls = 0;
static int g_method13_calls = 0;
static float g_last_placed_x = 0.0f;
static float g_last_placed_y = 0.0f;

int func_1CF350(void *self, int x, int y) {
    g_func_1cf350_calls++;
    return 1; // terrain 1
}

void func_1D09C0(void *self, void *cell, int index) {
    g_func_1d09c0_calls++;
}

int func_1AAB30() {
    g_func_1aab30_calls++;
    return 16383; // mid-range random value (~0.5f)
}

static void mock_delete_vtable31(void *item) {
    g_vtable31_calls++;
}

static int mock_method15_placement_check(
    void *entity, void *player, int a2, int a3, int t0, int t1, int t2, int t3,
    float pos_x, float pos_y, long long s0, long long s1
) {
    g_method15_calls++;
    return 0; // 0 = can place
}

static void mock_method13_place_entity(
    void *entity, void *player, float pos_x, float pos_y, float z
) {
    g_method13_calls++;
    g_last_placed_x = pos_x;
    g_last_placed_y = pos_y;
}
}

static void *g_vtable_item[35] = {};
static void *g_comp_vtable[20] = {};

// Test structures
struct DummyItemInfo { char pad[8]; short val; };
struct DummyItem { void **vtable; DummyItemInfo *info; void *player; };

static void reset_test_state() {
    g_func_1cf350_calls = 0; g_func_1d09c0_calls = 0; g_func_1aab30_calls = 0;
    g_vtable31_calls = 0; g_method15_calls = 0; g_method13_calls = 0;
    g_last_placed_x = 0.0f; g_last_placed_y = 0.0f;
    g_vtable_item[31] = (void *)&mock_delete_vtable31;
    g_comp_vtable[15] = (void *)&mock_method15_placement_check;
    g_comp_vtable[13] = (void *)&mock_method13_place_entity;
}

static void setup_zone_and_player(
    char *zone_mem, char *player_mem, char *cell_mem,
    void *dummy_entity, char *comp_mem, void *item_ptrs[4]
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(player_mem, 0, 0x200);
    std::memset(cell_mem, 0, 28);
    std::memset(comp_mem, 0, 0x40);

    *reinterpret_cast<void **>(comp_mem) = g_comp_vtable;
    *reinterpret_cast<void **>(reinterpret_cast<char *>(dummy_entity) + 0xA0) = comp_mem;

    static void *entity_table[16] = {};
    entity_table[0] = dummy_entity;
    *reinterpret_cast<void ***>(player_mem + 0x70) = entity_table;

    static char *row_ptrs[8];
    row_ptrs[3] = cell_mem - 2 * 28; // row 3, col 2 -> cell_mem
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    *reinterpret_cast<void ***>(cell_mem + 0x14) = item_ptrs;
    *reinterpret_cast<unsigned char *>(cell_mem + 0xD) = 1; // 1 item

    char *table1 = zone_mem + 1 * 416; // terrain 1
    *reinterpret_cast<short *>(table1 + 0x228) = 1; // 1 object type
    *reinterpret_cast<short *>(table1 + 0x192) = 0; // obj_id = 0
    *reinterpret_cast<unsigned char *>(table1 + 0x20A) = 1; // mode 1 (centered)
    *reinterpret_cast<short *>(table1 + 0x1CE) = 1000; // density 1000
}

static void test_flow_mode1_center_and_delete0() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], cell_mem[28], comp_mem[0x40], entity_mem[0x100];
    DummyItemInfo info = {}; info.val = 50;
    DummyItem item = {g_vtable_item, &info, player_mem};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone_and_player(zone_mem, player_mem, cell_mem, entity_mem, comp_mem, items);

    // Call with filter_type = -1, flag_delete_mode = 0, range = [10, 100]
    func_001CDF30(zone_mem, player_mem, 0, 3, 2, -1, 0, 10, 100);

    assert(g_func_1cf350_calls == 1);
    assert(g_func_1d09c0_calls == 1); // deleted item via 1D09C0
    assert(g_vtable31_calls == 0);
    assert(g_method15_calls == 1); // placed entity
    assert(g_method13_calls == 1);
    // Mode 1: exactly centered at (x + 0.5f, y + 0.5f) = (2.5f, 3.5f)
    assert(std::fabs(g_last_placed_x - 2.5f) < 0.001f);
    assert(std::fabs(g_last_placed_y - 3.5f) < 0.001f);
}

static void test_flow_mode0_jitter_and_delete1() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], cell_mem[28], comp_mem[0x40], entity_mem[0x100];
    DummyItemInfo info = {}; info.val = 75;
    DummyItem item = {g_vtable_item, &info, player_mem};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone_and_player(zone_mem, player_mem, cell_mem, entity_mem, comp_mem, items);
    // Set mode 0 (jittered) in terrain table
    *reinterpret_cast<unsigned char *>(zone_mem + 1 * 416 + 0x20A) = 0;

    // Call with flag_delete_mode = 1 -> uses vtable[31]
    func_001CDF30(zone_mem, player_mem, 0, 3, 2, -1, 1, 10, 100);

    assert(g_func_1d09c0_calls == 0);
    assert(g_vtable31_calls == 1); // deleted via vtable[31]
    assert(g_method15_calls == 1);
    assert(g_method13_calls == 1);
    // Mode 0 with random value 16383: 2.0f + 16383/32767.0f ~= 2.5f
    assert(g_func_1aab30_calls >= 2);
    assert(g_last_placed_x > 2.0f && g_last_placed_x < 3.0f);
}

static void test_filter_match_skips_deletion() {
    reset_test_state();
    char zone_mem[0x10000], player_mem[0x200], cell_mem[28], comp_mem[0x40], entity_mem[0x100];
    DummyItemInfo info = {}; info.val = 42;
    DummyItem item = {g_vtable_item, &info, player_mem};
    void *items[4] = {&item, nullptr, nullptr, nullptr};

    setup_zone_and_player(zone_mem, player_mem, cell_mem, entity_mem, comp_mem, items);

    // Setup filter_type = 2 in zone_mem: has table_id = 42
    char *filter_table = zone_mem + 2 * 416;
    *reinterpret_cast<short *>(filter_table + 0x228) = 1;
    *reinterpret_cast<short *>(filter_table + 0x192) = 42;

    func_001CDF30(zone_mem, player_mem, 0, 3, 2, 2, 0, 10, 100);

    // Item matched filter table, so it must NOT be deleted
    assert(g_func_1d09c0_calls == 0);
    assert(g_vtable31_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "jitter_delete1") {
        test_flow_mode0_jitter_and_delete1();
    } else if (argc > 1 && std::string(argv[1]) == "filter_skip") {
        test_filter_match_skips_deletion();
    } else {
        test_flow_mode1_center_and_delete0();
        test_flow_mode0_jitter_and_delete1();
        test_filter_match_skips_deletion();
    }
    return 0;
}

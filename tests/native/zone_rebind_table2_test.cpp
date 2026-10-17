#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CDE30(void *self);

static int g_parse_calls = 0;
static int g_alloc_item_calls = 0;
static int g_ctor_item_calls = 0;
static int g_free_calls = 0;
static std::string g_last_ext;

extern const char D_00492518[] = ".shp";
static char g_dummy_temp[32] = "parsed.shp";

void func_1EB780(void **out_str, void *src_str, const char *ext) {
    g_parse_calls++;
    g_last_ext = ext;
    *out_str = g_dummy_temp;
}

static char g_items_pool[32][0x14];
static int g_item_idx = 0;

void *func_25F2B0(int size) {
    g_alloc_item_calls++;
    assert(size == 0x14);
    assert(g_item_idx < 32);
    void *item = g_items_pool[g_item_idx++];
    std::memset(item, 0, 0x14);
    return item;
}

void func_25D6D0(void *item, void *parsed_str, void *a8) {
    g_ctor_item_calls++;
    assert(parsed_str == g_dummy_temp);
    // By default, set bit 1 in f_13 (0x2)
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(item) + 0x13) = 0x2;
}

void func_116F68(void *ptr) {
    g_free_calls++;
    assert(ptr == g_dummy_temp);
}
}

// Memory buffer layout: offset 0x3400 starts table 2 with 16 entries * 1440 bytes
static const size_t TABLE2_OFFSET = 0x3400;
static const size_t ENTRY_STRIDE = 1440;
static const size_t BUFFER_SIZE = TABLE2_OFFSET + 16 * ENTRY_STRIDE + 0x100;
static char g_zone_mem[BUFFER_SIZE];

static void reset_test_state() {
    g_parse_calls = 0; g_alloc_item_calls = 0; g_ctor_item_calls = 0;
    g_free_calls = 0; g_item_idx = 0; g_last_ext.clear();
    std::memset(g_zone_mem, 0, sizeof(g_zone_mem));
}

static char *get_table2_entry(size_t index) {
    return g_zone_mem + TABLE2_OFFSET + index * ENTRY_STRIDE;
}

static void test_rebind_flow() {
    reset_test_state();

    // Entry 0 (index 0): active (0x8C = 1), f_B0 = 0x12345678 (should be cleared to 0)
    char *e0 = get_table2_entry(0);
    e0[0x8C] = 1;
    *reinterpret_cast<int *>(e0 + 0xB0) = 0x12345678;

    // Entry 5 (index 5): active (0x8C = 1), f_B0 = 0x87654321
    char *e5 = get_table2_entry(5);
    e5[0x8C] = 1;
    *reinterpret_cast<int *>(e5 + 0xB0) = 0x87654321;

    // Entry 15 (index 15): inactive (0x8C = 0), f_B0 = 0x99999999
    char *e15 = get_table2_entry(15);
    e15[0x8C] = 0;
    *reinterpret_cast<int *>(e15 + 0xB0) = 0x99999999;

    func_001CDE30(g_zone_mem);

    // Only active entries (e0 and e5) triggered parse, alloc, ctor
    assert(g_parse_calls == 2);
    assert(g_alloc_item_calls == 2);
    assert(g_ctor_item_calls == 2);
    assert(g_free_calls == 1);
    assert(g_last_ext == ".shp");

    // Both active entries had f_B0 cleared to 0
    assert(*reinterpret_cast<int *>(e0 + 0xB0) == 0);
    assert(*reinterpret_cast<int *>(e5 + 0xB0) == 0);
    // Inactive entry remained untouched
    assert(*reinterpret_cast<int *>(e15 + 0xB0) == 0x99999999);
}

static void test_deactivate_when_flag_bit1_zero() {
    reset_test_state();

    // Active entry whose item ctor clears bit 1
    char *e0 = get_table2_entry(0);
    e0[0x8C] = 1;
    *reinterpret_cast<int *>(e0 + 0xB0) = 0x55555555;

    // Active entry whose item preserves bit 1
    char *e1 = get_table2_entry(1);
    e1[0x8C] = 1;
    *reinterpret_cast<int *>(e1 + 0xB0) = 0x66666666;

    // Clear bit 1 for item at index 0 (entry 1 processed first due to reverse order)
    func_001CDE30(g_zone_mem);

    assert(e0[0x8C] == 1); // with bit 1 set, remains 1
    assert(*reinterpret_cast<int *>(e0 + 0xB0) == 0);
    assert(e1[0x8C] == 1);
    assert(*reinterpret_cast<int *>(e1 + 0xB0) == 0);
}

static void test_no_active_entries_skips_free() {
    reset_test_state();

    // All entries are inactive (0x8C == 0)
    func_001CDE30(g_zone_mem);

    assert(g_parse_calls == 0);
    assert(g_alloc_item_calls == 0);
    assert(g_ctor_item_calls == 0);
    assert(g_free_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "deactivate") {
        test_deactivate_when_flag_bit1_zero();
    } else if (argc > 1 && std::string(argv[1]) == "no_active") {
        test_no_active_entries_skips_free();
    } else {
        test_rebind_flow();
        test_deactivate_when_flag_bit1_zero();
        test_no_active_entries_skips_free();
    }
    return 0;
}

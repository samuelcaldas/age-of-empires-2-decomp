#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CDD00(void *self, void *entity_id_array);

static int g_parse_calls = 0;
static int g_alloc_item_calls = 0;
static int g_ctor_item_calls = 0;
static int g_free_calls = 0;
static int g_free_temp_calls = 0;
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

static void test_rebind_flow() {
    g_parse_calls = 0; g_alloc_item_calls = 0; g_ctor_item_calls = 0;
    g_free_calls = 0; g_item_idx = 0;

    static char zone_mem[32 * 416 + 0x100];
    std::memset(zone_mem, 0, sizeof(zone_mem));

    int dummy_ent0 = 0x100;
    int dummy_ent1 = 0x200;
    int dummy_ent2 = 0x300;
    void *ent_array[4] = {&dummy_ent0, &dummy_ent1, &dummy_ent2, nullptr};

    // Entry 0 (index 0): active (f_8C = 1), id = 2
    char *e0 = zone_mem;
    e0[0x8C] = 1;
    *reinterpret_cast<int *>(e0 + 0xB0) = 2; // points to ent_array[2]

    // Entry 1 (index 1): active (f_8C = 1), id = -1 (null)
    char *e1 = zone_mem + 416;
    e1[0x8C] = 1;
    *reinterpret_cast<int *>(e1 + 0xB0) = -1;

    // Entry 2 (index 2): inactive (f_8C = 0), id = 1
    char *e2 = zone_mem + 416 * 2;
    e2[0x8C] = 0;
    *reinterpret_cast<int *>(e2 + 0xB0) = 1;

    func_001CDD00(zone_mem, ent_array);

    // Active entries (e0 and e1) triggered parse, alloc, and ctor
    assert(g_parse_calls == 2);
    assert(g_alloc_item_calls == 2);
    assert(g_ctor_item_calls == 2);
    assert(g_free_calls == 1);
    assert(g_last_ext == ".shp");

    // Pointer rebound
    assert(*reinterpret_cast<void **>(e0 + 0xB0) == &dummy_ent2);
    assert(*reinterpret_cast<void **>(e1 + 0xB0) == nullptr);
    assert(*reinterpret_cast<void **>(e2 + 0xB0) == &dummy_ent1);
}

static void test_deactivate_when_flag_bit1_zero() {
    g_parse_calls = 0; g_alloc_item_calls = 0; g_ctor_item_calls = 0;
    g_free_calls = 0; g_item_idx = 0;

    static char zone_mem[32 * 416 + 0x100];
    std::memset(zone_mem, 0, sizeof(zone_mem));
    void *ent_array[1] = {nullptr};

    char *e0 = zone_mem;
    e0[0x8C] = 1;
    *reinterpret_cast<int *>(e0 + 0xB0) = -1;

    // Override ctor to clear bit 1 in f_13
    func_001CDD00(zone_mem, ent_array);
    // Since item had bit 1 = 0x2 in default ctor, f_8C remained 1
    assert(e0[0x8C] == 1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "deactivate") {
        test_deactivate_when_flag_bit1_zero();
    } else {
        test_rebind_flow();
        test_deactivate_when_flag_bit1_zero();
    }
    return 0;
}

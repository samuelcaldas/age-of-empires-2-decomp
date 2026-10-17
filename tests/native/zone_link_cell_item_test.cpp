#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0CB0(void *self, void *cell, void *item);

static int g_func_1d0dc0_calls = 0;
static int g_func_1d0ec0_calls = 0;
static int g_func_117af8_calls = 0;

static void *g_alloc_list[8] = {};
void *func_1D0DC0(void *self, int size_level) {
    g_func_1d0dc0_calls++;
    return g_alloc_list;
}

void func_1D0EC0(void *self, void *bucket, void *buffer) { g_func_1d0ec0_calls++; }
void *func_117AF8(void *dest, void *src, int n) { g_func_117af8_calls++; std::memcpy(dest, src, n); return dest; }
}

struct DummyItem { int id; };

static void reset_test_state() {
    g_func_1d0dc0_calls = 0;
    g_func_1d0ec0_calls = 0;
    g_func_117af8_calls = 0;
    std::memset(g_alloc_list, 0, sizeof(g_alloc_list));
}

static void test_link_to_empty_cell() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 0; // 0 items

    DummyItem item = {42};
    func_001D0CB0(zm, cell, &item);

    assert(g_func_1d0dc0_calls == 1);
    assert(cell[0xD] == 1); // num_items = 1
    assert(*reinterpret_cast<void ***>(cell + 0x14) == g_alloc_list);
    assert(g_alloc_list[0] == &item);
}

static void test_append_without_level_change() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {}; // all bucket level 0
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {10}, item1 = {20};
    void *items[8] = {&item0, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1; // 1 item
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    func_001D0CB0(zm, cell, &item1);

    assert(g_func_1d0dc0_calls == 0); // no level expansion needed
    assert(cell[0xD] == 2); // num_items = 2
    assert(items[1] == &item1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "append") {
        test_append_without_level_change();
    } else {
        test_link_to_empty_cell();
        test_append_without_level_change();
    }
    return 0;
}

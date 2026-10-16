#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0B40(void *self, void *cell, void *item_to_remove);

static int g_func_1d0ec0_calls = 0;
static int g_func_1d0dc0_calls = 0;
static int g_func_117af8_calls = 0;

void func_1D0EC0(void *self, void *bucket, void *buffer) { g_func_1d0ec0_calls++; }
static char g_dummy_new_list[64] = {};
void *func_1D0DC0(void *self, int size_level) { g_func_1d0dc0_calls++; return g_dummy_new_list; }
void *func_117AF8(void *dest, void *src, int n) { g_func_117af8_calls++; std::memcpy(dest, src, n); return dest; }
}

struct DummyItem { int id; };

static void reset_test_state() {
    g_func_1d0ec0_calls = 0;
    g_func_1d0dc0_calls = 0;
    g_func_117af8_calls = 0;
}

static void test_unlink_entity_by_pointer_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {};
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {10}, item1 = {20}, item2 = {30};
    void *items[4] = {&item0, &item1, &item2, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 3;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Remove item1 by pointer -> item2 should be moved into index 1
    func_001D0B40(zm, cell, &item1);

    assert(cell[0xD] == 2);
    assert(items[0] == &item0);
    assert(items[1] == &item2); // last item moved to index 1
}

static void test_unlink_last_remaining_item() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {};
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {10};
    void *items[4] = {&item0, nullptr, nullptr, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    func_001D0B40(zm, cell, &item0);

    assert(cell[0xD] == 0);
    assert(g_func_1d0ec0_calls == 1); // freed buffer
}

static void test_item_not_found_leaves_cell_untouched() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {};
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {10}, foreign_item = {99};
    void *items[4] = {&item0, nullptr, nullptr, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    func_001D0B40(zm, cell, &foreign_item);

    assert(cell[0xD] == 1);
    assert(items[0] == &item0);
    assert(g_func_1d0ec0_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "unlink_by_ptr") {
        test_unlink_entity_by_pointer_flow();
    } else if (argc > 1 && std::string(argv[1]) == "last_item") {
        test_unlink_last_remaining_item();
    } else if (argc > 1 && std::string(argv[1]) == "not_found") {
        test_item_not_found_leaves_cell_untouched();
    } else {
        test_unlink_entity_by_pointer_flow();
        test_unlink_last_remaining_item();
        test_item_not_found_leaves_cell_untouched();
    }
    return 0;
}

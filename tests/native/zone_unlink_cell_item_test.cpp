#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D09C0(void *self, void *cell, int index);

static int g_func_1d0ec0_calls = 0;
static int g_func_1d0dc0_calls = 0;
static int g_func_117af8_calls = 0;
static int g_unlink_calls = 0;

void func_1D0EC0(void *self, void *bucket, void *buffer) { g_func_1d0ec0_calls++; }
static char g_dummy_new_list[64] = {};
void *func_1D0DC0(void *self, int size_level) { g_func_1d0dc0_calls++; return g_dummy_new_list; }
void *func_117AF8(void *dest, void *src, int n) { g_func_117af8_calls++; std::memcpy(dest, src, n); return dest; }

static void mock_item_unlink(void *item) {
    g_unlink_calls++;
}
}

static void *g_vtable[4] = {nullptr, nullptr, (void *)&mock_item_unlink, nullptr};

struct DummyItem {
    void **vtable;
    int id;
};

static void reset_test_state() {
    g_func_1d0ec0_calls = 0;
    g_func_1d0dc0_calls = 0;
    g_func_117af8_calls = 0;
    g_unlink_calls = 0;
}

static void test_unlink_item_swap_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {}; // all bucket level 0
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {g_vtable, 100};
    DummyItem item1 = {g_vtable, 200};
    void *items[4] = {&item0, &item1, nullptr, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 2; // 2 items
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Unlink item at index 0 -> should invoke item0->Unlink() and swap item1 into index 0
    func_001D09C0(zm, cell, 0);

    assert(g_unlink_calls == 1);
    assert(cell[0xD] == 1); // 1 item remaining
    assert(items[0] == &item1); // item1 moved to index 0
    assert(cell[0xF] == 0); // unlocked
}

static void test_unlink_last_item_frees_list() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    char lookup[256] = {};
    *reinterpret_cast<void **>(zm + 0x8F00) = lookup;

    DummyItem item0 = {g_vtable, 100};
    void *items[4] = {&item0, nullptr, nullptr, nullptr};

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1; // 1 item
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Unlink the only item -> frees list via func_1D0EC0
    func_001D09C0(zm, cell, 0);

    assert(g_unlink_calls == 1);
    assert(cell[0xD] == 0); // 0 items
    assert(g_func_1d0ec0_calls == 1); // buffer freed
}

static void test_out_of_bounds_index_skips() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1;

    // Index 5 >= num_items (1)
    func_001D09C0(zm, cell, 5);
    assert(g_unlink_calls == 0);

    // Empty cell
    cell[0xD] = 0;
    func_001D09C0(zm, cell, 0);
    assert(g_unlink_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "last_item") {
        test_unlink_last_item_frees_list();
    } else if (argc > 1 && std::string(argv[1]) == "oob") {
        test_out_of_bounds_index_skips();
    } else {
        test_unlink_item_swap_flow();
        test_unlink_last_item_frees_list();
        test_out_of_bounds_index_skips();
    }
    return 0;
}

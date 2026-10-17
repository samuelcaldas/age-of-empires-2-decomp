#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D1150(
    void *self, void *cell, void *a2, void *a3, void *t0, void *t1, int filter_mode
);

int D_004E34C0 = 0x1;
int D_004E34BC = 0x2;
int D_004E33F4 = 0;

static int g_func_326a80_calls = 0;
static int g_method6_calls = 0;

void func_326A80(void *a0, int a1, int a2) { g_func_326a80_calls++; }
void func_264A70(void *entity, void *a1, void *a2, void *a3) {}

static void mock_method6_render(void *entity, void *a1, void *a2, void *a3, int c68) {
    g_method6_calls++;
}
}

static void *g_vtable[10] = {};

struct DummyItemInfo {
    unsigned char type; // offset 0
    char pad[13];
    short attr; // offset 0xE
    char pad2[0x47];
    unsigned char b57; // offset 0x57
};

struct DummyItem {
    void **vtable;
    DummyItemInfo *info;
    void *player;
    char pad[0xBA];
    unsigned char c6; // offset 0xC6
    char pad2[0x2D];
    int flags; // offset 0xF4
};

static void reset_test_state() {
    g_func_326a80_calls = 0;
    g_method6_calls = 0;
    g_vtable[6] = (void *)&mock_method6_render;
}

static void test_filter_cell_items_flow() {
    reset_test_state();

    DummyItemInfo info = {};
    info.type = 60; // >= 50
    info.attr = 0x22;
    info.b57 = 0;

    char dummy_player[0x1000] = {};
    *reinterpret_cast<int *>(dummy_player + 0xC68) = 100;

    DummyItem item = {};
    item.vtable = g_vtable;
    item.info = &info;
    item.player = dummy_player;
    item.c6 = 1; // != 0
    item.flags = 0x1; // matches D_004E34C0

    void *items[4] = {&item, nullptr, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1; // 1 item
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Call with filter_mode = 0
    func_001D1150(nullptr, cell, nullptr, nullptr, nullptr, nullptr, 0);

    assert(g_func_326a80_calls == 1);
    assert(g_method6_calls == 1);
}

static void test_type_lt_50_skipped() {
    reset_test_state();

    DummyItemInfo info = {};
    info.type = 40; // < 50 -> skipped
    info.attr = 0x22;

    DummyItem item = {};
    item.vtable = g_vtable;
    item.info = &info;
    item.c6 = 1;

    void *items[4] = {&item, nullptr, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    func_001D1150(nullptr, cell, nullptr, nullptr, nullptr, nullptr, 0);

    assert(g_func_326a80_calls == 0);
    assert(g_method6_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "type_skip") {
        test_type_lt_50_skipped();
    } else {
        test_filter_cell_items_flow();
        test_type_lt_50_skipped();
    }
    return 0;
}

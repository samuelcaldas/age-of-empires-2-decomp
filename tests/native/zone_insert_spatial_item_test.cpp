#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D0F00(
    void *self, void *cell, int target_type, int filter_flag, int param_mode,
    void *grid_obj, float x, float y
);

int func_123350(float f) {
    return static_cast<int>(std::floor(f + 0.5f));
}

int func_269E50(void *grid_obj, int ix, int iy) {
    return 1;
}
}

struct DummyItemInfo {
    char pad[8];
    short type;
};

struct DummyItem {
    void *vtable;
    DummyItemInfo *info;
    void *player;
    char pad[0x2D];
    unsigned char mode; // 0x39
    char pad2[10];
    float pos_x; // 0x44
    float pos_y; // 0x48
};

static void test_find_nearest_item_flow() {
    DummyItemInfo info10 = {{}, 10};
    DummyItem item_far = {nullptr, &info10, nullptr, {}, 0, {}, 20.0f, 20.0f};
    DummyItem item_near = {nullptr, &info10, nullptr, {}, 0, {}, 2.0f, 2.0f};

    void *items[4] = {&item_far, &item_near, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 2; // 2 items
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Search target at (1.0f, 1.0f) for type 10
    void *found = func_001D0F00(nullptr, cell, 10, 0, 0, nullptr, 1.0f, 1.0f);

    assert(found == &item_near); // item_near is closest
}

static void test_filter_by_type_and_mode() {
    DummyItemInfo info10 = {{}, 10}, info20 = {{}, 20};
    DummyItem item_wrong_type = {nullptr, &info20, nullptr, {}, 0, {}, 1.0f, 1.0f};
    DummyItem item_match = {nullptr, &info10, nullptr, {}, 5, {}, 10.0f, 10.0f};

    void *items[4] = {&item_wrong_type, &item_match, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 2;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Search type 10 with filter_flag = 1, param_mode = 5
    void *found = func_001D0F00(nullptr, cell, 10, 1, 5, nullptr, 0.0f, 0.0f);
    assert(found == &item_match);

    // Search type 10 with filter_flag = 1, param_mode = 99 (no match)
    found = func_001D0F00(nullptr, cell, 10, 1, 99, nullptr, 0.0f, 0.0f);
    assert(found == nullptr);
}

static void test_fallback_query_returns_first_matching() {
    DummyItemInfo info10 = {{}, 10};
    DummyItem item1 = {nullptr, &info10, nullptr, {}, 0, {}, 50.0f, 50.0f};
    DummyItem item2 = {nullptr, &info10, nullptr, {}, 0, {}, 2.0f, 2.0f};

    void *items[4] = {&item1, &item2, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 2;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // When x = -1.0f and y = -1.0f, returns first matching type
    void *found = func_001D0F00(nullptr, cell, 10, 0, 0, nullptr, -1.0f, -1.0f);
    assert(found == &item1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "nearest") {
        test_find_nearest_item_flow();
    } else if (argc > 1 && std::string(argv[1]) == "filter") {
        test_filter_by_type_and_mode();
    } else if (argc > 1 && std::string(argv[1]) == "fallback") {
        test_fallback_query_returns_first_matching();
    } else {
        test_find_nearest_item_flow();
        test_filter_by_type_and_mode();
        test_fallback_query_returns_first_matching();
    }
    return 0;
}

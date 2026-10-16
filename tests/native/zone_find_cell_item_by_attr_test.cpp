#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D1100(void *self, void *cell, int target_attr);
}

struct DummyItemInfo {
    char pad[14];
    short attr; // offset 0xE
};

struct DummyItem {
    void *vtable;
    DummyItemInfo *info;
};

static void test_find_matching_attr() {
    DummyItemInfo info1 = {{}, 42};
    DummyItemInfo info2 = {{}, 99};
    DummyItem item1 = {nullptr, &info1};
    DummyItem item2 = {nullptr, &info2};

    void *items[4] = {&item1, &item2, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 2; // 2 items
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Search for attr 99 -> should return &item2
    void *found = func_001D1100(nullptr, cell, 99);
    assert(found == &item2);

    // Search for attr 42 -> should return &item1
    found = func_001D1100(nullptr, cell, 42);
    assert(found == &item1);
}

static void test_attr_not_found_returns_null() {
    DummyItemInfo info1 = {{}, 42};
    DummyItem item1 = {nullptr, &info1};

    void *items[4] = {&item1, nullptr, nullptr, nullptr};
    char cell[28];
    std::memset(cell, 0, sizeof(cell));
    cell[0xD] = 1;
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    // Search for non-existent attr 77
    void *found = func_001D1100(nullptr, cell, 77);
    assert(found == nullptr);

    // Empty cell
    cell[0xD] = 0;
    found = func_001D1100(nullptr, cell, 42);
    assert(found == nullptr);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "not_found") {
        test_attr_not_found_returns_null();
    } else {
        test_find_matching_attr();
        test_attr_not_found_returns_null();
    }
    return 0;
}

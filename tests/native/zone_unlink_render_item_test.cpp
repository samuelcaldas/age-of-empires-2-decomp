#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D1CC0(void *self, void *item);
}

static void test_unlink_render_item_null() {
    char zm[0x10000];
    char item[32];
    std::memset(zm, 0, sizeof(zm));
    std::memset(item, 0, sizeof(item));
    *reinterpret_cast<void **>(item + 0x10) = nullptr;

    func_001D1CC0(zm, item);
    // No-op if item->field_10 is null
    assert(*reinterpret_cast<void **>(item + 0x10) == nullptr);
}

static void test_unlink_render_item_single() {
    char zm[0x10000];
    char item[32];
    std::memset(zm, 0, sizeof(zm));
    std::memset(item, 0, sizeof(item));

    char dummy_sub[16];
    item[4] = 3; // slot 3
    *reinterpret_cast<void **>(item + 0x10) = dummy_sub;

    void *node[2] = { item, nullptr };
    int offset = 3 * 4;
    *reinterpret_cast<void **>(zm + offset + 0x9048) = node; // head
    *reinterpret_cast<void **>(zm + offset + 0x908C) = node; // tail
    *reinterpret_cast<void **>(zm + offset + 0x90D0) = nullptr; // free head

    func_001D1CC0(zm, item);

    assert(*reinterpret_cast<void **>(item + 0x10) == nullptr);
    assert(node[0] == dummy_sub);
    assert(*reinterpret_cast<void **>(zm + offset + 0x9048) == nullptr); // head cleared
    assert(*reinterpret_cast<void **>(zm + offset + 0x908C) == nullptr); // tail cleared
    assert(*reinterpret_cast<void **>(zm + offset + 0x90D0) == node);    // node pushed to free list
}

int main(int argc, char **argv) {
    test_unlink_render_item_null();
    test_unlink_render_item_single();
    return 0;
}

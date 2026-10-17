#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialNodeArray {
    void **items;
    int count;
};

extern "C" {
void *func_001D7BF0(SpatialNodeArray *self, void *item, int flag);

static int g_compare_calls = 0;
static void *g_expected_target = nullptr;

bool func_1D20D0(void *self, void *item, int flag) {
    g_compare_calls++;
    assert(flag == 10);
    return self == g_expected_target;
}
}

static void test_find_item_null_or_zero_flag() {
    g_compare_calls = 0;
    SpatialNodeArray arr;
    arr.items = nullptr;
    arr.count = 0;

    assert(func_001D7BF0(&arr, nullptr, 1) == nullptr);
    assert(func_001D7BF0(&arr, (void *)0x10, 0) == nullptr);
    assert(func_001D7BF0(&arr, (void *)0x10, -1) == nullptr);
    assert(g_compare_calls == 0);
}

static void test_find_item_not_found() {
    g_compare_calls = 0;
    g_expected_target = (void *)0x9999;

    void *items[3] = { (void *)0x1111, (void *)0x2222, (void *)0x3333 };
    SpatialNodeArray arr;
    arr.items = items;
    arr.count = 3;

    void *res = func_001D7BF0(&arr, (void *)0x10, 10);
    assert(res == nullptr);
    assert(g_compare_calls == 3);
}

static void test_find_item_found() {
    g_compare_calls = 0;
    g_expected_target = (void *)0x2222;

    void *items[3] = { (void *)0x1111, (void *)0x2222, (void *)0x3333 };
    SpatialNodeArray arr;
    arr.items = items;
    arr.count = 3;

    void *res = func_001D7BF0(&arr, (void *)0x10, 10);
    assert(res == (void *)0x2222);
    assert(g_compare_calls == 2);
}

int main(int argc, char **argv) {
    test_find_item_null_or_zero_flag();
    test_find_item_not_found();
    test_find_item_found();
    return 0;
}

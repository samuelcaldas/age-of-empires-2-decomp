#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D1FB0(void *self, int flag);

static int g_func_100630_calls = 0;
static int g_func_100670_calls = 0;

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void reset_test_state() {
    g_func_100630_calls = 0;
    g_func_100670_calls = 0;
}

static void test_pyramid_destroy_null() {
    reset_test_state();
    void *res = func_001D1FB0(nullptr, 0);
    assert(res == nullptr);
    assert(g_func_100630_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_pyramid_destroy_hierarchy() {
    reset_test_state();
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char dummy_9c[32];
    *reinterpret_cast<void **>(zm + 0x9C) = dummy_9c;

    void *level_arr0[2] = { reinterpret_cast<void *>(0x10), reinterpret_cast<void *>(0x20) };
    void *level_arr1[1] = { reinterpret_cast<void *>(0x30) };
    void *level_arr2[1] = { reinterpret_cast<void *>(0x40) };
    void *level_arr3[1] = { reinterpret_cast<void *>(0x50) };
    void **root[4] = { level_arr0, level_arr1, level_arr2, level_arr3 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    *reinterpret_cast<int *>(zm + 0xA4 + 0 * 4) = 2;
    *reinterpret_cast<int *>(zm + 0xA4 + 1 * 4) = 1;
    *reinterpret_cast<int *>(zm + 0xA4 + 2 * 4) = 1;
    *reinterpret_cast<int *>(zm + 0xA4 + 3 * 4) = 1;

    // Node list at 0x80
    char node1[0x30];
    char node2[0x30];
    *reinterpret_cast<void **>(zm + 0x80) = node1;
    *reinterpret_cast<void **>(node1 + 0x20) = node2;
    *reinterpret_cast<void **>(node2 + 0x20) = nullptr;

    void *res = func_001D1FB0(zm, 0);
    assert(res == zm);

    // 1 (dummy_9c) + 5 (level items) + 4 (level arrays) + 1 (root) = 11 calls to func_100630
    assert(g_func_100630_calls == 11);
    // 2 calls to func_100670 for nodes, 0 for zm (flag == 0)
    assert(g_func_100670_calls == 2);
}

int main(int argc, char **argv) {
    test_pyramid_destroy_null();
    test_pyramid_destroy_hierarchy();
    return 0;
}

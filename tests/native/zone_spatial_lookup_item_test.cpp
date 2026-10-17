#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D7BB0(void *self, void *item);

static int g_func_1d7bf0_calls = 0;

int func_1D7BF0(void *self, void *item, int flag) {
    g_func_1d7bf0_calls++;
    return 1;
}
}

static void test_lookup_item_null() {
    g_func_1d7bf0_calls = 0;
    assert(func_001D7BB0(nullptr, nullptr) == 0);
    assert(g_func_1d7bf0_calls == 0);
}

static void test_lookup_item_flow() {
    g_func_1d7bf0_calls = 0;
    char zm[0x20];
    char a2[0x80];
    char item[0x80];
    std::memset(zm, 0, sizeof(zm));
    std::memset(a2, 0, sizeof(a2));
    std::memset(item, 0, sizeof(item));

    *reinterpret_cast<void **>(zm + 8) = a2;
    *reinterpret_cast<short *>(item + 0x58) = 1; // v1 = 1

    void *items[2] = { nullptr, reinterpret_cast<void *>(0x1234) };
    *reinterpret_cast<void ***>(a2 + 0x68) = items;
    *reinterpret_cast<short *>(a2 + 0x66) = 7; // flag = 7

    int res = func_001D7BB0(zm, item);
    assert(res == 1);
    assert(g_func_1d7bf0_calls == 1);
}

int main(int argc, char **argv) {
    test_lookup_item_null();
    test_lookup_item_flow();
    return 0;
}

#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D7CA0(void *self, void *item);

static int g_func_1d7ce0_calls = 0;
static void *g_last_target = nullptr;
static int g_last_flag = 0;

void func_1D7CE0(void *self, void *item, int flag) {
    g_func_1d7ce0_calls++;
    g_last_target = item;
    g_last_flag = flag;
}
}

static void test_lookup_item_entry_null() {
    g_func_1d7ce0_calls = 0;
    func_001D7CA0(nullptr, nullptr);
    assert(g_func_1d7ce0_calls == 0);
}

static void test_lookup_item_entry_valid() {
    g_func_1d7ce0_calls = 0;
    char zm[0x20];
    char table[0x80];
    char item[0x80];
    std::memset(zm, 0, sizeof(zm));
    std::memset(table, 0, sizeof(table));
    std::memset(item, 0, sizeof(item));

    *reinterpret_cast<void **>(zm + 8) = table;
    *reinterpret_cast<short *>(item + 0x58) = 2; // index = 2

    void *items[4] = { nullptr, nullptr, reinterpret_cast<void *>(0x5678), nullptr };
    *reinterpret_cast<void ***>(table + 0x68) = items;
    *reinterpret_cast<short *>(table + 0x66) = 42; // flag = 42

    func_001D7CA0(zm, item);
    assert(g_func_1d7ce0_calls == 1);
    assert(g_last_target == reinterpret_cast<void *>(0x5678));
    assert(g_last_flag == 42);
}

int main(int argc, char **argv) {
    test_lookup_item_entry_null();
    test_lookup_item_entry_valid();
    return 0;
}

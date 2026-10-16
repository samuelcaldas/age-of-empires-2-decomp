#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D06A0(void *self);

static int g_func_100630_calls = 0;
static int g_func_117cac_calls = 0;

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void *func_117CAC(void *heap, int flag, int size) {
    g_func_117cac_calls++;
    return nullptr;
}
}

static void reset_test_state() {
    g_func_100630_calls = 0;
    g_func_117cac_calls = 0;
}

static void test_teardown_initialized_grid() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0x8EFC) = 1; // initialized
    char dummy_buf[256];
    *reinterpret_cast<void **>(zm + 0x8F00) = dummy_buf;

    char dummy_items[16][4];
    void *item_ptrs[16];
    for (int i = 0; i < 16; i++) item_ptrs[i] = &dummy_items[i];

    char dummy_buf1[64], dummy_buf2[64];
    for (int i = 0; i < 4; i++) {
        char *bucket = zm + 0x8F24 + i * 68;
        *reinterpret_cast<int *>(bucket + 0x10) = 4;
        *reinterpret_cast<void ***>(bucket + 0x0) = item_ptrs;
        *reinterpret_cast<void **>(bucket + 0x2C) = dummy_buf1;
        *reinterpret_cast<void **>(bucket + 0x34) = dummy_buf2;
    }

    func_001D06A0(zm);

    assert(g_func_100630_calls >= 8); // freed bucket buffers
    assert(g_func_117cac_calls == 1); // freed 251-byte table
    assert(*reinterpret_cast<int *>(zm + 0x8EFC) == 0); // cleared init flag
    assert(*reinterpret_cast<void **>(zm + 0x8F00) == nullptr);
}

static void test_uninitialized_grid_skips_teardown() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0x8EFC) = 0; // not initialized

    func_001D06A0(zm);

    assert(g_func_100630_calls == 0);
    assert(g_func_117cac_calls == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "uninit") {
        test_uninitialized_grid_skips_teardown();
    } else {
        test_teardown_initialized_grid();
        test_uninitialized_grid_skips_teardown();
    }
    return 0;
}

#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D16D0(void *self);

static int g_func_1d1560_calls = 0;
static int g_func_100670_calls = 0;
static int g_func_25de30_calls = 0;
static void *g_last_freed_ptr = nullptr;

void func_001D1560(void *self) {
    g_func_1d1560_calls++;
}

void func_00100670(void *ptr) {
    g_func_100670_calls++;
    g_last_freed_ptr = ptr;
}

void func_25DE30(void *item, int flag) {
    g_func_25de30_calls++;
    assert(flag == 1);
}
}

static void reset_test_state() {
    g_func_1d1560_calls = 0;
    g_func_100670_calls = 0;
    g_func_25de30_calls = 0;
    g_last_freed_ptr = nullptr;
}

static void test_destroy_render_items_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char dummy_buf[64];
    *reinterpret_cast<void **>(zm + 0x903C) = dummy_buf;
    *reinterpret_cast<int *>(zm + 0x9040) = 400;
    *reinterpret_cast<int *>(zm + 0x9044) = 15;
    *reinterpret_cast<void **>(zm + 0x9034) = dummy_buf;

    char dummy_items[17][16];
    for (int i = 0; i < 17; i++) {
        *reinterpret_cast<void **>(zm + 0x9114 + i * 4) = dummy_items[i];
    }

    func_001D16D0(zm);

    assert(g_func_1d1560_calls == 1);
    assert(g_func_100670_calls == 1);
    assert(g_last_freed_ptr == dummy_buf);
    assert(*reinterpret_cast<void **>(zm + 0x903C) == nullptr);
    assert(g_func_25de30_calls == 17);

    for (int i = 0; i < 17; i++) {
        assert(*reinterpret_cast<void **>(zm + 0x9114 + i * 4) == nullptr);
    }

    assert(*reinterpret_cast<int *>(zm + 0x9040) == 0);
    assert(*reinterpret_cast<int *>(zm + 0x9044) == 0);
    assert(*reinterpret_cast<void **>(zm + 0x9034) == nullptr);
}

int main(int argc, char **argv) {
    test_destroy_render_items_flow();
    return 0;
}

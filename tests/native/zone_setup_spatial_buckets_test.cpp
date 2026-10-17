#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0430(void *self);

static int g_func_117cac_calls = 0;
static int g_func_1d0ee0_calls = 0;
static int g_func_1d07d0_calls = 0;
static int g_func_1d08e0_calls = 0;
static char g_dummy_heap[512] = {};

void *func_117CAC(void *heap, int flag, int size) {
    g_func_117cac_calls++;
    assert(size == 251);
    return g_dummy_heap;
}

void func_1D0EE0(void *self, void *bucket, int size) { g_func_1d0ee0_calls++; }
void func_1D07D0(void *self, void *bucket, int flag) { g_func_1d07d0_calls++; }
void func_1D08E0(void *self, void *bucket, int size) { g_func_1d08e0_calls++; }
}

static void reset_test_state() {
    g_func_117cac_calls = 0; g_func_1d0ee0_calls = 0;
    g_func_1d07d0_calls = 0; g_func_1d08e0_calls = 0;
    std::memset(g_dummy_heap, 0, sizeof(g_dummy_heap));
}

static void test_setup_spatial_buckets_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0x8) = 64; // width
    *reinterpret_cast<int *>(zm + 0xC) = 64; // height

    func_001D0430(zm);

    assert(g_func_117cac_calls == 1);
    // 4 buckets initialized
    assert(g_func_1d0ee0_calls == 4);
    assert(g_func_1d07d0_calls == 4);
    assert(g_func_1d08e0_calls == 4);

    // Initialized flag set
    assert(*reinterpret_cast<int *>(zm + 0x8EFC) == 1);
    // Buffer pointer stored
    assert(*reinterpret_cast<void **>(zm + 0x8F00) == g_dummy_heap);
    // Thresholds
    assert(*reinterpret_cast<int *>(zm + 0x8F04) == 2);
    assert(*reinterpret_cast<int *>(zm + 0x8F08) == 4);
    assert(*reinterpret_cast<int *>(zm + 0x8F0C) == 12);
    assert(*reinterpret_cast<int *>(zm + 0x8F10) == 250);
}

int main(int argc, char **argv) {
    test_setup_spatial_buckets_flow();
    return 0;
}

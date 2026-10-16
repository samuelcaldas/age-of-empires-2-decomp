#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D1D70(void *self, void *zone, const void *values, int count);

static int g_func_100730_calls = 0;
static int g_func_117af8_calls = 0;
static int g_func_1d2140_calls = 0;
static int g_func_1d2320_calls = 0;
static char g_dummy_pool[128][64];
static int g_pool_idx = 0;

void *func_100730(int size) {
    g_func_100730_calls++;
    assert(g_pool_idx < 128);
    return g_dummy_pool[g_pool_idx++];
}

void func_117AF8(void *dst, const void *src, int size) {
    g_func_117af8_calls++;
    std::memcpy(dst, src, size);
}

void func_1D2140(void *self) {
    g_func_1d2140_calls++;
}

void func_1D2320(void *self, int x0, int y0, int x1, int y1) {
    g_func_1d2320_calls++;
}
}

static void reset_test_state() {
    g_func_100730_calls = 0;
    g_func_117af8_calls = 0;
    g_func_1d2140_calls = 0;
    g_func_1d2320_calls = 0;
    g_pool_idx = 0;
}

static void test_pyramid_init_flow() {
    reset_test_state();
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char dummy_zone[0x100];
    char dummy_v0[0x9000];
    std::memset(dummy_zone, 0, sizeof(dummy_zone));
    std::memset(dummy_v0, 0, sizeof(dummy_v0));

    *reinterpret_cast<void **>(dummy_zone + 0x3C) = dummy_v0;
    *reinterpret_cast<int *>(dummy_v0 + 8) = 16;  // e4 width
    *reinterpret_cast<int *>(dummy_v0 + 0xC) = 16; // e8 height
    *reinterpret_cast<void **>(dummy_v0 + 0x8E8C) = reinterpret_cast<void *>(0x1234);

    float vals[2] = { 1.5f, 2.5f };
    void *res = func_001D1D70(zm, dummy_zone, vals, 2);

    assert(res == zm);
    assert(*reinterpret_cast<void **>(zm + 0x94) == dummy_zone);
    assert(*reinterpret_cast<void **>(zm + 0x98) == reinterpret_cast<void *>(0x1234));
    assert(*reinterpret_cast<int *>(zm + 0xA0) == 2);
    assert(g_func_117af8_calls == 1);
    assert(*reinterpret_cast<int *>(zm + 0xE4) == 16);
    assert(*reinterpret_cast<int *>(zm + 0xE8) == 16);
    assert(*reinterpret_cast<int *>(zm + 0xEC) == 15);
    assert(*reinterpret_cast<int *>(zm + 0xF0) == 15);
    assert(g_func_1d2140_calls == 1);
    assert(g_func_1d2320_calls == 1);
    assert(*reinterpret_cast<void ****>(zm + 0) != nullptr);
}

int main(int argc, char **argv) {
    test_pyramid_init_flow();
    return 0;
}

#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D5B00(void *self, int x, int y, int flag);

static int g_func_1d5e50_calls = 0;
static int g_func_1d5a30_calls = 0;

int func_1D5E50(void *self, int x, int y) {
    g_func_1d5e50_calls++;
    return 1;
}

int func_1D5A30(void *self, int x, int y) {
    g_func_1d5a30_calls++;
    return 0; // no blocking attr
}
}

static void test_test_point_inside() {
    g_func_1d5e50_calls = 0;
    g_func_1d5a30_calls = 0;

    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 5;
    *reinterpret_cast<int *>(zm + 0xF8) = 5;
    *reinterpret_cast<int *>(zm + 0xFC) = 20;
    *reinterpret_cast<int *>(zm + 0x100) = 20;

    int res = func_001D5B00(zm, 10, 10, 0);
    assert(res == 1);
    assert(g_func_1d5e50_calls == 1);
    assert(g_func_1d5a30_calls == 1);
}

static void test_test_point_outside() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 5;
    *reinterpret_cast<int *>(zm + 0xF8) = 5;
    *reinterpret_cast<int *>(zm + 0xFC) = 20;
    *reinterpret_cast<int *>(zm + 0x100) = 20;

    int res = func_001D5B00(zm, 2, 10, 0); // x < 5
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_test_point_inside();
    test_test_point_outside();
    return 0;
}

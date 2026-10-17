#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2);

static int g_func_1d3440_calls = 0;

int func_1D3440(void *self, int level, int x, int y, void *p1, void *p2) {
    g_func_1d3440_calls++;
    return (x == 1 && y == 1) ? 1 : 0;
}
}

static void test_check_rect_hit() {
    g_func_1d3440_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 64;
    *reinterpret_cast<int *>(zm + 0xE8) = 64;

    int res = func_001D3310(zm, 8, 8, 16, 16, nullptr, nullptr);
    assert(res == 1);
    assert(g_func_1d3440_calls >= 1);
}

int main(int argc, char **argv) {
    test_check_rect_hit();
    return 0;
}

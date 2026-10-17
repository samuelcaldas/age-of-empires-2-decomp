#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D2320(void *self, int x0, int y0, int x1, int y1);

static int g_func_1d2460_calls = 0;

void func_1D2460(void *self, int level, int x, int y, void *p1, void *p2) {
    g_func_1d2460_calls++;
    assert(level == 3);
}
}

static void test_update_rect_flow() {
    g_func_1d2460_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0xE4) = 64; // e4 max_x
    *reinterpret_cast<int *>(zm + 0xE8) = 64; // e8 max_y
    *reinterpret_cast<int *>(zm + 0xEC) = 63; // ec max_x - 1
    *reinterpret_cast<int *>(zm + 0xF0) = 63; // f0 max_y - 1

    func_001D2320(zm, 10, 10, 20, 20);

    // x0=9, y0=9, x1=21, y1=21
    assert(*reinterpret_cast<int *>(zm + 0xF4) == 9);
    assert(*reinterpret_cast<int *>(zm + 0xF8) == 9);
    assert(*reinterpret_cast<int *>(zm + 0xFC) == 21);
    assert(*reinterpret_cast<int *>(zm + 0x100) == 21);

    // s4 = 9 >> 3 = 1, s2 = 21 >> 3 = 2 -> 2 x values (1, 2)
    // s1 = 9 >> 3 = 1, s3 = 21 >> 3 = 2 -> 2 y values (1, 2)
    // 2 * 2 = 4 calls to func_1D2460
    assert(g_func_1d2460_calls == 4);
}

int main(int argc, char **argv) {
    test_update_rect_flow();
    return 0;
}

#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D3C70(void *self, int op, float centerX, float centerY, float extent, float radius);

int func_00123350(float f) {
    return static_cast<int>(std::floor(f));
}

static int s_search_bounds_calls = 0;
static int s_mock_search_bounds_ret = 0;

int func_001D3EB0(
    void *self, int level, int x, int y, float minX, float minY, float maxX, float maxY, int op
) {
    (void)self;
    (void)level;
    (void)x;
    (void)y;
    (void)minX;
    (void)minY;
    (void)maxX;
    (void)maxY;
    (void)op;
    s_search_bounds_calls++;
    return s_mock_search_bounds_ret;
}
}

static void test_search_radius() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    // Grid limits
    *reinterpret_cast<int *>(zm + 0xE4) = 100; // limit_x
    *reinterpret_cast<int *>(zm + 0xE8) = 100; // limit_y
    *reinterpret_cast<int *>(zm + 0xEC) = 99;  // clamp_x
    *reinterpret_cast<int *>(zm + 0xF0) = 99;  // clamp_y

    // Level setup for fallback
    unsigned short cell_l3[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned short *col_l3[8] = {
        cell_l3, cell_l3, cell_l3, cell_l3, cell_l3, cell_l3, cell_l3, cell_l3
    };
    unsigned short **levels[4] = {nullptr, nullptr, nullptr, col_l3};
    *reinterpret_cast<void ***>(zm + 0x0) = reinterpret_cast<void **>(levels);

    // Test 1: Non-zero count from func_001D3EB0
    s_search_bounds_calls = 0;
    s_mock_search_bounds_ret = 1;
    func_001D3C70(zm, 1, 16.0f, 16.0f, 2.0f, 2.0f);

    assert(*reinterpret_cast<int *>(zm + 0xF4) == 12);  // 16 - 4
    assert(*reinterpret_cast<int *>(zm + 0xF8) == 12);
    assert(*reinterpret_cast<int *>(zm + 0xFC) == 20);  // 16 + 4
    assert(*reinterpret_cast<int *>(zm + 0x100) == 20);
    assert(*reinterpret_cast<int *>(zm + 0x104) == 16);
    assert(*reinterpret_cast<int *>(zm + 0x108) == 16);
    assert(s_search_bounds_calls > 0);

    // Test 2: Zero count triggers fallback to set bit 0x10 on cell with 0x20
    // center_ix = 16, center_iy = 16. At lvl 3: col_idx = 2, row_idx = 2
    // cell = col + 2 * 2 = cell_l3 + 2 (in 16-bit units), offset 4 bytes
    s_search_bounds_calls = 0;
    s_mock_search_bounds_ret = 0;
    reinterpret_cast<unsigned char *>(&cell_l3[2])[1] = 0x20;
    func_001D3C70(zm, 1, 16.0f, 16.0f, 2.0f, 2.0f);
    assert((reinterpret_cast<unsigned char *>(&cell_l3[2])[1] & 0x10) == 0x10);

    // Test 3: Zero count triggers fallback to clear bit 0x10 when op == 0
    s_search_bounds_calls = 0;
    s_mock_search_bounds_ret = 0;
    reinterpret_cast<unsigned char *>(&cell_l3[2])[1] = 0x30; // 0x20 | 0x10
    func_001D3C70(zm, 0, 16.0f, 16.0f, 2.0f, 2.0f);
    assert((reinterpret_cast<unsigned char *>(&cell_l3[2])[1] & 0x10) == 0);
}

int main(int argc, char **argv) {
    test_search_radius();
    return 0;
}

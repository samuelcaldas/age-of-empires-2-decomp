#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D40E0(void *self, int level, int x, int y, float *f1, float *f2);
}

static void test_test_cell_bounds_flow() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 8;   // x0
    *reinterpret_cast<int *>(zm + 0xF8) = 16;  // y0
    *reinterpret_cast<int *>(zm + 0xFC) = 32;  // x1
    *reinterpret_cast<int *>(zm + 0x100) = 48; // y1

    // At level 2 (>> 2): bounds are [2, 4, 8, 12]
    assert(func_001D40E0(zm, 2, 3, 5, nullptr, nullptr) == 1); // inside
    assert(func_001D40E0(zm, 2, 1, 5, nullptr, nullptr) == 0); // x < 2
    assert(func_001D40E0(zm, 2, 9, 5, nullptr, nullptr) == 0); // x > 8
}

int main(int argc, char **argv) {
    test_test_cell_bounds_flow();
    return 0;
}

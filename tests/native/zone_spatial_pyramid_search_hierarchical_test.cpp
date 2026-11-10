#include <cassert>
#include <cstddef>
#include <cstring>
#include "zone_spatial_pyramid_search_hierarchical.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_117CAC(void *dst, int val, int size) {
    return std::memset(dst, val, size);
}
}

static void test_search_hierarchical_clears_grid() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    int w = 4;
    int h = 8;
    char col0[8], col1[8], col2[8], col3[8];
    std::memset(col0, 0xAA, 8);
    std::memset(col1, 0xBB, 8);
    std::memset(col2, 0xCC, 8);
    std::memset(col3, 0xDD, 8);

    char *grid[4] = { col0, col1, col2, col3 };

    *(int *)(zm + 0xE4) = w;
    *(int *)(zm + 0xE8) = h;
    *(char ***)(zm + 0x11C) = grid;

    func_001D6F10(nullptr);
    func_001D6F10(zm);

    // After func_001D6F10, all columns must be zeroed
    for (int i = 0; i < h; ++i) {
        assert(col0[i] == 0);
        assert(col1[i] == 0);
        assert(col2[i] == 0);
        assert(col3[i] == 0);
    }
}

int main(int argc, char **argv) {
    test_search_hierarchical_clears_grid();
    return 0;
}

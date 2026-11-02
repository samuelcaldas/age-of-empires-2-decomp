#include <cassert>
#include <cstdlib>
#include <iostream>

struct NodeEntry {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
};

struct SpatialGrid {
    int m_f0;       // 0x00
    void *m_f4;     // 0x04
    int m_count1;   // 0x08 = 0x20
    void *m_fC;     // 0x0C
    int m_f10;      // 0x10
    int m_f14;      // 0x14
    int m_f18;      // 0x18
    int m_f1C;      // 0x1C
    int m_f20;      // 0x20
    int m_count2;   // 0x24 = 0xC8
    NodeEntry *m_f28;// 0x28
};

int D_004E3284 = 10;
static size_t s_last_alloc_sizes[3];
static int s_alloc_idx = 0;

extern "C" {
void *func_100730(unsigned int size) {
    if (s_alloc_idx < 3) {
        s_last_alloc_sizes[s_alloc_idx++] = size;
    }
    return std::malloc(size);
}

void func_001E3FA0(SpatialGrid *self);
}

int main() {
    SpatialGrid grid;
    grid.m_f10 = 99;
    grid.m_f14 = 99;
    grid.m_f18 = 99;
    grid.m_f1C = 99;

    func_001E3FA0(&grid);

    assert(grid.m_f0 == 0);
    assert(grid.m_count1 == 0x20);
    assert(grid.m_f20 == 0);
    assert(grid.m_count2 == 0xC8);

    assert(grid.m_f10 == 0);
    assert(grid.m_f14 == 0);
    assert(grid.m_f18 == 0);
    assert(grid.m_f1C == 0);

    assert(D_004E3284 == 11);

    assert(s_last_alloc_sizes[0] == 0x20 * 8);
    assert(s_last_alloc_sizes[1] == 0x20 * 4);
    assert(s_last_alloc_sizes[2] == 0xC8 * 20);

    std::free(grid.m_f4);
    std::free(grid.m_fC);
    std::free(grid.m_f28);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

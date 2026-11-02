#include <cassert>
#include <iostream>

struct SpatialGrid {
    int m_f0;       // 0x00
    void *m_f4;     // 0x04
    int m_count1;   // 0x08
    void *m_fC;     // 0x0C
    int m_f10;      // 0x10
    int m_f14;      // 0x14
    int m_f18;      // 0x18
    int m_f1C;      // 0x1C
    int m_f20;      // 0x20
    int m_count2;   // 0x24
    void *m_f28;    // 0x28
};

int D_004E3284 = 1;
void *D_004E3288 = (void *)0x5678;
int D_004E328C = 42;

static int s_freed_count = 0;

extern "C" {
void func_100630(void *ptr) {
    s_freed_count++;
}

void func_001E40A0(SpatialGrid *self);
}

int main() {
    SpatialGrid grid;
    grid.m_f28 = (void *)0x1;
    grid.m_f4 = (void *)0x2;
    grid.m_fC = (void *)0x3;

    func_001E40A0(&grid);

    assert(s_freed_count == 4); // 3 from grid + 1 from D_004E3288
    assert(D_004E3284 == 0);
    assert(D_004E3288 == 0);
    assert(D_004E328C == 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

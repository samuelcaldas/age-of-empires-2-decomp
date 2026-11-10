#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_reset_pyramid.h"

struct SpatialGrid {
    char pad_4[0x4];
    int f4;
    int f8;
    void **fC;
    char pad_8C[0x7C];
    int f8C;
    int f90;
    void *f94;
    char pad_A0[0x8];
    void *fA0;
    char pad_B4[0x10];
    void *fB4;
    void *fB8;
    char pad_CC[0x10];
    char fCC[0x100];
    char f1CC[0x400];
    char f5CC[0x400];
};

static int s_func_1E4090_called = 0;
static int s_func_1002A0_called = 0;
static int s_func_100630_called = 0;
static int s_func_1FD400_called = 0;

void *func_1FD480 = (void *)0x9999;

extern "C" {
void func_1E4090(void *ptr) {
    (void)ptr;
    s_func_1E4090_called++;
}

void *func_117CAC(void *dst, int val, unsigned int size) {
    return std::memset(dst, val, size);
}

void func_1002A0(void *ptr, void *fn) {
    (void)ptr; (void)fn;
    s_func_1002A0_called++;
}

void func_100630(void *ptr) {
    std::free(ptr);
    s_func_100630_called++;
}

void func_1FD400(void *p, int flag) {
    (void)p; (void)flag;
    s_func_1FD400_called++;
}
}

int main() {
    SpatialGrid grid;
    std::memset(&grid, 0xAA, sizeof(grid));

    char item1[0x2C];
    char item2[0x2C];
    std::memset(item1, 0x11, sizeof(item1));
    std::memset(item2, 0x22, sizeof(item2));

    void *items[2] = {item1, item2};
    grid.f8 = 2;
    grid.fC = items;

    grid.fB4 = (void *)0x1234;
    grid.fB8 = (void *)0x5678;

    // Dynamically allocated buffer for f94 (not fCC)
    grid.f94 = std::malloc(64);

    func_001E6550(&grid);

    // Verify item resets and function calls
    assert(s_func_1E4090_called == 2);
    assert(items[0] == NULL);
    assert(items[1] == NULL);

    assert(grid.f4 == 0);
    assert(grid.f8 == 0);
    assert(grid.fC == NULL);
    assert(grid.fA0 == NULL);
    assert(grid.fB4 == NULL);
    assert(grid.fB8 == NULL);
    assert(s_func_1002A0_called == 2);

    assert(grid.f94 == NULL);
    assert(s_func_100630_called == 1);

    assert(grid.f90 == 0);
    assert(grid.f8C == 0);
    assert(s_func_1FD400_called == 1);

    return 0;
}

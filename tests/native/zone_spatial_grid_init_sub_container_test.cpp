#include <cassert>
#include <iostream>

static int s_constructed = 0;

struct SubContainerItem12 {
    void *buffer;
    int f4;
    int f8;
    SubContainerItem12() : buffer(0), f4(0), f8(0) {
        s_constructed++;
    }
    ~SubContainerItem12() {}
};

struct SpatialGrid {
    char pad[0x64];
    SubContainerItem12 items[2];
    int f7C;
    int f80;
    int f84;

    SpatialGrid();
};

SpatialGrid::SpatialGrid() {
    this->f7C = 0;
    this->f80 = 0;
    this->f84 = 0;
}

int main() {
    SpatialGrid grid;
    assert(s_constructed == 2);
    assert(grid.f7C == 0);
    assert(grid.f80 == 0);
    assert(grid.f84 == 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

#pragma exceptions off
#include "zone_spatial_grid_init_sub_container.h"

struct SubContainerItem12 {
    void *buffer;
    int f4;
    int f8;
    SubContainerItem12();
    ~SubContainerItem12();
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

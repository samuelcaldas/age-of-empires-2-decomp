#pragma exceptions off
#include "zone_spatial_grid_reset_destructor.h"

extern "C" {
void func_100630(void *ptr);
void func_100670(void *ptr);
}

class SubContainer {
public:
    char pad[0xC];
    ~SubContainer();
};

class SpatialGrid {
public:
    char pad_64[0x64];
    SubContainer sub[2];
    void *buf_7C;

    ~SpatialGrid();
};

SpatialGrid::~SpatialGrid() {
    if ((void **)&buf_7C != 0 && buf_7C != 0) {
        func_100630(buf_7C);
        buf_7C = 0;
    }
}

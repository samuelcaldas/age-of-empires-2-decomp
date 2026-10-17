#pragma exceptions off

#include "zone_spatial_grid_zero_vector3.h"

struct Vector3Int {
    int x;
    int y;
    int z;
};

extern "C" void func_001E62A0(Vector3Int *v) {
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

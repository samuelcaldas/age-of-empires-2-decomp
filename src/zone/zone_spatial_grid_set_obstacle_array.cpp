#pragma exceptions off
#include "zone_spatial_grid_set_obstacle_array.h"

struct SpatialGrid {
    char pad_00[0x12B584];
    unsigned char flag;
    char pad_85[3];
    int count;
    int array_ptr;
};

extern "C" void func_001EE860(SpatialGrid *self, int flag, int array_ptr, int count) {
    if (array_ptr == 0) {
        flag = 0;
    }
    if (count <= 0) {
        flag = 0;
    }
    self->flag = (unsigned char)flag;
    if (flag != 0) {
        self->array_ptr = array_ptr;
        self->count = count;
    } else {
        self->array_ptr = 0;
        self->count = 0;
    }
}

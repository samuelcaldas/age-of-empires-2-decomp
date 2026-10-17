#pragma exceptions off
#include "zone_spatial_grid_leaf_helper.h"

extern "C" {
void func_1FD400(void *p, int flag);
}

extern "C" void func_001E6540(void *p) {
    func_1FD400(p, -1);
}

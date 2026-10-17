#pragma exceptions off

#include "zone_spatial_entity_check_grid_bounds.h"

extern "C" {
int func_123350(float val);
int func_1EE540(void *mgr, void *node);
extern void *D_004D6F34;
}

struct SpatialEntity {
    char pad[0x10];
};

extern "C" int func_001DD7F0(SpatialEntity *self, float x, float y) {
    int gx = func_123350(x);
    int gy = func_123350(y);
    if (gx < 0 || gy < 0) {
        return 0;
    }
    return 1;
}

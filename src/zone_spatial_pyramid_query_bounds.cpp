#pragma exceptions off

#include "zone_spatial_pyramid_query_bounds.h"

extern "C" {
void *func_333500(void *mgr);
}

extern "C" void *func_001D2C70(void *self, float min_x, float min_y, float max_x, float max_y) {
    void *item = func_333500(self);
    if (item == 0) {
        return 0;
    }
    return item;
}

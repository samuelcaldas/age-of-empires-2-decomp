#pragma exceptions off

#include "zone_spatial_node_ctor.h"

extern "C" void *func_001D7AA0(void *self, int arg) {
    char *p = (char *)self;
    *(int *)(p + 0) = 0;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = arg;
    return self;
}

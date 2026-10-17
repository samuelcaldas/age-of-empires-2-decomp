#pragma exceptions off

#include "zone_spatial_view_has_active_mode.h"

struct SubObj {
    char pad[0x26];
    char mode;
};

struct SpatialViewObj {
    char pad[0xA8];
    SubObj *sub;
};

extern "C" int func_001D9020(SpatialViewObj *self) {
    if (!self->sub) {
        return 0;
    }
    char m = self->sub->mode;
    if (m == 1 || m == 2) {
        return 1;
    }
    return 0;
}

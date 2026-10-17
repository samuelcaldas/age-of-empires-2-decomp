#pragma exceptions off

#include "zone_spatial_entity_check_motion_flag.h"

extern "C" {
extern unsigned int D_00492600;
}

struct SubEntity2 {
    char pad[0x18];
    unsigned int flags;
};

struct SubEntity {
    char pad[0x8];
    SubEntity2 *sub2;
};

struct SpatialEntity {
    char pad[0xB4];
    SubEntity *sub;
};

extern "C" int func_001E3600(const SpatialEntity *self) {
    SubEntity *s = self->sub;
    if (s != 0) {
        SubEntity2 *s2 = s->sub2;
        if (s2 != 0) {
            if ((s2->flags & D_00492600) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

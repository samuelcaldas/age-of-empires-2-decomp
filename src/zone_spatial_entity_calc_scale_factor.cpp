#pragma exceptions off

#include "zone_spatial_entity_calc_scale_factor.h"

struct SubEntity {
    char pad[0x1C];
    float f1C;
};

struct ConfigEntity {
    char pad[0xA4];
    float fA4;
};

struct SpatialEntity {
    char pad[0x4];
    ConfigEntity *f4;
    char pad2[0x8];
    SubEntity *f10;
};

extern "C" float func_001DEA90(SpatialEntity *self) {
    if (self->f10 != 0 && self->f10->f1C > 0.0f) {
        return self->f4->fA4 * self->f10->f1C;
    }
    return self->f4->fA4;
}

#include <cassert>
#include "zone_spatial_entity_calc_scale_factor_copy.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

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

static void test_calc_scale_factor_copy() {
    ConfigEntity cfg;
    cfg.fA4 = 15.0f;
    SubEntity sub;
    sub.f1C = 3.0f;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.f4 = &cfg;
    ent.f10 = &sub;

    assert(func_001E2CA0(&ent) == 45.0f);

    sub.f1C = -0.5f;
    assert(func_001E2CA0(&ent) == 15.0f);

    ent.f10 = nullptr;
    assert(func_001E2CA0(&ent) == 15.0f);
}

int main(int argc, char **argv) {
    test_calc_scale_factor_copy();
    return 0;
}

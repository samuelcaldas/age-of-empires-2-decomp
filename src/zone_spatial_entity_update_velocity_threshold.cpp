#pragma exceptions off

#include "zone_spatial_entity_update_velocity_threshold.h"

extern "C" {
float func_333EB0(void *world);
void func_1FCC40(void *v, void *ent, float f0);
float func_1B3860(float val);
void func_151C80(void *ent);
}

struct Vector3 {
    float x;
    float y;
    float z;
};

struct WorldContainer {
    char pad[0xB98];
    void *world;
};

struct SpatialEntity {
    char pad[0x8];
    WorldContainer *container;
    char pad_68[0x68 - 0xC];
    float threshold;
    char pad_BC[0xBC - 0x6C];
    Vector3 *vel_vec;
};

extern "C" void func_001DD710(SpatialEntity *self) {
    if (self->vel_vec != 0) {
        float f0 = func_333EB0(self->container->world);
        func_1FCC40(self->vel_vec, self, f0);
        float sq = self->vel_vec->x * self->vel_vec->x + self->vel_vec->y * self->vel_vec->y + self->vel_vec->z * self->vel_vec->z;
        self->threshold = func_1B3860(sq);
    } else {
        self->threshold = 0.0f;
    }
    func_151C80(self);
}

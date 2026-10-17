#pragma exceptions off

#include "zone_spatial_entity_ctor_simple.h"

extern "C" {
void func_151B20(void *self, int a1, int a2, int a3);
void func_26AD60(void *self, int mask);
void func_1E3710(void *self);
void func_1DC2E0(void *self, int a1, int a2);
}

struct SpatialEntity {
    char pad[0x6C];
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f90;
    int f94;
    int f98;
    float f9C;
    int fA0;
    int fA4;
    int fA8;
    int fAC;
    float fB0;
    int fB4;
    int fB8;
    int fBC;
    int fC0;
    char fC4;
};

extern "C" void func_001DBFC0(SpatialEntity *self, int a1, int a2, int flag) {
    func_151B20(self, a1, a2, 0);
    self->f6C = 0;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = 0;
    self->f7C = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    func_26AD60(self, 0x40);
    self->fC4 = 0;
    self->f98 = 0;
    self->f94 = 0;
    self->f90 = 0;
    self->f9C = 1.0f;
    self->fA4 = 0;
    self->fA0 = 0;
    self->fAC = 0;
    self->fA8 = 0;
    self->fB0 = -1.0f;
    self->fB4 = 0;
    self->fB8 = 0;
    self->fBC = 0;
    self->fC0 = 0;
    func_26AD60(self, 0x20);
    func_1E3710(self);
    if (flag != 0) {
        func_1DC2E0(self, a1, a2);
    }
}

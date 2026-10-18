#pragma exceptions off
#include "zone_spatial_grid_clear_tables.h"

extern "C" {
extern int D_00947960[];
extern int D_004E3294;
extern int D_004E3298;
extern int D_004E329C;
extern int D_004E32A0;
extern int D_004E32A4;
extern int D_004E32A8;
extern int D_004E32AC;
extern int D_004E32B0;
}

#ifndef __MWERKS__
int D_00947960[4] = { 0, 0, 0, 0 };
int D_004E3294 = 0;
int D_004E3298 = 0;
int D_004E329C = 0;
int D_004E32A0 = 0;
int D_004E32A4 = 0;
int D_004E32A8 = 0;
int D_004E32AC = 0;
int D_004E32B0 = 0;
#endif

struct SpatialGridTables {
    char pad_00[0x12B41C];
    char field_12B41C;
    int field_12B420;
    int field_12B424;
    int field_12B428;
    int field_12B42C;
    int field_12B430;
    int field_12B434;
    int field_12B438;
    int field_12B43C;
    int field_12B440;
    int field_12B444;
    int field_12B448;
    int field_12B44C;
    char buffer_12B450[0x80];
    char buffer_12B4D0[0xA0];
    int field_12B570;
    int field_12B574;
    int field_12B578;
    int field_12B57C;
    int field_12B580;
    char pad_12B5A4[0x12B5A4 - 0x12B580 - 4];
    int field_12B5A4;
    int field_12B5A8;
    int field_12B5AC;
};

extern "C" void func_001ED200(SpatialGridTables *self) {
    self->field_12B41C = 0;
    self->field_12B420 = 0;
    self->field_12B424 = 0;
    self->field_12B428 = 0;
    self->field_12B42C = 0;
    self->field_12B430 = 0;
    self->field_12B43C = 0;
    self->field_12B440 = 0;
    self->field_12B434 = 0;
    self->field_12B438 = 0;
    self->field_12B578 = 0;
    self->field_12B444 = 0;
    self->field_12B448 = 0;
    self->field_12B44C = 0;

    func_117CAC(self->buffer_12B450, 0, 0x80);
    func_117CAC(self->buffer_12B4D0, 0, 0xA0);

    self->field_12B57C = 0;
    self->field_12B580 = 0;
    self->field_12B570 = 0;

    func_1EE850(self, 0, 0, 0);
    func_1EE8C0(self, 0, 0, 0);
    func_1EE8F0(self, 0, 0.0f);

    self->field_12B5AC = 0;
    self->field_12B5A4 = 0;
    self->field_12B5A8 = 0;
    self->field_12B574 = -1;

    D_00947960[0] = 0;
    D_00947960[1] = 0;
    D_00947960[2] = 0;
    D_00947960[3] = 0;

    D_004E3294 = 0;
    D_004E3298 = 0;
    D_004E329C = 0;
    D_004E32A0 = 0;
    D_004E32A4 = 0;
    D_004E32A8 = 0;
    D_004E32AC = 0;
    D_004E32B0 = 0;
}

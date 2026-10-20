#pragma exceptions off
#include "zone_spatial_grid_constructor.h"

extern "C" void *D_004D9AD0[16];

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    void *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[10];
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
};

extern "C" ZoneSpatialGrid *func_001F24E0(ZoneSpatialGrid *self) {
    self->vtable_00 = D_004D9AD0;
    self->field_04 = 0;
    self->field_08 = 0;
    self->field_0C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = 0;
    self->field_1C = 0;

    self->field_A98 = 0;
    self->field_A9C = 1;
    self->field_AA0 = 0;
    self->field_AA4 = 0;
    self->field_AA8 = 0;
    self->field_AAC = 1;
    self->field_AB0 = 0;

    for (int i = 0; i < 10; ++i) {
        self->table_20[i] = 0;
        self->buckets_48[i][0] = 0;
        self->table_A48[i] = 0;
        self->table_A70[i] = 0;
    }

    func_001F2DA0(self);
    return self;
}

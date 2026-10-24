#pragma exceptions off
#include "zone_spatial_grid_bounds.h"

struct SpatialItem;

struct SpatialHandle {
    char pad_00[0x3C];
    SpatialItem *field_3C;
};

struct SpatialItem {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
    virtual void method_28(int);
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual void q8(); virtual void q9(); virtual void q10(); virtual void q11();
    virtual void q12(); virtual void q13(); virtual void q14(); virtual void q15();
    virtual void q16(); virtual void q17(); virtual void q18(); virtual void q19();
    virtual void q20(); virtual void q21(); virtual void q22(); virtual void q23();
    virtual void q24(); virtual void q25(); virtual void q26(); virtual void q27();
    virtual void q28(); virtual void q29(); virtual void q30(); virtual void q31();
    virtual void q32(); virtual void q33(); virtual void q34(); virtual void q35();
    virtual void q36(); virtual void q37(); virtual void q38(); virtual void q39();
    virtual void q40(); virtual void q41(); virtual void q42(); virtual void q43();
    virtual void method_DC(int);
    char pad_04[0x3C];
    SpatialHandle *field_40;
    char pad_44[0x48];
    int field_8C;
};

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    SpatialItem *field_0C;
    SpatialItem *field_10;
    void *field_14;
    int field_18;
    SpatialItem *field_1C;
};

extern "C" void func_001F2AD0(ZoneSpatialGrid *self, SpatialItem *elem) {
    if (self->field_0C != 0 && elem != 0) {
        func_001F6CC0(elem, self->field_0C);
    }
    SpatialItem *cur = self->field_0C;
    if (cur == 0) {
        if (self->field_1C != 0 && self->field_1C->field_40 != 0) {
            func_001F6750(self->field_1C->field_40, self->field_1C);
            self->field_1C = 0;
            goto next_step;
        }
    } else {
        if (cur->field_8C == 0 && cur->field_40 != 0) {
            func_001F6750(cur->field_40, self->field_1C);
        }
    }
    self->field_1C = 0;
next_step:
    self->field_0C = elem;
    cur = self->field_0C;
    if (cur != 0 && cur != self->field_10) {
        SpatialHandle *handle = cur->field_40;
        if (handle != 0) {
            self->field_1C = handle->field_3C;
            func_001F6750(handle, self->field_0C);
            return;
        }
        self->field_1C = 0;
        self->field_0C->method_DC(1);
    }
}

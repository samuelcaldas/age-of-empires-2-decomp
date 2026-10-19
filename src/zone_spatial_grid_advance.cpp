#pragma exceptions off
#include "zone_spatial_grid_advance.h"

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

extern "C" int func_001F2C20(ZoneSpatialGrid *self) {
    if (self->field_0C == 0) {
        return 0;
    }
    SpatialItem *item = func_001F6CB0(self->field_0C);
    if (item == 0) {
        return 0;
    }
    item->method_DC(1);
    func_001F2AB0(self, item);
    func_001F2AC0(self, item);
    self->field_0C = item;
    return 1;
}

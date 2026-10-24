#pragma exceptions off
#include "zone_spatial_grid_relink.h"

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

struct GlobalManager {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void method_C8(void *, int, int, int);
};

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    SpatialItem *field_10;
};

extern "C" int func_001F2980(ZoneSpatialGrid *self, int flag) {
    if (self->field_10 == 0) {
        return 0;
    }
    SpatialItem *newItem = func_001F6C90(self->field_10);
    if (newItem == 0 || newItem == self->field_10) {
        return 0;
    }
    SpatialItem *elem = self->field_10;
    if (flag == 0) {
        func_001F6CA0(newItem, elem);
        self->field_10 = newItem;
    } else {
        if (func_001F6C90(newItem) == elem) {
            func_001F6CA0(newItem, 0);
        }
        func_001F2CB0(self, func_001F6CD0(elem));
        self->field_10 = newItem;
    }
    self->field_10->method_DC(1);
    self->field_10->method_28(2);
    if (D_004D89C0 != 0) {
        D_004D89C0->method_C8(D_004D8940, 0, 0, 0);
    }
    return 1;
}

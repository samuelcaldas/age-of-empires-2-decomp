#pragma exceptions off

#include "zone_spatial_view_update_frustum.h"

extern "C" {
void *func_333EB0(void *obj);
void *func_3334A0(void *obj, int id);
void func_1DAC10(void *a0, void *a1, void *a2, int a3, float f12);
void func_1DAFE0(void *a0, float f12);
extern void *D_004E3180;
}

class SpatialViewObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void Method30(float f);
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void Method54(float f);
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void Method74();

    char pad[0xA8 - 4];
    struct SubObj *sub;
    char pad1[0xB0 - 0xAC];
    float field_B0;
};

struct SubObj {
    char pad[0x8];
    void *field_8;
    int field_C;
    char pad1[0x18 - 0x10];
    int field_18;
    float field_1C;
};

extern "C" int func_001D9430(SpatialViewObj *self, void *a1, void *a2) {
    if (!self->sub) {
        return 0;
    }
    if (self->sub->field_1C <= 0.0f) {
        return 0;
    }
    self->Method74();
    self->Method30(self->field_B0);
    return 1;
}

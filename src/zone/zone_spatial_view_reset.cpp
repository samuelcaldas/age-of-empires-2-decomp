#pragma exceptions off

#include "zone_spatial_view_reset.h"

extern "C" void func_1FCD90(void *ptr);

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
    void *field_A8;
};

extern "C" void func_001D90C0(SpatialViewObj *self) {
    self->Method74();
    if (self->field_A8 != 0) {
        func_1FCD90(self->field_A8);
    }
}

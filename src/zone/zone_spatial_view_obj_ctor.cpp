#pragma exceptions off

#include "zone_spatial_view_obj_ctor.h"

extern void *__vt__004D9610;

extern "C" {
extern float D_004E2808;
}

class SpatialViewObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void Method20(float *a1, float *a2, int a3);
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void Method90(int p1, int p2);

    int fields[37];
    float f98;
    float f9C;
    int fA0;
    float fA4;
    int fA8;
    int fAC;
    int fB0;
    int fB4;
    int fB8;
};

extern "C" SpatialViewObj *func_001D8AF0(SpatialViewObj *self) {
    *(void **)self = &__vt__004D9610;

    self->fields[0] = 0;
    self->fields[1] = 0;
    self->fields[2] = 0;
    self->fields[3] = 0;
    self->fields[4] = 0;
    self->fields[5] = 0;
    self->fields[6] = 0;
    self->fields[7] = 0;
    self->fields[8] = 0;
    self->fields[9] = 0;
    self->fields[10] = 0;
    self->fields[11] = 0;
    self->fields[12] = 0;
    self->fields[13] = 0;
    self->fields[14] = 0;
    self->fields[15] = 0;
    self->fields[16] = 0;
    self->fields[17] = 0;
    self->fields[18] = 0;
    self->fields[19] = 0;
    self->fields[20] = 0;
    self->fields[21] = 0;
    self->fields[22] = 0;
    self->fields[23] = 0;
    self->fields[24] = 0;
    self->fields[25] = 0;
    self->fields[26] = 0;
    self->fields[27] = 0;
    self->fields[28] = 0;
    self->fields[29] = 0;
    self->fields[30] = 0;
    self->fields[31] = 0;
    self->fields[32] = 0;
    self->fields[33] = 0;
    self->fields[34] = 0;
    self->fields[35] = 0;
    self->fields[36] = 0;

    self->f98 = D_004E2808;
    self->f9C = D_004E2808;
    self->fA0 = 0;
    self->fA4 = D_004E2808;
    self->fA8 = 0;
    self->fAC = 0;
    self->fB0 = 0;
    self->fB4 = 0;
    self->fB8 = 0;

    float sp20[3];
    float sp30[3];
    sp30[0] = 0.0f;
    sp20[0] = 1.0f;
    sp30[1] = 1.0f;
    sp20[1] = 0.0f;
    sp30[2] = 0.0f;
    sp20[2] = 0.0f;

    self->Method20(sp20, sp30, 1);
    self->Method90(1, 1);

    return self;
}

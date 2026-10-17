#pragma exceptions off
#pragma inline_intrinsics on

#include "zone_spatial_view_move_forward.h"

extern "C" {
extern float D_004E2824;
void func_314FE0(void *out, const void *in, float scale);
float __s_abs(float);
}

struct Vector3 {
    float x;
    float y;
    float z;
};

class SpatialViewObj {
public:
    virtual void m0();
    virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33();
    virtual void Method90(int p1, int p2);

    char pad_vtable_to_pos[0x34 - 4];
    Vector3 pos;
    Vector3 basis[3];
};

extern "C" void func_001DAF50(SpatialViewObj *self, float val) {
    if (__s_abs(val) <= D_004E2824) {
        return;
    }
    Vector3 delta;
    func_314FE0(&delta, &self->basis[2], val);
    self->pos.x += delta.x;
    self->pos.y += delta.y;
    self->pos.z += delta.z;
    self->Method90(0, 1);
}

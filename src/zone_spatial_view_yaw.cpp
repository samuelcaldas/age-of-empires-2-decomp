#pragma exceptions off
#pragma inline_intrinsics on

#include "zone_spatial_view_yaw.h"

extern "C" {
extern float D_004E2824;
void func_1D7ED0(void *out_matrix, const void *axis, float angle);
void func_1D8000(void *out_vec, const void *matrix, const void *in_vec);
float __s_abs(float);
float sqrtf(float);
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

extern "C" void func_001DAFE0(SpatialViewObj *self, float val) {
    if (__s_abs(val) <= D_004E2824) {
        return;
    }
    float rot_matrix[9];
    func_1D7ED0(rot_matrix, &self->basis[1], val);

    Vector3 rotated_right;
    func_1D8000(&rotated_right, rot_matrix, &self->basis[0]);
    self->basis[0] = rotated_right;

    Vector3 rotated_forward;
    func_1D8000(&rotated_forward, rot_matrix, &self->basis[2]);
    self->basis[2] = rotated_forward;

    float len0 = sqrtf(self->basis[0].x * self->basis[0].x +
                       self->basis[0].y * self->basis[0].y +
                       self->basis[0].z * self->basis[0].z);
    self->basis[0].x /= len0;
    self->basis[0].y /= len0;
    self->basis[0].z /= len0;

    float len2 = sqrtf(self->basis[2].x * self->basis[2].x +
                       self->basis[2].y * self->basis[2].y +
                       self->basis[2].z * self->basis[2].z);
    self->basis[2].x /= len2;
    self->basis[2].y /= len2;
    self->basis[2].z /= len2;

    self->Method90(0, 0);
}

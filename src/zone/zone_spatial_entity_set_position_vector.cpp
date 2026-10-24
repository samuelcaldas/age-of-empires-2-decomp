#pragma exceptions off

#include "zone_spatial_entity_set_position_vector.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

#define VIRT_10(base) \
    virtual void m##base##_0(); virtual void m##base##_1(); virtual void m##base##_2(); virtual void m##base##_3(); virtual void m##base##_4(); \
    virtual void m##base##_5(); virtual void m##base##_6(); virtual void m##base##_7(); virtual void m##base##_8(); virtual void m##base##_9();

class SpatialEntity {
public:
    VIRT_10(0)
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void Method44(float x, float z, float y);

    char pad[0x90 - 4];
    Vector3 pos_90;
};

extern "C" void func_001E00B0(SpatialEntity *self, const Vector3 *pos) {
    self->pos_90 = *pos;
    self->Method44(pos->x, pos->z, pos->y);
}

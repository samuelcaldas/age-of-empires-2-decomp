#pragma exceptions off

#include "zone_spatial_entity_set_heading.h"

#define VIRT_10(base) \
    virtual void m##base##_0(); virtual void m##base##_1(); virtual void m##base##_2(); virtual void m##base##_3(); virtual void m##base##_4(); \
    virtual void m##base##_5(); virtual void m##base##_6(); virtual void m##base##_7(); virtual void m##base##_8(); virtual void m##base##_9();

class SpatialEntity {
public:
    VIRT_10(0)
    VIRT_10(1)
    VIRT_10(2)
    VIRT_10(3)
    VIRT_10(4)
    VIRT_10(5)
    VIRT_10(6)
    VIRT_10(7)
    VIRT_10(8)
    VIRT_10(9)
    VIRT_10(10)
    VIRT_10(11)
    VIRT_10(12)
    VIRT_10(13)
    VIRT_10(14)
    VIRT_10(15)
    VIRT_10(16)
    VIRT_10(17)
    virtual void m180();
    virtual void m181();
    virtual void m182();
    virtual void m183();
    virtual void Method2E8();

    char pad_vtable_to_heading[0x7C - 4];
    float heading;
};

extern "C" void func_001DD6F0(SpatialEntity *self, float heading) {
    self->heading = heading;
    self->Method2E8();
}

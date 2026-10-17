#pragma exceptions off

#include "zone_spatial_entity_dispatch_motion_callback.h"

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
    virtual void m120();
    virtual void Method1EC();
};

extern "C" void func_001DEDB0(SpatialEntity *self) {
    self->Method1EC();
}

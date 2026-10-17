#pragma exceptions off

#include "zone_spatial_entity_finalize_motion_step.h"

extern "C" {
void func_1FCD90(void *p);
}

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
    virtual void m150();
    virtual void m151();
    virtual void m152();
    virtual void m153();
    virtual void m154();
    virtual void Method274();

    char pad[0xB4 - 4];
    void *fB4;
};

extern "C" void func_001DFC10(SpatialEntity *self) {
    self->Method274();
    if (self->fB4 != 0) {
        func_1FCD90(self->fB4);
    }
}

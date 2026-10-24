#pragma exceptions off

#include "zone_spatial_entity_reset_motion_state.h"

extern "C" {
void func_26A420(void *ent);
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
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void Method144(int val); // 79th method -> 8 + 79*4 = 324 = 0x144

    VIRT_10(8)
    VIRT_10(9)
    VIRT_10(10)
    VIRT_10(11)
    VIRT_10(12)
    VIRT_10(13)
    virtual void m140();
    virtual void m141();
    virtual void m142();
    virtual void m143();
    virtual void m144_d();
    virtual void m145();
    virtual void m146();
    virtual void m147();
    virtual void Method258(float val); // 148th method -> 8 + 148*4 = 600 = 0x258

    virtual void m149();
    virtual void Method260(float val); // 150th method -> 8 + 150*4 = 608 = 0x260
};

extern "C" void func_001E02E0(SpatialEntity *self) {
    self->Method258(0.0f);
    self->Method260(0.0f);
    self->Method144(0);
    func_26A420(self);
}

#pragma exceptions off

#include "zone_spatial_entity_dispatch_config_action_a8.h"

struct ConfigEntity {
    char pad[0xA8];
    void *fA8;
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
    virtual void m15();
    virtual void m16();
    virtual void Method4C(void *p);

    ConfigEntity *config;
};

extern "C" int func_001E36A0(SpatialEntity *self) {
    if (self->config->fA8 != 0) {
        self->Method4C(self->config->fA8);
        return 1;
    }
    return 0;
}

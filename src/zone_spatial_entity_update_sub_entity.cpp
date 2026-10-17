#pragma exceptions off

#include "zone_spatial_entity_update_sub_entity.h"

extern "C" {
void *func_266780(void *self);
}

struct SubEntityInfo {
    unsigned char type;
};

class SubEntity {
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
    virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36();
    virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40();
    virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47();
    virtual void MethodC4(float speed);

    SubEntityInfo *info;
};

struct SpatialEntity {
    char pad[0x7C];
    float f7C;
};

extern "C" void *func_001DCA30(SpatialEntity *self) {
    SubEntity *sub = (SubEntity *)func_266780(self);
    if (sub == 0) {
        return 0;
    }
    if (sub->info->type >= 0x1E) {
        sub->MethodC4(self->f7C);
    }
    return sub;
}

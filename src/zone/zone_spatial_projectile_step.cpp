#pragma exceptions off

#include "zone_spatial_projectile_step.h"

struct MapBounds {
    char pad[8];
    int width;
    int height;
};

struct MapObj {
    char pad[0x3C];
    MapBounds *bounds;
};

struct WorldObj {
    char pad[0xB98];
    MapObj *map;
};

class EntityMotion {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual float CheckTerrain(float x, float y, float z); // offset 0x44
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
    virtual void OnOutOfBounds(); // offset 0x80

    char pad_4[4];        // 0x4
    WorldObj *world;      // 0x8
    char pad_44[0x44 - 0xC]; // 0xC..0x43
    float x;              // 0x44
    float y;              // 0x48
    float z;              // 0x4C
    char pad_70[0x70 - 0x50]; // 0x50..0x6F
    float vx;             // 0x70
    float vy;             // 0x74
    float vz;             // 0x78
};

extern "C" int func_001D8800(EntityMotion *self) {
    float new_x = self->x + self->vx;
    float new_y = self->y + self->vy;
    float new_z = self->z + self->vz;

    if (new_x < 0.0f || !(new_x < (float)self->world->map->bounds->width) ||
        new_y < 0.0f || !(new_y < (float)self->world->map->bounds->height)) {
        self->OnOutOfBounds();
    }

    float res = self->CheckTerrain(new_x, new_y, new_z);
    return (int)(res == self->z);
}

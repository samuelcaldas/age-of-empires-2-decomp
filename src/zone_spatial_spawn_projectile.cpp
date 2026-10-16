#pragma exceptions off

#include "zone_spatial_spawn_projectile.h"

extern "C" {
void *func_366C20(void *factory);
void func_34E6E0(void *obj, void *self, void *target, void *info, float x, float y, float z);
void func_139430(void *list, void *obj);
extern int D_4E35DC;
}

struct TargetEntity {
    char pad[0x24];
    short id;
};

struct LaunchInfo {
    char pad[0x44];
    float x;
    float y;
    float z;
};

struct SpatialEntityMaster {
    char pad_cc[0xCC];
    void *list_cc;
    char pad_f8[0xF8 - 0xD0];
    int field_F8;
    int pad_100;
    float field_100;
    short field_104;
    char field_106;
    char field_107;
};

extern "C" void func_001D8650(SpatialEntityMaster *self, TargetEntity *target, LaunchInfo *info, int arg3, float f12) {
    self->field_F8 = arg3;
    void *obj = func_366C20(&D_4E35DC);
    if (obj != 0) {
        func_34E6E0(obj, self, target, info, info->x, info->y, info->z);
    }
    if (obj != 0) {
        func_139430(self->list_cc, obj);
    }
    self->field_100 = f12;
    if (target != 0) {
        self->field_104 = target->id;
        self->field_107 = 1;
    } else {
        self->field_104 = -1;
        self->field_107 = 0;
    }
}

#pragma exceptions off

#include "zone_spatial_projectile_collision.h"

extern "C" {
void *func_100850(unsigned int size);
void func_1ECFC0(void *self);
void func_001DB890(void *self, void *target_pos, void *cur_pos, int a3, int t0, int t1, float f12);
float func_3675D0(void *obj);
void func_1ED050(void *list, void *target, int zero, float f12, float f13);
void func_001ECFD0(void *list, int flag);
extern void *D_938FD0[];
extern int D_004E324C;
}

struct ProjectileConfig {
    char pad[0x20];
    float radius_x;
    float radius_y;
};

struct CollisionTarget {
    char pad[8];
    void *entity;
};

struct ProjectileMotion {
    void **vtable;
    ProjectileConfig *config; // 0x4
    char pad_44[0x44 - 0x8];
    float x; // 0x44
    float y; // 0x48
    float z; // 0x4C
};

struct HitList {
    int count;
};

extern "C" void *func_001D8900(ProjectileMotion *self, float tx, float ty, float tz) {
    if (self->config->radius_x <= 0.0f || self->config->radius_y <= 0.0f) {
        return 0;
    }

    HitList *list = (HitList *)func_100850(4);
    if (list != 0) {
        func_1ECFC0(list);
    }

    float target_pos[3];
    target_pos[0] = tx;
    target_pos[1] = tz;
    target_pos[2] = ty;

    float cur_pos[3];
    cur_pos[0] = self->x;
    cur_pos[1] = self->z;
    cur_pos[2] = self->y;

    func_001DB890(self, target_pos, cur_pos, 0, 0, 0, 1.0f);

    for (int i = 0; i < D_004E324C; i++) {
        CollisionTarget *target = (CollisionTarget *)D_938FD0[i];
        void *ent = target->entity;
        if (ent == 0) {
            continue;
        }

        float ent_z = *(float *)((char *)ent + 0x4C);
        float diff = ent_z - self->z;
        float radius = func_3675D0(ent);
        if (diff < -radius) {
            continue;
        }

        float self_radius = func_3675D0(self);
        if (diff <= self_radius) {
            func_1ED050(list, ent, 0, 0.0f, 0.0f);
        }
    }

    if (list->count == 0) {
        func_001ECFD0(list, 1);
        list = 0;
    }

    return list;
}

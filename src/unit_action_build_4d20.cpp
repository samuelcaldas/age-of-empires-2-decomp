#pragma exceptions off
#include "unit_action_build_4d20.h"

extern "C" {
    int func_123350(float val);
    int func_801AAB30();
    void func_802753E0(void *self, void *target, int zero,
                       float x, float y, float z,
                       float scatter_x, float scatter_y);
    void func_801958C0(void *self, void *target, float x, float y, float z);
}

static void spawn_scattered_particles(void *self, void *target, void *proto, int count,
                                      float x, float y, float z) {
    for (int i = 0; i < count; ++i) {
        float width = *(float *)((char *)proto + 0x14C);
        float rand_w = (float)func_801AAB30();
        float scatter_x = (width * rand_w) / 32767.0f - width / 2.0f;

        float height = *(float *)((char *)proto + 0x150);
        float rand_h = (float)func_801AAB30();
        float scatter_y = (height * rand_h) / 32767.0f - height / 2.0f;

        func_802753E0(self, target, 0, x, y, z, scatter_x, scatter_y);
    }
}

static bool check_spawn_limits(void *proto, void *owner) {
    if (*(short *)((char *)proto + 0x104) >= 0) {
        return true;
    }
    int v1 = *(int *)((char *)proto + 0x158);
    if (v1 < 0) {
        return false;
    }
    int limit = *(int *)((char *)owner + 0x6C);
    return v1 < limit;
}

int func_274D20(void *self, void *target, float x, float y, float z) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *proto = *(void **)((char *)self + 0x4);
    void *owner = *(void **)((char *)self + 0x8);
#endif

    if (!check_spawn_limits(proto, owner)) {
        return 0;
    }

    int capacity = *(unsigned char *)((char *)proto + 0x145);
    int s1 = 0;
    if (capacity <= 0) {
        s1 = 1;
    } else {
        int v0 = func_123350(*(float *)((char *)self + 0x120));
        int v1_val = *(unsigned char *)((char *)self + 0x11A);
        if (v1_val != 0 && capacity < v0) {
            s1 = 1;
            capacity = v0 - v1_val;
        }
    }

    int spawn_count = 1;
    if (*(short *)((char *)proto + 0xE) == 0xD) {
        spawn_count = capacity;
    } else {
        float f0 = *(float *)((char *)proto + 0x14C);
        float f1 = *(float *)((char *)proto + 0x150);
        if (f0 > 0.0f && f1 > 0.0f) {
            int rnd = (func_801AAB30() * 2) / 32767;
            spawn_count = rnd + 1;
            if (spawn_count > capacity) {
                spawn_count = capacity;
            }
        }
    }

    *(unsigned char *)((char *)self + 0x11A) = 0;
    *(unsigned char *)((char *)self + 0x11A) += (unsigned char)spawn_count;

    if (s1 != 0) {
        spawn_count -= 1;
    }

    if (spawn_count > 0) {
        spawn_scattered_particles(self, target, proto, spawn_count, x, y, z);
    }

    if (s1 != 0 && *(short *)((char *)proto + 0x104) >= 0) {
        func_801958C0(self, target, x, y, z);
    }

    return 0;
}

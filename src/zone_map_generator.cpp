#pragma once
#pragma exceptions off

#include "zone_map_generator.h"

extern "C" {
int func_1AAB30(void);
void func_1AAB70(int handle);
void func_001C97D0(void *self, int p1, void *world, int p3, int width, int height);
void *func_100850(int size);
void func_22F2F0(void *obj, int arg4, int p3);

extern void *D_004E3180;
}

struct WorldObject {
    char pad_0[0x31];
    unsigned char mode;     // 0x31
};

struct SystemManager {
    char pad_0[0x4C];
    int handle;             // 0x4C
    int f_50;               // 0x50
    int f_54;               // 0x54
};

struct GeneratorObject {
    void **vtable;          // 0x0
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8ED8];    // 0x10..0x8EE7
    WorldObject *m_world;   // 0x8EE8 (-0x7118)
};

typedef void (*GenExecFn)(void *obj);
typedef void (*GenDeleteFn)(void *obj, int flag);

extern "C" void func_001CD620(void *self, int width_param, int height_param, int arg4) {
    ZoneLayout *zm = (ZoneLayout *)self;
    WorldObject *world = zm->m_world;

    unsigned char old_mode = world->mode;
    world->mode = 3;

    SystemManager *sys = (SystemManager *)D_004E3180;
    int handle = sys->handle;
    if (handle == -1) {
        handle = func_1AAB30();
    }
    sys->f_54 = handle;

    if (width_param < 0) width_param = zm->width;
    if (height_param < 0) height_param = zm->height;

    func_1AAB70(handle);
    func_001C97D0(zm, 0, zm->m_world, 0, width_param, height_param);
    func_1AAB70(handle);

    GeneratorObject *gen = (GeneratorObject *)func_100850(0x2F7F8);
    if (gen != 0) {
        func_22F2F0(gen, arg4, -1);
        ((GenExecFn)gen->vtable[3])(gen);
    }

    if (gen != 0) {
        ((GenDeleteFn)gen->vtable[2])(gen, 1);
    }

    world->mode = old_mode;
}

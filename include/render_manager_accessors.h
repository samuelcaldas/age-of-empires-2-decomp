#ifndef RENDER_MANAGER_ACCESSORS_H
#define RENDER_MANAGER_ACCESSORS_H

struct PlayerSub404 {
    char pad_00[0x3C];
    void *field_3C;
    char pad_40[0x10];
    short field_50;
    char pad_52[0x46];
    short field_98;
};

struct SurfaceEntry {
    int f0, f4, f8;
};

struct RenderManagerAccessors {
    void *vtable;
    char pad_04[0x28];
    int field_2C;
    char pad_30[0x17C];
    void *field_1AC;
    char pad_1B0[0x18];
    int field_1C8;
    int field_1CC;
    int field_1D0;
    char pad_1D4[0x28];
    SurfaceEntry *field_1FC;
    char pad_200[0x204];
    PlayerSub404 *field_404;
};

extern "C" {
void *func_100850(int size);
void *func_32E8C0(void *obj);
int func_226610(int f2c, int p1, int p2, int p3);
void func_1C9F00(void *f3c);
int func_1880E0();
int func_190AF0(void *f1ac);

void *func_00185d00();
int func_00185d40(RenderManagerAccessors *self);
void func_00185d60(RenderManagerAccessors *self, int a1, int a2);
void func_00185d70(RenderManagerAccessors *self, short a1);
int func_00185dc0(RenderManagerAccessors *self, int a1);
SurfaceEntry *func_00185e20(RenderManagerAccessors *self, int a1);
}

#endif

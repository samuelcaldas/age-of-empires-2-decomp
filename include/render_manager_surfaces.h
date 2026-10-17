#ifndef RENDER_MANAGER_SURFACES_H
#define RENDER_MANAGER_SURFACES_H

struct SurfaceEntry {
    int f0;
    int f4;
    int f8;
};

struct RenderManagerSurfaces {
    void *vtable;
    char pad_04[0x6C];
    void *field_70;
    char pad_74[0xC];
    short field_80;
    char pad_82[2];
    void *field_84;
    char pad_88[0x170];
    short field_1F8;
    char pad_1FA[2];
    SurfaceEntry *field_1FC;
};

extern const char D_004919F0[];

extern "C" {
void *func_25F2B0(int size);
void func_25D6D0(void *obj, const char *name, int id);
void *func_1143F8(int count, int size);
void *func_1ABA00(void *f70);
void func_1ABA70(void *f70);
int func_2257A0(void *s0, int s2);
int func_223000(int s2);
int func_223040(int s2);

int func_001857b0(RenderManagerSurfaces *self);
int func_00185810(RenderManagerSurfaces *self);
}

#endif

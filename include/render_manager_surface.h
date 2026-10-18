#ifndef RENDER_MANAGER_SURFACE_H
#define RENDER_MANAGER_SURFACE_H

struct SubObj1AC {
    char pad_00[0x10E0];
    int field_10E0;
};

struct RenderManagerSurface {
    char pad_00[0x6C];
    void *field_6C;
    char pad_70[0x13C];
    SubObj1AC *field_1AC;
    char pad_1B0[0x258];
    int field_408;
    char pad_40C[0xC60];
    void *field_106C;
};

extern void *D_00598DA0;

extern "C" {
void *func_1AE480(void *arg);
int func_1AB7E0(void *surf, void *obj, int w, int h, int x, int y, int flags);
void func_1AE510(void *arg, void *ptr);
void func_1F34E0(void *arg);
void func_25D060(int id);
void func_00A80BB0();

int func_001889a0(RenderManagerSurface *self);
void func_00188a30();
void func_00188a40(RenderManagerSurface *self);
int func_00188a60();
int func_00188a70(RenderManagerSurface *self);
void func_00188a90(char code);
int func_00188ba0();
int func_00188bb0();
void func_00188bc0();
void func_00188bd0();
int func_00188be0();
int func_00188bf0();
}

#endif // RENDER_MANAGER_SURFACE_H

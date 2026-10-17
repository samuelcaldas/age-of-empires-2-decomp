#ifndef RENDER_MANAGER_COORDS_H
#define RENDER_MANAGER_COORDS_H

struct SubObj404C {
    char pad_00[0x30];
    char field_30;
};

struct POINT {
    int x;
    int y;
};

struct RenderManagerCoords {
    virtual void Method00();
    virtual void Method04();
    virtual void Method08();
    virtual void Method0C();
    virtual void Method10();
    virtual void Method14();
    virtual void Method20();

    char pad_04[0x80];
    void *field_84;
    char pad_88[4];
    short field_8C;
    char pad_8E[2];
    void **field_90;
    char pad_94[0x118];
    void *field_1AC;
    char pad_1B0[0x254];
    SubObj404C *field_404;
    char pad_408[0x718];
    int field_B20;
    int field_B24;
};

extern "C" {
int func_185DC0(RenderManagerCoords *self, int a1);
void func_190C40(void *arg);

void *func_00185e50(RenderManagerCoords *self, int a1);
void *func_00185e70(RenderManagerCoords *self, int a1);
void func_00185ec0(RenderManagerCoords *self);
void func_00185f00(RenderManagerCoords *self, int a1, int a2);
void func_00185f80(void *unused, int flags, unsigned int coords,
                   POINT *pt, int *b1, int *b2, int *b3, int *b4);
}

#endif

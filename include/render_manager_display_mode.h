#ifndef RENDER_MANAGER_DISPLAY_MODE_H
#define RENDER_MANAGER_DISPLAY_MODE_H

struct SubObj70 {
    char pad_00[0x18];
    int field_18;
    int field_1C;
};

struct SubObj6C {
    char pad_00[0x44];
    unsigned char field_44;
    unsigned char field_45;
};

struct SubObj404Item {};

struct SubObj404 {
    char pad_00[0x50];
    short count_50;
    char pad_52[2];
    SubObj404Item **items_54;
};

struct SubObj28 {
    char pad_00[0xAC];
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
};

struct RenderManagerDisplayMode {
    char pad_00[0x2C];
    void *field_2C;
    char pad_30[0x10];
    int field_40;
    char pad_44[0x28];
    SubObj6C *field_6C;
    SubObj70 *field_70;
    char pad_74[0x164];
    void *field_1D8;
    char pad_1DC[0x7F0];
    int field_9CC[11];
    int field_9F8[9];
    char pad_A1C[0x640];
    int field_105C;
};

extern int D_004E89EC;
extern const char D_00491A28[];

extern "C" {
void func_1DB4E0(void *);
void func_1AAF80(void *);
void func_188A40(void *);
void func_2264E0(void *, int, int);
void func_2254D0(void *, void *);
void func_225450(void *, void *);
void func_1F2CB0(void *, const char *);
void func_00A80BB0();
void func_25D2D0(int, int);
void func_25D060(void *);

void func_00188740(RenderManagerDisplayMode *self, int a1, int a2);
int func_00188870(RenderManagerDisplayMode *self, int idx);
void func_00188880(RenderManagerDisplayMode *self, int idx, int val);
void func_00188890(RenderManagerDisplayMode *self, int idx);
void func_001888b0(RenderManagerDisplayMode *self, int idx, int val);
void func_00188900(RenderManagerDisplayMode *self, int idx, int *out);
int func_00188940(RenderManagerDisplayMode *self, void *a1, int a2, int a3);
int func_00188980(RenderManagerDisplayMode *self);
void func_00188990(RenderManagerDisplayMode *self, int val);
}

#endif // RENDER_MANAGER_DISPLAY_MODE_H

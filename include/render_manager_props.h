#ifndef RENDER_MANAGER_PROPS_H
#define RENDER_MANAGER_PROPS_H

struct RenderManagerProps {
    char pad_00[0x24];
    void *field_24;
    char pad_28[0x8E4];
    float field_90C;
    unsigned char field_910;
    char field_911[0x80];
    unsigned char field_991;
    unsigned char field_992;
    unsigned char field_993;
    unsigned char field_994;
    unsigned char field_995;
    unsigned char field_996;
    unsigned char field_997;
    unsigned char field_998;
    unsigned char field_999;
    unsigned char field_99A;
    unsigned char field_99B;
    unsigned char field_99C;
    unsigned char field_99D[9];
    unsigned char field_9A6;
    unsigned char field_9A7;
    unsigned char field_9A8[9];
    char pad_9B1[0x7];
    unsigned char field_9B8;
    char pad_9B9[3];
    int field_9BC;
    int field_9C0;
    char pad_9C4[0x164];
    int field_B28;
    char pad_B2C[0x534];
    unsigned char field_1060;
};

extern "C" {
void func_3444E0(void *arg);

void func_00188020(RenderManagerProps *self, unsigned char val);
void func_00188030(RenderManagerProps *self, int val);
int func_00188040(RenderManagerProps *self);
unsigned char func_00188050(RenderManagerProps *self);
float func_00188060(RenderManagerProps *self);
unsigned char func_00188070(RenderManagerProps *self);
unsigned char func_00188080(RenderManagerProps *self);
int func_001880a0(RenderManagerProps *self);
int func_001880b0(RenderManagerProps *self);
const char *func_001880c0(RenderManagerProps *self);
unsigned char func_001880d0(RenderManagerProps *self);
unsigned char func_001880e0(RenderManagerProps *self);
unsigned char func_001880f0(RenderManagerProps *self);
unsigned char func_00188100(RenderManagerProps *self);
unsigned char func_00188110(RenderManagerProps *self);
unsigned char func_00188120(RenderManagerProps *self);
unsigned char func_00188130(RenderManagerProps *self);
unsigned char func_00188140(RenderManagerProps *self);
unsigned char func_00188150(RenderManagerProps *self);
unsigned char func_00188160(RenderManagerProps *self);
unsigned char func_00188170(RenderManagerProps *self);
unsigned char func_00188180(RenderManagerProps *self, int idx);
unsigned char func_00188190(RenderManagerProps *self, int idx);
unsigned char func_001881b0(RenderManagerProps *self, int idx);
unsigned char func_001881c0(RenderManagerProps *self);
unsigned char func_001881d0(RenderManagerProps *self);
unsigned char func_001881e0(RenderManagerProps *self, int idx);
unsigned char func_00188210(RenderManagerProps *self);
unsigned char func_00188220(RenderManagerProps *self);
void func_00188230(RenderManagerProps *self);
void func_00188240(RenderManagerProps *self, unsigned char val);
void func_00188250(RenderManagerProps *self, float val);
}

#endif // RENDER_MANAGER_PROPS_H

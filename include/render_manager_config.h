#ifndef RENDER_MANAGER_CONFIG_H
#define RENDER_MANAGER_CONFIG_H

struct RenderManagerConfigSnapshot {
    char pad_00[0x1AC];
    void *field_1AC;
    char pad_1B0[0x75C];
    char field_90C[0xB0];
};

extern "C" {
void *func_192BF0(void *obj, int *size_out);
void func_00187ca0(RenderManagerConfigSnapshot *self);
void func_00187d00(void *self, const unsigned char *data);
void func_00187ea0(void *self, unsigned char *data);

void func_188250(void *self, float val);
void func_188240(void *self, unsigned char val);
void func_188260(void *self, const void *ptr);
void func_1882B0(void *self, unsigned char val);
void func_1882D0(void *self, unsigned char val);
void func_1882F0(void *self, unsigned char v1, unsigned char v2, unsigned char v3);
void func_188300(void *self, unsigned char val);
void func_188310(void *self, unsigned char val);
void func_188320(void *self, unsigned char val);
void func_188330(void *self, unsigned char val);
void func_188340(void *self, unsigned char val);
void func_188350(void *self, unsigned char val);
void func_188360(void *self, unsigned char val);
void func_1883C0(void *self, unsigned char val);
void func_1883F0(void *self, unsigned char val);
void func_188020(void *self, unsigned char val);
void func_188490(void *self, float val);
void func_1884B0(void *self);
void func_1884F0(void *self);
void func_1884C0(void *self);
void func_188500(void *self);
void func_1883B0(void *self, int idx, unsigned char val);
void func_1883D0(void *self, int idx, unsigned char val);

float func_188060(void *self);
unsigned char func_188070(void *self);
const char *func_1880C0(void *self);
char *func_11ABBC(char *dst, const char *src);
unsigned char func_1880D0(void *self);
unsigned char func_1880E0(void *self);
unsigned char func_1880F0(void *self);
unsigned char func_188100(void *self);
unsigned char func_188110(void *self);
unsigned char func_188120(void *self);
unsigned char func_188130(void *self);
unsigned char func_188140(void *self);
unsigned char func_188150(void *self);
unsigned char func_188160(void *self);
unsigned char func_1881D0(void *self);
unsigned char func_188170(void *self);
unsigned char func_1881C0(void *self);
unsigned char func_188220(void *self);
unsigned char func_188050(void *self);
float func_1884E0(void *self);
unsigned char func_188510(void *self);
unsigned char func_188520(void *self);
unsigned char func_1881B0(void *self, int idx);
unsigned char func_1881E0(void *self, int idx);
}

#endif // RENDER_MANAGER_CONFIG_H

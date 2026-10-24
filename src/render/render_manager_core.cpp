#pragma exceptions off

extern "C" {
void func_117CAC(void *dst, int val, int size);
void func_188250(void *self, float f);
void func_188240(void *self, int);
void func_188290(void *self, int);
void func_1882A0(void *self, int);
void func_1882B0(void *self, int);
void func_1882D0(void *self, int);
void func_1882F0(void *self, int, int, int);
void func_188300(void *self, int);
void func_188310(void *self, int);
void func_188330(void *self, int);
void func_188340(void *self, int);
void func_1884A0(void *self, float f);
void func_188490(void *self, float f);
void func_1884F0(void *self);
void func_188500(void *self);
void func_188360(void *self, int);
void func_1883C0(void *self, int);
void func_1883B0(void *self, int, int);
void func_188370(void *self, int, int);
void func_188390(void *self, int, int);
void func_1883D0(void *self, int, int);
void func_1883E0(void *self, int);
void func_1883F0(void *self, int);
void func_188350(void *self, int);
void func_188260(void *self, const void *ptr);

extern void *D_004E3180;
extern int D_004E3110, D_004E3114, D_004E30FC, D_004E3100, D_004E3104;
extern int D_004E3108, D_004E310C, D_004E315C;
extern const char D_004D7DB0[];

void *func_00184340(void *this_ptr, void *a1, int a2) {
    char *p = (char *)this_ptr;
    *(const void **)p = D_004D7DB0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x48) = -1;
    *(int *)(p + 0x4C) = -1;
    *(int *)(p + 0x50) = -1;
    *(int *)(p + 0x54) = -1;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x9C4) = 0;
    func_117CAC(p + 0x9F8, 0, 0x24);
    func_117CAC(p + 0x90C, 0, 0xB0);
    func_117CAC(p + 0x1044, 0, 0x14);
    func_188250(p, 2.0f);
    *(int *)(p + 0x60) = 0;
    func_188240(p, 0);
    func_188290(p, 0);
    func_1882A0(p, 0);
    func_1882B0(p, 1);
    func_1882D0(p, 0);
    func_1882F0(p, 0x60, 0x60, 8);
    func_188300(p, 0);
    func_188310(p, 1);
    func_188330(p, 1);
    func_188340(p, 1);
    func_1884A0(p, 2.0f);
    func_188490(p, 2.0f);
    func_1884F0(p);
    func_188500(p);
    func_188360(p, 0);
    func_1883C0(p, 2);
    for (int i = 0; i < 9; i++) {
        func_1883B0(p, i, 0);
        func_188370(p, i, 0);
        func_188390(p, i, 0);
        func_1883D0(p, i, 1);
    }
    func_1883E0(p, 2);
    func_1883F0(p, 2);
    func_188350(p, 4);
    func_188260(p, (const void *)0x00491988);
    D_004E3180 = p;
    *(void **)(p + 0x28) = a1;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 1;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x40) = 0;
    D_004E3110 = 0;
    *(int *)(p + 0x58) = 0;
    *(int *)(p + 0x64) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    *(int *)(p + 0x70) = 0;
    *(char *)(p + 0x78) = 2;
    *(int *)(p + 0x7C) = 0;
    *(int *)(p + 0x84) = 0;
    *(int *)(p + 0x88) = 0;
    *(short *)(p + 0x8C) = 0;
    *(int *)(p + 0x90) = 0;
    for (int j = 0; j < 5; j++) {
        *(int *)(p + 0x1030 + j * 4) = 0;
        *(char *)(p + 0xB30 + (j << 8)) = 0;
    }
    *(char *)(p + 0x94) = 0;
    *(int *)(p + 0x98) = 0;
    *(int *)(p + 0x9C) = 0;
    *(int *)(p + 0xA0) = 0;
    *(char *)(p + 0xA4) = 0;
    *(int *)(p + 0x1A4) = 0;
    *(int *)(p + 0x1A8) = 0;
    *(int *)(p + 0x1AC) = 0;
    D_004E3114 = 0;
    *(int *)(p + 0x1C4) = 0;
    *(int *)(p + 0x1B0) = 0;
    *(int *)(p + 0x1B8) = 0;
    *(int *)(p + 0x1BC) = 0;
    *(int *)(p + 0x1C0) = 1;
    *(int *)(p + 0x1B4) = 0;
    *(int *)(p + 0xB28) = 0;
    *(int *)(p + 0x1C8) = 0;
    *(int *)(p + 0x1CC) = 0;
    *(int *)(p + 0x1D0) = 0;
    *(int *)(p + 0x1D4) = 0;
    *(int *)(p + 0x1D8) = 0;
    *(int *)(p + 0x1DC) = 0;
    *(int *)(p + 0x1E0) = 0;
    *(int *)(p + 0x1E4) = 0;
    *(int *)(p + 0x1E8) = 0;
    *(short *)(p + 0x1F8) = 0;
    *(int *)(p + 0x1FC) = 0;
    *(int *)(p + 0x20) = 10;
    *(int *)(p + 0x404) = 0;
    *(int *)(p + 0x408) = 1;
    *(short *)(p + 0x40C) = -1;
    *(short *)(p + 0x40E) = 0;
    *(char *)(p + 0x410) = 0;
    *(short *)(p + 0x412) = -1;
    *(short *)(p + 0x414) = -1;
    *(short *)(p + 0x416) = 1;
    *(char *)(p + 0x418) = 0;
    *(int *)(p + 0x518) = 0;
    *(int *)(p + 0x51C) = 0;
    *(int *)(p + 0x520) = 0;
    *(int *)(p + 0x524) = 0;
    *(int *)(p + 0x528) = 0;
    *(int *)(p + 0x52C) = 0;
    *(int *)(p + 0x530) = 0;
    *(int *)(p + 0x534) = 0;
    *(int *)(p + 0x538) = 0;
    *(int *)(p + 0x908) = 0;
    for (int k = 0; k < 30; k++) {
        char *el = p + 0x53C + k * 32;
        *(int *)(el + 0x00) = 0;
        *(int *)(el + 0x04) = 0;
        *(int *)(el + 0x08) = 0;
        *(int *)(el + 0x14) = 0;
        *(int *)(el + 0x18) = 0;
        *(int *)(el + 0x1C) = 0;
        *(int *)(el + 0x0C) = 0;
        *(int *)(el + 0x10) = 0;
    }
    *(int *)(p + 0x8FC) = 0;
    *(int *)(p + 0x900) = 0;
    *(int *)(p + 0x904) = 0;
    *(int *)(p + 0x9C8) = 1;
    *(int *)(p + 0x44) = 0;
    void *v0 = *(void **)(p + 0x28);
    D_004E30FC = *(int *)((char *)v0 + 0xC);
    D_004E3100 = 0;
    D_004E3104 = 0;
    D_004E3108 = 0;
    D_004E310C = 0;
    for (int m = 0; m < 9; m++) {
        *(int *)(p + 0x9CC + m * 4) = 0;
        *(char *)(p + 0x1061 + m) = 0;
    }
    for (int n = 0; n < 5; n++) {
        *(int *)(p + 0x8 + n * 4) = -1;
    }
    *(int *)(p + 0xB1C) = 0;
    *(int *)(p + 0xB2C) = 1;
    *(int *)(p + 0x106C) = 0;
    *(int *)(p + 0x105C) = 3;
    D_004E315C = 0x005670C0;
    if (a2 != 0) {
        typedef int (*VMethod26)(void *self);
        VMethod26 fn = *(VMethod26 *)(*(char **)p + 0x68);
        if (fn(p) == 0 && *(int *)(p + 0x64) == 0) {
            *(int *)(p + 0x64) = 1;
        }
    }
    *(int *)(p + 0x9F0) = 0;
    *(int *)(p + 0x9F4) = 0;
    *(unsigned char *)(p + 0x4) = 0xFF;
    return p;
}
}

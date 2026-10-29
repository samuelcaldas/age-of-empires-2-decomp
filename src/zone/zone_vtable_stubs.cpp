#pragma exceptions off

#include "zone_vtable_stubs.h"

struct ZoneStubLayout {
    char pad_base[0x8EAE];
    short f_8EAE;
    short f_8EB0;
    short f_8EB2;
    short f_8EB4;
    short f_8EB6;
    char pad_8EB8[0x15];
    unsigned char f_8ECD;
    unsigned char f_8ECE;
};

extern "C" {
void func_1C98A0(void *a0, void *a1, void *a2);
void func_32F090(void *a0);
void func_1CF9B0(void *a0, void *a1, void *a2, int a3, int a4,
                 short a5, short a6, void *a7, long long sp0, long long sp8);
void func_32FBD0(void *a0);

void func_001C97A0(void) {
}

void func_001C97B0(void *self, unsigned char val) {
    ZoneStubLayout *zm = (ZoneStubLayout *)self;
    zm->f_8ECD = val;
}

void func_001C97C0(void *self, unsigned char val) {
    ZoneStubLayout *zm = (ZoneStubLayout *)self;
    zm->f_8ECE = val;
}

void func_001C97D0(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    void *s5 = a4;
    void *s2 = a1;
    void *s4 = a5;
    void *s1 = a2;
    void *s0 = a3;
    void *s3 = a0;

    func_1C98A0(s3, s5, s4);

    if (s1) func_32F090(s1);

    func_1CF9B0(s3, s2, s1, 0, 0,
                (short)((int)s5 - 1),
                (short)((int)s4 - 1),
                s0, 1, 0);

    if (s1) func_32FBD0(s1);
}
}

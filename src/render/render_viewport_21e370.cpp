#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *obj);
void func_102C88(void *buffer, int a1, int a2, int a3, int a4, int a5);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_104890(void *obj, void *data, int count);
void *func_104600(void *obj);
void func_104FA0(void *obj);

struct ViewportTag {
    unsigned int words[4];
};

extern ViewportTag D_392BB0;
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

void *func_0021E370(void *obj, short s5, short s4, short s3, short s2,
                    short s1, short s0, short s7) {
    ViewportTag tag = D_392BB0;

    if (obj == 0) {
        obj = func_123908(0);
    }

    unsigned char buf[128];
    func_102C88(buf, (short)s4, (short)s3, (short)s2, (short)s0, (short)s7);

    int t1 = (s5 >> 11) & 0x1FF;
    int v1 = (s1 >> 11) & 0x1FF;
    int t2 = (s3 >> 6) & 0x3F;

    D_00CA158C = (unsigned short)s3;
    buf[3] = (unsigned char)((buf[3] & -0x40) | (s4 & 0x3F));
    buf[2] = (unsigned char)((buf[2] & -0x40) | t2);
    D_00CA158E = (unsigned short)s2;
    *(unsigned short *)(buf + 0) = (unsigned short)((*(unsigned short *)(buf + 0) & -0x200) | t1);
    *(unsigned short *)(buf + 16) = (unsigned short)((*(unsigned short *)(buf + 16) & -0x200) | v1);

    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, &tag);
    func_104890(obj, buf, 8);
    func_104600(obj);
    func_104FA0(0);
    return obj;
}
}

#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void func_102C88(void *a, void *b, void *c, void *d, void *e);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_104890(void *obj, void *data, int count);
void *func_104600(void *obj);
void func_104FA0(void *obj);

extern unsigned int D_00392BB0[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

void *func_0021E370(void *obj, int v0, int f1c, int width, int height, int t1, int t2, int t3) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    tag[0] = ((unsigned long long)D_00392BB0[0]) | (((unsigned long long)D_00392BB0[1]) << 32);
    tag[1] = ((unsigned long long)D_00392BB0[2]) | (((unsigned long long)D_00392BB0[3]) << 32);

    unsigned char buf[64];
    func_102C88(buf, (void *)v0, (void *)f1c, (void *)width, (void *)height);

    D_00CA158C = (unsigned short)width;
    D_00CA158E = (unsigned short)height;

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    func_104890(packet, buf, 8);
    func_104600(packet);

    func_104FA0(0);
    return packet;
}
}

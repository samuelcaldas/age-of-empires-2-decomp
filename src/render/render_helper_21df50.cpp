#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void func_1046D0(void *obj, void *data, int count);
void *func_0021C050(void *obj);

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

void *func_0021DF50(void *ctx, int a1, int f1c, int a3, int s1, int a5, int a6, int aligned_3c, long long f38) {
    void *packet = EnsurePacketObject(ctx);

    unsigned int params[8];
    params[0] = (unsigned int)a1;
    params[1] = (unsigned int)f1c;
    params[2] = (unsigned int)a3;
    params[3] = (unsigned int)s1;
    params[4] = (unsigned int)a5;
    params[5] = (unsigned int)a6;
    params[6] = (unsigned int)aligned_3c;
    params[7] = (unsigned int)f38;

    func_1046D0(packet, params, 8);
    func_0021C050(packet);

    return packet;
}
}

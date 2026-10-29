#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void func_1046D0(void *obj, unsigned short a1, unsigned char a2, unsigned short a3, void *t0, int t1, short t2,
                 short t3, long long stack_t3, long long stack_arg_b0);
void *func_0021C050(void *obj);

void *func_0021DF50(void *ctx, short a0, short a1, short a2, void *t0, short t1, short t2, short t3,
                    short arg_b0) {
    if (ctx == 0) {
        ctx = func_123908(0);
    }
    void *packet = ctx;

    int divisor = 0x40;
    if (a1 == 0x14) {
        divisor = 0x200;
    } else if (a1 == 0x13) {
        divisor = 0x100;
    } else if (a1 == 0x2) {
        divisor = 0x80;
    }

    int extent = ((t3 * arg_b0 << 4) + divisor - 1) / divisor;

    func_1046D0(packet, (unsigned short)a0, (unsigned char)a1, (unsigned short)a2, t0, extent, t1, t2,
                (long long)t3, (long long)arg_b0);
    func_0021C050(packet);
    return packet;
}
}

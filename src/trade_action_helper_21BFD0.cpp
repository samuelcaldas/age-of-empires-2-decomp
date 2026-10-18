#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B30[4];

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void *InitPacketHeader(void *obj) {
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, D_00392B30);
    return obj;
}

static void *FinalizePacket(void *obj, int reg, unsigned long long data) {
    func_1046A8(obj, reg, data);
    func_104600(obj);
    return obj;
}

void *func_0021BFD0(void *obj, int val) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x08, (unsigned int)val);
}

void *func_0021C050(void *obj) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x3F, 0ULL);
}

static unsigned long long PackBitfield42(int a1, int a2, int a3, int t0, int t1) {
    unsigned long long part_low = ((unsigned long long)(unsigned int)a1)
                                | (((unsigned long long)(unsigned int)a2) << 2)
                                | (((unsigned long long)(unsigned int)a3) << 4)
                                | (((unsigned long long)(unsigned int)t0) << 6);
    unsigned long long part_high = ((unsigned long long)(unsigned int)t1) << 32;
    return part_low | part_high;
}

void *func_0021C0D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield42(a1, a2, a3, t0, t1);
    return FinalizePacket(packet, 0x42, data);
}

void *func_0021C1D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield42(a1, a2, a3, t0, t1);
    return FinalizePacket(packet, 0x43, data);
}

static unsigned long long PackBitfield48(int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp90) {
    unsigned long long val = ((unsigned long long)(unsigned int)a1)
                           | (((unsigned long long)(unsigned int)a2) << 1)
                           | (((unsigned long long)(unsigned int)a3) << 4)
                           | (((unsigned long long)(unsigned int)t0) << 12)
                           | (((unsigned long long)(unsigned int)t1) << 14)
                           | (((unsigned long long)(unsigned int)t2) << 15)
                           | (((unsigned long long)(unsigned int)t3) << 16)
                           | (((unsigned long long)(unsigned int)sp90) << 17);
    return val;
}

void *func_0021C2D0(void *obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp90) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield48(a1, a2, a3, t0, t1, t2, t3, sp90);
    return FinalizePacket(packet, 0x48, data);
}
}

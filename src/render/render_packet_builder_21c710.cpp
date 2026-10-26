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

void *func_0021C710(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x14, (unsigned long long)(unsigned int)a1);
}

void *func_0021C790(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x16, (unsigned long long)(unsigned int)a1);
}

static unsigned long long PackBitfield3B(int a1, int a2, int a3) {
    unsigned long long part1 = (unsigned long long)(unsigned int)a1;
    unsigned long long part2 = ((unsigned long long)(unsigned int)a2) << 15;
    unsigned long long part3 = ((unsigned long long)(unsigned int)a3) << 32;
    return part1 | part2 | part3;
}

void *func_0021C810(void *obj, int a1, int a2, int a3) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield3B(a1, a2, a3);
    return FinalizePacket(packet, 0x3B, data);
}

static unsigned long long PackBitfield4F(int a1, int a2, int a3) {
    unsigned long long part1 = (unsigned long long)(unsigned int)a1;
    unsigned long long part2 = ((unsigned long long)(unsigned int)a2) << 24;
    unsigned long long part3 = ((unsigned long long)(unsigned int)a3) << 32;
    return part1 | part2 | part3;
}

void *func_0021C8D0(void *obj, int a1, int a2, int a3) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield4F(a1, a2, a3);
    return FinalizePacket(packet, 0x4F, data);
}
}

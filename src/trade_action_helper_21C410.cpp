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

void *func_0021C410(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = (unsigned long long)(unsigned int)a1;
    return FinalizePacket(packet, 0x4A, data);
}

void *func_0021C4A0(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = (unsigned long long)(unsigned int)a1;
    return FinalizePacket(packet, 0x4B, data);
}

static unsigned long long PackBitfield4D(int a1, int a2, int a3, int t0) {
    unsigned long long part1 = (unsigned long long)(unsigned int)a1;
    unsigned long long part2 = ((unsigned long long)(unsigned int)a2) << 16;
    unsigned long long part3 = ((unsigned long long)(unsigned int)a3) << 24;
    unsigned long long part4 = ((unsigned long long)(unsigned int)t0) << 32;
    return part1 | part2 | part3 | part4;
}

void *func_0021C530(void *obj, int a1, int a2, int a3, int t0) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield4D(a1, a2, a3, t0);
    return FinalizePacket(packet, 0x4D, data);
}

void *func_0021C610(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x48, (unsigned long long)(unsigned int)a1);
}

void *func_0021C690(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    return FinalizePacket(packet, 0x41, (unsigned long long)(unsigned int)a1);
}
}

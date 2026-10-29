#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B30[4];

static inline void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static inline void *InitPacketHeader(void *obj) {
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, D_00392B30);
    return obj;
}

static inline void *FinalizePacket(void *obj, int reg, unsigned long long data) {
    func_1046A8(obj, reg, data);
    func_104600(obj);
    return obj;
}

void *func_0021C710(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    func_1046A8(packet, 0x14, a1);
    func_104600(packet);
    return packet;
}

void *func_0021C790(void *obj, int a1) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    func_1046A8(packet, 0x16, a1);
    func_104600(packet);
    return packet;
}

static inline unsigned long long PackBitfield3B(int a1, int a2, int a3) {
    long long part1 = (long long)a1;
    long long part2 = (long long)a2 << 15;
    long long part3 = (long long)a3 << 32;
    return (unsigned long long)(part1 | part2 | part3);
}

void *func_0021C810(void *obj, int a1, int a2, int a3) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield3B(a1, a2, a3);
    return FinalizePacket(packet, 0x3B, data);
}

static inline unsigned long long PackBitfield4F(int a1, int a2, int a3) {
    long long part1 = (long long)a1;
    long long part2 = (long long)a2 << 24;
    long long part3 = (long long)a3 << 32;
    return (unsigned long long)(part1 | part2 | part3);
}

void *func_0021C8D0(void *obj, int a1, int a2, int a3) {
    void *packet = EnsurePacketObject(obj);
    InitPacketHeader(packet);
    unsigned long long data = PackBitfield4F(a1, a2, a3);
    return FinalizePacket(packet, 0x4F, data);
}
}

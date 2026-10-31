#pragma exceptions off

#if defined(__MWERKS__) || defined(_R5900)
typedef unsigned __int128 PacketTag;
#else
struct PacketTag {
    unsigned int w[4];
};
#endif

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, PacketTag tag);
void *func_1046A8(void *obj, int reg, ...);
void *func_104600(void *obj);

extern unsigned int D_00392B30[];

void *func_0021C710(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x14, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C790(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x16, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C810(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x3B, (long long)a1 | ((long long)a2 << 15) | ((long long)a3 << 32));
    func_104600(obj);
    return obj;
}

void *func_0021C8D0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x4F, (long long)a1 | ((long long)a2 << 24) | ((long long)a3 << 32));
    func_104600(obj);
    return obj;
}
}

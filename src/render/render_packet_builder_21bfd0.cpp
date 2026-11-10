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

void *func_0021BFD0(void *obj, int val) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x08, val);
    func_104600(obj);
    return obj;
}

void *func_0021C050(void *obj) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x3F, 0);
    func_104600(obj);
    return obj;
}

void *func_0021C0D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x42, (long long)a1 | ((long long)a2 << 2) | ((long long)a3 << 4) | ((long long)t0 << 6) | ((long long)t1 << 32));
    func_104600(obj);
    return obj;
}

void *func_0021C1D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x43, (long long)a1 | ((long long)a2 << 2) | ((long long)a3 << 4) | ((long long)t0 << 6) | ((long long)t1 << 32));
    func_104600(obj);
    return obj;
}

void *func_0021C2D0(void *obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp90) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x48, (long long)a1 | ((long long)a2 << 1) | ((long long)a3 << 4) | ((long long)t0 << 12) | ((long long)t1 << 14) |
                               ((long long)t2 << 15) | ((long long)t3 << 16) | ((long long)sp90 << 17));
    func_104600(obj);
    return obj;
}
}

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

void *func_0021C410(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x4A, (unsigned long long)(unsigned int)a1);
    func_104600(obj);
    return obj;
}

void *func_0021C4A0(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x4B, (unsigned long long)(unsigned int)a1);
    func_104600(obj);
    return obj;
}

void *func_0021C530(void *obj, int a1, int a2, int a3, int t0) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x4D, (unsigned long long)(unsigned int)a1 | ((unsigned long long)(unsigned int)a2 << 16) |
                               ((unsigned long long)(unsigned int)a3 << 24) | ((unsigned long long)(unsigned int)t0 << 32));
    func_104600(obj);
    return obj;
}

void *func_0021C610(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x48, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C690(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(PacketTag *)D_00392B30);
    func_1046A8(obj, 0x41, a1);
    func_104600(obj);
    return obj;
}
}

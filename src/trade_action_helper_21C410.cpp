#pragma exceptions off
#include "sub_list.h"

#ifdef __MWERKS__
typedef unsigned __int128 u128;
#else
struct u128 {
    unsigned int words[4];
};
#endif

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, u128 tag);
void *func_1046A8(void *obj, int reg, unsigned long long val);
void *func_104600(void *obj);

extern unsigned int D_00392B30[];

void *func_0021C410(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x4A, (unsigned long long)(unsigned int)a1);
    func_104600(obj);
    return obj;
}

void *func_0021C4A0(void *obj, int a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x4B, (unsigned long long)(unsigned int)a1);
    func_104600(obj);
    return obj;
}

void *func_0021C530(void *obj, int a1, int a2, int a3, int t0) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long part_low = ((unsigned long long)(unsigned int)a1)
                                | (((unsigned long long)(unsigned int)a2) << 16)
                                | (((unsigned long long)(unsigned int)a3) << 24);
    unsigned long long part_high = ((unsigned long long)(unsigned int)t0) << 32;
    func_1046A8(obj, 0x4D, part_high | part_low);
    func_104600(obj);
    return obj;
}

void *func_0021C610(void *obj, unsigned long a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x48, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C690(void *obj, unsigned long a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x41, a1);
    func_104600(obj);
    return obj;
}
}

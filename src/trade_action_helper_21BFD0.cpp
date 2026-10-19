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

void *func_0021BFD0(void *obj, unsigned long val) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 8, val);
    func_104600(obj);
    return obj;
}

void *func_0021C050(void *obj) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x3F, 0);
    func_104600(obj);
    return obj;
}

void *func_0021C0D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long part_low = ((unsigned long long)a1)
                                | (((unsigned long long)a2) << 2)
                                | (((unsigned long long)a3) << 4)
                                | (((unsigned long long)t0) << 6);
    unsigned long long part_high = ((unsigned long long)t1) << 32;
    func_1046A8(obj, 0x42, part_high | part_low);
    func_104600(obj);
    return obj;
}

void *func_0021C1D0(void *obj, int a1, int a2, int a3, int t0, int t1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long part_low = ((unsigned long long)a1)
                                | (((unsigned long long)a2) << 2)
                                | (((unsigned long long)a3) << 4)
                                | (((unsigned long long)t0) << 6);
    unsigned long long part_high = ((unsigned long long)t1) << 32;
    func_1046A8(obj, 0x43, part_high | part_low);
    func_104600(obj);
    return obj;
}

void *func_0021C2D0(void *obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp90) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long val = ((unsigned long long)a1)
                           | (((unsigned long long)a2) << 1)
                           | (((unsigned long long)a3) << 4)
                           | (((unsigned long long)t0) << 12)
                           | (((unsigned long long)t1) << 14)
                           | (((unsigned long long)t2) << 15)
                           | (((unsigned long long)t3) << 16)
                           | (((unsigned long long)sp90) << 17);
    func_1046A8(obj, 0x48, val);
    func_104600(obj);
    return obj;
}
}

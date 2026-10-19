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

void *func_0021C710(void *obj, unsigned long a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x14, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C790(void *obj, unsigned long a1) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    func_1046A8(obj, 0x16, a1);
    func_104600(obj);
    return obj;
}

void *func_0021C810(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long part_low = ((unsigned long long)a1)
                                | (((unsigned long long)a2) << 15);
    unsigned long long part_high = ((unsigned long long)a3) << 32;
    func_1046A8(obj, 0x3B, part_high | part_low);
    func_104600(obj);
    return obj;
}

void *func_0021C8D0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        obj = func_123908(0);
    }
    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)D_00392B30);
    unsigned long long part_low = ((unsigned long long)a1)
                                | (((unsigned long long)a2) << 24);
    unsigned long long part_high = ((unsigned long long)a3) << 32;
    func_1046A8(obj, 0x4F, part_high | part_low);
    func_104600(obj);
    return obj;
}
}
